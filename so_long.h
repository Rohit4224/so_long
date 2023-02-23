/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:07:34 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/23 18:56:37 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include "libft/get_next_line.h"
# define IMG_SIZE 16

// tipo di blocco(tiles)

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
}	t_player;

/* tutti le possibili immagini dei muri
(block) blocco muro
gli altri per la posizione 
*/
typedef struct s_wall_img
{
	void	*block;
}	t_wall_img;

/* information animazione collezzionabili
(img_0) primo frame per animare
(img_1) secondo frame per animare*/
typedef struct s_coll_img
{
	void	*current_img;
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
(red_panel) effetto schermo rosso
(white_panel) effetto schermo bianco
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
	int					win;
	int					death;
}	t_game;

int		error(char *message);
void	*null_error(char *message);
void	print_warning(char *message);

enum	e_keycode
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	RESET = 114,
	ESC = 65307,
};

#endif
