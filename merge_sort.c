/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:35:35 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/06 19:35:36 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"
#include <math.h>	// FORBIDDEN


void	merge_sort(t_list *stacks[], int step, int size)
{
	int	chunk_size;
	int	compare_step;
	int	push_count;
	int	iterations;
	iterations = 0;
	chunk_size = power(2, (double)step);
	while (iterations * chunk_size < size)
	{
		compare_step = 0;
		push_count = 0;
		while (compare_step < chunk_size)
		{
			if (stacks[a] == NULL || stacks[b] == NULL) //or something
			if (iterations % 2 == 1)
			{
				if (*(int*)stacks[a]->content > *(int*)stacks[b]->content && push_count++ < chunk_size / 2)
					push(&stacks[b], &stacks[a]);
				rotate(&stacks[a]);
			}
			else
			{
				if (*(int*)stacks[b]->content > *(int*)stacks[a]->content && push_count++ < chunk_size / 2)
					push(&stacks[a], &stacks[b]);
				rotate(&stacks[b]);
			}
			compare_step++;
		}
		iterations++;
	}
}

	if (step % 2 = 0)
	{
		
		while (size >= 0)	// check if math is correct
		{
			if (stacks[a] != NULL && stacks[a]->next != NULL)
				if (*(int*)stacks[a]->content < *(int*)stacks[a]->next->content)
				{
					rotate(stacks[a]);
					push(stacks[a], stacks[b]);
				}
				else
				{
					push(stacks[a], stacks[b]);
					rotate(stacks[a]);
				}
			size -= 2;
		}
	}
	else if (step == 1)
	{
		while (size >= 0)	// check if math is correct
		{
//			if (*(int*)stacks[a]->content < 
			if (stacks[a] != NULL && stacks[a]->next != NULL)
				if (*(int*)stacks[a]->content < *(int*)stacks[a]->next->content)
				{
					rotate(stacks[a]);
					push(stacks[a], stacks[b]);
				}
				else
				{
					push(stacks[b], stacks[a]);
					rotate(stacks[a]);
				}
			size -= 2;
		}
	}
}


// array A[] has the items to sort; array B[] is a work array
void BottomUpMergeSort(A[], B[], n)
{
    for (width = 1; width < n; width = 2 * width)
    {
        for (i = 0; i < n; i = i + 2 * width)
        {
            BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
        CopyArray(B, A, n);
    }
}

//  Left run is A[iLeft :iRight-1].
// Right run is A[iRight:iEnd-1  ].
void BottomUpMerge(A[], iLeft, iRight, iEnd, B[])
{
    i = iLeft, j = iRight;
    for (k = iLeft; k < iEnd; k++) {
        if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;    
        }
    } 
}

void CopyArray(B[], A[], n)
{
    for (i = 0; i < n; i++)
        A[i] = B[i];
}