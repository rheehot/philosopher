/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:04:07 by kmin              #+#    #+#             */
/*   Updated: 2020/09/08 23:39:23 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int		init_sems(t_sem *sems, t_pd *pd)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
	sem_unlink("state");
	sem_unlink("state2");
	if ((sems->s_forks = sem_open("forks", O_CREAT, 0644, pd->num_of_philo)) == SEM_FAILED)
		return (-1);
	if ((sems->s_write = sem_open("write", O_CREAT, 0644, WRITABLE)) == SEM_FAILED)
		return (-1);
	if ((sems->s_meal = sem_open("meal", O_CREAT, 0644, pd->num_of_philo / 2)) == SEM_FAILED)
		return (-1);
	if ((sems->s_state = sem_open("state", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (-1);
	if ((sems->s_state2 = sem_open("state2", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (-1);
	return (0);
}

void	init_struct(t_philo *ph, t_pd *pd, t_sem *sems)
{
	if (!(ph->pid = (pid_t *)malloc(sizeof(pid_t) * pd->num_of_philo)))
		return ;
	ph->philo_idx = 0;
	ph->pd = pd;
	ph->sems = sems;
	ph->program_start = get_time();
	ph->last_meal = get_time();
}