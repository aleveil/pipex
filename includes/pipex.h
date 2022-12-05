/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:19:06 by aleveil           #+#    #+#             */
/*   Updated: 2022/12/02 11:17:51 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	free_all(char **str);
void	error(void);

#endif