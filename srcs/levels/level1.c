/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:30:58 by kmira             #+#    #+#             */
/*   Updated: 2019/08/02 07:46:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "level.h"

int					break__of_level(t_level *level_1_cont)
{
	if (level_1_cont->exit_condition == 0)
		return (0);
	else
		return (1);
}

t_level			alloc__of_level_1(void)
{
	struct s_level result;

	bzero(&result, sizeof(result));
	result.exit_condition = 4;
	return (result);
}

void				listen_of_level(t_level *level_1_cont)
{
	return ;
}

void				update_of_level_1(t_level *level_1_cont)
{
	level_1_cont->exit_condition--;
	return ;
}

void				render_of_level_1(void)
{
	printf("This is your frame\n");
	return ;
}

void				clean__of_level_1(void)
{
	printf("Cleaned up level_1\n");
	return ;
}

void	enter_level_1(int *scene)
{
	SCENE_LOOP(level, level_1);
}

int		main(void)
{
	int scene;

	enter_level_1(&scene);
}
