/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:30:58 by kmira             #+#    #+#             */
/*   Updated: 2019/08/04 23:25:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "level.h"

t_normal_level	*alloc__of_level_1(void)
{
	t_normal_level *result;

	result = malloc(sizeof(*result));
	bzero(result, sizeof(*result));

	result->exit_condition = 100;

	result->screen = malloc(sizeof(*result->screen));
	result->screen->window = init_setup();

	result->sprites = malloc(sizeof(*(result->sprites)) * (100));

	result->player1.model.sprite_frame = malloc(sizeof(*(result->player1.model.sprite_frame)));

	result->player1.model.sprite_frame[0] = spaceship_sprite();

	result->player1.x = 5;
	result->player1.y = 5;

	result->sprites[0].sprite = result->player1.model.sprite_frame[0];
	result->sprites[0].sprite_attribute = spaceship_attributes();
	result->sprites[0].screen_x = result->player1.x;
	result->sprites[0].screen_y = result->player1.y;

	result->sprites[1].sprite = enemy01_sprite();
	result->sprites[1].sprite_attribute = enemy01_attributes();
	result->sprites[1].screen_x = 20;
	result->sprites[1].screen_y = 20;

	result->sprites[2].sprite = result->sprites[1].sprite;
	result->sprites[2].sprite_attribute = result->sprites[1].sprite_attribute;
	result->sprites[2].screen_x = 30;
	result->sprites[2].screen_y = 10;

	result->sprites[3].sprite = result->sprites[1].sprite;
	result->sprites[3].sprite_attribute = result->sprites[1].sprite_attribute;
	result->sprites[3].screen_x = 50;
	result->sprites[3].screen_y = 15;

	result->sprites[4] = (t_sprite){NULL, NULL, -1, -1};

	return (result);
}

void			update_of_level_1(t_normal_level *level_1_cont)
{
	char	in_char;

	in_char = wgetch(level_1_cont->screen->window);
	if (in_char == 'w')
		level_1_cont->sprites[0].screen_y = level_1_cont->sprites[0].screen_y - 1;
	if (in_char == 's')
		level_1_cont->sprites[0].screen_y = level_1_cont->sprites[0].screen_y + 1;
	if (in_char == 'a')
		level_1_cont->sprites[0].screen_x = level_1_cont->sprites[0].screen_x - 1;
	if (in_char == 'd')
		level_1_cont->sprites[0].screen_x = level_1_cont->sprites[0].screen_x + 1;

	level_1_cont->sprites[1].screen_x = level_1_cont->sprites[1].screen_x - 1;
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

	char in_char = wgetch(level_1_cont->screen->window);
}

int				main(void)
{
	int scene;

	scene = 0;
	enter_level_1(&scene);
	return (1);
}
