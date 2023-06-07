# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 16:31:22 by rennacir          #+#    #+#              #
#    Updated: 2023/06/07 22:12:12 by rennacir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -fsanitize=address
# -Wall -Wextra -Werror
LIBFT = $(addprefix libft/, ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c \
			ft_lstnew.c ft_lstsize.c ft_strdup.c ft_substr.c ft_strlen.c \
			is_alnum.c)
TOOLS = $(addprefix tools/, error.c)
TOKENIZER = $(addprefix tokenizer/, check_is_close.c  check_dir.c cases.c cases2.c \
			handle_errors.c )
EXPANDER = $(addprefix expander/, env_fill_struct.c rep_var.c)

SRCS =  minishell.c $(LIBFT) $(TOOLS) $(TOKENIZER) $(EXPANDER)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ)  -o $(NAME) -lreadline
	@echo $(NAME) "Created"

%.o:%.c minishell.h
	@$(CC) $(CFLAGS) -c  $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

clean_b:
	@$(RM) $(OBJBNS)

fclean_b: clean_b
	@$(RM) $(CHECKER_B)

re: fclean all

re_b: fclean_b bonus

.PHONY: all clean fclean re