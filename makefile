# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 16:38:49 by cquezada          #+#    #+#              #
#    Updated: 2020/10/30 18:17:08 by cquezada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LNAME = libftprintf.a

SOURCE = ft_printf.c \
ft_printstr.c \
ft_printchar.c \
ft_printdecimali.c \
ft_printu.c \
ft_widthsort.c \
ft_min.c \
ft_max.c \
ft_ifminus.c \
flagsutils.c \
ft_printxm.c \
ft_printx.c \

OBJFOLDER = Libft/

LIBSOURCE = Libft/ft_atoi.c \
			Libft/ft_isalpha.c \
			Libft/ft_itoa.c \
			Libft/ft_memcpy.c \
			Libft/ft_putendl_fd.c \
			Libft/ft_strchr.c \
			Libft/ft_strlcat.c \
			Libft/ft_strncmp.c \
			Libft/ft_substr.c \
			Libft/ft_bzero.c \
			Libft/ft_isascii.c \
			Libft/ft_memccpy.c \
			Libft/ft_memmove.c \
			Libft/ft_putnbr_fd.c \
			Libft/ft_strlcpy.c \
			Libft/ft_strnstr.c \
			Libft/ft_tolower.c \
			Libft/ft_calloc.c \
			Libft/ft_isdigit.c \
			Libft/ft_memchr.c \
			Libft/ft_memset.c\
			Libft/ft_putstr_fd.c \
			Libft/ft_strdup.c \
			Libft/ft_strlen.c \
			Libft/ft_strrchr.c \
			Libft/ft_toupper.c \
			Libft/ft_isalnum.c \
			Libft/ft_isprint.c \
			Libft/ft_memcmp.c \
			Libft/ft_putchar_fd.c \
			Libft/ft_split.c \
			Libft/ft_strjoin.c \
			Libft/ft_strmapi.c \
			Libft/ft_strtrim.c 

OBJ = $(SOURCE:.c=.o)

LIBOBJ = $(LIBSOURCE:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -c

all: $(NAME)

# Rule to build your object files and link them into a binary
$(NAME):
	@gcc $(CFLAGS) $(LFLAGS) $(LIBSOURCE)
	@mv -f *.o Libft
	@gcc $(CFLAGS) $(LFLAGS) $(SOURCE)
	@ar rc $(LNAME) $(OBJ) $(LIBOBJ)
	@ranlib $(LNAME)
	@echo "Compiled '$(NAME)' successfully"

# Rule to remove object files
clean:
	@rm -f $(LIBOBJ) $(LBONUSSRC) $(OBJ) $(LIBOBJ) Libft/*.o
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
	@gcc -g  *.c ./Libft/*.c ./test/main.c
	@echo "\ntest result:"
	@./a.out
	@echo "\n"
	@echo "Disabling debug\n"
	@sed -i '' 's/debug = 1/debug = 0/g' ft_printf.c


# Rules that are not linked with a filename should be listed here
.PHONY: all clean fclean re
