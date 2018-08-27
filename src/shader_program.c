//
// Created by Alim MINADZHIEV on 8/27/18.
//

#include "../inc/scop.h"

char 		*append(char *str1, char *str2)
{
	char 	*ret;
	int 	i;
	int 	k;

	if (!str1 || !str2)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 2))))
		return (NULL);
	i = 0;
	k = 0;
	while (str1[i])
		ret[k++] = str1[i++];
	i = 0;
	while (str2[i])
		ret[k++] = str2[i++];
	ret[k++] = '\n';
	ret[k] = '\0';
	free(str1);
	free(str2);
	return (ret);
}

char 		*load_shader(const char *filepath)
{
	int		fd;
	char 	*line;
	char 	*shader;

	fd = open(filepath, O_RDONLY);
	shader = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		shader = append(shader, line);
	}
	close(fd);
	return (shader);
}

void 		check_shader(unsigned int shader)
{
	GLint 	result;
	int 	info_log_len;
	char 	*message;

	result = GL_FALSE;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_len);
	if (info_log_len > 0)
	{
		message = (char *)malloc(sizeof(char) * info_log_len);
		glGetShaderInfoLog(shader, info_log_len, NULL, message);
		printf("%s", message);
		free(message);
	}
}

int 		check_program(unsigned int program)
{
	GLint 	result;
	int 	info_log_len;
	char 	*message;

	result = GL_FALSE;
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_len);
	if (info_log_len > 0)
	{
		message = (char *)malloc(sizeof(char) * info_log_len);
		glGetProgramInfoLog(program, info_log_len, NULL, message);
		ft_putendl(message);
		free(message);
		return (-1);
	}
	return (0);
}

unsigned int	compile_shader(unsigned int type, const char *file)
{
	unsigned int	id;
	char 			*shader_src;
	int 			result;
	int 			len;
	char 			*msg;

	id = glCreateShader(type);
	shader_src = load_shader(file);
	glShaderSource(id, 1, (const char **)&shader_src, NULL);
	glCompileShader(id);
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	ft_strdel(&shader_src);
	if (result == GL_FALSE)
	{
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
		msg = ft_strnew(len);
		glGetShaderInfoLog(id, len, &len, msg);
		ft_putendl(msg);
		free(msg);
		return(0);
	}
	return (id);
}

unsigned int		create_shader_program(const char *vs_file, const char *fs_file)
{
	unsigned int	program;
	unsigned int	vs;
	unsigned int	fs;

	vs = compile_shader(GL_VERTEX_SHADER, vs_file);
	fs = compile_shader(GL_FRAGMENT_SHADER, fs_file);
	program = glCreateProgram();
	glAttachShader(program, vs);
	glAttachShader(program, fs);
//	glBindAttribLocation(program, 0, "in_Position");//
//	glBindAttribLocation(program, 1, "in_Color");//
	glLinkProgram(program);
	glValidateProgram(program);
	if (check_program(program) < 0)
		return (0);
	glDeleteShader(vs);
	glDeleteShader(fs);
	return (program);
}
