#include "fractol.h"

void mk_julia(double real, double imag)
{
	t_elemt elemt;
	elemt.height = 600;
	elemt.width = 600;
	elemt.depth = 60;
	elemt.color = 0;
	elemt.zoom = 20;
	elemt.ver = 0;
	elemt.hor = 0;
	elemt.real = real;
	elemt.imag = imag;
	elemt.status = JULIA;
	elemt.x = elemt.height / 2;
	elemt.y = elemt.width / 2;
	elemt.mlx = mlx_init();
	elemt.window = mlx_new_window(elemt.mlx, elemt.height, elemt.width, "fractol");
	elemt.img = mlx_new_image(elemt.mlx, elemt.height, elemt.width);
	elemt.address = mlx_get_data_addr(elemt.img, &elemt.bit_pixel, &elemt.line_len, &elemt.endian);
	img_drawing(&elemt);
	mlx_mouse_hook(elemt.window, mouse_hook, &elemt);
	mlx_key_hook(elemt.window, key_hook, &elemt);
	mlx_hook(elemt.window, 17, 1L << 0, exit_window, (void*)&elemt);
	mlx_loop(elemt.mlx);
	exit(0); 
}

void mk_mandel(void)
{
	t_elemt elemt;
	elemt.height = 600;
	elemt.width = 600;
	elemt.depth = 60;
	elemt.color = 0;
	elemt.zoom = 20;
	elemt.ver = 0;
	elemt.hor = 0;
	elemt.real = -1;
	elemt.imag = -1;
	elemt.status = MANDEL;
	elemt.x = elemt.height / 2;
	elemt.y = elemt.width / 2;
	elemt.mlx = mlx_init();
	elemt.window = mlx_new_window(elemt.mlx, elemt.height, elemt.width, "fractol");
	elemt.img = mlx_new_image(elemt.mlx, elemt.height, elemt.width);
	elemt.address = mlx_get_data_addr(elemt.img, &elemt.bit_pixel, &elemt.line_len, &elemt.endian);
	img_drawing(&elemt);
	mlx_mouse_hook(elemt.window, mouse_hook, &elemt);
	mlx_key_hook(elemt.window, key_hook, &elemt);
	mlx_hook(elemt.window, 17, 1L << 0, exit_window, (void*)&elemt);
	mlx_loop(elemt.mlx);
	exit(0);
}

unsigned int chk_color_julia(t_elemt *elemt, double zre, double zim)
{
	int		i;
	double	tmp;

	i = 0;
	while(zre * zre + zim * zim <= 4 && i < elemt -> depth)
	{
		tmp = zre * zre - zim * zim + elemt -> real;
		zim = 2 * zre * zim + elemt -> imag;
		zre = tmp;
		i++;
	}
	if(zre * zre + zim * zim > 4)
	{
		if(1 < i)
			return (0x1234567890 + i * 190 + elemt -> color);
		else
			return(0x0);
	}
	else
		return(0xe2e627 + elemt -> color);
}

unsigned int chk_color_mandel(t_elemt *elemt, double real, double imag)
{
	int i;
	double tmp;
	double zre;
	double zim;

	i = 0;
	zre = 0;
	zim = 0;
	while (zre * zre + zim * zim <= 4 && i < elemt -> depth)
	{
		tmp = zre * zre - zim * zim + real;
		zim = 2 * zre * zim + imag;
		zre = tmp;
		i++;
	}
	if(zre * zre + zim * zim > 4)
	{
		if(1 < i)
			return(0x1234567890 + i * 190 + elemt -> color);
		else
			return (0x0);
	}
	return(0xe2e627 + elemt -> color);
}

void img_drawing(t_elemt *elemt)
{
	int	row;
	int	col;
	int	color;
	double	x;
	double	y;

	row = 0;
	while(row < elemt -> height)
	{
		col = 0;
		while(col < elemt -> width)
		{
			x = (col - elemt -> x + elemt -> hor) / (elemt -> width / elemt -> zoom);
			y = (row - elemt -> y + elemt -> ver) / (elemt -> height / elemt -> zoom);
			if(elemt -> status == MANDEL)
				color = chk_color_mandel(elemt, x, y);
			if(elemt -> status == JULIA)
				color = chk_color_julia(elemt, x, y);
			my_mlx_pixel_put(elemt, col, row, color);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(elemt -> mlx, elemt -> window, elemt -> img, 0, 0);
}
