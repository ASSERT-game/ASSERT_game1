/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:54:24 by kmira             #+#    #+#             */
/*   Updated: 2019/08/02 08:08:51 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "level.h"

int		break__of_level(t_normal_level *level_cont)
{
	if (level_cont->exit_condition == 0)
		return (0);
	else
		return (1);
}

void	listen_of_level(t_normal_level *level_cont)
{
	return ;
}

void	render_of_level(void)
{
	printf("This is your frame\n");
	return ;
}
