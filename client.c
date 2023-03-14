/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:17:33 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/10 11:17:35 by amaucher         ###   ########.fr       */
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

//! if I do it like this I have to store it! might be better to loop
//! differently and only send one character at a time
char	*str_to_binary(char str)
{
	int	strlen;
	int	i;
	int	j;
	int	ascii;
	char	*binary;

	/* if (str == NULL)
		return (0);
	strlen = ft_strlen(str);
	binary[0] = '\0';
	i = 0; */
	/* while (i < strlen)
	{
		/* convert each char to ascii
		ascii = str[i];
		/* since one byte are 8 bits */
		j = 7;
		while (j >= 0)
		{
			/* convert ascii to binary */ //! what is happening here
			if (ascii & (1 << j))
			/* to concatenate the new with the already existing string */
				printf("%d", 1);
				//strcat(binary, "1"); //! I can"t use library function! //send it directly
			else 
				printf("%d", 1);
				//strcat(binary, "0");
			j--;
			printf("%s\n", binary);
		}
	return (binary);
}

int	main(int ac, char **av)
{
	int	i;
	char	*binary_str;

	i = 1;
	if (ac == 2) //=3
	{
		//while (i >= 0) //av[2][i] != '\0'
		{
			binary_str = str_to_binary(av[2]);
			//i--;
		}
	}
	printf("%s", binary_str);
}
