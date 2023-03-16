/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:25:03 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/14 09:25:05 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	char_to_binary(char *str, pid_t pid)
{
	int	i;
	int mask;
	char	c;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		mask = 0b10000000;
		c = str[i];
		j = 0;
		while (j < 8)
		{
			//printf("%c", c & mask ? '1' : '0');
			/* compares the bits at the same position */
			if (c & mask)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			mask >>= 1;
			j++;
			usleep(5);
		}
		i++;
	}
	return (c);
}
/* 
char	send_signals(char *c, pid_t pid)
{
	int	i;
	int mask;

	i = 7;
	mask = 0b10000000;
	while (i >= 0)
	{
		printf("%c", c & mask ? '1' : '0');
		mask >>= 1;
		i--;
	}
	return (c);
} */

int	main(int argc, char *argv[])
{
   pid_t	pid;

   /* if (argc != 2)
   {
   	printf("client: invalid arguments\n");
   	exit(EXIT_FAILURE);
   } */
   pid = atoi(argv[1]);
   char_to_binary(argv[2], pid);
   return (0);
}
