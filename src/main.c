/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:14:12 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 13:07:38 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_settings	*settings;
	int			i;

	if (argc < 5 || argc > 6)
		ft_error(ERR_COUNT_ARG);
	if (!check_arg(argc, argv))
		ft_error(ERR_INVALID_ARG);
	settings = init_settings(argc, argv);
	if (!settings)
		ft_error(ERR_MALLOC_FAILED);
	if (init_mutex(settings))
		ft_error(ERR_MUTEX_FAILED);
	settings->philosophers = init_philosophers(settings);
	if (!settings->philosophers)
		ft_error(ERR_MALLOC_FAILED);
	start_dineer(settings);
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
