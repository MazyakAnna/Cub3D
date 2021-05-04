/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:21:27 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 03:21:16 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
** returns index of the first occurance of char (c) in str (s);
** retrurns (-1) if there is no (c) in (s) or if (s) is NULL;
*/

int	strchr_index(char *s, int c)
{
	int	ret;

	ret = 0;
	if (s)
	{
		while (*s)
		{
			if (*s == c)
				return (ret);
			ret++;
			s++;
		}
	}
	return (-1);
}

/*
** if there is no "/n" in (mem):
** copies with strdup (mem) to (*line) and makes (mem) an empty str.
** if there in "/n" in (mem):
** copies from (mem) to (*line) up to the first "/n"
** and deletes this part from (mem) including "/n"
*/

static char	*ft_mem2line(char **line, char *mem, int eol)
{
	char	*ret;

	if (eol == -1)
	{
		*line = ft_strdup(mem);
		ret = NULL;
	}
	else
	{
		*line = ft_strndup(mem, eol);
		ret = ft_strdup(&(mem[eol + 1]));
	}
	free(mem);
	return (ret);
}

/*
** copies (buf) to (mem) if (mem) is NULL
** or joins (buf) to (mem) is there is smth in (mem)
*/

static char	*ft_buf2mem(char *buf, char *mem)
{
	char	*res;

	if (mem)
	{
		res = ft_strjoin(mem, buf);
		free(mem);
	}
	else
		res = ft_strdup(buf);
	return (res);
}

/*
** _______________________________________________________________
** buf - just holds data from the last called (read) function;
** mem - static var, holds everything from last (buf)s until EOL is found;
** check - returns the result of (read) function;
** eol_index - index of the end of line ("/n") in mem;
** Behaviour:
** if there is already (eol = "/n") in (mem) starts ft_mem2line
** if there is no "/n" in m(mem)
** reads BUFFER_SIZE and adds it to (mem) till the EOF or EOL
** _______________________________________________________________
*/

int	get_next_line(int fd, char **line)
{
	static char	*mem;
	int			check;
	int			eol_indx;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	eol_indx = strchr_index(mem, '\n');
	check = 1;
	while (eol_indx == -1 && check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		buf[check] = '\0';
		mem = ft_buf2mem(buf, mem);
		eol_indx = strchr_index(mem, '\n');
	}
	mem = ft_mem2line(line, mem, eol_indx);
	if (check > 0)
		check = 1;
	return (check);
}
