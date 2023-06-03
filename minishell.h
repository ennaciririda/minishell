/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:23 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/03 16:19:13 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

#endif