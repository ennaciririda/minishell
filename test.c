/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:09:17 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/13 20:03:31 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include "minishell.h"
int main()
{
	char *str;
	str = malloc (200);
	getwd(str);
	printf("befoure [%s]\n", str);
	chdir("~");
	getwd(str);
	printf("after : [%s]\n", str);
}