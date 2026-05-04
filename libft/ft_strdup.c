/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 04:06:43 by muhakgul          #+#    #+#             */
/*   Updated: 2026/05/04 02:34:32 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
