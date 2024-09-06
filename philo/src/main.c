/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:01:56 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/18 16:01:56 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void death_row(t_table *table)
{
    int i;

    while (!(table->all_full))
    {
        i = -1;
        while (++i < table->num_of_philos)
        {
            if (table->philo[i].full == 0 && time_difference(table->philo[i].last_meal, get_time()) >= table->time2die)
            {
				pthread_mutex_lock(&table->philo[i].philo_mtx);
                print_message(&table->philo[i], DIED);
                table->death = 1;
				pthread_mutex_unlock(&table->philo[i].philo_mtx);
            }
        }
        if (table->death == 1 || table->full_philos == table->num_of_philos)
            break;
    }
}

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_time();
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_message_fork(philo, "left");
	while (philo->table->death == 0)
		usleep(100);
	return (NULL);
}

void	simulation(t_table *table)
{
	int			i;

	i = -1;
	table->start = get_time();
	if (table->nbr_meals == 0)
		return ;
	if (table->num_of_philos == 1)
		pthread_create(&table->philo[0].th, NULL, &one_philo, &table->philo[0]);
	else
	{
		while (++i < table->num_of_philos)
		{
			table->philo[i].last_meal = get_time();
			pthread_create(&table->philo[i].th, NULL, 
			&eat_think_sleep, (void *)(&table->philo[i]));
			usleep(100);
		}
	}
	death_row(table);
	i = -1;
	while (++i < table->num_of_philos)
		pthread_join(table->philo[i].th, NULL);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		if (!parsing(argv))
		{
			printf(PARSING_ERROR);
			return (1);
		}
		if (data_init(&table, argv) == -1)
			return (1);
		simulation(&table);
		free_mallocs(&table);
		return (0);
	}
	printf(USAGE_ERROR);
	return (1);
}
