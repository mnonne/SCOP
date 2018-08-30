//
// Created by Alim MINADZHIEV on 8/27/18.
//

#include "../inc/scop.h"

float       *create_array(void)
{
	float   arr[108] = {
				-1.0f,-1.0f,-1.0f, // Треугольник 1 : начало
				-1.0f,-1.0f, 1.0f,
				-1.0f, 1.0f, 1.0f, // Треугольник 1 : конец
				 1.0f, 1.0f,-1.0f, // Треугольник 2 : начало
				-1.0f,-1.0f,-1.0f,
				-1.0f, 1.0f,-1.0f, // Треугольник 2 : конец
				 1.0f,-1.0f, 1.0f,
				-1.0f,-1.0f,-1.0f,
				 1.0f,-1.0f,-1.0f,
				 1.0f, 1.0f,-1.0f,
				 1.0f,-1.0f,-1.0f,
				-1.0f,-1.0f,-1.0f,
				-1.0f,-1.0f,-1.0f,
				-1.0f, 1.0f, 1.0f,
				-1.0f, 1.0f,-1.0f,
				 1.0f,-1.0f, 1.0f,
				-1.0f,-1.0f, 1.0f,
				-1.0f,-1.0f,-1.0f,
				-1.0f, 1.0f, 1.0f,
				-1.0f,-1.0f, 1.0f,
				 1.0f,-1.0f, 1.0f,
				 1.0f, 1.0f, 1.0f,
				 1.0f,-1.0f,-1.0f,
				 1.0f, 1.0f,-1.0f,
				 1.0f,-1.0f,-1.0f,
				 1.0f, 1.0f, 1.0f,
				 1.0f,-1.0f, 1.0f,
				 1.0f, 1.0f, 1.0f,
				 1.0f, 1.0f,-1.0f,
				-1.0f, 1.0f,-1.0f,
				 1.0f, 1.0f, 1.0f,
				-1.0f, 1.0f,-1.0f,
				-1.0f, 1.0f, 1.0f,
				 1.0f, 1.0f, 1.0f,
				-1.0f, 1.0f, 1.0f,
				 1.0f,-1.0f, 1.0f
	};
	float *ptr = (float *)malloc(sizeof(float) * 216);
	ft_memcpy(ptr, arr, sizeof(float) * 216);
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

float		*vector_buffer(float *old, size_t *nb, char *str)
{
	float 	*new;
	char 	**arr;

	new = (float *)realloc(old, sizeof(float) * 3);
//	free(old);
	ft_memcpy(new, old, *nb);
	arr = ft_strsplit(str, ' ');
	while (*arr != NULL)
	{
		new[(*nb)++] = ft_atof(*arr);
		free(*arr);
		arr++;
	}
	free(arr - 3);
//	for (size_t i = 0; i < *nb; i++)
//	{
//		printf("%.4f\n", new[i]);
//	}
	printf("\n");
	return (new);
}

//float 		*create_array(const char *file)
//{
//	int 	fd;
//	size_t 	vert_count;
//	float 	*vert_array = NULL;
//	float 	*tmp_v_buff;
//	char 	*tmp_line;
//
//	vert_count = 0;
//	tmp_v_buff = NULL;
//	fd = open(file, O_RDONLY);
//	while (get_next_line(fd, &tmp_line) > 0)
//	{
//		if (*tmp_line == 'v')
//		{
//			tmp_v_buff = vector_buffer(tmp_v_buff, &vert_count, tmp_line + 2);
//		}
//		free(tmp_line);
//	}
//	close(fd);
//	return (vert_array);
//}

float 	*create_color_array(int size)
{
	float 	*arr;
	int 	i;

	arr = (float *)malloc(sizeof(float) * size);
	i = 0;
	while (i < size)
	{
		arr[i] = 1.0f / (i + 1) * 10;
		arr[i + 1] = 1.0f / (i + 2) * 10;
		arr[i + 2] = 1.0f / (i + 3) * 10;
//		printf("%f %f %f\n", arr[i], arr[i + 1], arr[i + 2]);
		i += 3;
	}
	return (arr);
}

void	load_object(t_obj *obj)
{

	obj->vertex_data = create_array();
	obj->color_data = create_color_array(108);
//	obj->vertex_data = create_array("../resources/objects/42.obj");
	glGenVertexArrays(1, &obj->vao);
	glBindVertexArray(obj->vao);
	glGenBuffers(2, obj->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 108, obj->vertex_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 108, obj->color_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
}
