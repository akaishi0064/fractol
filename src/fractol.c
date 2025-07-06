
#include "fractol.h"

int key_hook(int keycode, t_elemt *elemt)
{
	if(keycode == 65361)
	{
		elemt -> color += 10;
		elemt -> hor += 25;
	}
	else if(keycode == 65363)
	{
		elemt -> color += 10;
		elemt -> hor -= 25;
	}
	else if(keycode == 65362)
	{
		elemt -> color += 10;
		elemt -> ver += 25;
	}
	else if(keycode == 65364)
	{
		elemt -> color += 10;
		elemt -> ver -= 25;
	}
	else if(keycode == 65307)
		return(esc_close(keycode, elemt));
	img_drawing(elemt);
	return (0);
}

int mouse_hook(int mousecode, int x, int y, t_elemt *elemt)
{
	(void)x;
	(void)y;

	if(elemt -> zoom == 0.0)
		elemt -> zoom = 0.000001;
	if(mousecode == 4)
	{
		elemt -> zoom *= 1.2;
	}
	else if(mousecode == 5)
	{
		elemt -> zoom *= 0.8;
	}
	else
		return (0);
	img_drawing(elemt);
	return (0);
}

int esc_close(int keycode, t_elemt *elemt)
{
	(void)keycode;
	mlx_destroy_window(elemt -> mlx, elemt -> window);
	exit (0);
	return (0);
}

int exit_window(t_elemt *elemt)
{
	(void)elemt;
	exit (0);
}

void my_mlx_pixel_put(t_elemt *elemt, int x, int y, int color)
{
	char *dst;

	dst = elemt -> address + (y *elemt -> line_len + x *(elemt -> bit_pixel / 8));
	*(unsigned int *)dst = color;
}
