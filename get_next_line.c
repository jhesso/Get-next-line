/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:24:19 by jhesso            #+#    #+#             */
/*   Updated: 2022/11/23 13:12:46 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Get next line implementation:
	1. check if stash has stuff in it and if it does. check if we find a newline or EOF
	2. read into buffer and save that in to stash
	3. find the line, save line into our return variable and remove line from stash
	4. return line
*/

char	*ft_join(char *stash, char *buffer)
{
	char	*new_stash;

	new_stash = ft_strjoin(stash, buffer);
	free(stash);
	return (new_stash);
}

/* read fd and save what is read into stash. the while loop ends when
** either a newline or EOF is reached
*/
char	*ft_read(int fd, char *stash)
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

char	*ft_find_line(char *stash)
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
char	*ft_truncate_line(char *stash, char *line)
{
	char	*n_stash;
	int		i;

	n_stash = ft_calloc((ft_strlen(stash) - ft_strlen(line)) + 1, sizeof(char));
	if (n_stash == NULL)
		return (NULL);
	stash = stash + ft_strlen(line);
	i = 0;
	while (stash[i] != '\0')
	{
		n_stash[i] = stash[i];
		i++;
	}
	// free(stash); this line for some reason causes a malloc error/ why wouldnt stash be allocated?!?
	return (n_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	// add some protection because you can never be too careful
	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	// call our read function
	stash = ft_read(fd, stash);
	// call our line find function
	line = ft_find_line(stash);
	// truncate line from stash
	stash = ft_truncate_line(stash, line);
	return (line);
}
