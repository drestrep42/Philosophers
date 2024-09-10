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

void	philo_init(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->num_of_philos)
	{
		philo = &table->philo[i];
		philo->right_fork = &table->fork[(i + 1) % table->num_of_philos];
		pthread_mutex_init(&table->philo[i].philo_mtx, NULL);
		pthread_mutex_init(&table->fork[i].mutex, NULL);
		philo->left_fork = &table->fork[i];
		table->fork[i].fork_id = i;
		philo->meals_eaten = 0;
		philo->table = table;
		philo->last_meal = 0;
		philo->eating = 0;
		philo->dead = 0;
		philo->full = 0;
		philo->id = i;
	}
}

void	table_init(t_table *table, char **argv)
{
	pthread_mutex_init(&table->write, NULL);
	pthread_mutex_init(&table->table_mtx, NULL);
	table->death = 0;
	table->full_philos = 0;
	table->num_of_philos = ft_atoi(argv[1]);
	table->time2die = ft_atoi(argv[2]);
	table->time2eat = ft_atoi(argv[3]) * 1000;
	table->time2sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		table->nbr_meals = ft_atoi(argv[5]);
}

int	data_init(t_table *table, char **argv)
{
	table_init(table, argv);
	table->philo = malloc(table->num_of_philos * sizeof(t_philo));
	if (!table->philo)
		return (-1);
	table->fork = malloc(table->num_of_philos * sizeof(t_fork));
	if (!table->fork)
		return (-1);
	philo_init(table);
	return (0);
}
