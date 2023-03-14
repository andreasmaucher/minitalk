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

char	char_to_binary(char c)
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
}

int	main()
{
	char c = 'A';
	//printf("%c", char_to_binary(c));
	char_to_binary(c);
}