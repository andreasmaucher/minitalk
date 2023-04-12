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

//! GET RID OF PRINTF!!!

/* 0xFF = 0b11111111; 0x80 = 0b10000000; n is a counter to 8 bits */
void	handler_sigusr(int signal)
{
	static char		c = 0b11111111;
	static int		n = 0;
	int				mask;

	mask = 0b10000000;
	if (signal == SIGUSR1)
		c ^= mask >> n;
	else if (signal == SIGUSR2)
		c |= mask >> n;
	n++;
	if (n == 8)
	{
		printf("%c\n", c);
		n = 0;
		c = 0b11111111;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
}
