/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:53:10 by drestrep          #+#    #+#             */
/*   Updated: 2024/09/03 02:56:10 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*ft_think(t_philo *philo)
{
	print_message(philo, THINKING);
	return (NULL);
}

void	*ft_sleep(t_philo *philo)
{
	print_message(philo, SLEEPING);
	usleep(philo->table->time2sleep);
	return (NULL);
}

void	*ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork.mutex);
	print_message(philo, FORK);
	pthread_mutex_lock(&philo->right_fork.mutex);
	print_message(philo, FORK);
	philo->last_meal = get_time();
	print_message(philo, EATING);
	usleep(philo->table->time2eat);
	philo->meals_eaten++;
	if(philo->table->nbr_meals > 0 \
		&& philo->meals_eaten == philo->table->nbr_meals)
		philo->full = 1;
	pthread_mutex_unlock(&philo->left_fork.mutex);
	pthread_mutex_unlock(&philo->right_fork.mutex);
	return (NULL);
}

void	*eat_think_sleep(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	usleep(10000);
	print_message(philo, FORK);
	while (!philo->dead || !philo->full)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
