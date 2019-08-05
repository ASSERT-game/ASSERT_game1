/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:30:58 by kmira             #+#    #+#             */
/*   Updated: 2019/08/05 11:46:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "level.h"

#define SPRITE_COUNT_LEVEL_1 200

void			spawn_bullet01(t_sprite *sprites, int row, int col)
{
	int i;

	i = 0;
	while (sprites[i].sprite != NULL)
		i++;
	sprites[i].sprite = bullet01_sprite();
	sprites[i].sprite_attribute = bullet01_attribute();
	sprites[i].screen_x = col + 2;
	sprites[i].screen_y = row;
	while (sprites[i].sprite != NULL)
		i++;
	sprites[i].sprite = bullet01_sprite();
	sprites[i].sprite_attribute = bullet01_attribute();
	sprites[i].screen_x = col + 2;
	sprites[i].screen_y = row + 4;
	return ;
}

void			spawn_bullet02(t_sprite *sprites, int row, int col)
{
	int i;

	i = 0;
	while (sprites[i].sprite != NULL)
		i++;
	sprites[i].sprite = bullet02_sprite();
	sprites[i].sprite_attribute = bullet02_attribute();
	sprites[i].screen_x = col + 2;
	sprites[i].screen_y = row;
	while (sprites[i].sprite != NULL)
		i++;
	sprites[i].sprite = bullet02_sprite();
	sprites[i].sprite_attribute = bullet02_attribute();
	sprites[i].screen_x = col + 2;
	sprites[i].screen_y = row + 4;
	return ;
}

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

	result->player1.sprites.sprite = spaceship02_sprite();
	result->player1.sprites.sprite_attribute = spaceship02_attributes();
	result->player1.bullet.spawn = spawn_bullet02;
	result->player1.x = 5;
	result->player1.y = 5;

	result->sprites[0].sprite = result->player1.sprites.sprite;
	result->sprites[0].sprite_attribute = result->player1.sprites.sprite_attribute;
	result->sprites[0].screen_x = result->player1.x;
	result->sprites[0].screen_y = result->player1.y;

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

	result->sprites[4] = (t_sprite){NULL, NULL, -1, -1};
	return (result);
}

void			update_of_level_1(t_normal_level *level_1_cont)
{
	char		in_char;
	t_sprite	*player;

	WINDOW *window;
	window = level_1_cont->screen->window;
	player = &(level_1_cont->sprites[0]);
	in_char = wgetch(window);
	if (in_char == 'w')
		player->screen_y = player->screen_y - 1;
	if (in_char == 's')
		player->screen_y = player->screen_y + 1;
	if (in_char == 'a')
		player->screen_x = player->screen_x - 2;
	if (in_char == 'd')
		player->screen_x = player->screen_x + 2;
	if (in_char == ' ')
		level_1_cont->player1.bullet.spawn(level_1_cont->sprites, player->screen_y, player->screen_x);
	if (in_char == 't')
	{
		if (level_1_cont->player1.sprites.sprite == spaceship01_sprite())
		{
			level_1_cont->player1.sprites.sprite = spaceship02_sprite();
			level_1_cont->player1.sprites.sprite_attribute = spaceship02_attributes();

			level_1_cont->sprites[0].sprite = spaceship02_sprite();
			level_1_cont->sprites[0].sprite_attribute = spaceship02_attributes();

			level_1_cont->player1.bullet.spawn = spawn_bullet02;
		}
		else
		{
			level_1_cont->player1.sprites.sprite = spaceship01_sprite();
			level_1_cont->player1.sprites.sprite_attribute = spaceship01_attributes();

			level_1_cont->sprites[0].sprite = spaceship01_sprite();
			level_1_cont->sprites[0].sprite_attribute = spaceship01_attributes();

			level_1_cont->player1.bullet.spawn = spawn_bullet01;
		}
	}

	level_1_cont->sprites[1].screen_x = level_1_cont->sprites[1].screen_x - 1;

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

	int	i;
	i = 0;
	while (level_1_cont->sprites[i].sprite != NULL)
	{
		if (level_1_cont->sprites[i].sprite == (char *)1)
		{
			while (&level_1_cont->sprites[i] < &level_1_cont->sprites[j] && (level_1_cont->sprites[j].sprite == NULL || level_1_cont->sprites[j].sprite == (char *)1))
				j--;
			level_1_cont->sprites[i] = level_1_cont->sprites[j];
			level_1_cont->sprites[j] = NULL_SPRITE;
		}
		i++;
	}
	mvwaddch(level_1_cont->screen->window, 2, 2, '0');
	wrefresh(level_1_cont->screen->window);

	level_1_cont->exit_condition--;
	return ;
}

void			clean__of_level_1(void)
{
	return ;
}

void			enter_level_1(int *scene)
{
	SCENE_LOOP(normal_level, level_1);
}

int				main(void)
{
	int scene;

	scene = 0;
	enter_level_1(&scene);
	return (1);
}
