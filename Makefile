# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 14:36:42 by lolemmen          #+#    #+#              #
#    Updated: 2022/05/01 17:10:26 by lolemmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

# Compilation

RM = rm -rf
CC = gcc
FLAGS = -Wall -Werror -Wextra

# Directories

SRCSDIR = Srcs
INCSDIR = Includes
OBJSDIR = Objs

# Sources

INC = \
      ft_printf.h \

SRC = \
      ft_printf.c \
	  ft_checker.c \
	  ft_flags.c \
	  ft_init_flags.c \
	  ft_parse_flags.c \
	  ft_parsing.c \
	  ft_putchar.c \
	  ft_putstrbylen.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_check_conversion.c \
	  ft_convert_char.c \
	  ft_define_width.c \
	  ft_convert_string.c \
	  ft_convert_int.c \
	  ft_convert_percent.c \
	  ft_convert_unsigned_int.c \
	  ft_convert_hexadecimal.c \
	  ft_convert_pointer.c \
	  ft_itoa.c \
	  ft_utoa.c \
	  ft_convert_base.c \
	  ft_convert_base_ul.c \
	  
SRCBON = \
	  ft_printf.c \
	  ft_checker.c \
	  ft_flags.c \
	  ft_init_flags.c \
	  ft_parse_flags.c \
	  ft_parsing.c \
	  ft_putchar.c \
	  ft_putstrbylen.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_check_conversion.c \
	  ft_convert_char.c \
	  ft_define_width.c \
	  ft_convert_string.c \
	  ft_convert_int.c \
	  ft_convert_percent.c \
	  ft_convert_unsigned_int.c \
	  ft_convert_hexadecimal.c \
	  ft_convert_pointer.c \
	  ft_itoa.c \
	  ft_utoa.c \
	  ft_convert_base.c \
	  ft_convert_base_ul.c \


# **************************************************************************** #

# Special Chars

LOG_CLEAR = \033[2K
LOG_UP = \033[A
LOG_NOCOLOR = \033[0m
LOG_BLACK = \033[1;30m
LOG_RED = \033[1;31m
LOG_GREEN = \033[1;32m
LOG_YELLOW = \033[1;33m
LOG_BLUE = \033[1;34m
LOG_VIOLET = \033[1;35m
LOG_CYAN = \033[1;36m
LOG_WHITE = \033[1;37m

# **************************************************************************** #

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
SRCSBON = $(SRCBON)
OBJS = $(addprefix $(OBJSDIR)/, $(addsuffix .o, $(basename $(SRC))))
OBJS_DIR = $(sort $(dir $(OBJS)))
OBJSBON = $(addsuffix .o, $(basename $(SRCBON)))

INCS = $(addprefix -I, $(INC))

all : $(NAME)

$(NAME) : build $(OBJS)
	ar rcs $(NAME) $(OBJS)

build :
	mkdir -p $(OBJSDIR)
	mkdir -p $(OBJS_DIR)
	
clean :
	$(RM) $(OBJS)
	$(RM) $(OBJSBON)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(OBJSDIR)/%.o : $(SRCSDIR)/%.c
	$(CC) -c -o $@ $< $(FLAGS)

bonus :
	

