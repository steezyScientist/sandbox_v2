#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <sstream>

#include "GL.h"
#include "Input.h"
#include "Shader.h"
#include "Model.h"
#include "Colors.h"
#include "Camera.h"

//TIME
float lastFrameTime = 0.0f;
float deltaTime = 0.0f;


void EngineLoop() {

    glm::vec3 light_direction = glm::vec3(0.0f, -5.0f, -3.0f);
    glm::vec3 light_ambient = glm::vec3(0.2f);
    glm::vec3 light_diffuse = glm::vec3(0.2f);
    glm::vec3 light_specular = glm::vec3(0.2f);


    Shader shader("shaders/vertex.shader", "shaders/fragment.shader");
    Model player("models/Peasant Girl.fbx");
    Camera camera;

    while (GL::WindowIsOpen())
    {
        float currentTimeFrame = glfwGetTime();
        deltaTime = (currentTimeFrame - lastFrameTime);
        lastFrameTime = currentTimeFrame;

        GL::ShowFPS();
        Input::Update();
        camera.Update(deltaTime);

        ///PRE-DRAW
        GL::SetViewPortandPreDraw();

        ///DRAW
        glm::mat4 projection = glm::perspective(glm::radians(75.0f), 640.0f / 480.0f, 0.1f, 10.0f); //45 for more natural
        glm::mat4 model(1.0), view(1.0);

        view = camera.GetViewMatrix();

        shader.Use();
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);

        shader.setVec3("view_position", camera.GetPosition());

        shader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
        shader.setFloat("material.shininess", 2.0f);

        shader.setVec3("light.direction", light_direction);
        shader.setVec3("light.ambient",light_ambient);
        shader.setVec3("light.diffuse", light_diffuse);
        shader.setVec3("light.specular",light_specular);

        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -1.0f));
        model = glm::scale(model, glm::vec3(0.01f));
        //model = glm::rotate(glm::radians(currentTimeFrame * 20), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", model);

        player.Draw(shader);

        ///PDATE SCREEN
        GL::UpdateScreen();
    }
}


int main()
{

    GL::Init(640, 480, "sandyBox");   //Setup GLFW window
    EngineLoop();                       //main engine loop
    GL::Cleanup();  
    //exit
    return 0;
}