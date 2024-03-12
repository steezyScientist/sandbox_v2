#include "GL.h"


namespace GL {
    GLFWwindow* window = nullptr;
    int windowWidth = 0;
    int windowHeight = 0;
    const char* title = "";
}

//Callbacks
void processInput(GLFWwindow* window);

void GL::Init(int width, int height, const char* title) {
    windowWidth = width;
    windowHeight = height;

    glfwInit();
    if (!glfwInit())
    {
        std::cout << "Failed to initialize" << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(windowWidth, windowHeight, title, nullptr, nullptr);
    if (!window)
    {
        std::cout << "Failed to create window" << std::endl;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    GetOpenGLVersionInfo();

}

void GL::SetViewPortandPreDraw() {
    glViewport(0, 0, windowWidth, windowHeight);
    //background color
    glClearColor(1.0f, 0.43f, 0.78f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void GL::GetOpenGLVersionInfo() {
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void GL::UpdateScreen() {
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void GL::ShowFPS() {
    static double previousSeconds = 0.0;
    static int frameCount = 0;
    double elapsedSeconds;
    double currentSeconds = glfwGetTime();

    elapsedSeconds = currentSeconds - previousSeconds;

    if (elapsedSeconds > 0.25) {
        previousSeconds = currentSeconds;
        double fps = (double)frameCount / elapsedSeconds;
        double msPerFrame = 1000.0 / fps;

        std::ostringstream outs;
        outs.precision(3);
        outs << std::fixed
            << title << " "
            << "FPS: " << fps << " "
            << "Frame_Time: " << msPerFrame << " (ms)";
        glfwSetWindowTitle(window, outs.str().c_str());
        frameCount = 0;
    }
    frameCount++;
}

bool GL::WindowIsOpen() {
    return !glfwWindowShouldClose(window);
}

void GL::Cleanup() {
    glfwTerminate();
}

GLFWwindow* GL::GetWindowPtr() {
    return window;
}

int GL::GetWindowHeight() {
    return windowHeight;
}
int GL::GetWindowWidth() {
    return windowWidth;
}