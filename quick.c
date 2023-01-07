static void	quick_sort(int *tab, int start, int end)
{
	int	pivot;
	int	less_limit;
	int	greater_limit;
	int	aux;

	if (end - start > 1)
	{
		pivot = end - 1;
		less_limit = start;
		greater_limit = start;
		while (greater_limit < pivot)
		{
			if (tab[greater_limit] < tab[pivot])
			{
				aux = tab[greater_limit];
				tab[greater_limit] = tab[less_limit];
				tab[less_limit] = aux;
				less_limit++;
			}
			greater_limit++;
		}
		aux = tab[pivot];
		tab[pivot] = tab[less_limit];
		tab[less_limit] = aux;
		less_limit++;
		quick_sort(tab, less_limit, end);
		quick_sort(tab, start, less_limit - 1);
	}
}

void	sort(int *tab, int size)
{
	quick_sort(tab, 0, size);
}
