/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:30:58 by kmira             #+#    #+#             */
/*   Updated: 2019/08/02 22:00:04 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "level.h"

t_normal_level	alloc__of_level_1(void)
{
	t_normal_level result;

	bzero(&result, sizeof(result));
	result.exit_condition = 4;
	return (result);
}

void			update_of_level_1(t_normal_level *level_1_cont)
{
	level_1_cont->exit_condition--;
	return ;
}

void			clean__of_level_1(void)
{
	printf("Cleaned up level_1\n");
	return ;
}

void			enter_level_1(int *scene)
{
	SCENE_LOOP(normal_level, level_1);
}

int				main(void)
{
	int scene;

	enter_level_1(&scene);
}
