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

char	concetonate_str(int ascii, char *binary)
{
	int j;

	j = 7;
	while (j >= 0)
	{
		if (ascii & (1 << j))
			strcat(binary, "1"); //!
		else
			strcat(binary, "0"); //!
		j--;
		printf("%s\n", binary);
	}
	return (binary);
}

/* 1. convert each char to ascii; one byte are 8 bits
2. convert ascii to binary
3. concatenate the new with the already existing string */
char	*str_to_binary(char *str)
{
	int		strlen;
	int		i;
	int		j;
	int		ascii;
	char	*binary;

	if (str == NULL)
		return (0);
	strlen = ft_strlen(str);
	binary[0] = '\0';
	i = 0;
	while (i < strlen)
	{
		ascii = str[i];
		j = 7;
		binary = concetonate_str(ascii, binary);
		i++;
	}
	return (binary);
}

char	convert(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] += 32;
		i++;
	}
	return(str);
}

int	main(int ac, char **av)
{
	char	*binary;

	binary = convert(av[2]);
	printf("%s", binary);
}