/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:26:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/09 17:37:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	check_errors(argc, argv);
	data->map = parse_map(argv[1]);
	data->cam = init_cam(data);
	data->mlx = create_window();
	display_img(data);
	hooks_loop(data);
	return (0);
}
