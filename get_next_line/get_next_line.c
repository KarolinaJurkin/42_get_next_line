/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkin <kjurkin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:41:22 by kjurkin           #+#    #+#             */
/*   Updated: 2025/03/07 19:23:08 by kjurkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 20

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
	while (buffer[i] != '\n')
		i++;
	printf("i = %d\n", i);
	return (i + 1);
}

char	*get_next_line(int fd)
{
	ssize_t	a;
	char	*buffer;
	char	*final;
	
	
	buffer = malloc(BUFFER_SIZE);
	a = read(fd, buffer, BUFFER_SIZE - 1);
	final = ft_strchr(buffer, '\n'); // copy string to final, so after the change of buffer it still points to excess 
	while (a > 0 && !ft_strchr(buffer, '\n'))
	{
		printf("a: %zd\n", a);
		// buffer[a] = '\0';
		printf("%s\n", buffer);
		a = read(fd, buffer, BUFFER_SIZE - 1);
	}
	buffer[count(buffer) + 1] = '\0';
	// final = malloc(count(buffer) + 1);
	// final = buffer;
	printf("%s\n", buffer);
	return (buffer);
}

// char	*get_next_line(int fd)
// {
// 	ssize_t	a;
// 	char	*buffer;
// 	char	*final;
	
	
// 	buffer = malloc(BUFFER_SIZE);
// 	a = read(fd, buffer, BUFFER_SIZE - 1);
// 	while (a > 0)
// 	{
// 		if (ft_strchr(buffer, '\n'))
// 		{
// 			read(fd, buffer, count(buffer));
// 			printf("%s\n", buffer);
// 		}
// 		printf("a: %zd\n", a);
// 		// buffer[a] = '\0';
// 		printf("%s\n", buffer);
// 		a = read(fd, buffer, BUFFER_SIZE - 1);
// 	}
// 	return (buffer);
// }


int	main(int argc, char *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	close(fd);
	return (argc);
}

// ssize_t read(int fd, void buffer[.count], size_t count)
// if (count > buffer_size) {count = buffer_size} - to prevent overflow
