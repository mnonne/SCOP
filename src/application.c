//
// Created by Alim MINADZHIEV on 8/27/18.
//

#include "../inc/scop.h"

void	print_opengl_info(void)
{
	printf("%s\n", glGetString(GL_RENDERER));
	printf("%s\n", glGetString(GL_VERSION));
}

void		check_errors(void)
{
	int 	errcode;

	errcode = glGetError();
	printf("OpenGL error %d\n", errcode);
}

void	escape(const char *message)
{
	ft_putendl(message);
	exit(1);
}

t_scop	*init_scop(void)
{
	t_scop	*env;

	if (!(env = (t_scop *)malloc(sizeof(t_scop))))
		escape("Unable to malloc");
	if (!glfwInit())
		escape("Unable to initialize GLFW");
	glfwWindowHint(GLFW_SAMPLES, 4);//
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!(env->window = glfwCreateWindow(WIN_W, WIN_H, "SCOP", NULL, NULL)))
		escape("Unable to create GLFW window");
	glfwMakeContextCurrent(env->window);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		escape("Unable to initialize GLEW");
	env->is_running = TRUE;
	print_opengl_info();//
	return (env);
}

void	terminate_scop(t_scop *scop)
{
	glfwTerminate();
}

int 	main(void)
{
	t_scop		*scop;

	scop = init_scop();
	load_object(&scop->obj);
	scop->shader_program = create_shader_program("../shaders/vertex_shader.glsl", "../shaders/fragment_shader.glsl");
	init_camera(scop);
	init_uniforms(scop);
	render_routine(scop);
	terminate_scop(scop);
	return (0);
}
