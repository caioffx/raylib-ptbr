/*******************************************************************************************
*
*   raylib [text] exemplo - Formatação de texto
*
*   Exemplo originalmente criado com raylib 1.1, última atualização com raylib 3.0
*
*   Exemplo licenciado sob a licença zlib/libpng não modificada, que é uma licença certificada pela OSI, 
*   similar à BSD, que permite a vinculação estática com software de código fechado
*
*   Copyright (c) 2014-2024 Ramon Santamaria (@raysan5)
*   Tradução e comentários adicionais por Caio Fabio (@caioffx)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Ponto de entrada principal do programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialização
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;    // Largura da tela
    const int screenHeight = 450;   // Altura da tela

    // Inicializa a janela com o título
    InitWindow(screenWidth, screenHeight, "raylib [text] exemplo - Formatação de texto");

    // Cria variáveis que guardam valores atribuídos a elas que posteriormente serão exibidos na tela
    int score = 100020; 
    int hiscore = 200450;
    int lives = 5;

    SetTargetFPS(60);               // Define o FPS do jogo para 60 (jogo vai rodar a 60 quadros por segundo)
    //--------------------------------------------------------------------------------------

    // Loop do algoritmo principal
    while (!WindowShouldClose())    // Detecta o fechamento da janela ou pressionamento da tecla ESC
    {
        // Atualizar/modificar
        //----------------------------------------------------------------------------------
        // Para fazer: atualize e insira suas variáveis aqui
        //----------------------------------------------------------------------------------

        // Desenhar o conteúdo da janela
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // DrawText irá desenhar o texto resultante na tela com posição, tamanho e cor definidos. Junto da TextFormat, que gera o texto dinamicamente a partir dos valores das variáveis score, hiscore, lives, e GetFrameTime(). 

            DrawText(TextFormat("Pontuação: %08i", score), 200, 80, 20, RED);

            DrawText(TextFormat("Maior pontuação: %08i", hiscore), 200, 120, 20, GREEN);

            DrawText(TextFormat("Vidas: %02i", lives), 200, 160, 40, BLUE);

            DrawText(TextFormat("Tempo decorrido: %02.02f ms", GetFrameTime()*1000), 200, 220, 20, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Finalização
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha a janela e o contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}