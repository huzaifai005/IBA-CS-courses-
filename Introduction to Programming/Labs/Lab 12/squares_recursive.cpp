#include "raylib.h"
#include <iostream>

void DrawSquares(int n, float sz, float x, float y)
{
    if (n == 0)
        return;

    float halfSize = sz / 2.0f;
    float left = x - halfSize;
    float right = x + halfSize;
    float top = y - halfSize;
    float bottom = y + halfSize;

    DrawRectangle((int)(left * GetScreenWidth()), (int)(top * GetScreenHeight()),
                  (int)(sz * GetScreenWidth()), (int)(sz * GetScreenHeight()), GRAY);

    DrawRectangleLines((int)(left * GetScreenWidth()), (int)(top * GetScreenHeight()),
                       (int)(sz * GetScreenWidth()), (int)(sz * GetScreenHeight()), BLACK);

    float newSize = sz / 2.2f;
    DrawSquares(n - 1, newSize, left, top);
    DrawSquares(n - 1, newSize, left, bottom);
    DrawSquares(n - 1, newSize, right, top);
    DrawSquares(n - 1, newSize, right, bottom);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Recursive Squares");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawSquares(4, 0.5f, 0.5f, 0.5f);

        EndDrawing();
    }

    CloseWindow();
}