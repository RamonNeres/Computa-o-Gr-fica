#include <GL/glew.h>
#include <GLFW/glfw3.h>


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


int main(void)
{
	GLFWwindow* window;

	// Initialize the library
	if (!glfwInit())
	{
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	float vertices[] =
	{
		0.0, 300, 0.0,  // top left
		300, 300, 0.0,  // top right
		300, 0.0, 0.0, // bottom right
		0.0, 0.0, 0.0  // bottom left
	};

	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat lineVertices[] =
	{
		200, 100, 0,
		100, 300, 0
	};

	GLfloat lineVertices2[] =
	{
		300, 200, 0,
		200, 400, 0
	};

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		// Render OpenGL here
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_LINE_STIPPLE);
		//glPushAttrib(GL_LINE_BIT);
		glLineWidth(5);
		glLineStipple(5, 0x0C0F);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, lineVertices);
		glDrawArrays(GL_LINES, 0, 2);
		glDisableClientState(GL_VERTEX_ARRAY);
		//glPopAttrib();
		glDisable(GL_LINE_STIPPLE);
		glDisable(GL_LINE_SMOOTH);


		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_LINE_STIPPLE);
		glPushAttrib(GL_LINE_BIT);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, lineVertices2);
		glDrawArrays(GL_LINES, 0, 2);
		glDisableClientState(GL_VERTEX_ARRAY);
		glPopAttrib();
		glDisable(GL_LINE_STIPPLE);
		glDisable(GL_LINE_SMOOTH);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}