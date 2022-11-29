/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:19:06 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/29 18:25:24 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <sys/types.h>
# include <wait.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	free_all(char **str);
void	error(char *str);

#endif