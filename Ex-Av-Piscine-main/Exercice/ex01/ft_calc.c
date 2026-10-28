/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakhemkh <kakhemkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:51:01 by kakhemkh          #+#    #+#             */
/*   Updated: 2026/10/28 11:16:36 by kakhemkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_numeric(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            return (0);
        }
        i++;
    }
    return (1);
}

char check_sign
int ft_atoi(char *str)
{
    int i;
    int j;
    int result;

    i = 0;
    j = 1;
    result = 0;
    while (str[i] == ' ')
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            j *= -1;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10);
        i++;
    }
    return (result * j);
}