/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:20:26 by eel-orch          #+#    #+#             */
/*   Updated: 2020/12/29 08:20:50 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static bool is_in_square(t_square *sq, t_vector3 hitp)
{
    t_vector3   cp;
    double      halfd;
    cp = sub_vec(hitp, sq->center);
    halfd = sq->size / 2;
    return (fabs(cp.x) <= halfd && fabs(cp.y) <= halfd && fabs(cp.z) <= halfd);
}

bool        try_sq(t_ray *ray, t_square *sq, double *t)
{
    t_vector3 hitpoint;
    if (contain_plane(sq->center, sq->orientation, ray, t))
    {
        hitpoint = get_ray_hitp(ray->origin, *t, ray->dir);
        return (is_in_square(sq, hitpoint));
    }
    return (false);
}
