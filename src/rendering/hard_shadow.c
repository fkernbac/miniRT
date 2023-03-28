/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_shadow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:13:37 by fkernbac          #+#    #+#             */
/*   Updated: 2023/03/27 20:42:50 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	lambert_color(\
	t_vec light_color, t_vec object_color, t_vec face_normal, t_vec to_light)
{
	t_vec	color;
	t_vec	attenuation;

	attenuation = factor_mult_vector(object_color, ALBEDO);
	color = multiply_vector(attenuation, light_color);
	color = color_clamp(color);
	color = factor_mult_vector(color, \
		sin(scalar_vector(face_normal, to_light)));
	return (color);
}

t_vec	ray_at_light(t_ray *ray, t_obj *obj, t_obj *light)
{
	t_ray		bounce;

	bounce = bounce_ray(ray);
	if (hit_object(ray, obj) == true)
	{
		if (ray->closest_object->type == LIGHT)
			return (ray->closest_object->color);
		bounce.origin = point_at(*ray, ray->closest_t);
		bounce.direction = \
			unit_vector(subtract_vector(light->origin, bounce.origin));
		if (scalar_vector(bounce.direction, ray->normal) < 0)
			return (new_vector(0, 0, 0));
		if (front_facing(*ray) == true)
			return (lambert_color(ray_at_light(&bounce, obj, light), \
				ray->closest_object->color, ray->normal, bounce.direction));
		else
			return (new_vector(0, 1, 0));
	}
	if (SKY == true)
		return (gradient(ray));
	return (new_vector(0, 0, 0));
}
