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

#include "get_next_line.h"

/*	Reads up to BUFFER_SIZE bytes from fd into buf.
	Returns 1 if data was read successfully.
	Returns 0 on EOF (with non-empty str) or on read error (frees str). */
static int	read_buf(int fd, char **full_line, char *buf)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == 0 && (**full_line))
		return (0);
	if (bytes_read <= 0)
	{
		free(*full_line);
		*full_line = NULL;
		return (0);
	}
	buf[bytes_read] = '\0';
	return (1);
}

/*	Allocates a new string by appending 'len' characters from 'buf'
	(starting at 'start') to 'old_chunk_str'. Frees the old string.
	Returns the new string, or NULL on allocation failure. */
static char	*alloc_str(char *old_chunk_str, char *buf, ssize_t start,
				size_t len)
{
	size_t	i;
	char	*new_str;

	new_str = malloc(str_len(old_chunk_str) + len + 1);
	if (!new_str)
	{
		free(old_chunk_str);
		return (NULL);
	}
	i = 0;
	while (old_chunk_str[i])
	{
		new_str[i] = old_chunk_str[i];
		i++;
	}
	free(old_chunk_str);
	new_str[i + len] = '\0';
	while (len)
	{
		len--;
		new_str[i + len] = buf[start + len];
	}
	return (new_str);
}

/*	Appends the remaining buffer content (from line_start to end) to
	chunk_str. Resets line_start and line_len to 0 for the next read.
	Returns 1 on success, 0 on allocation failure. */
static int	add_chunk(char **chunk_str, char *buf, ssize_t *line_start,
		ssize_t *line_len)
{
	*chunk_str = alloc_str(*chunk_str, buf, *line_start,
			BUFFER_SIZE - *line_start);
	if (!*chunk_str)
		return (0);
	*line_start = 0;
	*line_len = 0;
	return (1);
}

/*	Appends the current line (from line_start, length line_len) to line.
	Advances line_start past the consumed characters, resets line_len.
	Returns the completed line string, or NULL on allocation failure. */
static char	*complete_line(char *line, char *buf, ssize_t *line_start,
		ssize_t *line_len)
{
	line = alloc_str(line, buf, *line_start, *line_len);
	*line_start += *line_len;
	*line_len = 0;
	return (line);
}

/*	Main function:
	Reads from a file (via the fd descriptor)
	Returns one line of text at a time
	On the next call, → returns the next line */
char	*get_next_line(int fd)
{
	char			*full_line;
	static char		buf[BUFFER_SIZE + 1];
	static ssize_t	line_start = 0;
	static ssize_t	len = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || !create_empty_line(&full_line))
		return (NULL);
	while (!len)
	{
		if (!line_start && !read_buf(fd, &full_line, buf))
			return (full_line);
		len = find_newline(buf, line_start) - line_start;
		if (len > 0)
			return (complete_line(full_line, buf, &line_start, &len));
		else if (!add_chunk(&full_line, buf, &line_start, &len))
			return (NULL);
	}
	return (NULL);
}
