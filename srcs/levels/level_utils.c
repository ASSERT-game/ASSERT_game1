/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:41:32 by kmira             #+#    #+#             */
/*   Updated: 2019/08/12 16:58:11 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "default.h"

int			rand_min_max(int min, int max)
{
	int a;

	if (min >= max)
		return (0);
	a = (rand() % (max + 1 - min)) + min;
	return (a);
}

void		set_sprite(t_sprite *sprite, t_pawn *entity)
{
	*sprite = entity->type_entity.sprites;
	sprite->screen_x = entity->type_entity.x;
	sprite->screen_y = entity->type_entity.y;
}
