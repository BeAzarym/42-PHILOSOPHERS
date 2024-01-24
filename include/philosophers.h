/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:20:08 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 11:45:21 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdatomic.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERR_COUNT_ARG "[ERROR] >> INVALID NUMBER OF ARGUMENT\n"
# define ERR_INVALID_ARG "[ERROR] >> INVALID ARGUMENT TYPE\n"
# define ERR_MALLOC_FAILED "[ERROR] >> MALLOC FAILED\n"
# define ERR_MUTEX_FAILED "[ERROR] >> MUTEX FAILED\n"

# define M_FORK "has taken a fork"
# define M_EAT "is eating"
# define M_SLEEP "is sleeping"
# define M_THINK "is thinking"
# define M_DIED "died"

typedef enum e_status
{
	BORN,
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED
}						t_status;

typedef struct s_philosophers
{
	int					pos;
	int					lfork_id;
	int					rfork_id;
	uint64_t			last_meal;
	int					weight;
	pthread_t			id;
	int					status;
	struct s_settings	*settings;

}						t_philosophers;

typedef struct s_settings
{
	int					nb_philo;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	uint64_t			time_to_die;
	int					limits;
	time_t				start;
	uint64_t			sated;
	uint64_t			is_alive;
	t_philosophers		*philosophers;
	pthread_mutex_t		talking;
	pthread_mutex_t		*forks;
}						t_settings;

long int				ft_atoi(const char *str);
int						check_arg(int argc, char **argv);
int						ft_error(char *error_code);
t_settings				*init_settings(int argc, char **argv);
int						init_mutex(t_settings *settings);
t_philosophers			*init_philosophers(t_settings *settings);
uint64_t				get_time(void);
void					ft_usleep(uint64_t time);
void					print(t_settings *settings, int pos);
void					eat(t_settings *settings, int pos);
void					*routine(void *v_pointer);
void					death_checking(t_settings *settings);
void					sated_checking(t_settings *settings);
void					clean_all(t_settings *settings);

#endif