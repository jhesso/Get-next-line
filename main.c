/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:21:30 by jhesso            #+#    #+#             */
/*   Updated: 2022/12/02 14:04:43 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	int	fd[3];
	char	*ret = "";

	printf(RED "get ready >:)\n" COLOR_RESET);
	fd[0] = open("files/multifd1", O_RDONLY);
	if (fd[0] < 0)
		return (-1);
	fd[1] = open("files/multifd2", O_RDONLY);
	if (fd[1] < 0)
		return (-1);
	fd[2] = open("files/multifd3", O_RDONLY);
	if (fd[2] < 0)
		return (-1);
	// while (ret != NULL)
	// {
	// 	ret = get_next_line(fd);
	// 	// printf("%s", ret);
	// }
	ret = get_next_line(fd[0]);
	printf("%s", ret);
	ret = get_next_line(fd[1]);
	printf("%s", ret);
	ret = get_next_line(fd[0]);
	printf("%s", ret);
	ret = get_next_line(fd[1]);
	printf("%s", ret);
	ret = get_next_line(fd[2]);
	printf("%s", ret);
	ret = get_next_line(fd[2]);
	printf("%s", ret);
	ret = get_next_line(fd[2]);
	printf("%s", ret);
	ret = get_next_line(fd[0]);
	printf("%s", ret);
	ret = get_next_line(fd[0]);
	printf("%s", ret);
	ret = get_next_line(fd[1]);
	printf("%s", ret);
	ret = get_next_line(fd[2]);
	printf("%s", ret);
	free(ret);
	return (0);
}
