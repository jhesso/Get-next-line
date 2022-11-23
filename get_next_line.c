/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:24:19 by jhesso            #+#    #+#             */
/*   Updated: 2022/11/23 16:47:10 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

static char	*ft_join(char *stash, char *buffer)
{
	char	*new_stash;

	new_stash = ft_strjoin(stash, buffer);
	free(stash);
	return (new_stash);
}

/* read fd and save what is read into stash. the while loop ends when
** either a newline or EOF is reached
*/
static char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	short	ret;

	// if stash has not been initialized yet, do that
	if (!stash)
		stash = ft_calloc(1, 1);
	// allocate memory for buffer so that we can read stuff
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (buffer == NULL || stash == NULL)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		if (ft_strchr(stash, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		stash = ft_join(stash, buffer);
	}
	free (buffer);
	return (stash);
}

static char	*ft_find_line(char *stash)
{
	int		len;
	int		i;
	char	*line;

	// first we calculate the length of our line
	len = 0;
	while(stash[len] != '\n' && stash[len] != '\0')
		len++;
	// allocate memory for our line
	line = ft_calloc(len + 1, sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

/* ! this function has malloc/free issues
** truncate line from stash and return the new stash back
*/
static char	*ft_truncate_stash(char *stash, char *line)
{
	char	*n_stash;
	int		i;
	int		j;

	j = ft_strlen(line);
	n_stash = ft_calloc((ft_strlen(stash) - j) + 1, sizeof(char));
	if (n_stash == NULL)
		return (NULL);
	i = 0;
	while (stash[j] != '\0')
	{
		n_stash[i] = stash[j];
		i++;
		j++;
	}
	free(stash); // this line for some reason causes a malloc/free error why wouldnt stash be allocated?!?
	return (n_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	// add some protection because you can never be too careful
	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	// if (!stash)
	// 	stash = ft_calloc(1,1);
	// call our read function
	stash = ft_read(fd, stash);
	if (stash == NULL)
		return (NULL);
	// call our line find function
	line = ft_find_line(stash);
	if (line == NULL)
		return (NULL);
	// truncate line from stash
	stash = ft_truncate_stash(stash, line);
	if (stash == NULL)
		return (NULL);
	return (line);
}
