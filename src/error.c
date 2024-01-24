/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:35:54 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 14:32:23 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_error(char *error_code, t_settings *settings)
{
	if (settings)
	{
		clean_all(settings);
	}
	printf("%s", error_code);
	exit(1);
}

void	clean_all(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->nb_philo)
	{
		pthread_mutex_destroy(&(settings->forks[i]));
		i++;
	}
	if (settings->forks)
		free(settings->forks);
	if (settings->philosophers)
		free(settings->philosophers);
	pthread_mutex_destroy(&(settings->talking));
}

void	clean_fail(t_settings *settings, int check)
{
	while (--check >= 0)
		pthread_join(settings->philosophers[check].id, NULL);
	while (++check < settings->nb_philo)
		pthread_mutex_destroy(&(settings->forks[check]));
	pthread_mutex_destroy(&settings->talking);
	free(settings->forks);
	free(settings->philosophers);
	free(settings);
	settings = NULL;
	ft_error("[ERROR] >> PTHREAD_CREATE FAILED\n", settings);
}
