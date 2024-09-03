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

#define USAGE_ERROR "Correct use: ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

#define PARSING_ERROR "All mandatory arguments should be numbers above 0"


#define FORK "has taken a fork"
#define EATING "is eating"
#define SLEEPING "is sleeping"
#define THINKING "is thinking"
#define DIED "died"


typedef struct	s_fork
{
	pthread_mutex_t	mutex;
	int				fork_id;
}				t_fork;


typedef struct s_philo
{
	struct s_table	*table;
	pthread_t		th;
	t_fork			left_fork;
	t_fork			right_fork;
	int				id;
	int				dead;
	int				full;
	int				last_meal;
	int				meals_eaten;
}				t_philo;

typedef struct s_table
{
	pthread_mutex_t	write;
	t_philo			*philo;
	t_fork			*fork;
	int				start;
	int				current_time;
	int				num_of_philos;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				nbr_meals;
	int				timeofday;
}				t_table;


//PARSING
int		parsing(char **argv);
int		ft_atoi(const char *str);

//DATA INIT
int		data_init(t_table *table, char **argv);
void	table_init(t_table *table, char **argv);
void	philo_init(t_table *table);	


// UTILS
void	print_message(t_philo *philo, char *message);
int		get_time(void);


// ROUTINE
void	*eat_think_sleep(void *arg);
void	*ft_think();
void	*ft_sleep();
void	*ft_eat(t_philo *philo);