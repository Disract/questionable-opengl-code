#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<cstdlib>
#include "./depdencies/include/custom/shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "./depdencies/include/image_loader/stb_image.h"


double static random_number()
{
	return rand() / (RAND_MAX + 1.0);
}
void static frambuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void static processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		std::cout << "debug";
		glClearColor((float)random_number(), (float)random_number(), (float)random_number(), (float)random_number());
		glClear(GL_COLOR_BUFFER_BIT);
	}
	
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{

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
		-0.5f, -0.5f, 0.0f,  1.0f,0.0f,1.0f,	0.0f,0.0f,   // left 
		0.5f, -0.5f, 0.0f,  0.0f,1.0f,0.7f,	1.0f,0.0f,	 // right
		0.0f, 0.5f, 0.0f,  0.0f,1.0f,0.4f,	0.5f,1.0f  // top 

	};
	float vertices2[] =
	{
		// second triangle   //volor
		 0.0f, -0.5f, 0.0f,  0.5f,0.4f,1.0f,   0.0f,0.0f,// left
		 0.9f, -0.5f, 0.0f,  1.0f,0.4f,1.0f,   1.0f,0.0f,// right
		 0.45f, 0.5f, 0.0f,  0.0f,0.0f,1.0f,   0.5f,1.0f// top 
	};
	float vertices3[] = {
	  0.5f,  0.5f, 0.0f,  1.0,0.0f,0.0f,  2.0f,2.0f,  // TOP RIGHT
	  0.5f, -0.5f, 0.0f,  0.0f,1.0f,0.0f, 2.0f,0.0f,  // BOTTOM RIGHT  
	 -0.5f, -0.5f, 0.0f,  0.0f,0.0f,1.0f, 0.0f,0.0f,  // BOTTOM LEFT
	 -0.5f,  0.5f, 0.0f,  1.0f,1.0f,0.0f, 0.0f,2.0f   //TOP LEFT
	};
	unsigned int indices3[] =
	{
		0,1,3,
		1,2,3
	};
	//unsigned int EBO;
	//glGenBuffers(1, &EBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
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
	glBindVertexArray(0);

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


	//one + one triangle

	GLuint VBO2, VAO2,EBO2;
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO2);
	glBindVertexArray(VAO2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices3), indices3, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);



	//LOOK AT ANY IMPORTING ISSUES THAT CAUSING THE STRETCHING
	//first texture
	int width, height, nrChannels;
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char *pdata1 = stbi_load("./textures/brickwall.jpg", &width, &height, &nrChannels, 0);
	if (pdata1)
	{
		cout << "FUCK ME EME ME E";
	}
	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pdata1);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(pdata1);


	//second texture
	unsigned int texture1;
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	unsigned char *pdata2 = stbi_load("./textures/awesomeface.png", &width, &height, &nrChannels, 0);
	if (pdata2)
	{
		cout << "IMAGE FINE";
	}
	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pdata2);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(pdata2);



	shaderProgram.use();
	shaderProgram.setInt("ourTexture", 0);
	//shaderProgram.use();
	shaderProgram.setInt("ourTexture1", 1);
	//fix the gluniform thats not getting utilised
	//shit works
	float val = 0.0f;
	float temp = 0.00000001f;
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.3f, 1.4f, 1.3f, 3.0f);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture1);

		//glBindVertexArray(VAO);

		
		//glUniform1i(glGetUniformLocation(shaderProgram.ID, "ourTexture"), 1);
		shaderProgram.use();
		float timeval = static_cast<float>(glfwGetTime());
		float greenValue = static_cast<float>((sin(timeval) / 2.0f) + 0.5f);
		shaderProgram.setFloat4("ourColor", greenValue, greenValue, 0.0f, 0.0f);
		shaderProgram.setFloat4("offset", 0.5, 0.0, 0.0, 0.0);
		//glBindTexture(GL_TEXTURE_2D, texture);
		//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glBindVertexArray(VAO2);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 3);

		//shaderProgram1.use();
		//float timeval1 = static_cast<float>(glfwGetTime());
		//float redValue = static_cast<float>((sin(timeval1) / 2.0f) + 0.5f);
		//shaderProgram1.setFloat4("ourColor1", greenValue, greenValue, 0.0f, 0.0f);
		//glBindTexture(GL_TEXTURE_2D, texture);
		//glBindVertexArray(VAO1);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		{
			shaderProgram.use();
			float timeval = static_cast<float>(glfwGetTime());
			temp = (temp+0.0001)*1/ 999999999;
			cout << "temp = " << temp << "\n";
		    val = static_cast<float>((sin(temp) / 2.0f) + 0.5f);
			cout << "val = "  << val << "\n";
	        shaderProgram.setFloat("vals",val);
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			shaderProgram.use();
			float timeval = static_cast<float>(glfwGetTime());
			temp = (temp--) * 1 / 999999999;
			val = static_cast<float>((sin(temp) / 2.0f) + 0.5f);
		    cout << val;
			shaderProgram.setFloat("vals", val);
		}
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_RELEASE || glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_RELEASE)
		{
			temp = 0;
		}


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;


}