/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 05:47:47 by kmira             #+#    #+#             */
/*   Updated: 2019/08/03 00:27:42 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include "default.h"

typedef struct		s_main_menu
{
	int				exit_condition;
	struct
	{
		int			at;
		int			destination;
	}				scenes;
	t_char_map		map;
	t_screen		*screen;
}					t_main_menu;

int					_break_of_main_menu(struct s_main_menu *main_menu_cont);
t_main_menu			*_alloc_of_main_menu(void);
void				listen_of_main_menu(t_main_menu *main_menu_cont);
void				update_of_main_menu(t_main_menu *main_menu_cont);
void				_clean_of_main_menu(void);

#endif
