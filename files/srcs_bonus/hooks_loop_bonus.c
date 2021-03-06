/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:40:36 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/09 11:12:17 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotation(int keycode, t_fdf *data)
{
	if (keycode == K_LEFT)
		data->cam.rotate[0] = 1;
	if (keycode == K_RIGHT)
		data->cam.rotate[1] = 1;
	if (keycode == K_UP)
		data->cam.rotate[2] = 1;
	if (keycode == K_DOWN)
	{
		data->cam.rotate[0] = 0;
		data->cam.rotate[1] = 0;
		data->cam.rotate[2] = 0;
		data->cam.angle = 0;
	}
	if (keycode == K_LEFT || keycode == K_RIGHT || keycode == K_UP)
		data->cam.angle += 0.1;
}

int	key_action(int keycode, t_fdf *data)
{
	if (keycode == K_ESC)
		end(&data->mlx);
	if (keycode == K_W)
		data->cam.pos_y -= SPEED_MOV;
	if (keycode == K_A)
		data->cam.pos_x -= SPEED_MOV;
	if (keycode == K_D)
		data->cam.pos_x += SPEED_MOV;
	if (keycode == K_S)
		data->cam.pos_y += SPEED_MOV;
	hooks_perspective(data, keycode);
	rotation(keycode, data);
	new_image(data);
	return (0);
}

int	close_x(t_mlx *mlx)
{
	end(mlx);
	return (0);
}

int	zoom(int button, int x, int y, t_fdf *data)
{
	x++;
	y++;
	if (button == M_SCR_U && data->cam.zoom)
		data->cam.zoom += 1;
	if (button == M_SCR_D && data->cam.zoom)
		data->cam.zoom -= 1;
	if (!data->cam.zoom)
		data->cam.zoom = 1;
	new_image(data);
	return (0);
}

void	hooks_loop(t_fdf *data)
{
	mlx_key_hook(data->mlx.win, key_action, data);
	mlx_hook(data->mlx.win, 17, (1L << 17), close_x, &data->mlx);
	mlx_mouse_hook(data->mlx.win, zoom, data);
	mlx_loop(data->mlx.ptr);
}
