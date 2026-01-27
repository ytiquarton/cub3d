#include "cub3d.h"


int init_player(t_data *game)
{
	game->player.angle = 0;
	return (0);
}

void my_mlx_pixel_put(t_windata *data, int x, int y, int color)
{
	char *dst;

	if (x < 0 || y < 0)
		return ;
	if (x >= win_x || y >= win_y)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int close_win(t_data *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	exit (0);
}

int move_player (int keycode, t_data *game)
{
	// update_map(game);
	// vanish_line(game);
	if (keycode == 'w')
		move_front(game);
	else if (keycode == 'a')
		move_left(game);
	else if (keycode == 's')
		move_rear(game);
	else if (keycode == 'd')
		move_right(game);
	else if (keycode == 65307)
		close_win(game);
	else if (keycode == 65363)
	{
		game->player.angle += 0.1;
		if (game->player.angle > 2 * pi)
			game->player.angle -= 2 * pi;
	}
	else if (keycode == 65361)
	{
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle += 2 * pi;
	}
	else
		printf("keycode = %d\n", keycode);
	// draw_line_player(game);
	// draw_player(game);
	return (0);
}

int main(void)
{
	t_data		game;

	game.mlx.mlx = mlx_init();
	game.windata.img = mlx_new_image(game.mlx.mlx, win_x, win_y);
	game.windata.addr = mlx_get_data_addr(game.windata.img, &game.windata.bpp, &game.windata.line_length, &game.windata.endian); //code pour set les variable en fonction de la taille de l'image
	game.mlx.mlx_win = mlx_new_window(game.mlx.mlx, win_x, win_y, "test");
	// draw_map("map.txt", &game);
	init_map("map.txt", &game);
	init_player(&game);
	// draw_player(&game);
	draw_sky_g(&game);
	draw_walls(&game);
	mlx_hook(game.mlx.mlx_win, 2, 1L<<0, move_player, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}