/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:34:29 by kmira             #+#    #+#             */
/*   Updated: 2019/08/02 07:36:18 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

typedef struct	s_level
{
	struct
	{
		int at;
		int destination;
	} scenes;
	int exit_condition;
}		t_level;

#endif
