/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   khafni.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 09:59:23 by eel-orch          #+#    #+#             */
/*   Updated: 2020/12/22 18:45:16 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rt.h"
#include <unistd.h>
/*typedef struct
{
	int x;
	int y;
	int z;
	int w;
}	vec;*/

float element(t_mat3x3 *mat, int colomn, int row)
{
	t_vec3  *element;
	float x;

	//element = *(((t_vec3 *)mat->c1) + 1);
	element = ((t_vec3 *)mat + colomn);
	if (row == 0)
		x = element->x;
	else if (row == 1)
		x = element->y;
	else if (row == 2)
		x = element->z;
	return (x);
}

int main()
{
	/*vec v1 = {4, 2, 3, 1};
	vec *v1p;
	v1p = &v1;
	int n = *((int*)v1p + 1);
	printf("%d", n);*/

	t_mat3x3 mat;
	float	elem;
	int 	c;
	int 	r;

	c = 0;
	r = 0;
	mat.c1 = vec3_creat(7.7, 8, 9);
	mat.c2 = vec3_creat(0, 1, 3);
	mat.c3 = vec3_creat(4, 5, 6);
	while (c < 3)
	{
		r = 0;
		while (r < 3)
		{
			elem = element (&mat, c, r);
			printf("%f ", elem);
			r++;
		}
		printf("\n");
		c++;
	}
	return (0);
}


//add = the pointer to the struct (doesn't matter if it's in the stack of the heap who gives a shit)
//*((members_type*)add + index)
