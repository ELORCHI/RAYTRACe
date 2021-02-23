/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:34:21 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:34:28 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

t_mat4x4	identity_mat(void)
{
	t_mat4x4 mat;

	mat.c1 = vec4_creat(1, 0, 0, 0);
	mat.c2 = vec4_creat(0, 1, 0, 0);
	mat.c3 = vec4_creat(0, 0, 1, 0);
	mat.c4 = vec4_creat(0, 0, 0, 1);
	return (mat);
}
