/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:25:38 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/19 00:25:38 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *str)
{
	double	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if (str[i] <= '0' && str[i] >= '9')
			return (0);
	}
	if (res > INT_MAX)
		return (0);
	return ((int)res);
}

int	parsing(char **argv)
{
	int	i;

	i = 0;
	argv++;
	while (argv && *argv)
	{
		if (ft_atoi(*argv) <= 0)
			return (0);
		argv++;
		i++;
	}
	return (1);
}
