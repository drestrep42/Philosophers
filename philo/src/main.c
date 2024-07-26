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

void	*eat_think_sleep(void *arg)
{
	t_philo			*philo;
	struct timeval	time;
	
	philo = (t_philo *)arg;
	gettimeofday(&time, NULL);
	printf("%ld\n", time.tv_sec * 1000 + time.tv_usec / 1000);
	exit(0);
	printf("Philo %d started to eat with one fork\n", philo->id);
	usleep(1000000);
	printf("Philo %d finished eating\n", philo->id);
	return (NULL);
}

void	*nothing(void *arg)
{
	(void) arg;
	return (NULL);
}

void	initialize_threads(t_table *table)
{
	int	i;
		
	i = -1;
	table->philo = malloc(sizeof(t_philo) * table->num_of_philos);
	if (!table->philo)
		return ;
	while (++i < table->num_of_philos)
	{
		pthread_mutex_init(&table->philo[i].fork_mutex, NULL);
		table->philo[i].id = i + 1;
	}
	i = -1;
	while (++i < table->num_of_philos)
	{
		table->philo[i].id = i;
		if (pthread_create(&table->philo[i].th, \
		NULL, &eat_think_sleep, (void *)&table->philo[i]) != 0)
			return ;
	}
	i = -1;
	while (++i < table->num_of_philos)
	{
		if (pthread_join(table->philo[i].th, NULL) != 0)
			return ;
	}
	pthread_mutex_destroy(&table->philo->fork_mutex);
	free(table->philo);
}

void	leaks(void)
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_table	table;

	atexit(leaks);
	if (argc != 5 && argc != 6)
	{
		printf(ERROR_USAGE);
		return (1);
	}
	if (!parsing(argv))
	{
		printf(PARSING_ERROR);
		return (1);
	}
	initialize_values(&table, argv);
	initialize_threads(&table);
	return (0);
}
