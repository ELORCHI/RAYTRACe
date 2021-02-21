/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:59:31 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/21 17:59:32 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAN_H
# define PLAN_H

# include "rt.h"

typedef struct	s_plan
{
	t_vector		point;
	t_vector		normal;
	t_vector		color;
	struct s_plan	*next;
}				t_plan;

t_intersection	ray_plans_intersection(t_plan *plan, t_ray ray);
#endif
