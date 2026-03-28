#include "Vector.hpp"
#include "Object.hpp"
#include "ObjectManager.hpp"
#include <iostream>
#include "raylib.h"
#include <cmath>

void drawObject(phun::ID<phun::Object>& obj)
{
    /*if (!(*obj).has_value())
        return;*/
    const phun::Object object = **obj;
    Mesh temp = { 0 };
    temp.vertexCount = object.GetVertexCount();
    temp.vertices = (float*)object.GetVertices();
    temp.indices = (unsigned short*)object.GetIndices();
}

int main()
{
    auto triangle = phun::ObjectManager<phun::Object>::instance().CreateObject();

    InitWindow(800, 450, "phun");
    SetTargetFPS(60);

    Camera3D camera;
    camera.position = { -2.0,2.5,-5.0 };
    camera.target = {};
    camera.up = { 0,1,0 };
    camera.fovy = 45.0;
    camera.projection = CAMERA_PERSPECTIVE;

    Mesh mesh = GenMeshCube(1, 1, 1);
    Model model = LoadModelFromMesh(mesh);

    model.transform = { 1,0,0,0,0,1,0,0.5,0,0,1,0,0,0,0,1 };

    Matrix matrix = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };

    float t = 0;

    while (!WindowShouldClose())
    {
        ClearBackground(WHITE);
        BeginDrawing();

        BeginMode3D(camera);

        DrawGrid(10, 0.5);
        DrawModelWires(model, {}, 1, RED);

        EndMode3D();

        EndDrawing();
        t += 0.01;
        if (t > 3)
            t -= 2*PI;
        camera.position = { 3.0f*cos(t),1.5,3.0f*sin(t) };
    }

    CloseWindow();
}