/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 15:54:17 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

int	count_her(t_list *list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->type == HER_DOC)
			count++;
		tmp = tmp->next;
	}
	return count;
}

char **fill_dilimiter(t_list *list, int *tab)
{
	int		count;
	char	**spl;
	int		i;

	i = 0;
	t_list	*tmp;
	char *s;
	s = NULL;
	tmp = list;
	count = count_her(list);
	spl = malloc (sizeof(char *) * (count + 1));
	if (!spl)
		return NULL;
	while(tmp)
	{
		if (tmp->type == HER_DOC)
		{
			tmp = tmp->next;
			if (tmp && tmp->type == WHITE_SPACE)
				tmp = tmp->next;
			if (tmp)
			{
				if (tmp->type == 3 || tmp->type == 4)
					tab[g_gv.tab_count] = 1337;
				s = ft_strjoin(ft_strdup(tmp->content), ft_strdup(""));
				tmp = tmp->next;
			}
			while (tmp && !check_redir_type(tmp->type) && tmp->type != WHITE_SPACE)
			{
				if (tmp->type == 3 || tmp->type == 4)
					tab[g_gv.tab_count] = 1337;
				s = ft_strjoin(s, ft_strdup(tmp->content));
				tmp = tmp->next;
			}
			spl[i] = s;
			g_gv.tab_count++;
			i++;
		}
		else
			tmp = tmp->next;
	}
	spl[i] = NULL;
	return spl;
}

void free_2d_tab(char **split)
{
	int i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

void	free_any_stack(t_list **list)
{
	t_list	*node;

	while (*list)
	{
		node = (*list)->next;
		free((*list)->content);
		free(*list);
		(*list) = node;
	}
}

void	free_any_stack_global(t_globallist **list)
{
	t_globallist	*node;

	while ((*list))
	{
		node = (*list)->next;
		free_any_stack(&((*list)->cmd));
		free((*list));
		(*list) = node;
	}
}

void	free_any_stack_final(t_finallist **list)
{
	t_finallist	*node;

	while ((*list))
	{
		node = (*list)->next;
		free_any_stack(&((*list)->red));
		free_2d_tab((*list)->cmd);
		(*list)->cmd = NULL;
		free((*list));
		(*list) = node;
	}
	list = NULL;
}

void	free_any_stack_env(t_env *list)
{
	t_env	*node;

	while (list)
	{
		node = list->next;
		if (list->variable)
			free(list->variable);
		if (list->value)
			free(list->value);
		free(list);
		list = node;
	}
}

void	free__env(t_env *list)
{
	if (list->variable)
		free(list->variable);
	if (list->value)
		free(list->value);
	free(list);
}


t_list *tokenizing(char *str)
{
	t_list	*list;
	list = NULL;
	int i = 0;
	while(str[i])
	{
		if (is_white_space(str[i]))
			space(&list, str, &i);
		else if (str[i] == '|')
			pipes(&list, &i);
		else if (str[i] == '$' && str[i + 1] == '$')
			double_dollar(&list, &i);
		else if (str[i] == '$' && str[i + 1] == '?')
			why_dollar(&list, &i);
		else if (str[i] == '>' && str[i + 1] == '>')
			ared_out(&list, str, &i);
		else if (str[i] == '<' && str[i + 1] == '<')
			here_doc(&list, str, &i);
		else if (str[i] == '>')
			red_out(&list, &i);
		else if (str[i] == '<')
			red_in(&list, &i);
		else if (str[i] == '$')
			dollar(&list, str, &i);
		else if (str[i] == '\"')
			double_quote(&list, str, &i);
		else if (str[i] == '\'')
			single_quote(&list, str, &i);
		else
			word(&list, str, &i);
	}
	return list;
}

void	replace_ex(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while(tmp)
	{
		if (tmp->type == DOLLAR_WHY)
			tmp->content = rep_str(tmp->content, tmp->content, ft_itoa(g_gv.ex_status));
		tmp = tmp->next;
	}
}

int main(int argc, char **argv, char **env)
{
	char	*str;
	char *str2;

	str2 = malloc(100);
	int	*tab;
	t_list	*list;
	t_list	*flist;
	t_list	*clist;
	t_list	*elist;
	t_list	*newlist;
	t_env	*envir;
	t_globallist *finalist;
	t_finallist	*lastlist;
	t_finallist	*tmplast;
	(void)argc;
	(void)argv;
	clist = NULL;
	elist = NULL;
	list = NULL;
	finalist = NULL;
	newlist = NULL;
	lastlist = NULL;
	tmplast = NULL;
	envir = env_fill_struct(env);
	g_gv.ex_status = 0;
	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
		{
			free(str);
			continue;
		}
		if (ft_strcmp(str, ""))
			add_history(str);
		if (ft_strcmp(str, ""))
		{
			list = tokenizing(str);
			if (check_errors(list))
			{
				replace_ex(&list);
				free(str);
				free_any_stack(&list);
				g_gv.check_close = 0;
				g_gv.ex_status = 258;
				continue;
			}
			tab = ft_calloc(count_her(list), 4);
			if (!tab)
				return 0;
			g_gv.spl = fill_dilimiter(list, tab);
			g_gv.tab_count = 0;
			g_gv.rep_tab_c = 0;
			elist = rep_var(list, envir);
			flist = rep_var_dq(elist, envir);
			clist = concatinated_list(flist);
			newlist = replace_redir(clist, envir, tab);
			finalist = final_list(newlist);
			lastlist = resume(finalist);
			exit_status(&lastlist);
			commands(lastlist, &envir);
			free_any_stack_final(&lastlist);
			free(str);
			free(tab);
			free_2d_tab(g_gv.spl);
			lastlist = NULL;
		}
		else
			free(str);
	}
	free_any_stack_env(envir);
	return 0;
}
