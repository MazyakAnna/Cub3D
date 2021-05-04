#include "cube3d.h"

/*
** making dinamic array in my struct out of list
*/
void	maplist_to_map(t_maze *maze, t_list *head)
{
	t_list	*tmp;
	int		i;

	maze->mapsize = ft_lstsize(head);
	maze->map = (char **)malloc(sizeof(char *) * (maze->mapsize + 1));
	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		(maze->map)[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	maze->map[i] = NULL;
}

int	get_map(t_list **map_head, t_list **map_tail, char *line)
{
	if (*map_tail != NULL)
	{
		ft_lstadd_back(map_tail, ft_lstnew(line));
		*map_tail = ((*map_tail)->next);
	}
	else
	{
		ft_lstadd_back(map_head, ft_lstnew(line));
		*map_tail = *map_head;
	}
	return (0);
}
