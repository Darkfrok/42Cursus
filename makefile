# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 16:38:49 by cquezada          #+#    #+#              #
#    Updated: 2021/02/19 13:55:53 by cquezada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE = 	ft_printf.c \
			ft_printstr.c \
			ft_printchar.c \
			ft_printdecimali.c \
			ft_printu.c \
			ft_min.c \
			ft_positivediff.c \
			flagsutils.c \
			ft_printhex.c \
			ft_itohex.c \
			ft_strtoupper.c \
			ft_invertstr.c \
			ft_printpointer.c \
			ft_putcharpercent.c \

LIBFTFOLDER = libft/
LIBFT = libft/libft.a

OBJ = $(SOURCE:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -c

# Rule to build your object files and link them into a binary
$(NAME): $(OBJ)
	@make -C $(LIBFTFOLDER)/
	@gcc -g -c $(SOURCE) $(LIBFT) 2> /dev/null
	@ar rc $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@echo "Compiled '$(NAME)' successfully"

all: $(NAME)

# Rule to remove object files
clean:
	@make clean -C $(LIBFTFOLDER)/
	@rm -f $(OBJ)
	@echo "Cleaned objects successfully"

# Rule to remove binary, calls the 'clean' rule first
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTFOLDER)/
	@echo "Removed '$(NAME)' with success"

# Rule to remove object files and binary, then re-build everything
re: fclean all

test: fclean 
	@clear
	@echo "Enabling debug\n"
	@sed -i '' 's/debug = 0/debug = 1/g' ft_printf.c
	@echo "Testing...\n"
	@gcc   *.c ./libft/*.c ./test/main.c
	@echo "\ntest result:"
	@./a.out
	@echo "\n"
	@echo "Disabling debug\n"
	@sed -i '' 's/debug = 1/debug = 0/g' ft_printf.c


# Rules that are not linked with a filename should be listed here
.PHONY: all clean fclean re
