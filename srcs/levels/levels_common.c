/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:54:24 by kmira             #+#    #+#             */
/*   Updated: 2019/08/06 15:04:07 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

#define KEY_ITER 1

int		break__of_normal_level(t_normal_level *level_cont)
{
	int result;

	result = 1;
	if (level_cont->player.x > GAME_COLS || level_cont->player.x < -1)
		result = 0;
	if (level_cont->player.y > GAME_ROWS || level_cont->player.y < -1)
		result = 0;
	if (level_cont->player.hitpoints <= ZERO_HP)
		result = 0;
	if (level_cont->exit_condition == 0)
		result = 0;

	if (result == 0)
		level_cont->scenes.destination = EXIT_SCENE;
	return (result);
}

void	keyupdate_of_player_on_normal_level(t_game_input *input, t_spaceship *spaceship, t_sprite *sprites)
{
	if (input->keys_pressed & FLAG_MOVE_UP)
		spaceship->y = spaceship->y - 1;
	if (input->keys_pressed & FLAG_MOVE_DOWN)
		spaceship->y = spaceship->y + 1;
	if (input->keys_pressed & FLAG_MOVE_LEFT)
		spaceship->x = spaceship->x - 2;
	if (input->keys_pressed & FLAG_MOVE_RIGHT)
		spaceship->x = spaceship->x + 2;
	if (input->keys_pressed & FLAG_FIRE)
		spaceship->bullet.spawn(sprites, spaceship->y, spaceship->x);
	if (input->keys_pressed & FLAG_SPECIAL)
		use_special(spaceship);
	if (input->keys_pressed & FLAG_HEAL)
		use_heal(spaceship);
}

void	listen_of_normal_level(WINDOW *window, t_game_input *input)
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

void	clean_up_empty_sprites(t_sprite *sprites)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (sprites[j].sprite != NULL)
		j++;
	while (sprites[i].sprite != NULL)
	{
		if (sprites[i].sprite == (char *)1)
		{
			while (&sprites[i] < &sprites[j] &&
			(sprites[j].sprite == NULL || sprites[j].sprite == (char *)1))
				j--;
			sprites[i] = sprites[j];
			sprites[j] = NULL_SPRITE;
		}
		i++;
	}
}
