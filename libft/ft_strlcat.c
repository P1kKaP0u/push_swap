/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakgul <muhakgul@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:32:20 by muhakgul          #+#    #+#             */
/*   Updated: 2026/01/31 13:27:38 by muhakgul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_n;
	size_t	s_n;
	size_t	i;

	d_n = 0;
	s_n = 0;
	i = 0;
	while (src[s_n])
		s_n++;
	while (dst[d_n] && d_n < dstsize)
		d_n++;
	if (dstsize <= d_n)
		return (dstsize + s_n);
	while (src[i] && (d_n + i) < (dstsize - 1))
	{
		dst[d_n + i] = src[i];
		i++;
	}
	dst[d_n + i] = '\0';
	return (d_n + s_n);
}
