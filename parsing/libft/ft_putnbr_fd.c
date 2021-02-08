/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:09:45 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/04 03:15:01 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		help;
	long	longn;

	longn = (long)n;
	if (longn < 0)
	{
		ft_putchar_fd('-', fd);
		longn = -1 * longn;
	}
	if (longn <= 9)
		ft_putchar_fd(longn + 48, fd);
	else
	{
		help = longn % 10;
		ft_putnbr_fd(longn / 10, fd);
		ft_putchar_fd(help + 48, fd);
	}
}
