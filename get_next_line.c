
#include "pushswap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = '\0';
	}
	if (!s2)
		return (s1);
	i = -1;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free (s1);
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	if (c == 0)
		return (s + i);
	return (NULL);
}

char	*ft_read(char *str, int fd)
{
	char	*ptr;
	int		rd;

	rd = 1;
	ptr = (char *)malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	while (!ft_strchr(str, '\n') && rd != 0)
	{
		rd = read(fd, ptr, BUFFER_SIZE);
		if (rd == -1)
		{
			free (ptr);
			return (NULL);
		}
		ptr[rd] = '\0';
		str = ft_strjoin(str, ptr);
	}
	free (ptr);
	return (str);
}

char	*get_after_new_line(char *str)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!ptr)
		return (NULL);
	while (str[++i])
		ptr[j++] = str[i];
	ptr[j] = '\0';
	free (str);
	return (ptr);
}

char	*get_line(char *str)
{
	char	*ptr;
	int		i;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ptr = (char *)malloc(sizeof(char) * i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	char static	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	ret = get_line(str);
	str = get_after_new_line(str);
	return (ret);
}
