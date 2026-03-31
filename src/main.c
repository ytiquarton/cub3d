#include "cub3d.h"
#include "libft.h"
#include "assets_utils.h"

int	close_win(t_data *game)
{
	free_assets(&(game->assets));
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	exit (0);
}

int	refresh_window(t_data *game)
{
	mlx_clear_window(game->mlx.mlx, game->mlx.mlx_win);
	draw_sky_g(game);
	draw_walls(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->windata.img, 0, 0);
	return (0);
}

int	move_player(int keycode, t_data *game)
{
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
		game->player.angle += 0.05;
		if (game->player.angle > 2 * PI)
			game->player.angle -= 2 * PI;
	}
	else if (keycode == 65361)
	{
		game->player.angle -= 0.05;
		if (game->player.angle < 0)
			game->player.angle += 2 * PI;
	}
	return (refresh_window(game));
}

void	do_game(t_data *game)
{
	draw_sky_g(game);
	draw_walls(game);
	mlx_put_image_to_window(game->mlx.mlx,
		game->mlx.mlx_win, game->windata.img, 0, 0);
	mlx_hook(game->mlx.mlx_win, 2, 1L << 0, move_player, game);
	mlx_hook(game->mlx.mlx_win, 17, 0, close_win, game);
	mlx_loop(game->mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_data		game;

	if (argc != 2)
		return (ft_putstr_fd("Wrong number of arguments!\n", 2), 1);
	game.mlx.mlx = mlx_init();
	game.windata.img = mlx_new_image(game.mlx.mlx, WIN_X, WIN_Y);
	game.windata.addr = mlx_get_data_addr(game.windata.img, &game.windata.bpp,
			&game.windata.line_length, &game.windata.endian);
	game.mlx.mlx_win = mlx_new_window(game.mlx.mlx, WIN_X, WIN_Y, "test");
	if (!draw_map(argv[1], &game))
		return (1);
	if (load_texture(&game, &game.assets.n_texture)
		|| load_texture(&game, &game.assets.s_texture)
		|| load_texture(&game, &game.assets.e_texture)
		|| load_texture(&game, &game.assets.w_texture))
		return (-1);
	do_game(&game);
	return (0);
}
