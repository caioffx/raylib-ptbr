/*******************************************************************************************
*
*   raylib [audio] exemplo - Reproduzindo áudio diversas vezes
*
*   Exemplo originalmente criado com raylib 4.6
*
*   Exemplo licenciado sob a licença zlib/libpng não modificada, que é uma licença certificada pela OSI, 
*   similar à BSD, que permite a vinculação estática com software de código fechado
*
*   Copyright (c) 2023 Jeffery Myers (@JeffM2501)
*   Tradução e comentários adicionais por Caio Fabio (@caioffx)
*
********************************************************************************************/

#include "raylib.h"

#define MAX_SOUNDS 10
Sound soundArray[MAX_SOUNDS] = { 0 };
int currentSound;

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
    InitWindow(screenWidth, screenHeight, "raylib [audio] example - playing sound multiple times");

    InitAudioDevice();      // Inicializa o dispositivo de áudio

    // Carrega a lista de áudios
    soundArray[0] = LoadSound("resources/sound.wav");         // Carrega o arquivo de áudio WAV no primeiro slot como o som 'fonte'
                                                              // Esse som possui os dados da amostra
    for (int i = 1; i < MAX_SOUNDS; i++)
    {
        soundArray[i] = LoadSoundAlias(soundArray[0]); // Carrega um alias do som no restante dos slots (1-9)
        // Os aliases não possuem dados independentes, mas podem ser usados para reproduzir o mesmo som em paralelo.
    }

    currentSound = 0;   // Define o índice inicial para o array de sons

    SetTargetFPS(60);   // Configura o jogo para rodar a 60 quadros por segundo (FPS)
    //--------------------------------------------------------------------------------------

    // Laço principal do programa
    while (!WindowShouldClose())    // Detecta se a janela foi fechada ou se a tecla ESC foi pressionada
    {
        // Atualização
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_SPACE)) // Se a tecla ESPAÇO for pressionada
        {
            PlaySound(soundArray[currentSound]);   // Reproduz o som do slot atual
            currentSound++;                        // Incrementa o índice para o próximo som
            
            if (currentSound >= MAX_SOUNDS)        // Se o índice exceder o número de slots
                currentSound = 0;                  // Reinicia o índice para o primeiro slot

            // Observação: Uma abordagem mais eficiente seria verificar o primeiro slot de som que não está em reprodução e usar aquele.
        }
        //----------------------------------------------------------------------------------

        // Desenho
        //----------------------------------------------------------------------------------
        BeginDrawing();  // Inicia a renderização do frame

            ClearBackground(RAYWHITE);  // Limpa o fundo da tela com a cor branca

            DrawText("Pressione ESPAÇO para tocar um som WAV!", 200, 180, 20, LIGHTGRAY);
            // Exibe texto na tela indicando a funcionalidade da tecla ESPAÇO

        EndDrawing();    // Finaliza a renderização do frame
        //----------------------------------------------------------------------------------
    }

    // Desinicialização
    //--------------------------------------------------------------------------------------
    for (int i = 1; i < MAX_SOUNDS; i++)
        UnloadSoundAlias(soundArray[i]); // Descarrega os aliases dos sons (slots 1 a 9)
    
    UnloadSound(soundArray[0]);          // Descarrega os dados do som principal (slot 0)

    CloseAudioDevice();                  // Fecha o dispositivo de áudio

    CloseWindow();                       // Fecha a janela e o contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;   // Finaliza o programa com sucesso
}