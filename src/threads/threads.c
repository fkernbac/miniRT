/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humbi <humbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:19:16 by rbetz             #+#    #+#             */
/*   Updated: 2023/03/23 09:36:39 by humbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < NOT)
	{
		data->threads[i].id = i + 1;
		data->threads[i].cam = data->cam;
		data->threads[i].img = data->img;
		data->threads[i].obj = data->obj;
		data->threads[i].mlx = data->mlx;
		data->threads[i].data = data;
		if (pthread_create(&data->threads[i].pid, NULL, &thread_routine, \
			(void *)&data->threads[i]) != 0)
			return (error_message(15), 1);
		i++;
	}
	return (0);
}

int	remove_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < NOT && data->threads[i].pid)
	{
		if (pthread_join(data->threads[i].pid, NULL) != 0)
			return (error_message(16), 1);
		data->threads[i].pid = 0;
		i++;
	}
	return (0);
}

int	cancel_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < NOT && data->threads[i].pid != 0)
	{
		if (pthread_cancel(data->threads[i].pid) != 0)
			return (error_message(17), 1);
		i++;
	}
	return (0);
}
