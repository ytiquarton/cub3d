#include "cub3d.h"

void move_front(t_data *game)
{
    // vanish_player(game);
    game->player.posx += 0.2f * cos(game->player.angle);
    game->player.posy += 0.2f * sin(game->player.angle);
    
}

void move_left(t_data *game)
{
    // vanish_player(game);
    game->player.posx += 0.2f * sin(game->player.angle);
    game->player.posy -= 0.2f * cos(game->player.angle);
}

void move_rear(t_data *game)
{
    // vanish_player(game);
    game->player.posx -= 0.2f * cos(game->player.angle);
    game->player.posy -= 0.2f * sin(game->player.angle);
}

void move_right(t_data *game)
{
    // vanish_player(game);
    game->player.posx -= 0.2f * sin(game->player.angle);
    game->player.posy += 0.2f * cos(game->player.angle);
}