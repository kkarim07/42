/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paragraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakhemkh <kakhemkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:51:46 by qzimmerm          #+#    #+#             */
/*   Updated: 2026/10/26 16:29:07 by kakhemkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_paragraph.h"
#include <unistd.h>
#include <stdio.h>

void	ft_make_paragraph(char *input, t_config *config)
{
	int D = 0;
	int	E = 0;
	int	F = 0;

	// "hello world"
	while (D < config-> l_len && input[D] != '\0') /*paragraphe (3)*/
	{
		while (E < config-> p_len && input[D] != '\0') /*ligne par paragraphe (2)*/
		{
			while (F < config-> p_nbr && input[D] != '\0') /*caractere par ligne (5)*/ 
			{
				write(1, &input[F], 1);
				F++;
			}
			write(1, "\n", 1);
			E++;
		}
		write (1, "\n\n", 2);
		D++;
	}
	if (input[D] != '\0')
	{
		write(1, "Reste :", 8);
		while (input[D] != '\0')
		{
			write(1, &input[D], 1);
			D++;
		}
	}
}




int	put_error(char *input)
{
	while (*input != '\0')
	{
		write(2, input, 1);
		input++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_config	config;

	config.p_nbr = 3;
	config.p_len = 2;
	config.l_len = 5;
	if (ac != 2)
		return (put_error("Error: usage ./a.out <text>.\n"));
	/*if 
		return (put_error("Not enough paragraphs.\n"));
	{
		if 
			return (put_error("Missing line in paragraph.\n"));
		if 
			return (put_error("Missing char in line.\n"));
	}*/
	(void) **av;
	ft_make_paragraph(av[1], &config);
	return ( 1);
}
