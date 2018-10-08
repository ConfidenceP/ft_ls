/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:40:57 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 10:48:01 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		g_ca = 0;
int		g_cr = 0;
int		g_la = 0;
int		g_ll = 0;
int		g_lr = 0;
int		g_ol = 0;
int		g_lt = 0;
int		g_check = 0;

void	show_file_info(char *filename, struct stat *info_p)
{
	char			modestr[11];
	char			*buf_2;

	mode_to_letters(info_p->st_mode, modestr);
	buf_2 = ft_strsub(4 + ctime(&info_p->st_mtime), 0, 12);
	ft_printf("%s\t", modestr);
	ft_printf("%u\t", (unsigned int)info_p->st_nlink);
	ft_printf("%s\t", uid_to_name(info_p->st_uid));
	ft_printf("%s\t", gid_to_name(info_p->st_gid));
	ft_printf("%u\t", (unsigned int)info_p->st_size);
	ft_printf("%s\t", buf_2);
	free(buf_2);
	if (ft_strchr(filename, '/'))
		(S_ISLNK(info_p->st_mode)) ? ft_printf("%s", 1 + ft_strstr(filename,
					"/")) : ft_printf("%s\n", 1 + ft_strstr(filename, "/"));
	else
		(S_ISLNK(info_p->st_mode)) ? ft_printf("%s", filename)
			: ft_printf("%s\n", filename);
	check_lnk(filename, info_p);
}

void	check_lnk(char *filename, struct stat *info_p)
{
	char			*buf;
	ssize_t			ret;

	if (S_ISLNK(info_p->st_mode))
	{
		buf = ft_strnew(BUFF_SIZE);
		ret = readlink(filename, buf, BUFF_SIZE);
		ft_strdel(&buf);
		buf = NULL;
		buf = ft_strnew(ret);
		ret = readlink(filename, buf, ret);
		ft_printf(" -> %s\n", buf);
		ft_strdel(&buf);
	}
}
