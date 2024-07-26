/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 05:23:41 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 05:23:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	initialize_values(t_table *table, char **argv)
{
	table->num_of_philos = ft_atoi(argv[1]);
	table->time2die = ft_atoi(argv[2]) * 1000;
	table->time2eat = ft_atoi(argv[3]) * 1000;
	table->time2sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		table->times_must_eat = ft_atoi(argv[5]);
	printf("Philos: %d\n", table->num_of_philos);
	printf("Time to die: %d\n", table->time2die);
	printf("Time to eat: %d\n", table->time2eat);
	printf("Time to sleep: %d\n", table->time2sleep);
}
