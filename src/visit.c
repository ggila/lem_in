
#include "lem_in.h"
#include "queue.h"

/*
**
**    typedef struct   s_queue_node
**    {
**        char    *node_id;
**        t_set   *way;
**    }                t_queue_node;
**
*/

	node_neighbour = set_getnextelem(neighbours);
	new = new_queue_node();

static void	visit(t_queue_node *q_node, t_queue *upcoming, t_hash_tbl *visited)
{
	t_set			*neighbours;
	t_queue			new_upcoming;

	neighbours = GRAPH_GET_NEIGHBOUR(q_node->node_id);
	while ((neighbour = set_getnextelem(node->neighbour)))
	{
		if (!set_isin(visited, neihgbour))
			add_neighbour(neihgbour, new_upcoming);
	}

}
