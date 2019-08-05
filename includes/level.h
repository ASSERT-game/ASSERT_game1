/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:34:29 by kmira             #+#    #+#             */
/*   Updated: 2019/08/04 22:02:52 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

# include "game_structs.h"

typedef struct	s_normal_level
{
	struct
	{
		int at;
		int destination;
	} scenes;
	t_char_map		map;
	t_screen		*screen;
	int exit_condition;

	t_sprite			*sprites;

	t_spaceship		player1;

}				t_normal_level;

int				break__of_normal_level(t_normal_level *level_1_cont);
void			listen_of_normal_level(t_normal_level *level_cont);

#endif
