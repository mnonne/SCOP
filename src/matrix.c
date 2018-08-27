//
// Created by Alim MINADZHIEV on 8/27/18.
//


#include "../inc/scop.h"

t_mat4		mat4_index(float num)
{
	t_mat4	index;

	index = (t_mat4){0.0f};
	index.f[0] = num;
	index.f[5] = num;
	index.f[10] = num;
	index.f[15] = 1.0f;
	return (index);
}

t_mat4      mat4_translation_matrix(float x, float y, float z)
{
	t_mat4  mat;

	mat = mat4_index(1.0f);
	mat.f[3] = x;
	mat.f[7] = y;
	mat.f[11] = z;
	return (mat);
}

t_mat4      mat4_transpose(t_mat4 matrix)
{
	t_mat4  res;

	res.f[0] = matrix.f[0];
	res.f[1] = matrix.f[4];
	res.f[2] = matrix.f[8];
	res.f[3] = matrix.f[12];
	res.f[4] = matrix.f[1];
	res.f[5] = matrix.f[5];
	res.f[6] = matrix.f[9];
	res.f[7] = matrix.f[13];
	res.f[8] = matrix.f[2];
	res.f[9] = matrix.f[6];
	res.f[10] = matrix.f[10];
	res.f[11] = matrix.f[14];
	res.f[12] = matrix.f[3];
	res.f[13] = matrix.f[7];
	res.f[14] = matrix.f[11];
	res.f[15] = matrix.f[15];
	return (res);
}

t_mat4      mat4_mult(t_mat4 m1, t_mat4 m2)
{
//    float		final_matrix[16];
//    unsigned	i;
//    unsigned	j;
//
//    i = 0;
//    while (i < 16)
//    {
//        final_matrix[i] = 0;
//        j = 0;
//        while (j < 4)
//        {
//            final_matrix[i] += left[((i / 4) * 4 + j)] * right[(j * 4 + i % 4)];
//            j++;
//        }
//        i++;
//    }
//    if (dest == NULL)
//        return (matrix_clone(final_matrix));
//    matrix_copy(dest, final_matrix);
//    return (dest);
	t_mat4  res;
	int     i;
	int     k;

	i = 0;
	while (i < 16)
	{
		res.f[i] = 0;
		k = 0;
		while (k < 4)
		{
			res.f[i] += m1.f[((i / 4) * 4 + k)] * m2.f[(k * 4 + i % 4)];
			k++;
		}
		i++;
	}
	return (res);
}

t_mat4 		mat4_proj(float angle, float near, float far, float fov)
{
	t_mat4 	matrix;

	matrix = (t_mat4){0};


	float asp_ratio = (float)WIN_W / (float)WIN_H;

	float tan_fov = tanf(fov / 2.0f);
	matrix.f[0] = 1.0f / (asp_ratio * tan_fov);
	matrix.f[5] = 1.0f / tan_fov;
	matrix.f[10] = (far + near) / (far - near) * -1;
	matrix.f[11] = -1.0f;
	matrix.f[14] = (2.0f * far * near) / (far - near) * -1;

	return (matrix);
}

t_mat4 	mat4_vew(t_vec3 pos, t_vec3 dir, t_vec3 up)
{
	t_vec3  forward;
	t_vec3  left;
	t_vec3  u;
	t_mat4  matrix;

	forward = vec3normalize(vec3subtr(pos, dir));
	left = vec3cross_prod(up, forward);
	u = vec3cross_prod(forward, left);
	matrix = mat4_index(1.0f);
	matrix.f[0] = left.f[0];
	matrix.f[4] = left.f[1];
	matrix.f[8] = left.f[2];
	matrix.f[1] = u.f[0];
	matrix.f[5] = u.f[1];
	matrix.f[9] = u.f[2];
	matrix.f[2] = forward.f[0];
	matrix.f[6] = forward.f[1];
	matrix.f[10] = forward.f[2];
	matrix.f[12] = -left.f[0] * (pos).f[0] - left.f[1] * (pos).f[1] - left.f[2] * (pos).f[2];
	matrix.f[13] = -u.f[0] * (pos).f[0] - u.f[1] * (pos).f[1] - u.f[2] * (pos).f[2];
	matrix.f[14] = -forward.f[0] * (pos).f[0] - forward.f[1] * (pos).f[1] - forward.f[2] * (pos).f[2];
	return (matrix);

}

t_mat4  mat4_rotation_y(float ang)
{
	t_mat4  res;

	res = mat4_index(1.0);
	res.f[0] = cosf(ang);
	res.f[2] = sinf(ang);
	res.f[8] = -sinf(ang);
	res.f[10] = cosf(ang);
	return (res);
}

t_mat4  mat4_rotation_x(float ang)
{
	t_mat4  res;

	res = mat4_index(1.0);
	res.f[5] = cosf(ang);
	res.f[6] = -sinf(ang);
	res.f[9] = sinf(ang);
	res.f[10] = cosf(ang);
	return (res);
}

t_mat4  mat4_rotation_z(float ang)
{
	t_mat4  res;

	res = mat4_index(1.0);
	res.f[0] = cosf(ang);
	res.f[1] = -sinf(ang);
	res.f[4] = sinf(ang);
	res.f[5] = cosf(ang);
	return (res);
}

/*-----*/

void print_matrix(t_mat4 mat)
{
	printf("Matrix:\n");
	for (int i = 0; i < 16; i+=4)
		printf("%5.2f %5.2f %5.2f %5.2f\n", mat.f[i], mat.f[i+1], mat.f[i+2], mat.f[i+3]);
}
