//
// Created by Alim MINADZHIEV on 8/27/18.
//

#include "../inc/scop.h"

void		handle_keys(t_scop *scop)
{
	glfwPollEvents();
	if (glfwWindowShouldClose(scop->window) ||
			glfwGetKey(scop->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		scop->is_running = FALSE;
	// move object
	if (glfwGetKey(scop->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		t_mat4  translate = mat4_translation_matrix(0.1f, 0, 0);
		translate = mat4_transpose(translate);
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, translate);
	}
	if (glfwGetKey(scop->window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		t_mat4  translate = mat4_translation_matrix(-0.1f, 0, 0);
		translate = mat4_transpose(translate);
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, translate);
	}
	if (glfwGetKey(scop->window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		t_mat4  translate = mat4_translation_matrix(0, 0.1f, 0);
		translate = mat4_transpose(translate);
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, translate);
	}
	if (glfwGetKey(scop->window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		t_mat4  translate = mat4_translation_matrix(0, -0.1f, 0);
		translate = mat4_transpose(translate);
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, translate);
	}
	if (glfwGetKey(scop->window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
	{
		t_mat4  translate = mat4_translation_matrix(0, 0, 0.1f);
		translate = mat4_transpose(translate);
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, translate);
	}
	if (glfwGetKey(scop->window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
	{
		t_mat4  translate = mat4_translation_matrix(0, 0, -0.1f);
		translate = mat4_transpose(translate);
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, translate);
	}
	//rotate object
	if (glfwGetKey(scop->window, GLFW_KEY_KP_4) == GLFW_PRESS)
	{
		t_mat4  rotate = mat4_rotation_y(RAD(1.0f));
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, rotate);
	}
	if (glfwGetKey(scop->window, GLFW_KEY_KP_6) == GLFW_PRESS)
	{
		t_mat4  rotate = mat4_rotation_y(RAD(-1.0f));
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, rotate);
	}
	if (glfwGetKey(scop->window, GLFW_KEY_KP_8) == GLFW_PRESS)
	{
		t_mat4  rotate = mat4_rotation_x(RAD(-1.0f));
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, rotate);
	}
	if (glfwGetKey(scop->window, GLFW_KEY_KP_2) == GLFW_PRESS)
	{
		t_mat4  rotate = mat4_rotation_x(RAD(1.0f));
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, rotate);
	}
	if (glfwGetKey(scop->window, GLFW_KEY_KP_7) == GLFW_PRESS)
	{
		t_mat4  rotate = mat4_rotation_z(RAD(1.0f));
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, rotate);
	}
	if (glfwGetKey(scop->window, GLFW_KEY_KP_9) == GLFW_PRESS)
	{
		t_mat4  rotate = mat4_rotation_z(RAD(-1.0f));
		scop->obj.model_mat = mat4_mult(scop->obj.model_mat, rotate);
	}
}

void		render_routine(t_scop *scop)
{
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glUseProgram(0);
	glDepthRangef(0.1f, 1000.0f);

	glEnable (GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	while (scop->is_running == TRUE)
	{

		scop->mvp_matrix = mat4_mult(scop->camera.proj_mat, scop->camera.view_mat);
		scop->mvp_matrix = mat4_mult(scop->mvp_matrix, scop->obj.model_mat);
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(scop->shader_program);
		glBindVertexArray(scop->obj.vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scop->obj.ibo);

		glUniformMatrix4fv(scop->uniform.model, 1, GL_FALSE, &scop->obj.model_mat.f[0]);
		glUniformMatrix4fv(scop->uniform.projection, 1, GL_FALSE, &scop->camera.proj_mat.f[0]);
		glUniformMatrix4fv(scop->uniform.view, 1, GL_FALSE, &scop->camera.view_mat.f[0]);

		glUniformMatrix4fv(scop->uniform.mvp, 1, GL_FALSE, &scop->mvp_matrix.f[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, scop->obj.ind_count, GL_UNSIGNED_INT, (void *)0);


		/* Swap front and back buffers */
		glfwSwapBuffers(scop->window);

		/* Poll for and process events */
		handle_keys(scop);
//		scop->is_running = FALSE;
	}
}
