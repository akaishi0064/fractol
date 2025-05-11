/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chakaish <chakaish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:30:34 by chakaish          #+#    #+#             */
/*   Updated: 2025/05/11 16:39:14 by chakaish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(void)
{
	exit(0);
	return (0);
}

int check_key(int key_nbr)
{
	if(key_nbr == 65307)
		close_window();
	return (0);
}
int	main(int ac, char *av[])
{
	t_mlx	mlx;

	(void)ac;
	(void)av;
	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (1);
	mlx.win = mlx_new_window(mlx.ptr, 500, 500, "fractol");
	if (!mlx.win)
		return (mlx_destroy_display(mlx.ptr), free(mlx.ptr), 1);
	mlx.img.ptr = mlx_new_image(mlx.ptr, 500, 500);
	if (!mlx.img.ptr)
	{
		mlx_destroy_window(mlx.ptr, mlx.win);
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		return (1);
	}
	mlx_hook(mlx.win, 17, 0, close_window, 0);
	mlx_key_hook(mlx.win, check_key, 0);
	mlx_loop(mlx.ptr);
	return (0);
}
