#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <unistd.h>
#include "libft.h"

#define MANDEL 1
#define JULIA 2

typedef struct s_elemt
{
	void	*mlx;
	void	*window;
	struct s_elemt *img;
	char	*address;
	int		height;
	int		width;
	int		color;
	int		status;
	double	real;
	double	imag;
	double	depth;
	double	x;
	double	y;
	int		ver;
	int		hor;
	double	zoom;
	int		bit_pixel;
	int		endian;
	int		line_len;
}	t_elemt;

int ft_atof(char *digit_str, double *num);
int error_message(void);
int key_hook(int keycode, t_elemt *elemt);
int mouse_hook(int mousecode, int x, int y, t_elemt *elemt);
int esc_close(int keycode, t_elemt *elemt);
void my_mlx_pixel_put(t_elemt *elemt, int x, int y, int color);
void mk_julia(double real, double imag);
void mk_mandel(void);
unsigned int chk_color_julia(t_elemt *elemt, double zre, double zim);
unsigned int chk_color_mandel(t_elemt *elemt, double real, double imag);
void img_drawing(t_elemt *elemt);
int exit_window(t_elemt *elemt);
#endif