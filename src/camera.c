//
// Created by Alim MINADZHIEV on 8/27/18.
//

#include "../inc/scop.h"

void	init_camera(t_scop *scop)
{
	scop->obj.model_mat = mat4_index(1.0f);
	scop->camera.proj_mat = mat4_proj(45.0f, 0.1f, 1000.0f, RAD(45.0f));
	scop->camera.pos = (t_vec3){0, 0, 5};
	scop->camera.dir = (t_vec3){0, 0, -10};
	scop->camera.up = (t_vec3){0, 1, 0};
	scop->camera.view_mat = mat4_vew(scop->camera.pos, scop->camera.dir, scop->camera.up);
}

void	init_uniforms(t_scop *scop)
{
	glUseProgram(scop->shader_program);
	scop->uniform.model = glGetUniformLocation(scop->shader_program, "ModelMatrix");
	glUniformMatrix4fv(scop->uniform.model, 1, GL_FALSE, &scop->obj.model_mat.f[0]);
	scop->uniform.projection = glGetUniformLocation(scop->shader_program, "ProjectionMatrix");
	glUniformMatrix4fv(scop->uniform.projection, 1, GL_FALSE, &scop->camera.proj_mat.f[0]);
	scop->uniform.view = glGetUniformLocation(scop->shader_program, "ViewMatrix");
	glUniformMatrix4fv(scop->uniform.view, 1, GL_FALSE, &scop->camera.view_mat.f[0]);
}
