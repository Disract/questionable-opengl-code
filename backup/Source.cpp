#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<cstdlib>
#include "./depdencies/include/custom/shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "./depdencies/include/image_loader/stb_image.h"


double random_number()
{
	return rand() / (RAND_MAX + 1.0);
}
void frambuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		std::cout << "debug";
		glClearColor((float)random_number(), (float)random_number(), (float)random_number(), (float)random_number());
		glClear(GL_COLOR_BUFFER_BIT);
	}

}
int main(void)
{
	using namespace std;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 800, "YO_WORK", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failure" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frambuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initalise GLAD" << std::endl;
		return -1;
	}
	float vertices1[] =
	{    //points            //colors            //tex 
		-0.9f, -0.5f, 0.0f,  1.0f,0.0f,1.0f,	0.0f,0.0f,   // left 
		-0.0f, -0.5f, 0.0f,  0.0f,1.0f,0.7f,	1.0f,0.0f,	 // right
		-0.45f, 0.5f, 0.0f,  0.0f,1.0f,0.4f,	0.5f,1.0f  // top 

	};
	float vertices2[] =
	{
		// second triangle   //volor
		 0.0f, -0.5f, 0.0f,  0.5f,0.4f,1.0f,   0.5f,1.0f,// left
		 0.9f, -0.5f, 0.0f,  1.0f,0.4f,1.0f,   1.0f,0.0f,// right
		 0.45f, 0.5f, 0.0f,  0.0f,0.0f,1.0f,   0.0f,0.0f// top 
	};
	unsigned int indices[] =
	{
		0,1,2,
		1,4,3
	};
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	Shader shaderProgram("./shaders/vertex/vertex.vs", "./shaders/fragment/frag1.fs");
	Shader shaderProgram1("./shaders/vertex/vertex.vs", "./shaders/fragment/frag2.fs");

	//creating a vertex buffer object to store vertices
	GLuint VBO1, VAO1;
	glGenVertexArrays(1, &VAO1);
	glGenBuffers(1, &VBO1);
	glBindVertexArray(VAO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);

	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);



	//LOOK AT ANY IMPORTING ISSUES THAT CAUSING THE STRETCHING
	int width, height, nrChannels;
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* data = stbi_load("./textures/wall.jpg", &width, &height, &nrChannels, 0);
	if (data)
	{
		cout << "FUCK ME EME ME E";
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
	//shaderProgram.use();
	//shaderProgram.setInt("ourTexture", 1);
	//shaderProgram1.use();
	//shaderProgram1.setInt("ourTexture", 1);
	//fix the gluniform thats not getting utilised
	//shit works
	while (!glfwWindowShouldClose(window))
	{
		cout << "debug";
		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.3f, 1.4f, 1.3f, 3.0f);

		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, texture);
		//glBindVertexArray(VAO);

		shaderProgram.use();
		float timeval = static_cast<float>(glfwGetTime());
		float greenValue = static_cast<float>((sin(timeval) / 2.0f) + 0.5f);
		shaderProgram.setFloat4("ourColor", greenValue, greenValue, 0.0f, 0.0f);
		shaderProgram.setFloat4("offset", 0.5, 0.0, 0.0, 0.0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		shaderProgram1.use();
		float timeval1 = static_cast<float>(glfwGetTime());
		float redValue = static_cast<float>((sin(timeval1) / 2.0f) + 0.5f);
		shaderProgram1.setFloat4("ourColor1", greenValue, greenValue, 0.0f, 0.0f);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(VAO1);
		glDrawArrays(GL_TRIANGLES, 0, 3);



		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;


}