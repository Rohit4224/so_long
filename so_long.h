/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:07:34 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/27 17:39:34 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include "libft/get_next_line.h"
# define IMG_SIZE 16

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

// tipo di blocco(tiles)

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tiletype;

/* struttura di ogni blocco
(type) il tipo
(og_type) resetta gioco
(position) coordinate pixel
(s_tile) movimento
*/
typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

/* tutti le possibili immagini dei muri
(block) blocco muro
gli altri per la posizione 
*/

typedef struct s_wall_img
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}	t_wall_img;

/*informazioni riguardo il giocatore
(idle_img_0) prima immagine
(idle_img_1) seconda immagine
(action frame) fotogrammo di azione
(action_img) l'azione
*/

typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	void	*idle_img_0;
}	t_player;

/* information  collezzionabili */

typedef struct s_coll_img
{
	void	*current_img;
	void	*img_0;
}	t_collect_img;

/*informaioni per gli effetti particellari
(frames) frame
(counter) contatore frame*/
/*typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;
*/

/* tutte le informazioni per l'avvio del gioco
(mlx) puntatore minilib
(window) finestra di gioco
(wndw_size) grandezza finestra
(tilemap) blocchi della mappa
(player) giocatore
(og_collects) oggetti collezzionabili
(collects) raccogli
(moves) movimento
(enemy_list) lista_nemici
(img_size) grandezza immagine
(wall_img) immagine muro
(collects_imgs) immagine collezionabili
(enemy_imgs) immagine nemici
(door_open_image) animazione apertura porta
(door_close_img) immagine chiusura porta
(effect) effetti
*/

typedef struct s_game
{
	void				*mlx;
	void				*window;
	t_vector			wndw_size;
	t_tile				**tilemap;
	t_player			player;
	int					og_collects;
	int					collects;
	int					moves;
	t_vector			img_size;
	t_wall_img			wall_imgs;
	t_collect_img		collects_imgs;
	void				*door_open_img;
	void				*door_close_img;
	t_tile				**backup;
}	t_game;

enum	e_keycode
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	RESET = 114,
	ESC = 65307,
};

int		error(char *message);
void	*null_error(char *message);
void	print_warning(char *message);

t_bool	begin(t_game *game, int argc, char **argv);
t_bool	possible_win(t_tile **backup);

int		end_program(t_game *game);
int		process(int key, t_game *game);
int		ft_chartable_linecount(char **table);
void	ft_free_chartable(char **table);

int		fill_in(t_game *game);
void	furnish(t_game game);
void	draw_wall(t_tile tile, t_game game, t_vector pos);

#endif
