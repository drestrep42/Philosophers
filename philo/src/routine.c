/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:53:10 by drestrep          #+#    #+#             */
/*   Updated: 2024/09/06 14:55:50 by drestrep         ###   ########.fr       */
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

void	print_message_fork(t_philo *philo, char *message)
{
	philo->table->current_time = get_time() - philo->table->start;
	pthread_mutex_lock(&philo->table->write);
	if (strcmp(message, "left") == 0)
		printf("%d %d has taken the left fork number %d\n", philo->table->current_time, philo->id + 1, philo->left_fork->fork_id);
	else if (strcmp(message, "right") == 0)
		printf("%d %d has taken the right fork number %d\n", philo->table->current_time, philo->id + 1, philo->right_fork->fork_id);
	pthread_mutex_unlock(&philo->table->write);
}

void	*ft_eat(t_philo *philo)
{
	if (philo->table->death)
		return (NULL);
	pthread_mutex_lock(&philo->left_fork->mutex);
	//print_message_fork(philo, "left");
	print_message(philo, FORK);
	pthread_mutex_lock(&philo->right_fork->mutex);
	//print_message_fork(philo, "right");
	print_message(philo, FORK);
	pthread_mutex_lock(&philo->philo_mtx);
	print_message(philo, EATING);
	philo->last_meal = get_time();
	usleep(philo->table->time2eat);
	philo->meals_eaten++;
	if(philo->meals_eaten == philo->table->nbr_meals)
	{
		philo->full = 1;
		philo->table->full_philos++;
	}
	pthread_mutex_unlock(&philo->philo_mtx);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	return (NULL);
}

/* void	*ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_mtx);
	if (philo->table->death)  // Stop if death has occurred
	{
		pthread_mutex_unlock(&philo->table->death_mtx);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->table->death_mtx);

	pthread_mutex_lock(&philo->left_fork->mutex);
	print_message(philo, FORK);

	pthread_mutex_lock(&philo->right_fork->mutex);
	print_message(philo, FORK);

	pthread_mutex_lock(&philo->philo_mtx);
	print_message(philo, EATING);
	philo->last_meal = get_time();
	usleep(philo->table->time2eat);
	philo->meals_eaten++;

	if(philo->meals_eaten == philo->table->nbr_meals)
	{
		philo->full = 1;
		philo->table->full_philos++;
	}

	pthread_mutex_unlock(&philo->philo_mtx);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);

	return (NULL);
} */



void	*eat_think_sleep(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->table->death == 0 && philo->full == 0)
	{
		ft_eat(philo);
		if (philo->table->death == 1)
			return (NULL);
		ft_sleep(philo);
		ft_think(philo);
		usleep(100);
	}
	return (NULL);
}


