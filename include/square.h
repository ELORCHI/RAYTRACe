#ifndef SQUARE_H
#define SQUARE_H

#include "rt.h"
#include "world.h"
#include "plan.h"
#include "ray.h"

typedef struct 	s_square
{
	t_vector 		center;
	t_vector 		normal;
	t_vector 		color;
	float			side;
	struct square 	*next;
} 				t_square;

#endif