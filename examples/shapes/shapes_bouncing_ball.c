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

//------------------------------------------------------------------------------------
// Ponto de entrada principal do programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialização
    //---------------------------------------------------------
    const int screenWidth = 800;   // Largura da tela
    const int screenHeight = 450;  // Altura da tela

    SetConfigFlags(FLAG_MSAA_4X_HINT);  // Ativa o anti-aliasing de 4x para melhor qualidade gráfica
    InitWindow(screenWidth, screenHeight, "raylib [shapes] exemplo - bola quicando");  // Inicializa a janela com o título

    // Posição inicial da bola no centro da tela
    Vector2 ballPosition = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };

    // Velocidade da bola (movimento em X e Y)
    Vector2 ballSpeed = { 5.0f, 4.0f };
    
    // Raio da bola
    int ballRadius = 20;

    // Variáveis para controlar o pause
    bool pause = 0;
    int framesCounter = 0;

    SetTargetFPS(60);  // Define o FPS do jogo para 60 (jogo vai rodar a 60 quadros por segundo)
    //----------------------------------------------------------

    // Loop principal do jogo
    while (!WindowShouldClose())    // Detecta o fechamento da janela ou pressionamento da tecla ESC
    {
        // Atualização
        //-----------------------------------------------------
        if (IsKeyPressed(KEY_SPACE)) pause = !pause;  // Alterna o estado de pausa ao pressionar a tecla SPACE

        if (!pause)  // Se o jogo não estiver pausado
        {
            // Atualiza a posição da bola com base na velocidade
            ballPosition.x += ballSpeed.x;
            ballPosition.y += ballSpeed.y;

            // Verifica colisão com as paredes para fazer a bola quicar
            if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) 
                ballSpeed.x *= -1.0f;  // Inverte a direção da velocidade no eixo X ao bater nas paredes laterais
            if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) 
                ballSpeed.y *= -1.0f;  // Inverte a direção da velocidade no eixo Y ao bater no topo ou no fundo
        }
        else framesCounter++;  // Conta os quadros enquanto o jogo está pausado (não há movimentação da bola)
        //-----------------------------------------------------

        // Desenho
        //-----------------------------------------------------
        BeginDrawing();  // Começa o processo de desenho na tela

            ClearBackground(RAYWHITE);  // Limpa a tela com fundo branco

            // Desenha a bola na posição atual com o raio especificado
            DrawCircleV(ballPosition, (float)ballRadius, MAROON);  

            // Exibe uma mensagem pedindo para pressionar a tecla SPACE para pausar o movimento da bola
            DrawText("PRESSIONE ESPAÇO para PAUSAR O MOVIMENTO DA BOLA", 10, GetScreenHeight() - 25, 20, LIGHTGRAY);

            // Se o jogo estiver pausado, exibe uma mensagem "PAUSADO" piscando
            if (pause && ((framesCounter/30)%2)) 
                DrawText("PAUSADO", 350, 200, 30, GRAY);

            // Exibe o FPS atual no canto superior esquerdo
            DrawFPS(10, 10);

        EndDrawing();  // Finaliza o processo de desenho
        //-----------------------------------------------------
    }

    // Desinicialização
    //---------------------------------------------------------
    CloseWindow();  // Fecha a janela e o contexto OpenGL
    //----------------------------------------------------------

    return 0;
}