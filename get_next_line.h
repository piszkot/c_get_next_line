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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/*	Counts the length of a string (like strlen) */
size_t	str_len(const char *s);

/* 	Creates an empty string (e.g. when there is nothing to read. 
	Returns status (success/error) */
int		create_empty_line(char **str);

/* 	Searches for the character '\n' in the buffer. 
	Returns its position or -1 if it is missing. */
ssize_t	find_newline(char *buf, size_t i);

/* 
	Main function:
		Reads from a file (via the fd descriptor)
		Returns one line of text at a time
		On the next call, → returns the next line
*/
char	*get_next_line(int fd);

#endif
