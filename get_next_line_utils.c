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

/*	Counts the length of a string (like strlen) */
size_t	str_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* 	Creates an empty string */
int	create_empty_line(char **str)
{
	*str = malloc(1);
	if (!*str)
		return (0);
	(*str)[0] = '\0';
	return (1);
}

/* Searches for the character '\n' in the buffer. */
ssize_t	find_newline(char *buf, size_t i)
{
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
