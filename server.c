/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:25:10 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/14 09:25:11 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signal)
{
	/* why static?! */
	/* why can"t i write it in norm?! */
   static char	c = 0b11111111; //0xFF = 0b11111111
   static int	n = 0; //counter to see when we converted 8 bits
   int	mask;

	//c = 0b11111111;
	//n = 0;
	mask = 0b10000000;
/* >> shifted right by the value of bits, which is the counter */
   if (signal == SIGUSR1)
   {
   	//printf("0");
   	c ^= mask >> n; //0x80 = 0b10000000 copies bit if its set in one operand but not both
   }
   else if (signal == SIGUSR2)
   {
   	//printf("1");
   	c |= mask >> n; // OR copies a bit if it exists in either operand (meaning also if its in both)
   }
   n++;
   if (n == 8)
   {
   	//printf("-> %c\n", c);
   	ft_printf("%c\n", c);
	//usleep(300);
   	n = 0;
   	c = 0b11111111;
   }
}

int	main(void)
{
   pid_t		pid;

   pid = getpid();
   ft_printf("PID: %d\n", pid);
   signal(SIGUSR1, handler_sigusr);
   signal(SIGUSR2, handler_sigusr);
   while (1)
   	pause();
}