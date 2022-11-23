/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:18:02 by jhesso            #+#    #+#             */
/*   Updated: 2022/11/23 16:25:16 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Join stash and buffer together
*  and free the old stash
*/
static char	*join_and_free(char *stash, char *buffer)
{
	char	*new_stash;

	new_stash = ft_strjoin(stash, buffer);
	free(stash);
	return (new_stash);
}

static char	*get_line(char *stash)
{
	int		i;
	char	*line;
	int		line_len;

	i = 0;
	line_len = 0;
	while (stash[line_len] != '\n' && stash[line_len] != '\0')
		line_len++;
	line = ft_calloc(line_len + 1, sizeof(char));
	if (line == NULL)
		return(NULL);
	while (line_len > 0)
	{
		line[i] = stash[i];
		i++;
		line_len--;
	}
	return (line);
}

/* remove the found line from stash */
static char	*get_next(char *stash, char *line)
{
	int		line_len;
	int		stash_len;
	char	*new_stash;
	int		i;

	line_len = (int)ft_strlen(line);
	stash_len = (int)ft_strlen(stash);
	new_stash = ft_calloc((stash_len - line_len + 1), sizeof(char));
	if (new_stash == NULL)
		return (NULL);
	stash = stash + (line_len - 1); // move the stash pointer forward
	// new_stash = stash;
	i = -1;
	while (stash[++i] != '\0') // tried to run through the stash and save into
		new_stash[i] = stash[i]; // new_stash instead of assigning &stash to new_stash
	free(stash); 				// to get rid of the malloc errors.. didnt work
	return (new_stash);
}

/* Read fd until we find a newline or EOF */
static char	*read_line(char *stash, int fd)
{
	char	*buffer;
	int		ret;

	if (!stash) // allocate some room for stash if not done before
		stash = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char)); // allocate memory for buffer
	ret = 1;
	while (ret > 0) // read from fd while we dont find \n or EOF
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1) // protect the read
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0'; // C strings should always be null terminated
		stash = join_and_free(stash, buffer); // strjoin buffer and stash + free stash
		if (ft_strchr(buffer, '\n')) // check if we have found a newline
			break;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash; // save read text here
	char		*line; // this is the char* we want to return

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) // always use protection
		return (NULL);
	stash = read_line(stash, fd);
	if (stash == NULL)
		return (NULL);
	line = get_line(stash);
	stash = get_next(stash, line);
	return (line);
}
