/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:25:10 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/14 09:25:11 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signum)
{
   static char	c = 0xFF;
   static int	bits = 0;

   if (signum == SIGUSR1)
   {
   	printf("0");
   	c ^= 0x80 >> bits;
   }
   else if (signum == SIGUSR2)
   {
   	printf("1");
   	c |= 0x80 >> bits;
   }
   bits++;
   if (bits == 8)
   {
   	printf("-> %c\n", c);
   	bits = 0;
   	c = 0xFF;
   }
}

int	main(void)
{
   pid_t		pid;

   pid = getpid();
   printf("PID: %d\n", pid);
   signal(SIGUSR1, handler_sigusr);
   signal(SIGUSR2, handler_sigusr);
   while (1)
   	pause();
}