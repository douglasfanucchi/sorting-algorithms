#include <stdlib.h>

void	push(int *origin, int *dest, int *size_origin, int *size_dest)
{
	int	i;

	if (*size_origin == 0)
		return ;
	i = *size_dest;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	*size_dest += 1;
	dest[0] = origin[0];
	i = 0;
	while (i < *size_origin - 1)
	{
		origin[i] = origin[i + 1];
		i++;
	}
	*size_origin -= 1;
}

void	rotate(int *tab, int size)
{
	int	i;
	int	top;

	if (size == 0)
		return ;
	i = 0;
	top = tab[0];
	while (i < size - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = top;
}

char	is_ordered(int *tab, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		if (i > 0 && tab[i] < tab[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort(int *tab, int size, int max_digit_len)
{
	int	*stack;
	int	stack_size;
	int	i;
	int	j;
	int	tmp;

	if (is_ordered(tab, size))
		return ;
	tmp = size;
	stack = malloc(sizeof(int) * size);
	stack_size = 0;
	i = 0;
	while (i < max_digit_len)
	{
		j = 0;
		while (j < tmp)
		{
			if ((tab[0] >> i) & 0b00000001)
				rotate(tab, size);
			else
				push(tab, stack, &size, &stack_size);
			j++;
		}
		while (stack_size)
			push(stack, tab, &stack_size, &size);
		i++;
	}
}
