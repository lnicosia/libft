/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tpool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:54:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/23 20:33:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tpool.h"
#include "libft.h"

int		free_tpool2(t_tpool *tpool)
{
	ft_memdel((void**)&tpool->threads);
	if (pthread_mutex_destroy(&tpool->mutex))
		custom_error("Could not destroy the mutex\n");
	if (pthread_cond_destroy(&tpool->worker_cond))
		custom_error("Could not destroy the jober condition\n");
	if (pthread_cond_destroy(&tpool->main_cond))
		custom_error("Could not destroy the main condition\n");
	return (0);
}

int		free_tpool(t_tpool *tpool)
{
	t_job	*job;
	t_job	*tmp;
	int		i;

	if (!tpool->threads)
		return (0);
	pthread_mutex_lock(&tpool->mutex);
	job = tpool->jobs;
	while (job)
	{
		tmp = job->next;
		destroy_job(job);
		job = tmp;
	}
	tpool->stop = 1;
	pthread_cond_broadcast(&tpool->worker_cond);
	pthread_mutex_unlock(&tpool->mutex);
	i = 0;
	while (i < tpool->nb_threads)
	{
		if (pthread_join(tpool->threads[i], NULL))
			custom_error("Could not join thread %d\n", i);
		i++;
	}
	return (free_tpool2(tpool));
}
