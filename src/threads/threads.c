/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:19:16 by rbetz             #+#    #+#             */
/*   Updated: 2023/03/20 15:32:51 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < NOT)
	{
		data->threads[i] = ft_calloc(1, sizeof(t_thread));
		data->threads[i]->id = i + 1;
		data->threads[i]->cam = data->cam;
		data->threads[i]->img = data->img;
		data->threads[i]->obj = data->obj;
		data->threads[i]->mlx = data->mlx;
		data->threads[i]->data = data;
		if (pthread_create(&data->threads[i]->pid, NULL, &draw_image, (void *)data->threads[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	remove_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < NOT)
	{
		if (pthread_join(data->threads[i]->pid, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}