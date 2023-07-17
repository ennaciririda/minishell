/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:23 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/17 16:37:25 by rennacir         ###   ########.fr       */
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
int fll;

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_list
{
	char			*content;
	int				type;
	struct s_list	*next;
}t_list;

typedef struct s_globallist
{
	t_list				*cmd;
	t_list				*red;
	struct s_globallist	*next;
}t_globallist;

typedef struct s_finallist
{
	char	**cmd;
	t_list	*red;
	struct s_finallist	*next;
}t_finallist;

typedef struct s_env
{
	char			*variable;
	char			*value;
	struct s_env	*next;
}t_env;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_back_env(t_env **env, t_env *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_env	*ft_lstlast_env(t_env *env);
t_list	*ft_lstnew_tokens(char *content, int type);
t_env	*ft_lstnew_env(char *variable, char *value);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strstr(const char* haystack, const char* needle);
int		ft_strcmp(const char *first, const char *second);
char	**ft_split(char const *s);
char	*ft_strncpy(char *dest, const char *src, int n);
int		ft_strncmp(const char *first, const char *second, size_t n);
int		ft_isalnum(int c);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_isdigit(int a);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
//libft
int		is_white_space(char c);
void	error(char *str);
void	check_is_close(char *str, char c);
void	check_dir(char *str, char c);
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
int	redirections_errors(t_list *list);
int	pipe_errors(t_list *list);
int	cmd_errors(t_list *list);
void	double_dollar(t_list **list, int *i);
void	why_dollar(t_list **list, int *i);
int	check_errors(t_list *list);
t_env	*env_fill_struct(char **env);
t_list	*rep_var(t_list *list, t_env *envir);
t_env	*return_node(t_list *tmp, t_env *etmp);
t_list	*rep_var_dq(t_list *list, t_env *envir);
char	*replace_string(char *str, char *oldstr, char *newstr);
t_env	*return_node_with_cond(t_env *env, char *str);
int		return_index_of_char(char *str, char c);
char	*return_variable(char *str, t_env *envir);
// concatin
int		check_type(int type);
int check_redir_type(int type);
t_list	*concatinated_list(t_list *list);
t_list	*replace_redir(t_list *list, t_env *envir);
char	*here_doc_case(char *content, t_env *envir);
t_globallist *final_list(t_list *list);
t_env	*heredoc_return_node(char *str, t_env *envir);
//get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin_get(char *s1, char *s2);
int		ft_strchr_get(char *str, char c);
char	*ft_strdup_get(char *s1);
size_t	ft_strlen_get(const char *str);
//globallist
void			ft_lstadd_back_global(t_globallist **glist, t_globallist *new_glist);
t_globallist	*ft_lstlast_global(t_globallist *glist);
t_globallist	*ft_lstnew_global(t_list *cmd, t_list *redir);
//resume
int count_cmd(t_list *list);
t_finallist	*resume(t_globallist *list);
char		**fill_str(t_list *tmp);
t_finallist	*ft_lstnew_resume(char **str, t_list *redir);
t_finallist	*ft_lstlast_resume(t_finallist *resumelist);
void		ft_lstadd_back_resume(t_finallist **resume, t_finallist *new_resume);

char	*extract_var_herdoc(char *str, t_env *envir);
void	print_str(char **str);
int	check_moins_n_case(char *str);
void	commands(t_finallist	*lastlist, t_env *envir);
// bulins
void	echo(char **cmd);
void	cd(t_env *envir, char **cmd);
void	pwd(char **cmd);
void	env(t_env *envir);
void	export(t_env *envir, char **cmd);
char	*cd_get_env(t_env *envir, char *str);
int		check_word(char *mai, char *str);
void	change_old_pwd(t_env *envir, char *str);
void	change_pwd(t_env *envir, char *str);
int		check_var_if_exist(t_env *envir, char *to_check);
void	free_2d_tab(char **split);
void	free_any_stack_env(t_env *list);
#endif
