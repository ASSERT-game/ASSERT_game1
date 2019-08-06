/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:34:29 by kmira             #+#    #+#             */
/*   Updated: 2019/08/05 19:13:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

# include "game_structs.h"

typedef struct	s_normal_level
{
	struct
	{
		int at;
		int destination;
	} scenes;

	t_game_input	input;

	t_char_map		map;
	t_screen		*screen;

	int exit_condition;

	t_sprite			*sprites;

	t_spaceship		player;

}				t_normal_level;

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: levels_common.c
*/

int				break__of_normal_level(t_normal_level *level_1_cont);
void			listen_of_normal_level(WINDOW *window, t_game_input *input);
void			keyupdate_of_player_on_normal_level(t_game_input *input, t_spaceship *spaceship, t_sprite *sprites);
void			clean_up_empty_sprites(t_sprite *sprites);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: weapons.c
*/

void			spawn_bullet01(t_sprite *sprites, int row, int col);
void			spawn_bullet02(t_sprite *sprites, int row, int col);
void			use_special(t_spaceship *player);

#endif
