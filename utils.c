/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:17:33 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/08 13:17:37 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	char_to_binary(char *str)
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
			printf("%c", c & mask ? '1' : '0');
			mask >>= 1;
			j++;
		}
		printf("\n");
		i++;
	}
	return (c);
}

int	main(int ac, char **av)
{
	//char c[] = "Blue";
	//printf("%c", char_to_binary(c));
	char_to_binary(av[1]);
}