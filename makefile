# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 16:38:49 by cquezada          #+#    #+#              #
#    Updated: 2020/12/30 17:14:39 by cquezada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LNAME = libftprintf.a

SOURCE = ft_printf.c \
ft_printstr.c \
ft_printchar.c \
ft_printdecimali.c \
ft_printu.c \
ft_digitcount.c \
ft_min.c \
ft_max.c \
ft_positivediff.c \
flagsutils.c \
ft_printxm.c \
ft_printx.c \

OBJFOLDER = libft/

LIBSOURCE = libft/ft_atoi.c \
			libft/ft_isalpha.c \
			libft/ft_itoa.c \
			libft/ft_memcpy.c \
			libft/ft_putendl_fd.c \
			libft/ft_strchr.c \
			libft/ft_strlcat.c \
			libft/ft_strncmp.c \
			libft/ft_substr.c \
			libft/ft_bzero.c \
			libft/ft_isascii.c \
			libft/ft_memccpy.c \
			libft/ft_memmove.c \
			libft/ft_putnbr_fd.c \
			libft/ft_strlcpy.c \
			libft/ft_strnstr.c \
			libft/ft_tolower.c \
			libft/ft_calloc.c \
			libft/ft_isdigit.c \
			libft/ft_memchr.c \
			libft/ft_memset.c\
			libft/ft_putstr_fd.c \
			libft/ft_strdup.c \
			libft/ft_strlen.c \
			libft/ft_strrchr.c \
			libft/ft_toupper.c \
			libft/ft_isalnum.c \
			libft/ft_isprint.c \
			libft/ft_memcmp.c \
			libft/ft_putchar_fd.c \
			libft/ft_split.c \
			libft/ft_strjoin.c \
			libft/ft_strmapi.c \
			libft/ft_strtrim.c 

OBJ = $(SOURCE:.c=.o)

LIBOBJ = $(LIBSOURCE:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -c

all: $(NAME)

# Rule to build your object files and link them into a binary
$(NAME):
	@gcc $(CFLAGS) $(LFLAGS) $(LIBSOURCE)
	@mv -f *.o libft
	@gcc $(CFLAGS) $(LFLAGS) $(SOURCE)
	@ar rc $(LNAME) $(OBJ) $(LIBOBJ)
	@ranlib $(LNAME)
	@echo "Compiled '$(NAME)' successfully"

# Rule to remove object files
clean:
	@rm -f $(LIBOBJ) $(LBONUSSRC) $(OBJ) $(LIBOBJ) libft/*.o
	@echo "Cleaned objects successfully"

# Rule to remove binary, calls the 'clean' rule first
fclean: clean
	@rm -f $(LNAME)
	@echo "Removed '$(LNAME)' with success"

# Rule to remove object files and binary, then re-build everything
re: fclean all

test: fclean 
	@clear
	@echo "Enabling debug\n"
	@sed -i '' 's/debug = 0/debug = 1/g' ft_printf.c
	@echo "Testing...\n"
	@gcc -g  *.c ./libft/*.c ./test/main.c
	@echo "\ntest result:"
	@./a.out
	@echo "\n"
	@echo "Disabling debug\n"
	@sed -i '' 's/debug = 1/debug = 0/g' ft_printf.c


# Rules that are not linked with a filename should be listed here
.PHONY: all clean fclean re
