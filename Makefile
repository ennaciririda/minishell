# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 16:31:22 by rennacir          #+#    #+#              #
#    Updated: 2023/07/14 08:26:03 by rennacir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -fsanitize=address
LIBFT = $(addprefix libft/, ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c \
			ft_lstnew.c ft_lstsize.c ft_strdup.c ft_substr.c ft_strlen.c \
			is_alnum.c ft_strcmp.c ft_split.c ft_strncmp.c ft_strncpy.c \
			ft_strstr.c ft_strchr.c ft_strjoin.c ft_isdigit.c ft_putstr_fd.c ft_itoi.c)
TOOLS = $(addprefix tools/, error.c)
TOKENIZER = $(addprefix tokenizer/, check_is_close.c  check_dir.c cases.c cases2.c \
			handle_errors.c is_white_space.c)
GNL = $(addprefix get_next_line/, get_next_line_utils.c get_next_line.c)
EXPANDER = $(addprefix expander/, env_fill_struct.c rep_var.c replace_string.c rep_var_dq.c return_index_of_char.c \
				return_variable.c)
CONCAT = $(addprefix concatication/, check_type.c concatinated_list.c replace_redir.c here_doc_case.c \
			heredoc_return_node.c extract_var_herdoc.c)
RESUM  = $(addprefix resume/, check_redir_type.c final_list.c count_cmd.c fill_str.c resume.c)
BUILTINS = $(addprefix builtins/, echo.c cd.c check_moins_n_case.c commands.c cd_get_env.c check_word.c)
SRCS =  minishell.c $(LIBFT) $(TOOLS) $(TOKENIZER) $(EXPANDER) $(CONCAT) $(GNL) $(RESUM) $(BUILTINS)

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