//
// Created by Alim MINADZHIEV on 8/27/18.
//

#ifndef SCOP_H
#define SCOP_H

# include <stdio.h>
# include "../libft/get_next_line.h"
# include "../glew/include/GL/glew.h"
# include "GLFW/glfw3.h"
# include <math.h>

# define WIN_W 800
# define WIN_H 600
# define RAD(x) ((x) * ((float)M_PI / 180))

typedef	struct		s_vec3
{
	float 			f[3];
}					t_vec3;

typedef struct		s_mat4
{
	float 			f[16];
}					t_mat4;

typedef enum 		e_bool
{
	TRUE,
	FALSE
}					t_bool;

typedef struct		s_obj
{
	float 			*vertex_data;
	unsigned int	vao;
	unsigned int	vbo[2];
//	unsigned int	cbo;
	t_mat4			model_mat;
}					t_obj;

typedef struct		s_camera
{
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			up;
	t_mat4			view_mat;
	t_mat4			proj_mat;
}					t_camera;

typedef struct 		s_uniform
{
	int 			model;
	int 			view;
	int 			projection;
}					t_uniform;

typedef struct		s_scop
{
	GLFWwindow		*window;
	t_obj			obj;
	unsigned int	shader_program;
	t_camera		camera;
	t_uniform		uniform;
	t_bool			is_running;
}					t_scop;

/*
** application.c
*/

t_scop				*init_scop(void);
void				escape(const char *message);
void				check_errors(void);

/*
** load_object.c
*/
void				*load_object(t_obj *obj);

/*
** shader_program.c
*/
unsigned int		create_shader_program(const char *vs_file, const char *fs_file);

/*
 * camera.c
 */

void	init_camera(t_scop *scop);
void	init_uniforms(t_scop *scop);

/*
** render.c
*/
void				render_routine(t_scop *scop);

/*
** vectors.c
*/

t_vec3		vec3normalize(t_vec3 vec);
t_vec3		vec3subtract(t_vec3 v1, t_vec3 v2);
float		vec3mod(t_vec3 vec);
t_vec3		vec3cross_prod(t_vec3 v1, t_vec3 v2);
t_vec3      vec3rotate_y(t_vec3 vec, float angle);
t_vec3      vec3rotate_x(t_vec3 vec, float angle);
t_vec3      vec3translate_z(t_vec3 vec, float num);
t_vec3      vec3translate_x(t_vec3 vec, float num);
t_vec3      vec3subtr(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3add(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3mult_scal(t_vec3 vec, float num);
float       vec3dot_prod(t_vec3 v1, t_vec3 v2);
void        print_vector(t_vec3 vec);

/*
** matrix.c
*/

t_mat4		mat4_index(float num);
t_mat4      mat4_translation_matrix(float x, float y, float z);
t_mat4      mat4_transpose(t_mat4 matrix);
t_mat4      mat4_mult(t_mat4 m1, t_mat4 m2);
t_mat4 		mat4_proj(float angle, float near, float far, float fov);
t_mat4 	mat4_vew(t_vec3 pos, t_vec3 dir, t_vec3 up);
t_mat4  mat4_rotation_y(float ang);
t_mat4  mat4_rotation_x(float ang);
t_mat4  mat4_rotation_z(float ang);
void print_matrix(t_mat4 mat);

#endif
