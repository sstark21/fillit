#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**move_up(char **matrix)
{
	while (matrix[0][0] == '.' && matrix[0][1] == '.' && matrix[0][2] == '.' && matrix[0][3] =='.')
	{
		int x = 0;
		int n = 0;
		char **arr;

		arr = (char **)malloc(sizeof(char *) * 5);
		while(n <= 4 )
		{
			arr[n] = (char *)malloc(sizeof(char *) * 5);
			x++;
		}

		int x = 0;
		while (x < 4)
		{
			int y = 0;
			while (y < 3)
			{
				matrix[y][x] = arr[y + 1][x];
				y++;
			}
			matrix[y][x] = '.';
			x++;
		}
	}
	return (matrix);
}
