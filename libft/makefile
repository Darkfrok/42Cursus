# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:07:35 by cquezada          #+#    #+#              #
#    Updated: 2021/02/18 14:20:18 by cquezada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

LNAME = libft.a

SOURCE = ft_atoi.c \
		 ft_isalpha.c \
		 ft_itoa.c \
		 ft_memcpy.c \
		 ft_putendl_fd.c \
		 ft_strchr.c \
		 ft_strlcat.c \
		 ft_strncmp.c \
		 ft_substr.c \
		 ft_bzero.c \
		 ft_isascii.c \
		 ft_memccpy.c \
		 ft_memmove.c \
		 ft_putnbr_fd.c \
		 ft_strlcpy.c \
		 ft_strnstr.c \
		 ft_tolower.c \
		 ft_calloc.c \
		 ft_isdigit.c \
		 ft_memchr.c \
		 ft_memset.c\
		 ft_putstr_fd.c \
		 ft_strdup.c \
		 ft_strlen.c \
		 ft_strrchr.c \
		 ft_toupper.c \
		 ft_isalnum.c \
		 ft_isprint.c \
		 ft_memcmp.c \
		 ft_putchar_fd.c \
		 ft_split.c \
		 ft_strjoin.c \
		 ft_strmapi.c \
		 ft_strtrim.c \
		 ft_utoa.c \

LSOURCE = ft_atoi.o \
		 ft_isalpha.o \
		 ft_itoa.o \
		 ft_memcpy.o \
		 ft_putendl_fd.o \
		 ft_strchr.o \
		 ft_strlcat.o \
		 ft_strncmp.o \
		 ft_substr.o \
		 ft_bzero.o \
		 ft_isascii.o \
		 ft_memccpy.o \
		 ft_memmove.o \
		 ft_putnbr_fd.o \
		 ft_strlcpy.o \
		 ft_strnstr.o \
		 ft_tolower.o \
		 ft_calloc.o \
		 ft_isdigit.o \
		 ft_memchr.o \
		 ft_memset.o\
		 ft_putstr_fd.o \
		 ft_strdup.o \
		 ft_strlen.o \
		 ft_strrchr.o \
		 ft_toupper.o \
		 ft_isalnum.o \
		 ft_isprint.o \
		 ft_memcmp.o \
		 ft_putchar_fd.o \
		 ft_split.o \
		 ft_strjoin.o \
		 ft_strmapi.o \
		 ft_strtrim.o \
		 ft_utoa.o \

CFLAGS = -Wall -Werror -Wextra

LFLAGS = -c

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(LFLAGS) $(SOURCE)
	@ar rcs $(LNAME) $(LSOURCE)
	
clean:
	rm -f $(LSOURCE)

fclean: clean
	rm -f $(LNAME)

re: fclean all 
