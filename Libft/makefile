# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:07:35 by cquezada          #+#    #+#              #
#    Updated: 2019/11/25 13:04:29 by cquezada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

LNAME = libft.a

SOURCE = *.c

LSOURCE = *.o

CFLAGS = -Wall -Werror -Wextra

LFLAGS = -c

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(LFLAGS) $(SOURCE)
	ar rc $(LNAME) $(LSOURCE)
	
clean:
	rm -f *.o

fclean:
	rm -f $(LNAME)

re: fclean all 
