/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:11:24 by hlabouit          #+#    #+#             */
/*   Updated: 2023/07/23 00:19:21 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libc.h>

int main(void)
{
    int nfd = open("zzebb", O_CREAT | O_RDWR);
    int rtrn = dup2(nfd, 1);
    printf("rtrn %d\n", rtrn);
    
    printf("ayo from the new fd\n");
}