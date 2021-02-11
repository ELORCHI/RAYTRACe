#ifndef PLAN_H
#define PLAN_H

#include "rt.h"

typedef struct  s_plan
{
    t_vector        point;
    t_vector        normal;
    t_vector        color;
    struct s_plan   *next;
}               t_plan;

t_intersection ray_plans_intersection(t_plan *plan, t_ray ray);
#endif
