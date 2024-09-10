/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:53:10 by drestrep          #+#    #+#             */
/*   Updated: 2024/09/10 14:30:39 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*ft_sleep(t_philo *philo)
{
	print_message(philo, SLEEPING);
	usleep(philo->table->time2sleep);
	return (NULL);
}

void	*ft_think(t_philo *philo)
{
	print_message(philo, THINKING);
	return (NULL);
}

void	*ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_message(philo, FORK);
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_message(philo, FORK);
	print_message(philo, EATING);
	pthread_mutex_lock(&philo->philo_mtx);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->philo_mtx);
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->table->nbr_meals)
	{
		philo->full = 1;
		pthread_mutex_lock(&philo->table->table_mtx);
		philo->table->full_philos++;
		pthread_mutex_unlock(&philo->table->table_mtx);
	}
	usleep(philo->table->time2eat);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	return (NULL);
}

void	*eat_think_sleep(void *arg)
{
	t_philo	*philo;
	int		check;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->table_mtx);
	check = philo->table->death;
	pthread_mutex_unlock(&philo->table->table_mtx);
	while (!check && !philo->full)
	{
		ft_eat(philo);
		pthread_mutex_lock(&philo->table->table_mtx);
		check = philo->table->death;
		pthread_mutex_unlock(&philo->table->table_mtx);
		if (check)
			return (NULL);
		ft_sleep(philo);
		ft_think(philo);
		usleep(100);
	}
	return (NULL);
}
