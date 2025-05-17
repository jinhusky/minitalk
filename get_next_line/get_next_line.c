/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:59:32 by kationg           #+#    #+#             */
/*   Updated: 2025/01/07 13:53:38 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_buffers(char *new_b, char *b)
{
	char	*temp;

	temp = ft_strjoin(new_b, b);
	free(new_b);
	return (temp);
}

char	*generate_nextline(int fd, char *new_buffer)
{
	char	*buffer;
	long	bytes_read;

	if (!new_buffer)
		new_buffer = ft_calloc(1, 1);
	buffer = malloc(BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(new_buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(new_buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		new_buffer = join_buffers(new_buffer, buffer);
	}
	free(buffer);
	return (new_buffer);
}

char	*extract_nextline(char *s)
{
	size_t	i;
	char	*line;
	size_t	j;

	j = 0;
	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n' && s[i])
		i++;
	line = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = s[j];
		j++;
	}
	return (line);
}

char	*get_leftover(char *s)
{
	size_t	len;
	char	*leftover;
	size_t	i;
	size_t	j;

	i = 0;
	len = ft_strlen(s);
	while (s[i] != '\n' && s[i])
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	leftover = ft_calloc(len - i + 1, 1);
	i++;
	j = 0;
	while (s[i])
		leftover[j++] = s[i++];
	free(s);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = generate_nextline(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_nextline(buffer);
	buffer = get_leftover(buffer);
	return (line);
}
/*
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);

int main(void)
{
    char *line;
    int fd1;
    int i;

    // Open the file
    fd1 = open("file1.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("Error opening file");
        return (1);
    }

    i = 0;

    while (1) {
        line = get_next_line(fd1);
        if (!line) {
            break; // Stop if EOF is reached 
        }
        printf("%s", line); 
        free(line);         // Free the allocated memory
        i++;
    }
	printf("%s", line);

    // Close the file descriptor
    close(fd1);

    return (0);
}*/
