/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:10:47 by kmira             #+#    #+#             */
/*   Updated: 2019/08/05 00:55:12 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define LOAD_SCENE(name) if (*scene == 0) enter_ ## name ## (scene);

# define INIT(type, scene)           t_ ## type *scene ## _cont = alloc__of_ ## scene ();
# define IN(type, scene)             break__of_ ## type (scene ## _cont)
# define GET_USER_INPUT(type, scene) listen_of_ ## type (scene ## _cont)
# define UPDATE_STATE(scene)         update_of_ ## scene (scene ## _cont)
# define RENDER(type, scene)         render(scene ## _cont->sprites, scene ## _cont->screen)
# define CLEAN_UP(scene)             clean__of_ ## scene ()
# define TRANSITION(from) transition(from ## _cont->scenes.at, from ## _cont->scenes.destination)

# define SCENE_LOOP(type, scene)		\
	INIT(type, scene);					\
	RENDER(type, scene);				\
	while (IN(type, scene))				\
	{									\
		GET_USER_INPUT(type, scene);	\
		UPDATE_STATE(scene);			\
		RENDER(type, scene);			\
		usleep(GAME_TICK);				\
	}									\
	CLEAN_UP(scene);					\
	TRANSITION(scene);					\

# define NULL_SPRITE (t_sprite){NULL, NULL, -1, -1};
/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** SCENES
*/

# define NULL_SCENE -1
# define TRANSITION_SCENE 0
# define MAIN_MENU 1

#endif
