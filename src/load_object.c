//
// Created by Alim MINADZHIEV on 8/27/18.
//

#include "../inc/scop.h"

float       *create_array(void)
{
	float   arr[108] = {
//				-1.0f,-1.0f,-1.0f, // Треугольник 1 : начало
//				-1.0f,-1.0f, 1.0f,
//				-1.0f, 1.0f, 1.0f, // Треугольник 1 : конец
//				 1.0f, 1.0f,-1.0f, // Треугольник 2 : начало
//				-1.0f,-1.0f,-1.0f,
//				-1.0f, 1.0f,-1.0f, // Треугольник 2 : конец
//				 1.0f,-1.0f, 1.0f,
//				-1.0f,-1.0f,-1.0f,
//				 1.0f,-1.0f,-1.0f,
//				 1.0f, 1.0f,-1.0f,
//				 1.0f,-1.0f,-1.0f,
//				-1.0f,-1.0f,-1.0f,
//				-1.0f,-1.0f,-1.0f,
//				-1.0f, 1.0f, 1.0f,
//				-1.0f, 1.0f,-1.0f,
//				 1.0f,-1.0f, 1.0f,
//				-1.0f,-1.0f, 1.0f,
//				-1.0f,-1.0f,-1.0f,
//				-1.0f, 1.0f, 1.0f,
//				-1.0f,-1.0f, 1.0f,
//				 1.0f,-1.0f, 1.0f,
//				 1.0f, 1.0f, 1.0f,
//				 1.0f,-1.0f,-1.0f,
//				 1.0f, 1.0f,-1.0f,
//				 1.0f,-1.0f,-1.0f,
//				 1.0f, 1.0f, 1.0f,
//				 1.0f,-1.0f, 1.0f,
//				 1.0f, 1.0f, 1.0f,
//				 1.0f, 1.0f,-1.0f,
//				-1.0f, 1.0f,-1.0f,
//				 1.0f, 1.0f, 1.0f,
//				-1.0f, 1.0f,-1.0f,
//				-1.0f, 1.0f, 1.0f,
//				 1.0f, 1.0f, 1.0f,
//				-1.0f, 1.0f, 1.0f,
//				 1.0f,-1.0f, 1.0f


			 1.000000f, -1.000000f, -1.000000f, //1 -0
			 1.000000f, -1.000000f,  1.000000f, //2 -3
			-1.000000f, -1.000000f,  1.000000f, //3 -6
			-1.000000f, -1.000000f, -1.000000f, //4 -9
			 1.000000f,  1.000000f, -0.999999f, //5 -12
			 0.999999f,  1.000000f,  1.000001f, //6 -15
			-1.000000f,  1.000000f,  1.000000f, //7 -18
			-1.000000f,  1.000000f, -1.000000f  //8 -21

//			-1.000000f, -1.000000f, -1.000000f, //4
//			 1.000000f, -1.000000f, -1.000000f, //1
//			 1.000000f, -1.000000f,  1.000000f, //2
//			 1.000000f, -1.000000f,  1.000000f, //2
//			-1.000000f, -1.000000f,  1.000000f, //3
//			-1.000000f, -1.000000f, -1.000000f, //4
//			 0.999999f,  1.000000f,  1.000001f, //6
//			 1.000000f,  1.000000f, -0.999999f, //5
//			-1.000000f,  1.000000f, -1.000000f, //8
//			-1.000000f,  1.000000f, -1.000000f, //8
//			-1.000000f,  1.000000f,  1.000000f, //7
//			 0.999999f,  1.000000f,  1.000001f, //6
//			 1.000000f, -1.000000f,  1.000000f, //2
//			 1.000000f, -1.000000f, -1.000000f, //1
//			 1.000000f,  1.000000f, -0.999999f, //5
//			 1.000000f,  1.000000f, -0.999999f, //5
//			 0.999999f,  1.000000f,  1.000001f, //6
//			 1.000000f, -1.000000f,  1.000000f, //2
//			-1.000000f, -1.000000f,  1.000000f, //3
//			 1.000000f, -1.000000f,  1.000000f, //2
//			 0.999999f,  1.000000f,  1.000001f, //6
//			 0.999999f,  1.000000f,  1.000001f, //6
//			-1.000000f,  1.000000f,  1.000000f, //7
//			-1.000000f, -1.000000f,  1.000000f, //3
//			-1.000000f, -1.000000f, -1.000000f, //4
//			-1.000000f, -1.000000f,  1.000000f, //3
//			-1.000000f,  1.000000f,  1.000000f, //7
//			-1.000000f,  1.000000f,  1.000000f, //7
//			-1.000000f,  1.000000f, -1.000000f, //8
//			-1.000000f, -1.000000f, -1.000000f, //4
//			-1.000000f,  1.000000f, -1.000000f, //8
//			 1.000000f,  1.000000f, -0.999999f, //5
//			 1.000000f, -1.000000f, -1.000000f, //1
//			 1.000000f, -1.000000f, -1.000000f, //1
//			-1.000000f, -1.000000f, -1.000000f, //4
//			-1.000000f,  1.000000f, -1.000000f, //8
	};
	float *ptr = (float *)malloc(sizeof(float) * 108);
	ft_memcpy(ptr, arr, sizeof(float) * 108);
	return (ptr);
}


static int	ft_instr(char ch, char *str)
{
	while (str && *str && *str != ch)
		++str;
	return (*str == ch);
}

static char	*skip_blank(const char *str)
{
	int i;

	i = 0;
	while (ft_instr(str[i], " \t\n\v\r\f"))
		i++;
	if (ft_instr(str[i], "+-") || ft_isdigit(str[i]))
		return ((char *)&str[i]);
	else
		return (0);
}

float		ft_atof(const char *str)
{
	char	*p;
	int		i;
	float	num;
	float	tmp;

	if (!(p = skip_blank(str)))
		return (0);
	num = 0;
	i = ((*p == '-') || (*p == '+')) ? 0 : -1;
	while (p[++i] != '.' && p[i] != 0 && ft_isdigit(p[i]))
		num = num * 10 + (int)(p[i] - '0');
	tmp = 1;
	while (ft_isdigit(p[++i]))
	{
		tmp *= 10;
		num += (float)(p[i] - '0') / (float)tmp;
	}
	return ((*p == '-') ? -num : num);
}

float 		*copy_float_arr(float *old, int size)
{
	float 	*new;
	int 	i;

	i = 0;
	new = (float *)malloc(sizeof(float) * (size + 3));
	while (i < size)
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

float 		*positions_array(float *old, char *str, int *arr_size)
{
	char	**tab;
	float 	*new;

	tab = ft_strsplit(str + 2, ' ');
	new = copy_float_arr(old, *arr_size);
	while (*tab)
	{
		new[(*arr_size)++] = ft_atof(*tab);
//		printf("%f ", new[*arr_size - 1]);//r
		free(*tab);
		tab++;
	}
//	printf("\n");//
	free(tab - 3);
	return (new);
}

unsigned int 		*copy_int_arr(unsigned int *old, int size, int add)
{
	unsigned int 	*new;
	int 	i;

	i = 0;
	if (add == 4)
		add = 6;
	new = (unsigned int *)malloc(sizeof(unsigned int) * (size + add));
	while (i < size)
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

unsigned int		*read_index_array(unsigned int *old, char *str, int *arr_size)
{
	char			**tab;
	unsigned int	*new;
	int 			i;

	tab = ft_strsplit(str + 2, ' ');
	i = 0;
	while (*tab)
	{
		i++;
		tab++;
	}
	tab = tab - i;
	new = copy_int_arr(old, *arr_size, i);
//	while (*tab)
//	{
//		new[(*arr_size)++] = (unsigned int)ft_atoi(*tab) - 1;
////		free(*tab);
//		tab++;
//	}
	new[(*arr_size)++] = (unsigned int)ft_atoi(tab[0]) - 1;
//	printf("%u ", new[*arr_size - 1]);
	new[(*arr_size)++] = (unsigned int)ft_atoi(tab[1]) - 1;
//	printf("%u ", new[*arr_size - 1]);
	new[(*arr_size)++] = (unsigned int)ft_atoi(tab[2]) - 1;
//	printf("%u ", new[*arr_size - 1]);
//	tab -= i;
	if (i == 4)
	{
		new[(*arr_size)++] = (unsigned int)ft_atoi(tab[2]) - 1;
//		printf("%u ", new[*arr_size - 1]);
		new[(*arr_size)++] = (unsigned int)ft_atoi(tab[3]) - 1;
//		printf("%u ", new[*arr_size - 1]);
		new[(*arr_size)++] = (unsigned int)ft_atoi(tab[0]) - 1;
//		printf("%u ", new[*arr_size - 1]);
//		printf("\n");
	}
	free(tab);
	return (new);
}

//unsigned int	*create_index_array(unsigned int *arr, int size)
//{
//	unsigned int	*new;
//	unsigned int	i;
//
//	new = (unsigned int *)malloc(sizeof(unsigned int) * size * 3);
//	i = 0;
//	while (i < size)
//	{
////		if (i % 6 == 0 && i != 0)
////			printf("\n");
//		new[i * 3] = arr[i] * 3;
//		new[i * 3 + 1] = arr[i] * 3 + 1;
//		new[i * 3 + 2] = arr[i] * 3 + 2;
////		printf("%2d %2d %2d | ", new[i * 3], new[i * 3 + 1], new[i * 3 + 2]);
//		i++;
//	}
//	return (new);
//}

t_arrays	fill_data(const char *file, float *positions, unsigned int *indices, int *pos_count, int *ind_count)
{
	int 	fd;
	char 	*line;
	int 	i;
	int 	j;
	t_arrays arrays;

	fd = open(file, O_RDONLY);
	i = 0;
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == 'v' && *(line + 1) == ' ')
			positions = positions_array(positions, line, &i);
		else if (*line == 'f')
			indices = read_index_array(indices, line, &j);
		free(line);
	}
//	for (int x = 0; x < j; x++)
//	{
//		if (x % 6 == 0 && x != 0)
//			printf("\n");
//		printf("%u ", indices[x]);
//	}
//	printf("\n");
//	indices = create_index_array(indices, j);
	close(fd);
	arrays.positions = positions;
	arrays.indices = indices;
	*pos_count = i;
	*ind_count = j;
	return(arrays);
}

float 	*create_color_array(int size)
{
	float 	*arr;
	int 	i;

	arr = (float *)malloc(sizeof(float) * size);
	i = 0;
	while (i < size)
	{
		if (i % 4 == 0)
		{
			arr[i] = 0.583f;
			arr[i + 1] = 0.771f;
			arr[i + 2] = 0.014;
		}
		else if (i % 4 == 1)
		{
			arr[i] = 0.167f;
			arr[i + 1] = 0.620f;
			arr[i + 2] = 0.077f;
		}
		else if (i % 4 == 2)
		{
			arr[i] = 0.393f;
			arr[i + 1] = 0.621f;
			arr[i + 2] = 0.362f;
		}
		else if (i % 4 == 3)
		{
			arr[i] = 0.945f;
			arr[i + 1] = 0.719f;
			arr[i + 2] = 0.592f;
		}

//		printf("%f %f %f\n", arr[i], arr[i + 1], arr[i + 2]);
		i += 3;
	}
	return (arr);
}

t_arrays	fill_data2(const char *file, float *pos, unsigned int *indices, int *pos_count, int *ind_count)
{
	t_arrays res;
	float *posi;
	unsigned int *ind;

	float arr_f[12] = {
			-1.0f, -1.0f, -1, //0
			 1.0f, -1.0f, -1, //1
			 1.0f,  1.0f, -1, //2
			-1.0f,  1.0f, -1  //3
	};
	unsigned int arr_i[6] = {
			0, 1, 2, 2, 3, 0
	};
	ind = (unsigned int *)malloc(sizeof(unsigned int) * 6);
	ind[0] = 0;
	ind[1] = 1;
	ind[2] = 2;
	ind[3] = 2;
	ind[4] = 3;
	ind[5] = 0;
	posi = (float *)malloc(sizeof(float) * 12);
//	posi[0] =  1.0f;
//	posi[1] = -1.0f;
//	posi[2] = -1.0f;
//	posi[3] = 1.0f;
//	posi[4] = -1.0f;
//	posi[5] = 1.0f;
//	posi[6] = -1.0f;
//	posi[7] = -1.0f;
//	posi[8] = 1.0f;
//	posi[9] = -1.0f;
//	posi[10] = 1.0f;
//	posi[11] = -0.999999f;

	posi[0] =  1.0f; posi[1] = -1.0f; posi[2] = -1.0f;
	posi[3] =  1.0f; posi[4] =  -1.0f; posi[5] = 1.0f;
	posi[6] = -1.0f; posi[7] =  -1.0f; posi[8] = 1.0f;
	posi[9] = -1.0f; posi[10] = -1.0f; posi[11] = -1.0f;
	res.positions = posi;
	res.indices = ind;
	*pos_count = 12;
	*ind_count = 6;
	return (res);
}

void	load_object(t_obj *obj)
{
//	float *positions = (float *)malloc(sizeof(float));
//	unsigned int *indices = (unsigned int *)malloc(sizeof(unsigned int));
	t_arrays	arrays;
	float *colors = NULL;

//	indices = create_index_data_arr();
//	positions = create_array();
	obj->pos_count = 0;
	obj->ind_count = 0;
	arrays = (t_arrays) {NULL};
	obj->v_count = 24;
	arrays = fill_data("../resources/objects/teapot2.obj", arrays.positions, arrays.indices, &obj->pos_count, &obj->ind_count);
//	for (int i = 0; i < obj->pos_count; i++)
//	{
//		if (i != 0 && i % 3 == 0)
//			printf("\n");
//		printf("%2f ", arrays.positions[i]);
//	}
//	for (int i = 0; i < obj->ind_count; i++)
//	{
//		if (i % 6 == 0)
//			printf("\n");
//		printf("%2u ", arrays.indices[i]);
//	}
	colors = create_color_array(obj->pos_count);
	glGenVertexArrays(1, &obj->vao);
	glBindVertexArray(obj->vao);
	
	glGenBuffers(2, obj->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * obj->pos_count, arrays.positions, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * obj->pos_count, colors, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

	glGenBuffers(1, &obj->ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * obj->ind_count, arrays.indices, GL_STATIC_DRAW);
}
