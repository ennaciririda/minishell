# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 16:31:22 by rennacir          #+#    #+#              #
#    Updated: 2023/06/17 18:20:17 by rennacir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -g -fsanitize=address
# -Wall -Wextra -Werror
LIBFT = $(addprefix libft/, ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c \
			ft_lstnew.c ft_lstsize.c ft_strdup.c ft_substr.c ft_strlen.c \
			is_alnum.c ft_strcmp.c ft_split.c ft_strncmp.c ft_strncpy.c \
			ft_strstr.c ft_strchr.c ft_strjoin.c ft_isdigit.c)
TOOLS = $(addprefix tools/, error.c)
TOKENIZER = $(addprefix tokenizer/, check_is_close.c  check_dir.c cases.c cases2.c \
			handle_errors.c )
EXPANDER = $(addprefix expander/, env_fill_struct.c rep_var.c replace_string.c rep_var_dq.c return_index_of_char.c \
				return_variable.c)
CONCAT = $(addprefix concatication/, check_type.c concatinated_list.c replace_redir.c)

SRCS =  minishell.c $(LIBFT) $(TOOLS) $(TOKENIZER) $(EXPANDER) $(CONCAT)

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