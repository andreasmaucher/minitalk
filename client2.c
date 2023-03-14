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

// client.c
int	main(int argc, char *argv[])
{
   int	pid;

   if (argc != 2)
   {
   	printf("client: invalid arguments\n");
   	exit(EXIT_FAILURE);
   }
   pid = atoi(argv[1]);
   kill(pid, SIGUSR1);
   return (0);
}
