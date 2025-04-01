/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkin <kjurkin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:29:20 by kjurkin           #+#    #+#             */
/*   Updated: 2025/04/01 17:43:34 by kjurkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	ptr = malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	while (j < i)
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != c % 256 && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == '\0' && c != '\0')
		return (NULL);
	return ((char *)(&s[i]));
}