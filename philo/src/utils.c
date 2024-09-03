/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:34:03 by drestrep          #+#    #+#             */
/*   Updated: 2024/09/02 22:16:50 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(t_philo *philo, char *message)
{
	philo->table->current_time = get_time() - philo->table->start;
	pthread_mutex_lock(&philo->table->write);
	printf("%d %d %s\n", philo->table->current_time, philo->id, message);
	pthread_mutex_unlock(&philo->table->write);
}
