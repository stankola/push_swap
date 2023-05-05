#include "ring.h"
#include "stdlib.h"

int		get_ring_size(t_ring *ring)
{
	t_ring	*temp_ring;
	int i;

	if (ring == NULL)
		return (0);
	temp_ring = ring->next;
	i = 1;
	while (temp_ring != ring)
	{
		i++;
		temp_ring = temp_ring->next;
	}
	return (i);
}