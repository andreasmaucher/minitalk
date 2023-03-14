/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:17:12 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/08 13:17:16 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf/ft_printf.h"
#include <sys/types.h>

int	ft_printf(const char *format, ...);

/* only need to link if I have functions in other files than my program */
/* utils */
size_t	ft_strlen(const char *s);
char	str_to_binary(char str);
char	char_to_binary(char *str, pid_t pid);

#endif