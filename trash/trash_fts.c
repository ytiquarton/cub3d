void draw_block(int x, int y, int tile_w, int tile_h, t_data *game)
{
    int i = 0;
    int j;

    while (i < tile_w)
    {
        j = 0;
        while (j < tile_h)
        {
            my_mlx_pixel_put(&game->windata, x + i, y + j, 0x00FFFF00);
            j++;
        }
        i++;
    }
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
			if (x > win_x || y > win_y || x < 0 || y < 0)
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
			if (x > win_x || y > win_y || x < 0 || y < 0)
				break ;
			front_pix++;
		}
		line--;
	}
}

void draw_map(char *name, t_data *game)
{
    int fd;
    int i;
    int j;
    int tile_w;
    int tile_h;

    tile_w = win_x / game->map.size_map[0];
    tile_h = win_y / game->map.size_map[1];
    i = 0;
    while (i < game->map.size_map[1])
    {
        j = 0;
        while (j < game->map.size_map[0])
        {
            if (game->map.map[i][j] == 'P')
            {
                game->player.posx = j * tile_w + tile_w / 2;
                game->player.posy = i * tile_h + tile_h / 2;
            }
            j++;
        }
        i++;
    }
}