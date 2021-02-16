# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:07:35 by cquezada          #+#    #+#              #
#    Updated: 2021/02/16 19:05:16 by cquezada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

LNAME = libft.a

SOURCE = *.c

LSOURCE = *.o

CFLAGS = -g3 -Wall -Werror -Wextra

LFLAGS = -c

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(LFLAGS) $(SOURCE)
	ar rcs $(LNAME) $(LSOURCE)
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(LNAME)

re: fclean all 
