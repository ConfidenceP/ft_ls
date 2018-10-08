/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:38:20 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 11:52:33 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define BUFF_SIZE 4096

# include "cmukwind/ft_printf.h"
# include "libft/libft.h"
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>
# include <uuid/uuid.h>

char		**rev_nsort(int j, char **av);
char		**rev_sort(char **av);
char		**sort_ls(char **av);
char		**sort_nls(int i, char **av);
char		*gid_to_name(gid_t gid);
char		*uid_to_name(uid_t uid);
char		**sort_time(char **av);

int			block_cnt(int i, struct dirent *de, char *join, char *av);
int			check_name(char *av);
int			f_d_check(char *av);
int			flag_c(char c);
int			main(int ac, char **av);

void		arg_check_2(int i, char **av);
void		funcs_op_2(char *av);
void		ls_only_2(char *av);
void		check_arg(char *av);
void		dir_check(int i, char **av);
void		dostat(char *av);
void		dotstat(char *filename);
void		file_check(int i, char **av);
void		file_dir_check(int i, char **av);
void		funcs_op(char *av);
void		init_var(char *str);
void		lr_only(char *av);
void		ls_ar(char *av);
void		ls_arl(char *av);
void		ls_cr(char *av);
void		ls_la(char *av);
void		ls_ll(char *av);
void		ls_only(char *av);
void		ls_print(char **av);
void		mode_to_letters(int mode, char *str);
void		num_blks(char *av, char *join);
void		num_blks_la(char *av, char *join);
void		print_arr(char **arra);
void		show_file_info(char *filename, struct stat *info_p);
void		check_lnk(char *filename, struct stat *info_p);
void		ls_acr(char *av);
void		ls_acr_2(struct dirent *de, DIR *dr, char *av);
void		ls_alcr(char *av);
void		ls_alcr_2(struct dirent *de, DIR *dr, char *av);
void		ls_arcr(char *av);
void		ls_arcr_2(struct dirent *de, DIR *dr, char *av);
void		ls_arl_2(int i, struct dirent *de, DIR *dr, char *av);
void		ls_cr_2(struct dirent *de, DIR *dr, char *av);
void		ls_la_2(struct dirent *de, DIR *dr);
void		ls_ll_2(struct dirent *de, DIR *dr, char *av);
void		ls_lla_2(int i, struct dirent *de, DIR *dr, char *av);
void		ls_rcr(char *av);
void		ls_rcr_2(struct dirent *de, DIR *dr, char *av);
void		ls_rl(char *av);
void		ls_rl_2(int i, struct dirent *de, DIR *dr, char *av);
void		ls_ar_2(struct dirent *de, DIR *dr);
void		ls_ca(char *av);
void		ls_lla(char *av);
void		mode_to_letters_2(int mode, char *str);

extern int	g_ca;
extern int	g_check;
extern int	g_cr;
extern int	g_la;
extern int	g_ll;
extern int	g_lr;
extern int	g_ol;
extern int	g_lt;

#endif
