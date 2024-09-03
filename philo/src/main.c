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

<<<<<<< HEAD
void	simulation(t_table *table)
{
	int	i;
=======
int	get_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*eat_think_sleep(void *arg)
{
	t_philo	*philo;
	int		start;
	int		current_time;

	philo = (t_philo *)arg;
	start = get_time();
	(void)philo;
	current_time = get_time();
	printf("%d %d has taken a fork\n", current_time - start, philo->id);
	return (NULL);
}


//	TODO: Fix mutexes problem

void	threads_init(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_of_philos)
	{
		pthread_mutex_init(&table->philo[i].left_fork_mutex, NULL);
		pthread_mutex_init(&table->philo[i].right_fork_mutex, NULL);
	}
	i = -1;
	while (++i < table->num_of_philos)
	{
		table->philo[i].id = i + 1;
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
	free(table->philo);
}

void	leaks(void)
{
	system("leaks -q philo");
}
>>>>>>> a2dd4b22f468872a7b2a26d079ae3b09cd05708c

	i = -1;
	table->start = get_time();
	if (table->nbr_meals == 0)
		return ;
	else
	{
		while (++i < table->num_of_philos)
		{
			pthread_create(&table->philo[i].th, NULL, 
			&eat_think_sleep, (void *)(&table->philo[i]));
			usleep(10);
		}
	}
	i = -1;
	while (++i < table->num_of_philos)
		pthread_join(table->philo[i].th, NULL);
}
 
int	main(int argc, char **argv)
{
	t_table	table;

<<<<<<< HEAD
	if (argc == 5 || argc == 6)
=======
	atexit(leaks);
	if (argc != 5 && argc != 6)
>>>>>>> a2dd4b22f468872a7b2a26d079ae3b09cd05708c
	{
		if (!parsing(argv))
		{
			printf(PARSING_ERROR);
			return (1);
		}
		if (data_init(&table, argv) == -1)
			return (1);
		simulation(&table);
		return (0);
	}
<<<<<<< HEAD
	printf(USAGE_ERROR);
	return (1);
=======
	if (!parsing(argv))
	{
		printf(PARSING_ERROR);
		return (1);
	}
	values_init(&table, argv);
	threads_init(&table);
	return (0);
>>>>>>> a2dd4b22f468872a7b2a26d079ae3b09cd05708c
}
