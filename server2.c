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
	/* why static?! */
   static char	c = 0xFF; //0xFF = 0b11111111
   static int	bits = 0; //counter to see when we converted 8 bits
   int	mask;
	
	mask = 0b10000000;

/* >> shifted right by the value of bits, which is the counter */
   if (signum == SIGUSR1)
   {
   	printf("0");
   	c ^= mask >> bits; //0x80 = 0b10000000 copies bit if its set in one operand but not both
   }
   else if (signum == SIGUSR2)
   {
   	printf("1");
   	c |= mask >> bits; // OR copies a bit if it exists in either operand (meaning also if its in both)
   }
   bits++;
   if (bits == 8)
   {
   	printf("-> %c\n", c);
   	bits = 0;
   	c = 0xFF;
   }
}
/* 
while (str[i] != '\0')
	{
		mask = 0b10000000;
		c = str[i];
		j = 0;
		while (j < 8)
		{
			printf("%c", c & mask ? '1' : '0');
			if (c & mask)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			mask >>= 1;
			j++;
			usleep(5);
		}
		i++;
		printf("\n");
	}
 */
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