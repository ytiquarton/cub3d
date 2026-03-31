*This project has been created as part of the 42 curriculum by marccost*

---

# cub3D

## Description

`cub3D` is a first-person maze exploration project from the 42 curriculum, inspired by the early raycasting techniques used in games like *Wolfenstein 3D*.

The goal is to render a pseudo-3D view of a 2D map using raycasting, while handling player movement, wall orientation, textures, and floor/ceiling colors through the MiniLibX graphics library.

This repository currently includes:

- a parser for `.cub` scene files
- support for four directional wall textures (`NO`, `SO`, `WE`, `EA`)
- configurable floor and ceiling RGB colors (`F`, `C`)
- keyboard-based movement and camera rotation
- a Linux MiniLibX setup (`mlx_linux`)

## Features

- Raycasted first-person rendering of a maze
- Different wall textures depending on wall orientation
- Floor and ceiling color parsing from the scene file
- Player spawn direction from `N`, `S`, `E`, or `W`
- Movement with `W`, `A`, `S`, `D`
- View rotation with left and right arrow keys
- Clean exit with `ESC`

## Instructions

### Requirements

This project is currently configured for Linux and uses:

- `cc`
- `make`
- X11 development libraries required by `mlx_linux`
- the math library (`-lm`)

If your system does not already provide the X11 headers/libs used by MiniLibX, install them first.

### Compilation

From the repository root, run:

```bash
make
```

This builds the local `libft`, then compiles the project executable:

```bash
./cubtest
```

### Cleaning

```bash
make clean
make fclean
make re
```

### Execution

Run the program with a valid `.cub` map file:

```bash
./cubtest map.cub
```

The repository already includes:

- `map.cub`
- texture files in `assets/`

## Controls

- `W` / `A` / `S` / `D`: move the player
- `Left Arrow`: rotate camera left
- `Right Arrow`: rotate camera right
- `ESC`: quit the program

## Map Format

The program expects a scene description file with the `.cub` extension.

The asset section must define:

```text
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm
F 220,100,0
C 225,30,0
```

Then the map must appear last in the file and contain only:

- `1` for walls
- `0` for empty space
- `N`, `S`, `E`, or `W` for the player start position
- spaces where applicable inside the map layout

The map must be closed by walls, or the program exits with an error.

## Project Structure

```text
.
├── assets/      # wall textures
├── include/     # headers
├── libft/       # local libft
├── mlx_linux/   # MiniLibX for Linux
├── src/         # parsing, movement, rendering, raycasting
├── map.cub      # sample scene
└── Makefile
```

## Technical Notes

- The current window size is defined as `1920x1080`
- Rendering is image-based through MiniLibX
- The current Makefile builds the executable as `cubtest`
- The project uses Linux keycodes from X11 for arrows and `ESC`

## Resources

### Classic references

- 42 cub3D subject PDF
- MiniLibX documentation
- Lode Vandevenne's raycasting tutorial
- F. Permadi's raycasting tutorial series
- Harm-Smits 42 documentation for MiniLibX and graphics projects

### AI usage

AI was used for documentation support on this repository snapshot:

- extracting the README requirements from the project PDF
- reviewing the repository structure to document the current build, controls, and file layout
- drafting and refining this `README.md`

The README content was aligned with the existing source files and current project structure before being written.
