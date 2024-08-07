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

void	values_init(t_table *table, char **argv)
{
	table->num_of_philos = ft_atoi(argv[1]);
	table->philo = malloc(sizeof(t_philo) * table->num_of_philos);
	if (!table->philo)
		return ;
	table->philo->t_die = ft_atoi(argv[2]) * 1000;
	table->philo->t_eat = ft_atoi(argv[3]) * 1000;
	table->philo->t_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		table->philo->times_must_eat = ft_atoi(argv[5]);
}
