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
	(void)philo;
	gettimeofday(&time, NULL);
	printf("%ld\n", time.tv_sec * 1000 + time.tv_usec / 1000);
	printf("Philo %d started to eat with one fork\n", philo->philo_nbr);
	usleep(1000000);
	//printf("Philo finished eating\n");
	return (NULL);
}

void	initialize_threads(char **argv)
{
	t_philo *philo;
	int	i;
	philo = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
		
	i = 1;
	while (i <= ft_atoi(argv[1]))
	{
		printf("Hola\n");
		philo->philo_nbr = i;
		printf("%d\n", philo->philo_nbr);
		exit(0);
		pthread_create(&philo->thread, NULL, eat_think_sleep, &philo);
		pthread_join(philo->thread, NULL);
		philo = philo->next_philo;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;

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
	initialize_threads(argv);
	//pthread_create(&table.philo.thread, NULL, eat_think_sleep, &philo);
	//pthread_join(philo.thread, NULL);
	return (0);
}
