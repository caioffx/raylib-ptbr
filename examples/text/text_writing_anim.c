/*******************************************************************************************
*
*   raylib [text] exemplo - Animação de Escrita de Texto
*
*   Exemplo originalmente criado com raylib 1.4, última atualização com raylib 1.4
*
*   Exemplo licenciado sob a licença zlib/libpng não modificada, que é uma licença certificada pela OSI, 
*   similar à BSD, que permite a vinculação estática com software de código fechado
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
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;    // Largura da tela
    const int screenHeight = 450;   // Altura da tela
    
    // Inicializa a janela com o título
    InitWindow(screenWidth, screenHeight, "raylib [text] exemplo - Animação de Escrita de Texto"); 

    const char message[128] = "Este exemplo ilustra um efeito de escrita de texto\nanimação! Confira! ;)"; // Cria a string "message" e atribui uma frase a ela.

    int framesCounter = 0; // Inicializa em 0 um contador de quadros (frames)

    SetTargetFPS(60);               // Define o FPS do jogo para 60 (jogo vai rodar a 60 quadros por segundo)
    //--------------------------------------------------------------------------------------

    // Loop do algoritmo principal
    while (!WindowShouldClose())    // Detecta o fechamento da janela ou pressionamento da tecla ESC
    {
        // Atualiza
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_SPACE)) framesCounter += 8; // Verifica se a tecla ESPAÇO está sendo pressionada: se estiver, o valor de framesCounter aumenta em 8 (acelera o contador).
        else framesCounter++; // Caso contrário, ele incrementa em 1 a cada frame.

        if (IsKeyPressed(KEY_ENTER)) framesCounter = 0; // Verifica se a tecla ENTER foi pressionada e se sim, o contador framesCounter é reiniciado para 0.
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        // Inicia o processo de desenho e limpa o fundo com a cor branca (RAYWHITE).
        BeginDrawing();

            ClearBackground(RAYWHITE); 

            DrawText(TextSubtext(message, 0, framesCounter/10), 210, 160, 20, MAROON); // Isso cria uma animação de texto "digitado", onde os caracteres são revelados gradualmente. 

            DrawText("PRESSIONE [ENTER] para REINICIAR!", 240, 260, 20, LIGHTGRAY); // Instrui o usuário a reiniciar a animação pressionando ENTER.
            DrawText("SEGURE [ESPAÇO] para ACELERAR!", 239, 300, 20, LIGHTGRAY); // Instrui o usuário a acelerar a animação ao pressionar a tecla ESPACO.

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Desinicialização
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha a janela e o contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}