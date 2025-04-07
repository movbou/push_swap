#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (srclen);
}
int	word_count(const char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

static int	word_malloc(char **arr, int index, size_t len)
{
	int	i;

	arr[index] = malloc(len);
	if (arr[index] == NULL)
	{
		i = 0;
		while (i < index)
			free(arr[i++]);
		free(arr);
		return (1);
	}
	return (0);
}

static int	fill_arr(char **arr, const char *s, char c, int index)
{
	size_t	len;

	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (len)
		{
			if (word_malloc(arr, index, len + 1))
				return (1);
			ft_strlcpy(arr[index], s - len, len + 1);
			index++;
		}
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	int		nwords;
	char	**arr;

	if (!s)
		return (NULL);
	nwords = word_count(s, c);
	arr = malloc((nwords + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[nwords] = NULL;
	if (fill_arr(arr, s, c, 0))
		return (NULL);
	return (arr);
}
