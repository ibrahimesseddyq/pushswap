#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
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
	if((c < 48 || c > 57) && (c != '+' || c != '-'))
		return (INVALID_CHAR);
	return (SUCCESS);
}
int check_invalid_chars(char	*str)
{
	int i =0;
	while(i < ft_strlen(str))
	{
		if (invalid_char(str[i]) == INVALID_CHAR)
		{
			printf("%c\n", str[i]);
			return (INVALID_CHAR);

		}
		i++;
	}
	return (SUCCESS);
}
int check_validity(t_strings *strs)
{
	int i = 0;
	while(i < strs->size)
	{
		if (check_invalid_chars(strs->strs[i]) == INVALID_CHAR)
			return (ERROR);
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
    t_strings *str = strs_to_str(av + 1, ac - 1);
	if (check_validity(str) == ERROR)
	{
		printf("format invalid");
		return (0);
	}
    if (str == NULL) {
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