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

void	simulation(t_table *table)
{
	int	i;

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
		return (0);
	}
	printf(USAGE_ERROR);
	return (1);
}
