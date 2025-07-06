/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaishichiharu <akaishichiharu@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:30:34 by chakaish          #+#    #+#             */
/*   Updated: 2025/06/21 20:07:15 by akaishichih      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int ac, char *av[])
{
	double	real;
	double	imag;
	int		chk_real;
	int		chk_imag;

	if (ac == 2 && av[1][0] == 'm' && av[1][1] == '\0')
		mk_mandel();
	else if(ac == 4 && av[1][0] =='j' && av[1][1] == '\0')
	{
		chk_real = ft_atof(av[2], &real);
		chk_imag = ft_atof(av[3], &imag);
		if(chk_real == 1 || chk_imag == 1)
			return (error_message());
		mk_julia(real,imag);
	}
	return (error_message());
}

int ft_atof(char *digit_str, double *num)
{
	int i;
	i = 0;

	if (5 < ft_strlen(digit_str))
		return (1);
	if (digit_str[i] == '-')
		i++;
	while('0' <= digit_str[i] && digit_str[i] <= '9')
		i++;
	if(digit_str[i] != '\0')
		return (1);
	*num = (double)ft_atoi(digit_str) / 1000;
	return(0);
}

int error_message(void)
{
	ft_putstr_fd("Please enter the following valuse\n ex:./a.out m\n \
	ex:./a.out j -345 654", 2);
	return (0);
}
