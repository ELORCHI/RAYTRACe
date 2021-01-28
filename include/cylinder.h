/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <eel-orch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:24:09 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/27 14:23:59 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
#include "rt.h"

typedef struct	s_cylinder
{
	t_vector 				point;
	t_vector 				normal;
	t_vector 				color;
	float 					height;
	float					diameter;
	struct	s_cylinder 		*next;
}				t_cylinder;

#endif
