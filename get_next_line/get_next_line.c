/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkin <kjurkin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:41:22 by kjurkin           #+#    #+#             */
/*   Updated: 2025/03/22 16:21:49 by kjurkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 10


static int	ft_strlenconst(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*ptr;
	int		i;

	len1 = ft_strlenconst(s1);
	len2 = ft_strlenconst(s2);
	ptr = malloc(len1 + len2 + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		ptr[len1 + i] = s2[i];
		i++;
	}
	ptr[len1 + i] = '\0';
	return (ptr);
}

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

int	count(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (i + 1);
}

char	*get_next_line(int fd)
{
	ssize_t	a;
	char	*buffer;
	static char	*final;
	
	buffer = malloc(BUFFER_SIZE); //?jesli buffer size < od linijki to musze jakos zmalokowac wystarczajaco miejsca na cala linijke
	a = read(fd, buffer, BUFFER_SIZE - 1);
	if (final)
	{
		// printf("final: %s\n", final);
		buffer = ft_strjoin(final, buffer);
	}
	if (ft_strchr(buffer, '\n'))
		final = ft_strchr(buffer, '\n') + 1;
	final = ft_strdup(final);
	while (a > 0 && !ft_strchr(buffer, '\n' && !ft_strchr(buffer, '\0')))
	{
		final = buffer;
		// printf("%s\n", buffer);
		a = read(fd, buffer, BUFFER_SIZE - 1);
		buffer = ft_strjoin(final, buffer);
	}
	buffer = ft_strjoin(final, buffer); //????
	buffer[count(buffer)] = '\0';
	printf("%s", buffer);
	return (buffer);
}

int	main(int argc, char *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (argc);
}

// ssize_t read(int fd, void buffer[.count], size_t count)
// if (count > buffer_size) {count = buffer_size} - to prevent overflow
