/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:01:26 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/29 18:25:49 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**all_paths;
	int		i;
	char	*path;
	char	*path_slash;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_paths[i++])
	{
		path_slash = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	free_all(all_paths);
	return (0);
}

void	exec_cmd(char *input_cmd, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(input_cmd, ' ');
	path = get_cmd_path(cmd[0], envp);
	execve(path, cmd, envp);
}

void	child_process(char **argv, int *pipe_fd, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	dup2(infile, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	exec_cmd(argv[2], envp);
}

void	parent_process(char **argv, int *pipe_fd, char **envp)
{
	int	outfile;

	wait(NULL);
	outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	dup2(pipe_fd[0], 0);
	dup2(outfile, 1);
	close(pipe_fd[1]);
	exec_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			error("Error");
		pid = fork();
		if (pid == -1)
			error("Error");
		if (pid == 0)
			child_process(argv, pipe_fd, envp);
		else
			parent_process(argv, pipe_fd, envp);
	}
}
