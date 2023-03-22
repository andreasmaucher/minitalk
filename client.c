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

# include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

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
			/* this needs to be adjusted depending on the computer */
			usleep(300);
		}
		i++;
	}
	return (c);
}

int	main(int argc, char *argv[])
{
   pid_t	pid;

   if (argc != 3)
   {
   	printf("Error: invalid arguments\n");
   		return(0);
   }
   pid = ft_atoi(argv[1]);
   char_to_binary(argv[2], pid);
   return (0);
}
