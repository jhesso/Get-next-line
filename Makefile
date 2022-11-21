# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:09:15 by jhesso            #+#    #+#              #
#    Updated: 2022/11/21 13:19:53 by jhesso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

all: main.o get_next_line.o get_next_line_utils.o
	cc $(CFLAGS) $^ -o gnl

main.o: main.c
	cc $(CFLAGS) -c $<

get_next_line.o: get_next_line.c get_next_line.h
	cc $(CFLAGS) -c $<

get_next_line_utils.o: get_next_line_utils.c
	cc $(CFLAGS) -c $<

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm gnl

re: fclean all

.PHONY: all clean fclean re
