/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:39:16 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 20:09:12 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"

# define ENV			t_environment
# define TRANS  		7
# define MENU_END		275
# define MENU_START		65
# define MIN_W			500
# define MIN_H			500
# define MAX_Y			e->index[0]
# define MAX_X			e->index[1]
# define WIN_TITLE		"FIL DE FER"
# define COL_TITLE		0x3D67FF
# define COL_TXT		0xDAE2E5
# define COL_BCKGRND	0x1F1147
# define SCREEN_W		2600
# define SCREEN_H		1440
# define PADDING		350
# define PPMOVE_RATIO	0.00001

/*
 ** USER INPUT KEY CODES
*/
# define KEY_ESC		53
# define KEY_LF			123
# define KEY_RT			124
# define KEY_UP			126
# define KEY_DW			125
# define KEY_XUP		91
# define KEY_XDW		84
# define KEY_YUP		86
# define KEY_YDW		88
# define KEY_ZUP		92
# define KEY_ZDW		89
# define KEY_ZMIN		69
# define KEY_ZMOUT		78
# define KEY_HEIGHT_UP	116
# define KEY_HEIGHT_DW	121
# define KEY_DEFAULT	15
# define KEY_COLOR_UP	115
# define KEY_COLOR_DW	119
# define KEY_VEGAS		9
# define KEY_COLOR		8
# define KEY_COLOR_MAP	46
# define KEY_INVERT		34

/*
 ** MAP COLORS
*/
# define GREEN0			0xACD0A5
# define GREEN1			0x94BF8B
# define GREEN2			0xA8C68F
# define GREEN3			0xBDCC96
# define GREEN4			0xD1D8AB
# define EARTH0			0xE1E4B5
# define EARTH1			0xEFEBC0
# define EARTH2			0xE8E1B6
# define EARTH3			0xDED6A3
# define EARTH4			0xD3CA9D
# define EARTH5			0xCAB982
# define EARTH6			0xC3A76B
# define EARTH7			0xB9985A
# define GREY0			0xAA8753
# define GREY1			0xAC9A7C
# define GREY2			0xBAAE9A
# define GREY3			0xCAC3B8
# define GREY4			0xE0DED8
# define OFFWHITE		0xF5F4F2
# define BLUE0			0xD8F2FE
# define BLUE1			0xC6ECFF
# define BLUE2			0xB9E3FF
# define BLUE3			0xACDBFB
# define BLUE4			0xA1D2F7
# define BLUE5			0x96C9F0
# define BLUE6			0x8DC1EA
# define BLUE7			0x84B9E3
# define BLUE8			0x79B2DE
# define BLUE9			0x71ABD8
# define BLUE10			0x0978AB

/*
 ** NICE COLORS
*/
# define BLACK			0x000000
# define RED			0xEF5350
# define PINK			0xEC407A
# define PURPLE			0x7E57C2
# define INDIGO			0x5C6BC0
# define BLUE			0x42A5F5
# define LBLUE			0x29B6F6
# define CYAN			0x26C6DA
# define TEAL			0x26A69A
# define GREEN			0x66BB6A
# define LGREEN			0x9CCC65
# define LIME			0xD4E157
# define YELLOW			0xFFEE58
# define AMBER			0xFFCA28
# define ORANGE			0xFFA726
# define DORANGE		0xFF7043
# define BROWN			0x8D6E63
# define GREY			0xBDBDBD
# define BGREY			0x78909C
# define WHITE			0xFFFFFF

typedef struct			s_map
{
	int					row_size;
	int					*row;
	struct s_map		*next;
}						t_map;

typedef struct			s_pinfo
{
	t_4vect				p;
	t_4vect				init;
	int					row_size;
	int					color;
}						t_pinfo;

typedef struct			s_uservar
{
	double				event_m[4][4];
	double				rotx;
	double				roty;
	double				zoom;
	double				height;
	int					mv_hor;
	int					mv_ver;
	int					invert;
	int					rotcolor;
	int					color;
	int					color_map;
	int					vegas;
}						t_uservar;

typedef struct			s_linecoord
{
	int					x0;
	int					y0;
	int					z0;
	int					x1;
	int					y1;
	int					z1;
	int					dx;
	int					dy;
}						t_linecoord;

typedef struct			s_image
{
	int					size;
	int					bpp;
	int					endian;
	void				*img;
	char				*ptr;
}						t_image;

typedef struct			s_menu
{
	int					gap0;
	int					gap1;
	int					gap2;
	int					gap3;
	int					gap4;
	int					gap5;
	int					gap6;
	int					gap7;
}						t_menu;

typedef struct			s_environment
{
	t_map				*map_input;
	t_pinfo				**points;
	t_4vect				shift;
	t_4vect				min;
	t_4vect				max;
	t_uservar			uinput;
	t_linecoord			coord;
	t_image				img;
	t_menu				menu;
	int					setextremes;
	int					mesh_size;
	int					mesh_init;
	int					maxzoomin;
	int					maxzoomout;
	int					ppmove;
	int					width;
	int					height;
	int					newheight;
	int					maxheight;
	int					minheight;
	int					win_w;
	int					win_h;
	int					revert;
	int					index[2];
	int					row;
	int					col;
	int					color;
	unsigned char		*line;
	void				*mlx;
	void				*win;
	int					txt;
	int					title;
}						t_environment;

enum					e_directions
{
	HOR, VER
};

enum					e_coordinates
{
	X, Y
};

enum					e_angles
{
	COSX, SINX, COSY, SINY, COSZ, SINZ
};

/*
** Read map
*/
t_map					*ft_getmap(ENV *e, char *file);
t_pinfo					**ft_getpoints(ENV *env);

/*
** Graphic environment | Window & Image
*/
int						ft_init_win(ENV *e);
int						ft_close_window(ENV *e);
int						ft_get_img(ENV *e);
void					ft_put_to_img(ENV *e, int row, int col, int color);
void					*ft_points_to_img(ENV *e);

/*
 ** Transformation
*/
int						ft_transform_points(ENV *e);
void					ft_getm_trans(ENV *e, double (*dest)[4][4]);
void					ft_getm_scaleup(ENV *e, double (*dest)[4][4]);
void					ft_getm_scaledown(ENV *e, double (*dest)[4][4]);
void					ft_getm_rot(ENV *e, double (*dest)[4][4]);
void					ft_getm_setcenter(ENV *e, double (*dest)[4][4]);
void					ft_getm_center_to_origin(ENV *e, double (*dest)[4][4]);
void					ft_getm_height(ENV *e, double (*dest)[4][4]);
void					ft_getm_heightinit(ENV *e, double (*dest)[4][4]);
void					ft_getm_move(ENV *e, double (*dest)[4][4]);
void					ft_getm_zoom(ENV *e, double (*dest)[4][4]);
int						ft_back_to_default(ENV *e);

/*
 ** Menu & User input
*/
int						ft_menu_txt(ENV *e);
int						ft_display_menu(ENV *e);
int						ft_dealkey(int key, void *param);

/*
 ** Line drawing
*/
void					ft_drawline(ENV *e);

/*
 ** Colors
*/
int						ft_rotate_colors(ENV *e);
int						ft_get_altcolor(ENV *e, double alt);
int						ft_get_nicecolor(ENV *e, double alt);

/*
** Initialize & Free
*/
int						ft_getenv(ENV *e);
void					free_list(t_map *lst);
void					free_tab(ENV *e, t_pinfo **tab);

/*
** Error Management
*/
void					*ft_error_alloc(ENV *e);
void					*ft_error_map(void);

/*
** Utils
*/
int						ft_setextremes(ENV *e);

/*
** KEY CODES pc fixe
**
** # define KEY_PGUP 65365
** # define KEY_PGDW 65366
** # define KEY_ESC  65307
** # define KEY_LF 65361
** # define KEY_RT 65363
** # define KEY_UP 65362
** # define KEY_DW 65364
** # define KEY_XUP 65431
** # define KEY_XDW 65433
** # define KEY_YUP 65430
** # define KEY_YDW 65432
** # define KEY_ZUP 65429
** # define KEY_ZDW 65434
** # define KEY_ZMIN 65451
** # define KEY_ZMOUT 65453
** # define KEY_PAD_SUB	78
** # define KEY_PAD_ADD	69
** # define KEY_ESC		53
*/
/*
** KEY CODES pc portable
**
** # define KEY_ESC  65307
** # define KEY_LF 65361
** # define KEY_RT 65363
** # define KEY_UP 65362
** # define KEY_DW 65364
** # define KEY_XUP 112
** # define KEY_XDW 105
** # define KEY_YUP 231
** # define KEY_YDW 108
** # define KEY_ZUP 224
** # define KEY_ZDW 95
** # define KEY_ZMIN 61
** # define KEY_ZMOUT 41
** # define KEY_HEIGHT_UP 233
** # define KEY_HEIGHT_DW 38
** # define KEY_DEFAULT 100
** # define KEY_PAD_SUB	78
** # define KEY_PAD_ADD	69
** # define KEY_ESC		53
*/

#endif
