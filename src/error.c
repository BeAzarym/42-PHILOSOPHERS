/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:35:54 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 10:27:12 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int ft_error(char *error_code)
{
	printf("%s", error_code);
	exit(1);
}

void clean_all(t_settings *settings)
{
	int i;

	i = 0;
	while(i < settings->nb_philo)
	{
		pthread_mutex_destroy(&(settings->forks[i]));
		i++;
	}
	free(settings->forks);
	free(settings->philosophers);
	pthread_mutex_destroy(&(settings->talking));
}