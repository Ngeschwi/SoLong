/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:15:07 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 15:15:20 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dst;

	if (str == NULL)
	{
		dst = malloc(sizeof(char) * 1);
		dst[0] = '\0';
		return (dst);
	}
	dst = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
