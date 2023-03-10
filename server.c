/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:17:40 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/10 11:17:41 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

int	main(int ac , char **av)
{
	/* process needs to run to always receive signals */
	ft_printf("%d", getpid());
	while (1)
	{
		signal(SIGSUR_1, atob);
		signal(SIGSUR_2, atob);
	}

}
