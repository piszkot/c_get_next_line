/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:00:00 by your_login        #+#    #+#             */
/*   Updated: 2026/03/17 12:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);

void	read_file(const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	main(void)
{
	const char	*files[] = {"pan_tadeusz.txt", "test.txt"};
	size_t		i;
	size_t		files_len;

	i = 0;
	files_len = sizeof(files) / sizeof(files[0]);
	while (i < files_len)
	{
		read_file(files[i]);
		if (i < (files_len - 1))
			printf("\n-------------------------------------------\n");
		i++;
	}
	return (0);
}
