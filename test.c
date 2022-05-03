#include <stdio.h>
#include "mlx.h"

int main()
{
	void *mlx_ptr;
	void	*win_ptr;


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "afsdf");
	int i = 0;
	while (i < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, i, 16777215);
		i++;
	}
	i = 500;
	while (i > 200)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, i, 255);
		i--;
	}
	mlx_loop(mlx_ptr);
	printf("%d\n", 0xFFFFFF);
	printf("%x\n", 0xFFFFFF);
}
