/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:29:40 by kmira             #+#    #+#             */
/*   Updated: 2019/08/04 22:02:36 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCTS_H
# define GAME_STRUCTS_H

# include <ncurses.h>

# include "default.h"

typedef struct	s_char_map
{
	char	*line;
	char	frame[WIN_ROWS * WIN_COLS + 1];

}				t_char_map;

typedef struct	s_screen
{
	WINDOW	*window;
}				t_screen;

typedef struct	s_sprite
{
	char		*sprite;
	int			*sprite_attribute;
	int			screen_x;
	int			screen_y;
}				t_sprite;

typedef struct	s_model
{
	void		**hitbox_frame;
	void		**sprite_frame;
}				t_model;

typedef	struct	s_spaceship
{
	t_model		model;
	int			x;
	int			y;
}				t_spaceship;

#endif
