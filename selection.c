void	sort(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min])
				min = j;
			j++;
		}
		j = tab[min];
		tab[min] = tab[i];
		tab[i] = j;
		i++;
	}
}
