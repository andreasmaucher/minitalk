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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*str_to_binary(char *str)
{
	int	strlen;
	int	i;
	int	j;
	int	ascii;
	char	*binary;

	strlen = 0;
	ascii = 0;
	if (str == NULL)
		return (0);
	strlen = ft_strlen(str);
	binary[0] = '\0';
	i = 0;
	while (i < strlen)
	{
		/* convert each char to ascii */
		ascii = str[i];
		/* since one byte are 8 bits */
		j = 7;
		while (j >= 0)
		{
			/* convert ascii to binary */
			if (ascii & (1 << j))
			/* to concatenate the new with the already existing string */
				strcat(binary, "1"); //! I can't use library function!
			else 
				strcat(binary, "0");
			j--;
			//printf("%s\n", binary);
		}
		i++;
	}
	return (binary);
}

int	main(int ac, char **av) //int ac, char **av
{
	char *str = av[2];
	char *binary;

	while (1)
	{
		binary = str_to_binary(str);
		//binary = str_to_binary(av[2]);
		printf("%s", binary);
	}
}