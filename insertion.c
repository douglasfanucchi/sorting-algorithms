void	sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < size)
	{
		tmp = tab[i];
		j = i - 1;
		while (tmp < tab[j] && j >= 0)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = tmp;
		i++;
	}
}
