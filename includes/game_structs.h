/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:29:40 by kmira             #+#    #+#             */
/*   Updated: 2019/08/12 21:23:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCTS_H
# define GAME_STRUCTS_H

# include <ncurses.h>

typedef union s_pawn t_pawn;

typedef struct	s_char_map
{
	char		*line;
	t_pawn		*frame[GAME_ROWS * GAME_COLS + 1];
	char		g_frame[GAME_ROWS * GAME_COLS + 1];

}				t_char_map;

typedef struct	s_screen
{
	WINDOW		*window;
}				t_screen;

typedef struct	s_sprite
{
	char		*sprite;
	int			*sprite_attribute;
	int			screen_x;
	int			screen_y;
}				t_sprite;

typedef char	t_keymask;

enum			e_keyflags
{
    FLAG_MOVE_UP    = 0b0000001,
    FLAG_MOVE_DOWN  = 0b0000010,
    FLAG_MOVE_LEFT  = 0b0000100,
    FLAG_MOVE_RIGHT = 0b0001000,
    FLAG_FIRE       = 0b0010000,
    FLAG_SPECIAL    = 0b0100000,
    FLAG_HEAL       = 0b1000000,
    FLAG_NULL       = 0b0000000
};

typedef struct	s_game_input
{
	t_keymask		keys_pressed;
}				t_game_input;

#endif
