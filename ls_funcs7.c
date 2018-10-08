/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_funcs7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:33:03 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 12:02:10 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	num_blks_la(char *av, char *join)
{
	int				i;
	DIR				*dr;
	struct dirent	*de;
	struct stat		blk;
	char			*store;

	i = 0;
	dr = opendir(av);
	if (f_d_check(av) == 2 && g_ll == 1)
	{
		while ((de = readdir(dr)) != NULL)
		{
			join = ft_strjoin(av, "/");
			store = ft_strjoin(join, de->d_name);
			stat(store, &blk);
			i += blk.st_blocks;
			ft_strdel(&store);
			ft_strdel(&join);
		}
		ft_printf("total %i\n", i);
		closedir(dr);
	}
	return ;
}

char	*uid_to_name(uid_t uid)
{
	struct passwd	*pw;
	static char		numstr[10];

	if ((pw = getpwuid(uid)) == NULL)
		return (numstr);
	else
		return (pw->pw_name);
}

char	*gid_to_name(gid_t gid)
{
	struct group	*grp;
	static char		numstr[10];

	if ((grp = getgrgid(gid)) == NULL)
		return (numstr);
	else
		return (grp->gr_name);
}

void	mode_to_letters(int mode, char *str)
{
	strcpy(str, "----------");
	if (S_ISLNK(mode))
		str[0] = 'l';
	else if (S_ISCHR(mode))
		str[0] = 'c';
	else if (S_ISBLK(mode))
		str[0] = 'b';
	else if (S_ISDIR(mode))
		str[0] = 'd';
	if (mode & S_IRUSR)
		str[1] = 'r';
	if (mode & S_IWUSR)
		str[2] = 'w';
	if (mode & S_IXUSR)
		str[3] = 'x';
	mode_to_letters_2(mode, str);
}

void	mode_to_letters_2(int mode, char *str)
{
	if (mode & S_IRGRP)
		str[4] = 'r';
	if (mode & S_IWGRP)
		str[5] = 'w';
	if (mode & S_IXGRP)
		str[6] = 'x';
	if (mode & S_IROTH)
		str[7] = 'r';
	if (mode & S_IWOTH)
		str[8] = 'w';
	if (mode & S_IXOTH)
		str[9] = 'x';
}
