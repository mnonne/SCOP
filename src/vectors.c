//
// Created by Alim MINADZHIEV on 8/27/18.
//

#include "../inc/scop.h"

t_vec3		vec3subtract(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.f[0] = v1.f[0] - v2.f[0];
	res.f[1] = v1.f[1] - v2.f[1];
	res.f[2] = v1.f[2] - v2.f[2];
	return (res);
}

float		vec3mod(t_vec3 vec)
{
	float 	res;

	res = sqrtf((vec.f[0] * vec.f[0]) + (vec.f[1] * vec.f[1]) + (vec.f[2] * vec.f[2]));
	return (res);
}

t_vec3		vec3normalize(t_vec3 vec)
{
	float 	mod;
	t_vec3	ret;

	mod = vec3mod(vec);
	ret.f[0] = vec.f[0] / mod;
	ret.f[1] = vec.f[1] / mod;
	ret.f[2] = vec.f[2] / mod;
	return (ret);
}

t_vec3		vec3cross_prod(t_vec3 v1, t_vec3 v2)
{
	t_vec3	ret;

	ret.f[0] = v1.f[1] * v2.f[2] - v1.f[2] * v2.f[1];
	ret.f[1] = v1.f[2] * v2.f[0] - v1.f[0] * v2.f[2];
	ret.f[2] = v1.f[0] * v2.f[1] - v1.f[1] * v2.f[0];
	return (ret);
}

t_vec3      vec3rotate_y(t_vec3 vec, float angle)
{
	t_vec3  new;

	new.f[0] = vec.f[0] * cosf(angle) + vec.f[2] * sinf(angle);
	new.f[1] = vec.f[1];
	new.f[2] = -vec.f[0] * sinf(angle) + vec.f[2] * cosf(angle);
	return (new);
}

t_vec3      vec3rotate_x(t_vec3 vec, float angle)
{
	t_vec3  new;

	new.f[0] = vec.f[0];
	new.f[1] = vec.f[1] * cosf(angle) - vec.f[2] * sinf(angle);
	new.f[2] = vec.f[1] * sinf(angle) + vec.f[2] * cosf(angle);
	return (new);
}

t_vec3      vec3translate_z(t_vec3 vec, float num)
{
	t_vec3  new;

	new = (t_vec3){vec.f[0], vec.f[1], vec.f[2] + num};
	return new;
}

t_vec3      vec3translate_x(t_vec3 vec, float num)
{
	t_vec3  new;

	new = (t_vec3){vec.f[0] + num, vec.f[1], vec.f[2]};
	return new;
}

t_vec3      vec3subtr(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3  res;

	res.f[0] = vec1.f[0] - vec2.f[0];
	res.f[1] = vec1.f[1] - vec2.f[1];
	res.f[2] = vec1.f[2] - vec2.f[2];
	return (res);
}

t_vec3      vec3add(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3  res;

	res.f[0] = vec1.f[0] + vec2.f[0];
	res.f[1] = vec1.f[1] + vec2.f[1];
	res.f[2] = vec1.f[2] + vec2.f[2];
	return (res);
}

t_vec3      vec3mult_scal(t_vec3 vec, float num)
{
	t_vec3  res;

	res.f[0] = vec.f[0] * num;
	res.f[1] = vec.f[1] * num;
	res.f[2] = vec.f[2] * num;
	return (res);
}

float       vec3dot_prod(t_vec3 v1, t_vec3 v2)
{
	float   ret;

	ret = v1.f[0] * v2.f[0] + v1.f[1] * v2.f[2] + v1.f[2] * v2.f[2];
	return (ret);
}

void        print_vector(t_vec3 vec)
{
	printf("Vector: %.2f %.2f %.2f\n", vec.f[0], vec.f[1], vec.f[2]);
}
