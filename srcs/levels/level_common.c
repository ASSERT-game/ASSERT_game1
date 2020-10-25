/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:54:24 by kmira             #+#    #+#             */
/*   Updated: 2020/10/24 20:12:06 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

#define KEY_ITER 30

int			break__of_normal_level(t_normal_level *level_cont)
{
	int result;

	result = 1;
	if (level_cont->player.e.x > GAME_COLS || level_cont->player.e.x < -1)
		result = 0;
	if (level_cont->player.e.y > GAME_ROWS || level_cont->player.e.y < -1)
		result = 0;
	if (level_cont->player.class.hitpoints <= ZERO_HP)
	{
		printf("Player died\n");
		result = 0;
	}
	if (level_cont->exit_condition == 0)
	{
		result = 0;
		printf("Some exit?\n");
	}
	if (result == 0)
		level_cont->scenes.destination = EXIT_SCENE;
	return (result);
}

void		listen_of_normal_level(WINDOW *window, t_game_input *input)
{
	int				j;
	char			in_char;

	input->keys_pressed = 0;
	j = 0;
	while (j < KEY_ITER)
	{
		in_char = wgetch(window);
		if (in_char == 'w')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_UP;
		if (in_char == 's')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_DOWN;
		if (in_char == 'a')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_LEFT;
		if (in_char == 'd')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_RIGHT;
		if (in_char == ' ')
			input->keys_pressed = input->keys_pressed | FLAG_FIRE;
		if (in_char == 't')
			input->keys_pressed = input->keys_pressed | FLAG_SPECIAL;
		if (in_char == 'h')
			input->keys_pressed = input->keys_pressed | FLAG_HEAL;
		j++;
	}
	return ;
}

void		clean_up_empty_sprites(t_pawn *entities, t_sprite *sprites)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (entities[j].type_entity.sprites.sprite != NULL)
		j++;
	while (entities[i].type_entity.sprites.sprite != NULL)
	{
		if (entities[i].type_entity.sprites.sprite == (char *)1)
		{
			while (&entities[i] < &entities[j] &&
			(entities[j].type_entity.sprites.sprite == NULL
			|| entities[j].type_entity.sprites.sprite == (char *)1))
				j--;
			entities[i] = entities[j];
			sprites[i] = entities[i].type_entity.sprites;
			entities[j].type_entity.sprites = NULL_SPRITE;
			sprites[j] = NULL_SPRITE;
		}
		i++;
	}
}

void		display_hp(t_normal_level *level_cont)
{
	int i;
	int hp;

	i = 0;
	while (level_cont->entities[i].type_entity.sprites.sprite != NULL)
		i++;
	hp = (level_cont->entities[0].type_spaceship.class.hitpoints) / 20;
	if (hp < 0)
		hp = 0;
	level_cont->sprites[i].sprite = hitpoints_sprite();
	level_cont->sprites[i].sprite_attribute = hitpoints_attribute();
	memset(level_cont->sprites[i].sprite, '/', hp);
	level_cont->sprites[i].sprite[hp] = '\0';
	level_cont->sprites[i].screen_x = level_cont->entities[0].type_entity.x;
	level_cont->sprites[i].screen_y = level_cont->entities[0].type_entity.y - 2;
	level_cont->sprites[i + 1] = NULL_SPRITE;
}

#include <fcntl.h>

void	make_map(t_normal_level *level_cont)
{
	int		j;
	int		k;
	int		e_row;
	int		e_col;
	int		row;
	int		col;
	t_sprite sprite_frame;

	j = 0;
	while (j < (GAME_ROWS) * GAME_COLS + 1)
	{
		level_cont->map.frame[j] = (void *)1;
		j++;
	}
	j = 0;
	while (level_cont->entities[j].type_entity.sprites.sprite != NULL)
	{
		k = 0;
		e_row = level_cont->entities[j].type_entity.y;
		e_col = level_cont->entities[j].type_entity.x;
		sprite_frame = level_cont->entities[j].type_entity.sprites;
		row = 0;
		col = 0;
		while (sprite_frame.sprite[k] != '\0')
		{
			if (sprite_frame.sprite[k] == ' ')
				col = col + 1;
			else if (sprite_frame.sprite[k] == '\n')
			{
				row = row + 1;
				col = 0;
			}
			else
			{
				if (e_row + row < GAME_ROWS && e_col + col < GAME_COLS)
					level_cont->map.frame[(e_row + row) * GAME_COLS + e_col + col] = &level_cont->entities[j];
				col = col + 1;
			}
			k++;
		}
		j++;
	}
	level_cont->map.frame[GAME_ROWS * GAME_COLS] = 0;

	j = 0;
	memset(level_cont->map.g_frame, '.', sizeof(level_cont->map.g_frame));
	while (level_cont->entities[j].type_entity.sprites.sprite != NULL)
	{
		k = 0;
		e_row = level_cont->entities[j].type_entity.y - 1;
		e_col = level_cont->entities[j].type_entity.x - 1;
		sprite_frame = level_cont->entities[j].type_entity.sprites;
		row = 0;
		col = 0;
		while (sprite_frame.sprite[k] != '\0')
		{
			if (sprite_frame.sprite[k] == ' ')
				col = col + 1;
			else if (sprite_frame.sprite[k] == '\n')
			{
				row = row + 1;
				col = 0;
			}
			else
			{
				if (e_row + row < GAME_ROWS && e_col + col < GAME_COLS)
				{
					if (level_cont->entities[j].type_entity.type[0] == 'B')
						level_cont->map.g_frame[(e_row + row) * GAME_COLS + e_col + col] = 'B';
					else if (level_cont->entities[j].type_entity.type[0] == 'P')
						level_cont->map.g_frame[(e_row + row) * GAME_COLS + e_col + col] = 'P';
					else if (level_cont->entities[j].type_entity.type[0] == 'F')
						level_cont->map.g_frame[(e_row + row) * GAME_COLS + e_col + col] = 'F';
					else if (level_cont->entities[j].type_entity.type[0] == 'e')
						level_cont->map.g_frame[(e_row + row) * GAME_COLS + e_col + col] = 'E';
				}
				col = col + 1;
			}
			k++;
		}
		j++;
	}
	level_cont->map.g_frame[GAME_ROWS * GAME_COLS] = 0;
	if (level_cont->game_tick)
	{
		int h;
		h = 0;
		int fd = open("./txt", 2);
		printf("%d\n", fd);
		while (h < GAME_ROWS)
		{
			write(fd, &level_cont->map.g_frame[h * GAME_COLS], GAME_COLS);
			write(fd, "\n", 1);
			h++;
		}
	// 	exit(1);
	}
	(void)level_cont;
}
