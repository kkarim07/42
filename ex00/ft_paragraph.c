/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paragraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakhemkh <kakhemkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:31:17 by kakhemkh          #+#    #+#             */
/*   Updated: 2026/10/26 15:19:53 by kakhemkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_paragraph.h"

int	put_error(char *inputerror)
{
	while(*inputerror)
	{
		write(2,inputerror,1);
		inputerror++;
	}
	return (1);
}
int	main(int argc, char **argv)
{
	t_config	config;

	config.l_len = 5;
	config.p_len = 2;
	config.p_nbr = 3;
	
	if(argc != 2)
		return(put_error("Error: usage ./a.out <text>.\n"));
	(void) **argv;
}