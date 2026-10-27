/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paragraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakhemkh <kakhemkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:51:46 by qzimmerm          #+#    #+#             */
/*   Updated: 2026/10/27 15:00:11 by kakhemkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_paragraph.h"
#include <unistd.h>
#include <stdio.h>

void	ft_make_paragraph(char *input, t_config *config)
{
	while (input[config->f] != '\0' && config->d < config->p_nbr)
	{
		write(1, &input[config->f++], 1);
		if (config->f % config-> l_len == 0)
		{
			write (1, "\n", 1);
			config->e++;
		}
		if (config->e == config->p_len)
		{
			write(1, "\n", 1);
			config->d++;
			config->e = 0;
		}
	}
		write(1,"\n", 1);
	if (input[config->f] != '\0')
	{
		write(1, "Rest: ", 6);
		while (input[config->f] != '\0')
			write(1, &input[config->f++], 1);
		write(1, "\n", 1);
	}
}

int	put_error(t_config *config)
{
	if (config->d < config->p_nbr)
		write(1,"Not enough paragraphs.\n",23);
	if (config->e % config->p_len || config->p_len == 0)
		write(1,"Missing line in paragraph.\n", 27);
	if (config->f % config->l_len || config->l_len <= 2)
		write(1,"Missing char in line.\n",22);
	return(0);
}

int	main(int ac, char **av)
{
	t_config	config;

	config.d = 0;
	config.e = 0;
	config.f = 0;
	config.l_len = 5;
	config.p_len = 2;
	config.p_nbr = 3;
	if (ac != 2)
		write(1,"Error: usage ./a.out <text>.\n", 29);
	ft_make_paragraph(av[1], &config);
	put_error(&config);
	return (1);
}
