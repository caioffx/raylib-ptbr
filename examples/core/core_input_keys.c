/*******************************************************************************************
*
*   raylib [núcleo] exemplo - Entrada de teclado (teclas de seta)
*
*   Exemplo originalmente criado com raylib 1.0, última atualização com raylib 1.0
*
*   Exemplo licenciado sob uma licença zlib/libpng não modificada, que é uma licença do tipo BSD 
*   certificada pela OSI que permite vinculação estática com software de código fechado
*
*   Copyright (c) 2014-2024 Ramon Santamaria (@raysan5)
*   Tradução e comentários adicionais por Caio Fabio (@caioffx)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Ponto de entrada do programa principal (main)
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialização
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800; //Define valor constante para screenWidth (Largura da tela)
    const int screenHeight = 450; //Define valor constante para screenHeight (Altura da tela)

    InitWindow(screenWidth, screenHeight, "raylib [núcleo] exemplo - Entrada de teclado (teclas de seta)"); //Inicializa a janela, define valores para altura e largura da janela

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 }; //Define que "ballPosition" (ou seja, a posição inicial da bola que será movida com as teclas de seta) será uma struct Vector2, com duas variáveis do tipo float, o primeiro para x (coincidindo com largura, ou seja, movimento no eixo horizontal x) e o segundo para y (coincidindo com altura, ou seja, movimento vertical y).

    SetTargetFPS(60);               // Define nosso jogo para rodar a 60 quadros por segundo
    //--------------------------------------------------------------------------------------

    // Loop do jogo principal
    while (!WindowShouldClose())    // Detecta um botão de fechar janela ou tecla ESC
    {
        // Atualizar/modificar
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f; //Função que verifica se a tecla de seta direita está sendo pressionada. Caso verdadeiro, a bola começa a movimentar no sentido horizontal (x) à direita. O número no final da sentença define a velocidade na qual a bola irá percorrer a janela.
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f; //Função que verifica se a tecla de seta esquerda está sendo pressionada. Caso verdadeiro, a bola começa a movimentar no sentido horizontal (x) à esquerda. O número no final da sentença define a velocidade na qual a bola irá percorrer a janela.
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f; //Função que verifica se a tecla de seta cima está sendo pressionada. Caso verdadeiro, a bola começa a movimentar no sentido vertical (y) para cima. O número no final da sentença define a velocidade na qual a bola irá percorrer a janela.
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f; //Função que verifica se a tecla de seta baixo está sendo pressionada. Caso verdadeiro, a bola começa a movimentar no sentido vertical (y) para baixo. O número no final da sentença define a velocidade na qual a bola irá percorrer a janela.
        //----------------------------------------------------------------------------------

        // Desenhar o conteúdo da janela
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE); //Define cor de fundo de janela

            DrawText("mova a bola com as teclas de seta", 10, 10, 20, DARKGRAY); //Define mensagem mostrada na janela, a posição e a cor da mensagem

            DrawCircleV(ballPosition, 50, MAROON); //Função que desenha o círculo: recebe a struct de posição vetorial, o tamanho da bola a ser desenhada e a cor da mesma.

        EndDrawing(); //Finaliza o desenho
        //----------------------------------------------------------------------------------
    }

    // Finalização
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha janela e contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}