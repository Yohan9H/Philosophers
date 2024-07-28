/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:13:07 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/28 14:27:48 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# define ERROR_ARG 0
# define MAX_PHILO 200

typedef pthread_mutex_t	t_mutex;

typedef struct timeval	t_timeval;

typedef struct s_data
{
	int			dead_flag;
	int			eat_flag;
	int			philo_eat_max;
	t_mutex		dead_lock;
	t_mutex		eat_lock;
	t_mutex		write_lock;
	t_mutex		check_lock;
	t_mutex		*forks;
	t_timeval	start;
	long		set_t_die;
	long		set_t_eat;
	long		set_t_sleep;
	int			nb_philo;
	int			nb_eat;
	int			one_time;
}	t_data;

typedef struct s_philo
{
	pthread_t	thread;
	int			num;
	int			eating;
	long		last_eat;
	long		start_time;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	t_mutex		*l_fork;
	t_mutex		*r_fork;
	t_data		*data;
}	t_philo;

int		check_args(int ac, char **av, t_data *data);

int		check_break(t_philo *philo);

long	ft_atoi(const char *str);

void	error(int code_error);

void	init_data(t_data *data, t_mutex *forks);

void	init_forks(t_data *data);

void	init_philo(t_philo *philos, t_data *data);

int		make_threads(t_philo *philos, t_data *data);

void	if_stop(t_data *data, t_philo *philos);

void	*routine(void *philo);

void	take_fork_long(t_philo *philo);

void	free_all(t_philo *philos);

long	give_time(t_data *data);

int		ft_usleep(size_t milliseconds, t_data *data);

void	print_status(t_philo *philo, char *str, long time);

int		one_philo(t_philo *philo);

int		if_dead(t_philo *philo);

int		if_eat_finish(t_philo *philo);

#endif