/*******************************************************************************************
*
*   raylib [audio] exemplo - Reprodução de música (streaming)
*
*   Exemplo originalmente criado com raylib 1.3, última atualização com raylib 4.0
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
    InitWindow(screenWidth, screenHeight, "raylib [audio] exemplo - Reprodução de música (streaming)");

    InitAudioDevice();              // Inicializa o dispositivo de áudio

    Music music = LoadMusicStream("resources/country.mp3");
    // Carrega o arquivo de música em formato streaming (permite reproduzir arquivos grandes)

    PlayMusicStream(music);         // Inicia a reprodução da música

    float timePlayed = 0.0f;        // Tempo de reprodução normalizado (intervalo de [0.0f a 1.0f])
    bool pause = false;             // Variável para controlar o estado de pausa da música

    SetTargetFPS(30);               // Configura o jogo para rodar a 30 quadros por segundo (FPS)
    //--------------------------------------------------------------------------------------

    // Laço principal do programa
    while (!WindowShouldClose())    // Detecta se a janela foi fechada ou se a tecla ESC foi pressionada
    {
        // Atualização
        //----------------------------------------------------------------------------------
        UpdateMusicStream(music);   // Atualiza o buffer da música com novos dados do stream
        
        // Reinicia a reprodução da música (para e inicia novamente)
        if (IsKeyPressed(KEY_SPACE))   // Se a tecla ESPAÇO for pressionada
        {
            StopMusicStream(music);   // Para a música
            PlayMusicStream(music);   // Reinicia a música
        }

        // Pausar/Retomar a reprodução da música
        if (IsKeyPressed(KEY_P))      // Se a tecla P for pressionada
        {
            pause = !pause;           // Alterna o estado de pausa

            if (pause) PauseMusicStream(music);  // Pausa a música
            else ResumeMusicStream(music);       // Retoma a música
        }

        // Obtém o tempo normalizado da música que já foi reproduzido
        timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);
        // "GetMusicTimePlayed" retorna o tempo decorrido; "GetMusicTimeLength" retorna a duração total.

        if (timePlayed > 1.0f) timePlayed = 1.0f;   // Garante que o tempo não ultrapasse 1.0f (fim da música)
        //----------------------------------------------------------------------------------

        // Desenho
        //----------------------------------------------------------------------------------
        BeginDrawing();   // Inicia a renderização do frame

            ClearBackground(RAYWHITE);  // Limpa o fundo da tela com a cor branca

            DrawText("MÚSICA DEVE ESTAR TOCANDO!", 255, 150, 20, LIGHTGRAY);
            // Desenha texto na tela indicando que a música está sendo reproduzida

            DrawRectangle(200, 200, 400, 12, LIGHTGRAY);
            // Desenha uma barra de fundo cinza clara para representar o progresso da música

            DrawRectangle(200, 200, (int)(timePlayed*400.0f), 12, MAROON);
            // Desenha uma barra de progresso em vermelho proporcional ao tempo reproduzido

            DrawRectangleLines(200, 200, 400, 12, GRAY);
            // Desenha um contorno ao redor da barra de progresso

            DrawText("PRESSIONE ESPAÇO PARA REINICIAR A MÚSICA", 215, 250, 20, LIGHTGRAY);
            // Exibe texto indicando a funcionalidade da tecla ESPAÇO

            DrawText("PRESSIONE P PARA PAUSAR/RETOMAR A MÚSICA", 208, 280, 20, LIGHTGRAY);
            // Exibe texto indicando a funcionalidade da tecla P

        EndDrawing();     // Finaliza a renderização do frame
        //----------------------------------------------------------------------------------
    }

    // Finalização
    //--------------------------------------------------------------------------------------
    UnloadMusicStream(music);   // Libera os buffers do stream de música da memória RAM

    CloseAudioDevice();         // Fecha o dispositivo de áudio (a reprodução é interrompida automaticamente)

    CloseWindow();              // Fecha a janela e o contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;   // Finaliza o programa com sucesso
}
