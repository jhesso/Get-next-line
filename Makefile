# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:09:15 by jhesso            #+#    #+#              #
#    Updated: 2022/12/02 14:42:12 by jhesso           ###   ########.fr        #
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

bonus:
	cc $(CFLAGS) main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl

debug:
	cc $(CFLAGS) -g main.c get_next_line.c get_next_line_utils.c -o gnl

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm gnl

re: fclean all

.PHONY: all clean fclean re debug bonus
