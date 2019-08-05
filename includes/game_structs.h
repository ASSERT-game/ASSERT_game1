/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:29:40 by kmira             #+#    #+#             */
/*   Updated: 2019/08/05 11:19:10 by kmira            ###   ########.fr       */
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

typedef union	u_spawn_bullet
{
	void		(*spawn)(t_sprite *sprites, int row, int col);
}				t_spawn_bullet;

typedef	struct	s_spaceship
{
	t_model			model;
	t_sprite		sprites;
	t_spawn_bullet	bullet;
	int				x;
	int				y;
}				t_spaceship;

#endif
