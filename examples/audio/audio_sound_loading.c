/*******************************************************************************************
*
*   raylib [audio] exemplo - Carregando e tocando som
*
*   Exemplo originalmente criado com raylib 1.1, última atualização com raylib 3.5
*
*   Exemplo licenciado sob a licença zlib/libpng não modificada, que é uma licença certificada pela OSI, 
*   similar à BSD, que permite a vinculação estática com software de código fechado
*
*   Copyright (c) 2019-2024 Ramon Santamaria (@raysan5)
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
    InitWindow(screenWidth, screenHeight, "raylib [audio] example - sound loading and playing");

    InitAudioDevice();      // Inicializa o dispositivo de áudio

    Sound fxWav = LoadSound("resources/sound.wav");         // Carrega arquivo de áudio WAV
    Sound fxOgg = LoadSound("resources/target.ogg");        // Carrega arquivo de áudio OGG

    SetTargetFPS(60);               // Define nosso jogo para rodar a 60 quadros por segundo
    //--------------------------------------------------------------------------------------

    // Loop do jogo principal
    while (!WindowShouldClose())    // Detecta um botão de fechar janela ou tecla ESC
    {
        // Atualizar/modificar
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_SPACE)) PlaySound(fxWav);      // Reproduz o áudio .WAV
        if (IsKeyPressed(KEY_ENTER)) PlaySound(fxOgg);      // Reproduz o áudio .OGG
        //----------------------------------------------------------------------------------

        // Desenhar o conteúdo da janela
        //----------------------------------------------------------------------------------
        BeginDrawing(); 

            ClearBackground(RAYWHITE);
            // Exibe os textos fornecidos na tela, com tamanho 20 e na cor cinza claro
            DrawText("Pressione ESPAÇO para REPRODUZIR o som WAV!", 200, 180, 20, LIGHTGRAY);
            DrawText("Pressione ENTER para REPRODUZIR o som OGG!", 200, 220, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Finalização
    //--------------------------------------------------------------------------------------
    UnloadSound(fxWav);     // Libera espaço de armazenamento dos dados de som
    UnloadSound(fxOgg);     // Libera espaço de armazenamento dos dados de som

    CloseAudioDevice();     // Fecha dispositivo de áudio

    CloseWindow();          // Fecha janela e contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}