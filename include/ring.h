typedef struct	s_ring
{
	t_ring	*next;
	t_ring	*prev;
	void	*content;
}				t_ring;