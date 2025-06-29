# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 13:17:32 by ikawamuk          #+#    #+#              #
#    Updated: 2025/06/28 13:33:59 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
BONUS_NAME := checker

CC := cc
CFLAGS=-Wall -Wextra -Werror $(addprefix -I,$(INCLUDES))
AR := ar
ARFLAGS := rcs
RM := rm -f
RMDIR := rm -rf

SRCDIR := src/mandatory
BONUS_SRCDIR := src/bonus
OBJDIR := obj/mandatory
BONUS_OBJDIR := obj/bonus
INCDIR := include
LIBFTDIR := libft
TMPDIR := ar_tmp

SRCFILES :=	main.c \
			set_stack.c \
			utils.c \
			push.c \
			swap.c \
			rotate.c \
			reverse_rotate.c \
			push_max.c \
			sort_by_range.c \
			validate.c \
			ft_atol.c\
			is_sorted.c\
			small_sort.c\

BONUS_SRCFILES :=	main.c\
					set_stack.c \
					validate_arg.c\
					ft_atol.c\
					utils.c\
					get_instr_lst.c\
					excute_instr.c\
					push.c \
					swap.c \
					rotate.c \
					reverse_rotate.c \

SRCS := $(addprefix $(SRCDIR)/, $(SRCFILES))
BONUS_SRCS := $(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCFILES))

OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
BONUS_OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(BONUS_SRCS))

INCLUDES := $(INCDIR) $(LIBFTDIR)/include

LIBFT := $(LIBFTDIR)/libft.a

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --track-origins=yes --show-leak-kinds=all

all: $(LIBFT) $(NAME) 

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
	
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFTDIR) clean	
	@$(RMDIR) $(OBJDIR) $(BONUS_OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $@	

$(BONUS_OBJDIR)/%.o: $(BONUS_SRCDIR)/%.c
	@mkdir -p $(BONUS_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: all
	@$(CC) $(CFLAGS) test.c $(LIBFT) -o test
# $(VALGRIND) $(VALGRIND_FLAGS) ./test

.PHONY:all clean fclean re test bonus
