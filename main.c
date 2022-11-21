/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:21:30 by jhesso            #+#    #+#             */
/*   Updated: 2022/11/21 13:08:32 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	int		fd;
	char	*ret = "";

	printf(RED "get ready >:)\n" COLOR_RESET);
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	while (ret != NULL)
	{
		ret = get_next_line(fd);
		printf("%s", ret);
	}
	return (0);
}
