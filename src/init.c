/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:18:27 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 13:08:09 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_settings	*init_settings(int argc, char **argv)
{
	t_settings	*settings;

	settings = malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	settings->nb_philo = ft_atoi(argv[1]);
	settings->time_to_die = ft_atoi(argv[2]);
	settings->time_to_eat = ft_atoi(argv[3]);
	settings->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		settings->limits = ft_atoi(argv[5]);
	else
		settings->limits = -1;
	settings->sated = 0;
	settings->is_alive = 1;
	return (settings);
}

int	init_mutex(t_settings *settings)
{
	int	id;

	id = settings->nb_philo;
	settings->forks = malloc(sizeof(pthread_mutex_t) * settings->nb_philo);
	if (!settings->forks)
		return (1);
	while (--id >= 0)
	{
		if (pthread_mutex_init(&settings->forks[id], NULL))
		{
			free(settings->forks);
			return (1);
		}
	}
	if (pthread_mutex_init(&settings->talking, NULL))
	{
		free(settings->forks);
		return (1);
	}
	return (0);
}

t_philosophers	*init_philosophers(t_settings *settings)
{
	t_philosophers	*philosophers;
	int				i;

	philosophers = malloc(sizeof(t_philosophers) * (settings->nb_philo));
	if (!philosophers)
		return (NULL);
	i = settings->nb_philo;
	while (--i >= 0)
	{
		philosophers[i].pos = i;
		philosophers[i].lfork_id = i;
		philosophers[i].rfork_id = (i + 1) % settings->nb_philo;
		philosophers[i].last_meal = 0;
		philosophers[i].weight = 0;
		philosophers[i].status = BORN;
		philosophers[i].settings = settings;
	}
	return (philosophers);
}

void	*routine(void *v_pointer)
{
	t_philosophers	*philosophers;
	t_settings		*settings;

	philosophers = (t_philosophers *)v_pointer;
	settings = philosophers->settings;
	if (philosophers->pos % 2)
		ft_usleep(settings->time_to_eat / 2);
	while (settings->is_alive == 1)
	{
		eat(settings, philosophers->pos);
		if (settings->sated)
			break ;
		philosophers->status = SLEEP;
		print(settings, philosophers->pos);
		ft_usleep(settings->time_to_sleep);
		philosophers->status = THINK;
		print(settings, philosophers->pos);
	}
	return (0);
}

void	start_dineer(t_settings *set)
{
	int	i;

	i = 0;
	settings->start = get_time();
	while (i < settings->nb_philo)
	{
		settings->philosophers[i].last_meal = get_time();
		if (pthread_create(&(settings->philosophers[i].id), NULL, routine,
				&(settings->philosophers[i])))
			return (i);
		i++;
	}
}
