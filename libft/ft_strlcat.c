/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chakaish <chakaish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:20:12 by chakaish          #+#    #+#             */
/*   Updated: 2024/12/15 17:51:27 by chakaish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <bsd/string.h>

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	if (n == 0)
		return (ft_strlen(src));
	if (!dest && !src)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (n <= dest_len)
		return (n + src_len);
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i < n - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	char	dest[20] = "ABCDE";
// 	char	src1[10] = "1234";
// 	char	src2[10] = "1234";
// 	int		result1;
// 	int		result2;
// 	result1 = ft_strlcat(NULL, src1, 0);
// 	result2 = strlcat(NULL, src2, 0);
// 	printf("%s: %d\n", dest, result1);
// 	printf("%s: %d\n", dest, result2);
// 	return (0);
// }
