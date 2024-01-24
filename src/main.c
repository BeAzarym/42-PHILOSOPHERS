/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:14:12 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 14:32:53 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_settings	*init_all_data(int argc, char **argv, t_settings *settings)
{
	if (argc < 5 || argc > 6)
		ft_error(ERR_COUNT_ARG, settings);
	if (!check_arg(argc, argv))
		ft_error(ERR_INVALID_ARG, settings);
	settings = init_settings(argc, argv);
	if (!settings)
		ft_error(ERR_MALLOC_FAILED, settings);
	if (init_mutex(settings))
		ft_error(ERR_MUTEX_FAILED, settings);
	settings->philosophers = init_philosophers(settings);
	if (!settings->philosophers)
		ft_error(ERR_MALLOC_FAILED, settings);
	return (settings);
}

int	main(int argc, char **argv)
{
	t_settings	*settings;
	int			i;
	int			check;

	settings = NULL;
	settings = init_all_data(argc, argv, settings);
	check = start_dineer(settings);
	if (check)
	{
		clean_fail(settings, check);
		return (0);
	}
	death_checking(settings);
	i = -1;
	if (settings->nb_philo > 1)
	{
		while (++i < settings->nb_philo)
			pthread_join(settings->philosophers[i].id, NULL);
	}
	clean_all(settings);
	free(settings);
}
