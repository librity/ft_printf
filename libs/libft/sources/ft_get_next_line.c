/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 02:35:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static bool	bad_params(int file_descriptor, char **line)
{
	if (file_descriptor < 0)
		return (true);
	if (file_descriptor > MAX_FILE_DESCRIPTOR)
		return (true);
	if (BUFFER_SIZE <= 0)
		return (true);
	if (line == NULL)
		return (true);
	return (false);
}

static char	*initialize_line_buffer(char *read_buffer, bool *found_linebreak)
{
	char	*linebreak_position;
	char	*line_buffer;

	if (read_buffer[0] == '\0')
		return (ft_strdup(""));
	line_buffer = ft_strdup(read_buffer);
	linebreak_position = ft_strchr(read_buffer, '\n');
	if (linebreak_position == NULL)
		return (line_buffer);
	*found_linebreak = true;
	line_buffer = ft_strjoin_and_free(line_buffer, read_buffer);
	if (line_buffer == NULL)
		return (NULL);
	*(ft_strchr(line_buffer, '\n')) = '\0';
	ft_strcpy(read_buffer, linebreak_position + 1);
	return (line_buffer);
}

static char	*read_and_join(int fd,
							char *read_buffer,
							char *line_buffer,
							bool *found_linebreak)
{
	char		*linebreak_position;
	long int	bytes_read;

	while (*found_linebreak == false)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0 || bytes_read > SSIZE_MAX)
		{
			free(line_buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		line_buffer = ft_strjoin_and_free(line_buffer, read_buffer);
		if (line_buffer == NULL)
			return (NULL);
		if ((linebreak_position = ft_strchr(line_buffer, '\n')) != NULL)
		{
			*found_linebreak = true;
			*linebreak_position = '\0';
			ft_strcpy(read_buffer, ft_strchr(read_buffer, '\n') + 1);
		}
		if (bytes_read == 0)
			break ;
	}
	return (line_buffer);
}

int			ft_get_next_line(int fd, char **line)
{
	static char	read_buffer[BUFFER_SIZE + 1];
	char		*line_buffer;
	bool		found_linebreak;

	if (bad_params(fd, line))
		return (GNL_ERROR);
	found_linebreak = false;
	line_buffer = initialize_line_buffer(read_buffer, &found_linebreak);
	if (line_buffer == NULL)
		return (GNL_ERROR);
	line_buffer = read_and_join(fd, read_buffer, line_buffer, &found_linebreak);
	*line = line_buffer;
	if (line_buffer == NULL)
		return (GNL_ERROR);
	if (found_linebreak)
		return (GNL_FOUND_LINEBREAK);
	return (GNL_FOUND_EOF);
}
