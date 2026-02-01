#include "cub3d.h"

# define ROV 1000

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
	if (x >= 1920 || y >= 1080)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int close_win(t_data *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	exit (0);
}

void draw_player(t_data *game)
{
	float x;
	float y;
	int i = 0;
	int j = 0;

	x = game->player.posx;
	y = game->player.posy;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(&game->windata, i + x, j + y, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->windata.img, 0, 0);
}

void vanish_player(t_data *game)
{
		float x;
	float y;
	int i = 0;
	int j = 0;

	x = game->player.posx;
	y = game->player.posy;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(&game->windata, i + x, j + y, 0x00000000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->windata.img, 0, 0);
}

void vanish_line(t_data *game)
{
	int front_pix;
	float x;
	float y;
	float line;
	
	line = 0;
	while (line < 20)
	{
		front_pix = 0;
		x = game->player.posx;
		x += 4;
		y = game->player.posy;
		y += 4;
		while (front_pix < ROV)
		{
			if (is_in_block(x, y, game))
				break;
			my_mlx_pixel_put(&game->windata, x, y, 0x00000000);
			x += cos(game->player.angle + (line / 35.0f));
			y += sin(game->player.angle + (line / 35.0f));
			if (x > 1920 || y > 1080 || x < 0 || y < 0)
				break ;
			front_pix++;
		}
		line++;
	}
	while (line > 0)
	{
		front_pix = 0;
		x = game->player.posx;
		x += 4;
		y = game->player.posy;
		y += 4;
		while (front_pix < ROV)
		{
			if (is_in_block(x, y, game))
				break;
			my_mlx_pixel_put(&game->windata, x, y, 0x00000000);
			x += cos(game->player.angle - (line / 35.0f));
			y += sin(game->player.angle - (line / 35.0f));
			if (x > 1920 || y > 1080 || x < 0 || y < 0)
				break ;
			front_pix++;
		}
		line--;
	}
}

void draw_line_player(t_data *game)
{
	int front_pix;
	float x;
	float y;
	float line;
	
	line = 0;
	while (line < 20) // côté gauche
	{
		front_pix = 0;
		x = game->player.posx;
		x += 4;
		y = game->player.posy;
		y += 4;
		while (front_pix < ROV)
		{
			if (is_in_block(x, y, game))
				break;
			my_mlx_pixel_put(&game->windata, x, y, 0x00FFFFFF);
			x += cos(game->player.angle + (line / 35.0f));
			y += sin(game->player.angle + (line / 35.0f));
			if (x > 1920 || y > 1080 || x < 0 || y < 0)
				break ;
			front_pix++;
		}
		line++;
	}
	while (line > 0) // coté droit ou jsp
	{
		front_pix = 0;
		x = game->player.posx;
		x += 4;
		y = game->player.posy;
		y += 4;
		while (front_pix < ROV)
		{
			if (is_in_block(x, y, game))
				break;
			my_mlx_pixel_put(&game->windata, x, y, 0x00FFFFFF);
			x += cos(game->player.angle - (line / 35.0f));
			y += sin(game->player.angle - (line / 35.0f));
			if (x > 1920 || y > 1080 || x < 0 || y < 0)
				break ;
			front_pix++;
		}
		line--;
	}
}

int move_player (int keycode, t_data *game)
{
	// update_map(game);
	vanish_line(game);
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
	draw_line_player(game);
	draw_player(game);
	return (0);
}

int main(void)
{
	t_data		game;

	game.mlx.mlx = mlx_init();
	game.windata.img = mlx_new_image(game.mlx.mlx, 1920, 1080);
	game.windata.addr = mlx_get_data_addr(game.windata.img, &game.windata.bpp, &game.windata.line_length, &game.windata.endian); //code pour set les variable en fonction de la taille de l'image
	game.mlx.mlx_win = mlx_new_window(game.mlx.mlx, 1920, 1080, "test");
	if (!draw_map("map.txt", &game))
		return (42);
	init_player(&game);
	draw_player(&game);
	draw_line_player(&game);
	mlx_hook(game.mlx.mlx_win, 2, 1L<<0, move_player, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}