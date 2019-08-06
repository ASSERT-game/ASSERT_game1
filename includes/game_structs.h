/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:29:40 by kmira             #+#    #+#             */
/*   Updated: 2019/08/05 16:16:39 by kmira            ###   ########.fr       */
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

typedef char keymask;

enum	e_keyFlags
{
    FLAG_MOVE_UP    = 0b000001,
    FLAG_MOVE_DOWN  = 0b000010,
    FLAG_MOVE_LEFT  = 0b000100,
    FLAG_MOVE_RIGHT = 0b001000,
	FLAG_FIRE       = 0b010000,
	FLAG_SPECIAL    = 0b100000,
    FLAG_NULL       = 0b000000
};


typedef struct s_game_input
{
	keymask		keys_pressed;
}				t_game_input;

#endif
