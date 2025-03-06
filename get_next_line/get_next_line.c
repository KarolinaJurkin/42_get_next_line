/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkin <kjurkin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:41:22 by kjurkin           #+#    #+#             */
/*   Updated: 2025/03/06 18:40:55 by kjurkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

char	*get_next_line(int fd)
{
	ssize_t	a;
	char	*buffer;
	
	buffer = malloc(BUFFER_SIZE);
	a = read(fd, buffer, BUFFER_SIZE - 1);
	while (a > 0)
	{
		buffer[a] = '\0';
		printf("%s\n", buffer);
		a = read(fd, buffer, BUFFER_SIZE - 1);
	}
	return (buffer);
}


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
