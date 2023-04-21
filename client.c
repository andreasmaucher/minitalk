/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:25:03 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/14 09:25:05 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = nptr[i] - 48 + res;
		i++;
	}
	return (res * sign);
}

/* sending out the signal via kill */
int kill_function(char c, int mask, pid_t pid)
{
	int j;

	j = 0;
	while (j < 8)
	{
		if (c & mask)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		mask >>= 1;
		usleep(300);
		j++;
	}
	return (mask);
}

/* conversion by comparing the bits at the same position */
char	char_to_binary(char *str, pid_t pid)
{
	int		i;
	int		mask;
	char	c;
	i = 0;
	
	while (str[i] != '\0')
	{
		mask = 0b10000000;
		c = str[i];
		mask = kill_function(c, mask, pid);
		i++;
	}
	return (c);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		write(1, "Error: invalid arguments\n", 25);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	char_to_binary(argv[2], pid);
	return (0);
}
