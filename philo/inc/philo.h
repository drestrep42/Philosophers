/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:54:32 by marvin            #+#    #+#             */
/*   Updated: 2024/03/18 15:54:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define INT_MAX 2147483647

#define ERROR_USAGE "Correct use: ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

#define PARSING_ERROR "All mandatory arguments should be numbers above 0"

typedef struct s_philo
{
	struct s_philo	*next_philo;
	pthread_mutex_t	fork_mutex;
	pthread_t		th;
	int				id;
	int				fork;
	int				dead;
}				t_philo;

typedef struct s_table
{
	t_philo			*philo;
	int				timeofday;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				times_must_eat;
	int				num_of_philos;
}				t_table;

int		parsing(char **argv);
int		ft_atoi(const char *str);
void	initialize_values(t_table *table, char **argv);
