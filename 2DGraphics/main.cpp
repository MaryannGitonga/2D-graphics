#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 680
#define M_PI 3.142

int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "2D Graphics", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {

        // Bigger Rect
        glBegin(GL_LINE_STRIP);
        glVertex2f(200, 400); //top left
        glVertex2f(200, 150); // bottom left
        glVertex2f(600, 150); // bottom right
        glVertex2f(600, 400); // top right
        glEnd();

        // Smaller Upper Rect
        glBegin(GL_LINE_STRIP);
        glVertex2f(650, 400); // bottom right
        glVertex2f(650, 450); // top right
        glVertex2f(150, 450); // top left
        glVertex2f(150, 400); // bottom left
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(150, 400);
        glVertex2f(200, 400);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(600, 400);
        glVertex2f(650, 400);
        glEnd();

        // Door
        glBegin(GL_LINE_LOOP);
        glVertex2f(450, 350);
        glVertex2f(350, 350);
        glVertex2f(350, 150);
        glVertex2f(450, 150);
        glEnd();

        // Door Knob
        int i;
        int triangleAmount = 20; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi = 2.0f * M_PI;

        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(435, 270); // center of circle
        for (i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                435 + (5 * cos(i * twicePi / triangleAmount)),
                270 + (5 * sin(i * twicePi / triangleAmount))
            );
        }
        glEnd();

      // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();

    }

    glfwTerminate();

    return 0;
}