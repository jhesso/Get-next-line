/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:18:05 by jhesso            #+#    #+#             */
/*   Updated: 2022/12/02 14:43:00 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*dst;

	dst = (char *)s;
	while (n--)
		*dst++ = (char)0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size == 0 || count == 0)
		return (ft_calloc(1, 1));
	if (count * size / size != count || count * size / count != size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*ret;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ret = malloc(sizeof(char) * size + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		ret[j++] = s2[i++];
	ret[j] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	char	a;

	tmp = (char *)s;
	a = (char)c;
	while (*tmp != '\0')
	{
		if (*tmp == a)
			return ((char *)tmp);
		tmp++;
	}
	if (a == '\0')
		return ((char *)tmp);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}
