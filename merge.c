#include <stdlib.h>

static int	*ft_slice(int *tab, int start, int end)
{
	int	i;
	int	size;
	int	*result;

	size = end - start;
	result = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
		result[i++] = tab[start++];
	return (result);
}

static void	merge_sort(int *tab, int start, int end)
{
	int	half;
	int	*first_half;
	int	*second_half;
	int	i;
	int	j;
	int	k;

	if (end - start > 1)
	{
		half = (end + start) / 2;
		merge_sort(tab, start, half);
		merge_sort(tab, half, end);
		first_half = ft_slice(tab, start, half);
		second_half = ft_slice(tab, half, end);
		i = start;
		j = 0;
		k = 0;
		while (i < end)
		{
			if (j == half - start)
				tab[i] = second_half[k++];
			else if (k == end - half)
				tab[i] = first_half[j++];
			else if (first_half[j] <= second_half[k])
				tab[i] = first_half[j++];
			else
				tab[i] = second_half[k++];
			i++;
		}
	}
}

void	sort(int *tab, int size)
{
	merge_sort(tab, 0, size);
}
