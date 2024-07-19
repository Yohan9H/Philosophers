/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:13:07 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/19 11:49:47 by yohurteb         ###   ########.fr       */
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

typedef pthread_mutex_t mutex;

typedef struct s_philo // peut etre rajouter une var pour think
{
	pthread_t	thread;
	size_t		start_time;
	int			num;
	int			eating;
	size_t		last_eat;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		start_time;
	int			*dead;
	mutex		l_fork;
	mutex		r_fork;
	mutex		*dead_lock;
	mutex		*eat_lock;
	mutex		*write_lock;
}	t_philo;

typedef	struct s_data
{
	int			dead_flag;
	mutex		dead_lock;
	mutex		eat_lock;
	mutex		write_lock;
	t_philo		*philos;
	mutex		*forks;
	size_t		set_t_die; //av[2]
	size_t		set_t_eat; //av[3]
	size_t		set_t_sleep; //av[4]
	int			nb_philo; 	//av[1]
	int			nb_eat; 	//av[5]
}	t_data;

typedef struct s_time 
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
} t_time;

int		check_args(int ac, char **av, t_data *data);

size_t	ft_atoi(const char *str);

void	error(int code_error);

void	init_data(t_data *data, t_philo philos[], mutex forks[]);

void	init_forks(t_data *data, mutex forks[]);

void	init_philo(t_data *data, t_philo philos[], mutex forks[]);

int		make_threads(t_data *data);

int		if_stop(t_data *);

int		routine(t_data *data);

void	free_all(t_data *data);

long	give_time(void);

#endif