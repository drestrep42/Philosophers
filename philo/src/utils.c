/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:34:03 by drestrep          #+#    #+#             */
/*   Updated: 2024/09/06 15:31:13 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	free_mallocs(t_table *table)
{
	free(table->philo);
	free(table->fork);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	time_difference(long long last_meal, long long current_time)
{
	return (current_time - last_meal);
}

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->table->write);
	if (!philo->table->death) 
	{
		philo->table->current_time = get_time() - philo->table->start;
		printf("%d %d %s\n", philo->table->current_time, philo->id + 1, message);
	}
	pthread_mutex_unlock(&philo->table->write);
}
