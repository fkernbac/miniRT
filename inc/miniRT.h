/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:45:02 by rbetz             #+#    #+#             */
/*   Updated: 2023/03/04 13:22:43 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>		//printf
# include <fcntl.h>		//open
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "MLX42.h"
# include "libft.h"

# define WIDTH 800
# define HEIGHT 480
// # define WIDTH 1280
// # define HEIGHT 720
// # define WIDTH 1680
// # define HEIGHT 1050

# define T_MIN 0.1
# define T_MAX __DBL_MAX__

typedef enum e_type
{
	CAM,
	LIGHT,
	AMBI,
	SPHERE,
	CYL,
	PLN,
	RES
}	t_type;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vec;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}			t_color;

typedef struct s_sphere
{
	t_vec	*center;
	double	radius;
}			t_sphere;

typedef struct s_obj
{
	int		type;
	double	dia_rat;
	double	hei_fov;
	t_vec	*coord;
	t_vec	*vector;
	t_vec	*color;
	struct s_obj *next;
}			t_obj;

typedef struct s_ray
{
	t_vec		origin;
	t_vec		direction;
	double		closest_t;
	t_sphere	*closest_object;
	t_vec		normal;
}				t_ray;

typedef struct s_camera
{
	double	focal_length;
	t_vec	*origin;
	t_vec	*horizontal;
	t_vec	*vertical;
	t_vec	*upper_left_corner;
}			t_cam;

typedef struct s_map
{
	int		fd;
	char	**file;
}	t_map;

typedef struct s_data
{
	mlx_t					*mlx;
	mlx_image_t				*img;
	// typedef struct s_item	*items;
}							t_data;

//PARSING
t_map	*check_input(int argc, char **argv);
void	print_map(t_map *map);
int		ft_isvalue(int c);
int		ft_isspace(int c);
int		theend(char *s);
char	*kill_nltb(char *line);
int		first_iscomment(char *line);
t_obj	*create_obj(t_map *map);
char	**ft_split_p(char *s, char c);
void	get_reso(t_obj *obj, char **split);
void	get_cam(t_obj *obj, char **split);
void	get_ambi(t_obj *obj, char **split);
void	get_light(t_obj *obj, char **split);
void	get_sphere(t_obj *obj, char **split);
void	get_pln(t_obj *obj, char **split);
void	get_cyl(t_obj *obj, char **split);
double	ft_atof(char *nbr);

//IMAGE
int		draw_image(mlx_image_t *img, t_cam *cam);

//ERROR
void	ft_error(t_data *data, int ecase);

//RAY UTILS
t_ray	*new_ray(t_vec *origin, t_vec *direction);
int		ray_color(t_ray *ray);
t_ray	*delete_ray(t_ray *ray);
t_vec	point_at(t_ray *ray, double t);

//VECTOR UTILS
t_vec	*new_vector(double x, double y, double z);
void	print_vector(t_vec vector);
t_vec	add_vector(t_vec v1, t_vec v2);
t_vec	subtract_vector(t_vec v1, t_vec v2);
t_vec	multiply_vector(t_vec v1, t_vec v2);
t_vec	factor_mult_vector(t_vec v1, double f);
t_vec	factor_div_vector(t_vec v1, double f);
double	scalar_vector(t_vec v1, t_vec v2);
t_vec	cross_vector(t_vec v1, t_vec v2);
double	length_vector(t_vec v1);
t_vec	unit_vector(t_vec v1);

//CAMERA
t_cam	*setup_camera(t_obj *obj, int width, int height);
t_cam	*delete_camera(t_cam *cam);

//COLOR UTILS
int		double_to_color(double r, double g, double b);
int		factor_color(int rgba, double factor);
int		add_color(int c1, int c2);

//UTILS
void	*ft_free(void *pointer);

#endif
