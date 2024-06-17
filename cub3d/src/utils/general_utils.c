/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:30:14 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/07 03:48:03 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	cancel_d(void)
{
	printf("error initializing mlx42: \n\t%s\n", mlx_strerror(mlx_errno));
	exit(1);
}

void	close_handle(void *param)
{
	t_ptrs		*_ptrs;

	_ptrs = (t_ptrs *)param;
	mlx_terminate(_ptrs->mlx_ptr);
	exit(0);
}

void	put_pixel(t_ptrs *_ptrs, int x, int y, int color)
{
	if (x > 0 && y > 0
		&& x < _ptrs->win_width && y < _ptrs->win_height)
		mlx_put_pixel(_ptrs->mlx_img, x, y, color << 8 | 0xFF);
}

void	adapt_camera_plane(t_ptrs	*_ptrs)
{
	_ptrs->horizontal_camera_plane[0] = _ptrs->direction[1] * -1;
	_ptrs->horizontal_camera_plane[1] = _ptrs->direction[0];
}

int	better_collision_detection(
		t_ptrs *_ptrs, float newX, float newY, float range)
{
	float			y;
	float			x;

	y = newY - range;
	while (y < newY + range)
	{
		x = newX - range;
		while (x < newX + range)
		{
			if (_ptrs->map_data->map[(int)y][(int)x] == '1')
				return (0);
			x += range / 2;
		}
		y += range / 2;
	}
	return (1);
}
