/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:30:58 by kmira             #+#    #+#             */
/*   Updated: 2019/08/05 22:21:16 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "level.h"

#define SPRITE_COUNT_LEVEL_1 200

t_normal_level	*alloc__of_level_1(void)
{
	t_normal_level *result;

	result = malloc(sizeof(*result));
	bzero(result, sizeof(*result));

	result->exit_condition = 100000000;

	result->screen = malloc(sizeof(*result->screen));
	result->screen->window = init_setup();

	result->sprites = malloc(sizeof(*(result->sprites)) * (SPRITE_COUNT_LEVEL_1));
	bzero(result->sprites, sizeof(*(result->sprites)) * (SPRITE_COUNT_LEVEL_1));

	result->player.sprites.sprite = spaceship02_sprite();
	result->player.sprites.sprite_attribute = spaceship02_attributes();
	result->player.bullet.spawn = spawn_bullet02;
	result->player.x = 5;
	result->player.y = 5;

	result->sprites[0].sprite = result->player.sprites.sprite;
	result->sprites[0].sprite_attribute = result->player.sprites.sprite_attribute;
	result->sprites[0].screen_x = result->player.x;
	result->sprites[0].screen_y = result->player.y;

	result->sprites[1].sprite = enemy01_sprite();
	result->sprites[1].sprite_attribute = enemy01_attributes();
	result->sprites[1].screen_x = 20;
	result->sprites[1].screen_y = 20;

	result->sprites[2].sprite = enemy01_sprite();
	result->sprites[2].sprite_attribute = enemy01_attributes();
	result->sprites[2].screen_x = 30;
	result->sprites[2].screen_y = 10;

	result->sprites[3].sprite = enemy01_sprite();
	result->sprites[3].sprite_attribute = enemy01_attributes();
	result->sprites[3].screen_x = 50;
	result->sprites[3].screen_y = 15;

	result->sprites[4] = NULL_SPRITE;
	return (result);
}

void			update_of_level_1(t_normal_level *level_1_cont)
{
	t_sprite	*player;

	WINDOW *window;
	window = level_1_cont->screen->window;
	player = &(level_1_cont->sprites[0]);

	keyupdate_of_player_on_normal_level(&level_1_cont->input, &level_1_cont->player, level_1_cont->sprites);

	level_1_cont->sprites[0].sprite = level_1_cont->player.sprites.sprite;
	level_1_cont->sprites[0].sprite_attribute = level_1_cont->player.sprites.sprite_attribute;
	level_1_cont->sprites[0].screen_x = level_1_cont->player.x;
	level_1_cont->sprites[0].screen_y = level_1_cont->player.y;

	int j = 0;
	while (level_1_cont->sprites[j].sprite != NULL)
	{
		if (level_1_cont->sprites[j].sprite[0] == '>' || level_1_cont->sprites[j].sprite[0] == '*')
		{
			level_1_cont->sprites[j].screen_x = level_1_cont->sprites[j].screen_x + 1;
			if (level_1_cont->sprites[j].screen_x > GAME_COLS)
				level_1_cont->sprites[j] = EMPTY_SPRITE;
		}
		else if (level_1_cont->sprites[j].sprite[0] == '*')
		{
			level_1_cont->sprites[j].screen_x = level_1_cont->sprites[j].screen_x + 1;
			if (level_1_cont->sprites[j].screen_x > GAME_COLS - 40)
				level_1_cont->sprites[j] = EMPTY_SPRITE;
		}
		j++;
	}
	clean_up_empty_sprites(level_1_cont->sprites);
}

void			clean__of_level_1(t_normal_level *level_1_cont)
{
	(void)level_1_cont;
	return ;
}

void			enter_level_1(int *scene)
{
	SCENE_LOOP(normal_level, level_1);
	(void)scene;
}

