/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:13:23 by hlabouit          #+#    #+#             */
/*   Updated: 2023/07/31 15:52:54 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include<libc.h>


# define RED_IN 7
# define RED_OUT 5
# define ARED_OUT 6
# define HER_DOC 9

typedef struct s_list
{
	char			*content;
	int				type;
	struct s_list	*next;
}t_list;

typedef struct s_finallist
{
	char				**cmd;
	t_list				*red;
	struct s_finallist	*next;
}t_finallist;

/*******************************    libft    *******************************/

int	ft_strlen(const char *s);
int	number_of_nodes(t_list *head);
char	**ft_split(char *s, char c);
int	ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strncpy(char *s1, char *s2, int n);
char	*ft_strjoin(char const *s1, char const *s2);

/*****************************    minishell    *****************************/

char	**get_global_path(char **env);
char	*get_exact_path(char *command, char **env);
void	commands_execution(t_finallist *commands_list, char **env);



#endif