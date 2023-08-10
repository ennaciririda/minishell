/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:34:03 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/10 16:14:28 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minishell.h"

// void	signals_handling()
// {
// 	rl_catch_signals = 0;
// 	if (signal_type == SIGQUIT && g_gv.which_process )
// 	{
// 		if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
// 			printf("\ncan't catch SIGQUIT\n");
// 	}
// 	if (signal_type == SIGINT)
// 	{
// 		if (signal(SIGINT, &handle_signals) == SIG_ERR)
// 			printf("\ncan't catch SIGQUIT\n");
// 	}
// }