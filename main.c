#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	sort(int *tab, int size);

int	main()
{
	int tab[] = {3, 1, 2, 0, 5, 4, 8, 9, 7, 10, 6};
	sort(tab, sizeof(tab) / 4);
	for (int i = 0; i < (sizeof(tab) / 4); i++)
		printf("%d\n", tab[i]);
	printf("\n");
}
