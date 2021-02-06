/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:10:54 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/06 18:10:57 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "parsing.h"

float	to_float(int int_part, char *decimal, int negative)
{
	int		decimal_part;
	int 	decimal_len;
	int 	tmp;
	float	number;
	int		i;

	i = 0;
	decimal_len = 0;
	tmp = int_part;
	while (decimal[i] == 48)
		i++;
	decimal_part = ft_atoi(decimal + i);
	decimal_len = ft_int_size(decimal_part) + i;
	int_part = int_part * pow(10, decimal_len);
	if (negative == 1 && int_part != 0)
		decimal_part = -1 * decimal_part;
	int_part = int_part + decimal_part;
	number = int_part * pow(10, -decimal_len);
	if (negative == 1 && tmp == 0)
		number *= -1;
	return (number);
}

float	ft_atof(char *line)
{
	int 	int_part;
	int 	int_len;
	int		negative;
	float	number;
	int		i;

	i = 0;
	int_len = 0;
	negative = 0;
	if (line[i] == '-')
	{
		i = 1;
		negative = 1;
	}
	while (line[i] == 48)
		i++;
	int_part = ft_atoi(line);
	int_len += ft_int_size(int_part);
	int_len += (i > 1) ? --i : 0;
	number = to_float(int_part, line + int_len + 1, negative);
	return(number); 
}

int main()
{
	float decimal;
	char *line = "-69.0063";
	int test;

	test = ft_atoi(line);
	decimal = ft_atof(line);
	printf("%f\n%d\n",decimal, test);
	return (0);
}
