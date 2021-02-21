/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:02:16 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/21 18:02:17 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "rt.h"
# include "ray.h"
# include "plan.h"

typedef	struct	s_square
{
	t_vector		center;
	t_vector		normal;
	t_vector		color;
	float			side;
	struct s_square	*next;
}				t_square;

t_intersection	ray_sqaures_intersection(t_square *square, t_ray ray);
#endif
