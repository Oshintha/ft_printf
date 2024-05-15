# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 07:45:55 by aoshinth          #+#    #+#              #
#    Updated: 2024/05/15 11:40:24 by aoshinth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the output library
NAME = libftprintf.a

# Name of the linked library
LIBFTNAME = libft.a

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Directory containing the linked library
LIBFTDIR = ./libft

# Source files
SRCS = 	ft_printf.c \
		print_pointer.c \
		print_unsigned.c \
		print_string.c \
		print_int.c \
		print_char.c \
		print_hex.c \

# Object files derived from source files
OBJS = $(SRCS:.c=.o)

# Target for building everything
all: $(NAME)

# Target for making the linked library
makelibft:
	@make -C $(LIBFTDIR) # Make the linked library in the specified directory
	@cp $(LIBFTDIR)/$(LIBFTNAME) . # Copy the linked library to the current directory
	@mv $(LIBFTNAME) $(NAME) # Rename the linked library to the desired output library name

# Target for building the final library
$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS) # Archive the object files into the output library

# Target for cleaning object files
clean:
	@rm -f $(OBJS) # Remove object files
	@cd $(LIBFTDIR) && make clean # Clean the linked library in its directory

# Target for cleaning everything
fclean: clean
	@rm -f $(NAME) # Remove the output library
	@cd $(LIBFTDIR) && make fclean # Clean everything in the linked library directory

# Target for cleaning and rebuilding
re: fclean all

# Phony targets (targets that are not actual files)
.PHONY: all clean fclean re

