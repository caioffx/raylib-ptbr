/*******************************************************************************************
*
*   raylib [shapes] exemplo - bola quicando
*
*   Exemplo originalmente criado com raylib 2.5, última atualização com raylib 2.5
*
*   Exemplo licenciado sob a licença zlib/libpng não modificada, que é uma licença certificada pela OSI, similar à BSD, que permite a vinculação estática com software de código fechado
*
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*   Tradução e comentários adicionais por Caio Fabio (@caioffx)
*
********************************************************************************************/


#include "raylib.h"

#include <math.h>       // Necessário para função: atan2f()

//------------------------------------------------------------------------------------
// Ponto de entrada principal do programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialização
    //---------------------------------------------------------
    const int screenWidth = 800;    // Largura da tela
    const int screenHeight = 450;   // Altura da tela

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - following eyes");  // Inicializa a janela com o título

    Vector2 scleraLeftPosition = { GetScreenWidth()/2.0f - 100.0f, GetScreenHeight()/2.0f }; // Define posição, nas dimensões da tela, da esclera (parte branca do olho) esquerda
    Vector2 scleraRightPosition = { GetScreenWidth()/2.0f + 100.0f, GetScreenHeight()/2.0f }; // Define posição, nas dimensões da tela, da esclera (parte branca do olho) direita
    float scleraRadius = 80; // Define raio da esclera

    Vector2 irisLeftPosition = { GetScreenWidth()/2.0f - 100.0f, GetScreenHeight()/2.0f }; // Define posição, nas dimensões da tela, da iris (parte branca do olho) esquerda
    Vector2 irisRightPosition = { GetScreenWidth()/2.0f + 100.0f, GetScreenHeight()/2.0f }; // Define posição, nas dimensões da tela, da iris (parte branca do olho) direita
    float irisRadius = 24; // Define raio da irís

    float angle = 0.0f;
    float dx = 0.0f, dy = 0.0f, dxx = 0.0f, dyy = 0.0f;

    SetTargetFPS(60);               // Define o FPS do jogo para 60 (jogo vai rodar a 60 quadros por segundo)
    //--------------------------------------------------------------------------------------

    // Loop principal do jogo
    while (!WindowShouldClose())    // Detecta o fechamento da janela ou pressionamento da tecla ESC
    {
        // Update
        //----------------------------------------------------------------------------------
        irisLeftPosition = GetMousePosition(); // Irís esquerda captura posição do mouse
        irisRightPosition = GetMousePosition(); // Irís direita captura posição do mouse

        // Verifica se a posição da irís esquerda está ou não está fora da esclera esquerda:
        if (!CheckCollisionPointCircle(irisLeftPosition, scleraLeftPosition, scleraRadius - irisRadius))
        {
            dx = irisLeftPosition.x - scleraLeftPosition.x;
            dy = irisLeftPosition.y - scleraLeftPosition.y;

            angle = atan2f(dy, dx);

            dxx = (scleraRadius - irisRadius)*cosf(angle);
            dyy = (scleraRadius - irisRadius)*sinf(angle);

            irisLeftPosition.x = scleraLeftPosition.x + dxx;
            irisLeftPosition.y = scleraLeftPosition.y + dyy;
        }

        // Verifica se a posição da irís direita está ou não está fora da esclera direita:
        if (!CheckCollisionPointCircle(irisRightPosition, scleraRightPosition, scleraRadius - irisRadius))
        {
            dx = irisRightPosition.x - scleraRightPosition.x;
            dy = irisRightPosition.y - scleraRightPosition.y;

            angle = atan2f(dy, dx);

            dxx = (scleraRadius - irisRadius)*cosf(angle);
            dyy = (scleraRadius - irisRadius)*sinf(angle);

            irisRightPosition.x = scleraRightPosition.x + dxx;
            irisRightPosition.y = scleraRightPosition.y + dyy;
        }
        //----------------------------------------------------------------------------------

        // Função para desenhar e pintar a esclera, irís e pupila (circulo menor BLACK dentro de círculo maior DARKGREEN)
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircleV(scleraLeftPosition, scleraRadius, LIGHTGRAY);
            DrawCircleV(irisLeftPosition, irisRadius, BROWN);
            DrawCircleV(irisLeftPosition, 10, BLACK);

            DrawCircleV(scleraRightPosition, scleraRadius, LIGHTGRAY);
            DrawCircleV(irisRightPosition, irisRadius, DARKGREEN);
            DrawCircleV(irisRightPosition, 10, BLACK);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Desinicialização
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha a janela e o contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}