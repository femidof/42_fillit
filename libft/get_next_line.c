/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:43:21 by vinguyen          #+#    #+#             */
/*   Updated: 2019/11/21 19:09:07 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		read_new_line(char **fds, int fd, char **line)
{
	char	*tmp;
	char	*nwl_loc;

	if ((nwl_loc = ft_strchr(fds[fd], '\n')))
	{
		tmp = fds[fd];
		*line = ft_strsub(fds[fd], 0, nwl_loc - fds[fd]);
		fds[fd] = ft_strsub(fds[fd],
			ft_strlen(*line) + 1, ft_strlen(nwl_loc + 1));
		free(tmp);
		return (1);
	}
	return (0);
}

void	string_join_free(char **fds, int fd, char *buf)
{
	char	*tmp;

	tmp = fds[fd];
	fds[fd] = ft_strjoin(fds[fd], buf);
	free(tmp);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*fds[MAX_FD];
	ssize_t			bytes_rd;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !line || fd > MAX_FD ||
			BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	fds[fd] = (fds[fd] == NULL) ? ft_strnew(1) : fds[fd];
	if (read_new_line(fds, fd, line) == 1)
		return (1);
	while ((bytes_rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes_rd] = '\0';
		string_join_free(fds, fd, buf);
		if (read_new_line(fds, fd, line) == 1)
			return (1);
	}
	if (bytes_rd == 0 && (fds[fd][0] == '\0'))
		return (0);
	tmp = fds[fd];
	*line = ft_strdup(fds[fd]);
	fds[fd] = ft_strnew(1);
	free(tmp);
	return (1);
}
