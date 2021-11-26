/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:41:11 by hashly            #+#    #+#             */
/*   Updated: 2021/11/26 14:30:47 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_atoi(const char *str)
{
	int		n;
	int		flag;
	size_t	len_num;

	n = 0;
	flag = 1;
	len_num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			flag *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str++ - '0');
		if (len_num++ > 12 && flag == 1)
			return (-1);
		else if (len_num > 12 && flag == -1)
			return (0);
	}
	return (n * flag);
}

static void	set_def_param(t_data *data)
{
	data->error = 0;
	data->max_eat = -1;
	return ;
}

static void	check_param(t_data *data, int argc)
{
	if (data->num_phil < 1 || data->t_die < 1 || data->t_sleep < 1 ||
	data->t_sleep < 1 || (argc == 6 && data->max_eat < 1))
		data->error = 1;
	if (data->error)
		printf("Not valid param\n");
}

static void	get_param(t_data *data, int argc, char **argv)
{
	if (argc != 5 && argc !=6)
	{
		printf("wrong number arguments\n");
		data->error = 1;
	}
	else
	{
		data->num_phil = ft_atoi(argv[1]);
		data->t_die = ft_atoi(argv[2]);
		data->t_eat = ft_atoi(argv[3]);
		data->t_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->max_eat = ft_atoi(argv[5]);
		check_param(data, argc);
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	set_def_param(data);
	get_param(data, argc, argv);
	return ;
}
