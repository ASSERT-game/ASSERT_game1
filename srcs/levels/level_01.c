/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:30:58 by kmira             #+#    #+#             */
/*   Updated: 2020/10/24 21:11:42 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

#define SPRITE_COUNT_LEVEL_1 500

t_normal_level	*alloc__of_level_1(void)
{
	t_normal_level *result;

	result = malloc(sizeof(*result));
	bzero(result, sizeof(*result));

	result->exit_condition = 1;
	result->game_tick = 0;
	result->score = 0;

	result->screen = malloc(sizeof(*result->screen));
	result->screen->window = init_setup();

	result->name = "Level One";

	result->sprites = malloc(sizeof(*(result->sprites)) * (SPRITE_COUNT_LEVEL_1));
	bzero(result->sprites, sizeof(*(result->sprites)) * (SPRITE_COUNT_LEVEL_1));

	result->entities = malloc(sizeof(*(result->entities)) * (SPRITE_COUNT_LEVEL_1));
	bzero(result->entities, sizeof(*(result->entities)) * (SPRITE_COUNT_LEVEL_1));

	result->entities[0].type_spaceship = spawn_player(1);
	result->player = result->entities[0].type_spaceship;
	make_map(result);
	return (result);
}

void			update_of_level_1(t_normal_level *level_1_cont)
{
	int	i;

	i = 0;
	bzero(level_1_cont->sprites, sizeof(*(level_1_cont->sprites)) * (SPRITE_COUNT_LEVEL_1));
	while (level_1_cont->entities[i].type_entity.sprites.sprite != NULL)
	{
		level_1_cont->entities[i].type_entity.update(&level_1_cont->entities[i], level_1_cont);
		set_sprite(&level_1_cont->sprites[i], &level_1_cont->entities[i]);
		i++;
	}
	if (level_1_cont->game_tick % 3 == 0 && rand_min_max(0, 3) == 1)
	{
		level_1_cont->entities[i].type_enemy01 = spawn_enemy01();
		set_sprite(&level_1_cont->sprites[i], &level_1_cont->entities[i]);
		i++;
	}
	clean_up_empty_sprites(level_1_cont->entities, level_1_cont->sprites);
	make_map(level_1_cont);
	display_hp(level_1_cont);

	level_1_cont->game_tick = level_1_cont->game_tick + 1;
}

void			clean__of_level_1(t_normal_level *level_1_cont)
{
	(void)level_1_cont;
	return ;
}

void			enter_level_1(int *scene)
{
	// INIT(normal_level, level_1);
	//  RENDER(normal_level, level_1);
	//  while (IN(normal_level, level_1)) { GET_USER_INPUT(normal_level, level_1);
	//  UPDATE_STATE(level_1);
	//  RENDER(normal_level, level_1);
	//  usleep(GAME_TICK);
	//  } CLEAN_UP(normal_level, level_1);
	//  TRANSITION(level_1);

	SCENE_LOOP(normal_level, level_1);
	(void)scene;
}
