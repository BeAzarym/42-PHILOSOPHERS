/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:14:12 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/18 14:39:28 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		ft_error(ERR_COUNT_ARG);
	if (!check_arg(argc, argv))
		ft_error(ERR_INVALID_ARG);
}
