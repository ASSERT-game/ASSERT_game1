/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_normal_level.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:34:29 by kmira             #+#    #+#             */
/*   Updated: 2019/08/06 13:02:35 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_NORMAL_LEVEL_H
# define SCENE_NORMAL_LEVEL_H

# include "game_structs.h"

typedef struct	s_normal_level
{
	char			*name;
	struct
	{
		int at;
		int destination;
	} scenes;

	t_game_input	input;

	t_char_map		map;
	t_screen		*screen;

	int				exit_condition;
	int				score;

	t_sprite			*sprites;

	t_spaceship		player;

}				t_normal_level;

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MACROS
*/

/*
** MAX HP is 100 but multiplied with 10 to have at least a precision of 1
**
** ZERO_HP is 9 because 10 is 1.0 HP. We can lower this to 5 or 0 to give players
** last second chances!
*/

# define MAX_HP 1000
# define ZERO_HP 9

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
void			use_heal(t_spaceship *player);

#endif
