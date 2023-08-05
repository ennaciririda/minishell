/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/05 18:16:31 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// char **fill_dilimiter(t_list *list)
// {
// 	int		count;
// 	char	**spl;
// 	int		i;
// 	t_list	*tmp;
// 	char *s;
// 	char *p;
// 	s = NULL;
// 	tmp = list;
// 	i = 0;
// 	count = count_her(list);
// 	spl = malloc (sizeof(char *) * (count + 1));
// 	if (!spl)
// 		return NULL;
// 	while(tmp)
// 	{
// 		if (tmp->type == HER_DOC)
// 		{
// 			tmp = tmp->next;
// 			if (tmp && tmp->type == WHITE_SPACE)
// 				tmp = tmp->next;
// 			if (tmp)
// 			{
// 				s = ft_strjoin(ft_strdup(tmp->content), ft_strdup(""));
// 				tmp = tmp->next;
// 			}
// 			while (tmp && !check_redir_type(tmp->type) && tmp->type != WHITE_SPACE)
// 			{
// 				if (tmp->type == DOUBLE_QUOTE || tmp->type == SINGLE_QUOTE)
// 					g_gv.fll = 1337;
// 				s = ft_strjoin(s, ft_strdup(tmp->content));
// 				tmp = tmp->next;
// 			}
// 			spl[i] = s;
// 			i++;
// 		}
// 		else
// 			tmp = tmp->next;
// 	}
// 	spl[i] = NULL;
// 	return spl;
// }

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
	int i = 0;
	int	*tab;
	t_list	*list;
	t_list	*flist;
	t_list	*clist;
	t_list	*elist;
	char **spl;
	t_list	*newlist;
	t_list	*tmp;
	t_list	*tmp1;
	t_env	*envir;
	t_env	*tmpenv;
	t_globallist *finalist;
	t_globallist *finaltmp;
	t_finallist	*lastlist;
	t_finallist	*tmplast;
	(void)argc;
	(void)argv;
	tmp = NULL;
	tmp1 = NULL;
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
		if (ft_strcmp(str, ""))
			add_history(str);
		if (ft_strcmp(str, ""))
		{
			list = tokenizing(str);\
			if (check_errors(list))
			{
				replace_ex(&list);
				free(str);
				free_any_stack(&list);
				g_gv.check_close = 0;
				g_gv.ex_status = 258;
				continue;
			}
			// g_gv.spl = fill_dilimiter(list);
			// print_str(g_gv.spl);
			tab = malloc(count_her(list) * sizeof(int));
			if (!tab)
				return 0;
			elist = rep_var(list, envir);
			flist = rep_var_dq(elist, envir);
			clist = concatinated_list(flist, tab);
			// tmp = list;
			// while (tmp)
			// {
			// 	printf("[%s]------>[%d]\n", tmp->content , tmp->type);
			// 	tmp = tmp->next;
			// }
			newlist = replace_redir(clist, envir, tab);

			finalist = final_list(newlist);
			lastlist = resume(finalist);
			// tmplast  = lastlist;
			exit_status(&lastlist);
			commands(lastlist, &envir);
			// while (tmplast)
			// {
			// 	printf("double string\n");
			// 	print_str(tmplast->cmd);
			// 	printf("\n-----------------------------\n");
			// 	tmplast = tmplast->next;
			// }
			free_any_stack(&list);
			free_any_stack(&elist);
			free_any_stack(&flist);
			free_any_stack(&clist);
			free_any_stack(&newlist);
			free_any_stack_global(&finalist);
			free_any_stack_final(&lastlist);
			free(str);
			lastlist = NULL;
		}
		else
			free(str);
	}
	free_any_stack_env(envir);
	return 0;
}
