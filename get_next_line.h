/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:37:43 by dhadding          #+#    #+#             */
/*   Updated: 2023/03/20 09:17:27 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// OPEN_MAX is a reasonable limit to the number of files which
// can be open at one time.

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

/*
	get_next_line will read a file (described by the file descriptor "fd")
	it will then load the file line by line at a size defined by the MACRO
	BUFFER_SIZE (which can be redefined upon compilation), the line is loaded
	into the variable named *buffer on each call of get_next_line,
	a copy of this variable is made as well, named *buffer_copy
	it is a static variable, and as such its lifetime is during the time the 
	program is running. Allowing separate function calls to get the next line
	in succession wihin the file.

	get_next_line will search for an occurrence of a newline within each line
	defined by the BUFFER_SIZE, and *buffer_copy will be updated to start after
	the occurrence of this newline.

	get_next_line will also allow for multiple file descriptors to be used in
	separate function calls, with a maximum open file limit of 256.
*/

char	*get_next_line(int fd);

	/* UTILITIES */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif