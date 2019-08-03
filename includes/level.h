/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:34:29 by kmira             #+#    #+#             */
/*   Updated: 2019/08/02 07:56:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

typedef struct	s_normal_level
{
	struct
	{
		int at;
		int destination;
	} scenes;
	int exit_condition;
}		t_normal_level;

int				break__of_level(t_normal_level *level_1_cont);
void			listen_of_level(t_normal_level *level_cont);

#endif
