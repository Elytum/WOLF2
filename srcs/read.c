#include "wolf3d.h"

void	get_map(t_env *e)
{
	int		fd;
	int		nbl;
	char	**map;
	char	*line;

	nbl = 0;
	fd = open(MAP_FILE, O_RDONLY);
	while ((get_next_line(fd, &line) > 0 || *line) && ++nbl)
		free(line);
	free(line);
	close(fd);
	if (!(map = (char **)malloc(sizeof(char *) * (nbl + 1))))
		return ;
	nbl = 0;
	fd = open(MAP_FILE, O_RDONLY);
	while (get_next_line(fd, &line) > 0 || *line)
	{
		map[nbl++] = ft_strdup(line);
		free(line);
	}
	map[nbl] = NULL;
	close(fd);
	e->map = map;
}