/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:23 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/06 22:41:52 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define WORD 1
# define WHITE_SPACE 2
# define DOUBLE_QUOTE 3
# define SINGLE_QUOTE 4
# define RED_OUT 5
# define ARED_OUT 6
# define RED_IN 7
# define PIPE 8
# define HER_DOC 9
# define VARIABLE 10
# define DOUBLE_DOLLAR 11
# define DOLLAR_WHY 12


# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_list
{
	char			*content;
	int				type;
	struct s_list	*next;
}t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char *content, int type);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	error(char *str);
void	check_is_close(char *str, char c);
void	check_dir(char *str, char c);
int		ft_isalnum(int c);
void	space(t_list **list , char *str, int *i);
void	pipes(t_list **list ,int *i);
void	ared_out(t_list **list, char *str, int *i);
void	here_doc(t_list **list, char *str, int *i);
void	red_out(t_list **list, int *i);
void	red_in(t_list **list, int *i);
void	dollar(t_list **list, char *str, int *i);
void	double_quote(t_list **list, char *str, int *i);
void	single_quote(t_list **list, char *str, int *i);
void	word(t_list **list, char *str, int *i);
void	redirections_errors(t_list *list);
void	pipe_errors(t_list *list);
void	cmd_errors(t_list *list);
void	double_dollar(t_list **list, int *i);
void	why_dollar(t_list **list, int *i);

#endif