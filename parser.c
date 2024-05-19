#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "parser.h"
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int	ft_atoi(const char *str);
int checkifminusone(char *str)
{

	if(str[0] == '-' && str[1] == '1' && !str[2])
		return (1);
	return (0);
}
t_strings	*strs_to_str(char **strs, int len)
{
    int i = 0;
    int j = 0;
    int h = 0;
    char **tmp;
	t_strings	*strings;
    char **result;
    int totalsize = 0;

	strings = malloc(sizeof(t_strings));

    while (i < len) {
        tmp = ft_split(strs[i], ' ');
        for (j = 0; tmp[j] != NULL; j++) {
            totalsize++;
        }
        for (j = 0; tmp[j] != NULL; j++) {
            free(tmp[j]);
        }
        free(tmp); 
        i++;
    }
	strings->size = totalsize;
    result = (char **)malloc(sizeof(char *) * (totalsize + 1));
    if (!result) {
        return NULL;
    }
    i = 0;
    while (i < len) {
        tmp = ft_split(strs[i], ' ');
        for (j = 0; tmp[j] != NULL; j++) {
            result[h] = ft_strdup(tmp[j]);
            if (!result[h]) {
                for (int k = 0; k < h; k++)
				{
                    free(result[k]);
                }
                free(result);
                return NULL;
            }
            h++;
        }
        for (j = 0; tmp[j] != NULL; j++) {
            free(tmp[j]);
        }
        free(tmp);
        i++;
    }
    result[h] = NULL;
	strings->strs = result;
    return strings;
}
int invalid_char(char c)
{
	if((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (SUCCESS);
	return (INVALID_CHAR);
}
int check_invalid_chars(char	*str)
{
	int i =0;
	while(i < ft_strlen(str))
	{
		if (invalid_char(str[i]) == INVALID_CHAR)
		{
			// printf("%c\n", str[i]);
			return (INVALID_CHAR);

		}
		i++;
	}
	return (SUCCESS);
}
int is_digit(char c){
	if(c >= '0' && c <= '9')
		return (1);
	else 
		return (0);
}
int is_number(const char *str) {
    if (*str == '\0') {
        return -1;
    }

    if (*str == '-' || *str == '+') {
        str++;
    }

    int has_digits = 0;
    while (*str) {
        if (!is_digit(*str)) {
            return -1;
        }
        has_digits = 1;
        str++;
    }

    return has_digits ? 1 : -1;
}
int check_validity(t_strings *strs)
{
	int i = 0;
	long long nb;
	int ismo;
	while(i < strs->size)
	{
		ismo = checkifminusone(strs->strs[i]);
		// printf("[%d]",ismo);
		if (check_invalid_chars(strs->strs[i]) == INVALID_CHAR)
			return (ERROR);
		if (is_number(strs->strs[i]) == NOT_ANUMBER)
			return (ERROR);
		nb = ft_atoi(strs->strs[i]);
		if (nb == -1 && ismo == 0)
			return (ERROR);
		// printf("[%lld]{%s}",nb, strs->strs[i], );
		i++;
	}
	return (SUCCESS);
}


char *ft_strdup(const char *src) {
    size_t len = strlen(src);
    char *dup = (char *)malloc(len + 1);
    if (dup) {
        strcpy(dup, src);
    }
    return dup;
}

size_t ft_strlcpy(char *dst, const char *src, size_t len) {
    size_t srclen = strlen(src);
    if (len > 0) {
        size_t copylen = (srclen >= len) ? len - 1 : srclen;
        memcpy(dst, src, copylen);
        dst[copylen] = '\0';
    }
    return srclen;
}

char **ft_split(char const *s, char c) {
    if (!s) return NULL;
    size_t count = 0;
    for (size_t i = 0; s[i]; i++) {
        if (s[i] != c && (i == 0 || s[i - 1] == c)) {
            count++;
        }
    }
    char **result = (char **)malloc(sizeof(char *) * (count + 1));
    if (!result) return NULL;

    size_t j = 0;
    const char *start = NULL;
    for (size_t i = 0; s[i]; i++) {
        if (s[i] != c && !start) {
            start = &s[i];
        }
        if (start && (s[i + 1] == c || s[i + 1] == '\0')) {
            size_t len = &s[i] - start + 1;
            result[j] = (char *)malloc(len + 1);
            if (result[j]) {
                ft_strlcpy(result[j], start, len + 1);
                j++;
            }
            start = NULL;
        }
    }
    result[j] = NULL;
    return result;
}
int main(int ac, char **av) {
    if (ac <= 1) {
        printf("Usage: %s <string1> <string2> ... <stringN>\n", av[0]);
        return 1;
    }

    int i = 0;
	// s_swap *lst;
    t_strings *str = strs_to_str(av + 1, ac - 1);
	if (check_validity(str) == ERROR)
	{
		printf("format invalid");
		return (0);
	}
	// list = store_in_linked_list(str);
    if (str == NULL)
	{
        printf("Error allocating memory.\n");
        return 1;
    }

    while (str->strs[i] != NULL) {
        printf("%s\n", str->strs[i]);
        free(str->strs[i]);
        i++;
    }
    free(str);

    return 0;
}