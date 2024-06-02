#include<iostream>
#include <GLFW/glfw3.h>
#include<cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float xOne = -0.5f;
float xTwo = 0.0f;
float xThree = 0.5f;
float yOne = -0.5f;
float yTwo = 0.5f;
float yThree = -0.5f;

float angle = 0.0f;

void Rotate(float& x, float& y, float angle) {
    float s = sin(angle);
    float c = cos(angle);

    float newX = x * c - y * s;
    float newY = x * s + y * c;

    x = newX;
    y = newY;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Increment the rotation angle
        angle += 0.01f;
        if (angle >= 2 * M_PI) {
            angle -= 2 * M_PI;
        }

        // Copy original vertices
        float x1_rot = xOne, y1_rot = yOne;
        float x2_rot = xTwo, y2_rot = yTwo;
        float x3_rot = xThree, y3_rot = yThree;

        // Rotate vertices
        Rotate(x1_rot, y1_rot, angle);
        Rotate(x2_rot, y2_rot, angle);
        Rotate(x3_rot, y3_rot, angle);

        glBegin(GL_TRIANGLES);
        glVertex2f(x1_rot, y1_rot);
        glVertex2f(x2_rot, y2_rot);
        glVertex2f(x3_rot, y3_rot);
        glEnd();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}