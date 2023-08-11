# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 16:31:22 by rennacir          #+#    #+#              #
#    Updated: 2023/08/11 13:56:33 by rennacir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFT = $(addprefix parsing/libft/, ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c \
			ft_lstnew.c ft_lstsize.c ft_strdup.c ft_substr.c ft_strlen.c \
			is_alnum.c ft_strcmp.c ft_split.c ft_strncmp.c ft_strncpy.c \
			ft_strstr.c ft_strchr.c ft_strjoin.c ft_isdigit.c ft_putstr_fd.c ft_itoi.c ft_atoi.c)
TOKENIZER = $(addprefix parsing/tokenizer/, check_is_close.c  check_dir.c cases.c cases2.c \
			cases3.c handle_errors.c is_white_space.c)
GNL = $(addprefix parsing/get_next_line/, get_next_line_utils.c get_next_line.c)
EXPANDER = $(addprefix parsing/expander/, env_fill_struct.c rep_var.c replace_string.c rep_var_dq.c return_index_of_char.c \
				return_variable.c)
CONCAT = $(addprefix parsing/concatication/, check_type.c concatinated_list.c replace_redir.c here_doc_case.c \
			heredoc_return_node.c extract_var_herdoc.c)
RESUM  = $(addprefix parsing/resume/, check_redir_type.c final_list.c count_cmd.c fill_str.c resume.c check_built.c)
BUILTINS = $(addprefix parsing/builtins/, echo.c cd.c pwd.c env.c export.c export2.c unset.c check_moins_n_case.c commands.c cd_get_env.c check_word.c \
			change_old_pwd.c check_var_if_exist.c export_check_var.c exit.c exit_status.c get_pos.c)
FT_PRINTF = $(addprefix parsing/ft_printf/, ft_printf.c ft_putnbr.c ft_putchar.c ft_exanum.c ft_putnbru.c ft_cases.c ft_putstr.c)
EXECUTION = $(addprefix execution/, useful_functions1.c commands_execution.c ft_split_e.c ft_strjoin_e.c)
SRCS =  minishell.c $(LIBFT) $(TOKENIZER) $(EXPANDER) $(CONCAT) $(GNL) $(RESUM) $(BUILTINS) $(FT_PRINTF) $(EXECUTION)
RL = -L/goinfre/rennacir/.brew/opt/readline/lib
RL2 = -I/goinfre/rennacir/.brew/opt/readline/include
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(RL) -lreadline
	@echo $(NAME) "Created"

%.o:%.c minishell.h
	@$(CC) $(CFLAGS) $(RL2) -c $< -o $@

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

PHONY: all clean fclean re
