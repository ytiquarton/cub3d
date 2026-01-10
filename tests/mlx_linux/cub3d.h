
#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"

typedef struct s_mlx_data
{
    void *mlx;
    void *mlx_win;
}              t_mlx_data;

typedef struct s_windata
{
    void *img;
    char *addr;
    int     bpp;
    int     line_length;
    int     endian;
}               t_windata;

typedef struct s_player
{
    float posx;
    float posy;
    int angle;
}               t_player;

typedef struct s_data
{
    t_mlx_data mlx;
    t_windata windata;
    t_player player;
}               t_data;

#endif
