/*******************************************************************************************
*
*   raylib [textures] exemplo - sprite de explosão
*
*   Exemplo originalmente criado com raylib 2.5, última atualização com raylib 3.5
*
*   Exemplo licenciado sob a licença zlib/libpng não modificada, que é uma licença certificada pela OSI, 
*   similar à BSD, que permite a vinculação estática com software de código fechado
*
*   Copyright (c) 2019-2024 Ramon Santamaria (@raysan5)
*   Tradução e comentários adicionais por Caio Fabio (@caioffx)
*
********************************************************************************************/

#include "raylib.h"

#define NUM_FRAMES_PER_LINE     5
#define NUM_LINES               5

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
    InitWindow(screenWidth, screenHeight, "raylib [textures] exemplo - sprite de explosão");

    // Chama função que inicializa os dispositivos de áudio a reproduzirem sons
    InitAudioDevice();

    // Cria variável fxBoom e carrega o arquivo do som de explosão
    Sound fxBoom = LoadSound("resources/boom.wav");

    // Cria variável explosion e carrega o arquivo com a textura de explosão (um png de uma sprite sheet, uma imagem com várias subimagens organizadas em linhas e colunas, normalmente representando uma sequência de eventos)
    Texture2D explosion = LoadTexture("resources/explosion.png");

    // Inicia as variáveis ​​para animação
    // Calculam as dimensões de cada quadro (subimagem) dividindo a largura/altura total do sprite sheet pelo número de frames/linhas.
    float frameWidth = (float)(explosion.width/NUM_FRAMES_PER_LINE);   
    float frameHeight = (float)(explosion.height/NUM_LINES);           
    
    // Representam o índice atual da animação. Primeiro quadro está na linha 0 e coluna 0.
    int currentFrame = 0;
    int currentLine = 0;

    Rectangle frameRec = { 0, 0, frameWidth, frameHeight }; // Define a região da sprite sheet que será desenhada. Inicialmente, começa no quadro superior esquerdo (x = 0, y = 0).
    Vector2 position = { 0.0f, 0.0f }; // Determina a posição onde a explosão será desenhada na tela.

    bool active = false; // Controla se a animação está ativa ou não.
    int framesCounter = 0; // Conta os frames do jogo para controlar a velocidade da animação.

    SetTargetFPS(60);               // Define nosso jogo para rodar a 60 quadros por segundo
    //---------------------------------------------------------------------------------------

    // Loop do jogo principal
    while (!WindowShouldClose())    // Detecta um botão de fechar janela ou tecla ESC
    {
        // Atualizar/modificar
        //----------------------------------------------------------------------------------

        // Verifica se o botão esquerdo do mouse foi pressionado e ativa a explosão (se não estiver ativa)
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !active)
        {
            position = GetMousePosition();
            active = true;

            position.x -= frameWidth/2.0f;
            position.y -= frameHeight/2.0f;
            
            // Reproduz o som de explosão
            PlaySound(fxBoom);
        }

        // Animação do sprite sheet: contabiliza quadros de animação da explosão
        if (active)
        {
            // O contador framesCounter controla a velocidade da animação, avançando a cada 3 frames. 
            framesCounter++;

            if (framesCounter > 2)
            {
                // O currentFrame percorre os quadros horizontalmente, e o currentLine avança para a próxima linha quando todos os quadros de uma linha são usados. 
                currentFrame++;

                if (currentFrame >= NUM_FRAMES_PER_LINE)
                {
                    currentFrame = 0;
                    currentLine++;
                    
                    // Quando todos os quadros são exibidos, a animação termina e active é definido como falso.
                    if (currentLine >= NUM_LINES)
                    {
                        currentLine = 0;
                        active = false;
                    }
                }

                framesCounter = 0;
            }
        }

        // Atualiza frameRec com as coordenadas do quadro atual na sprite sheet.
            
        frameRec.x = frameWidth*currentFrame;
        frameRec.y = frameHeight*currentLine;
        //----------------------------------------------------------------------------------

        // Desenhar o conteúdo da janela
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Desenha a região frameRec da textura explosion na posição position. Só é chamado enquanto a animação está ativa.
            if (active) DrawTextureRec(explosion, frameRec, position, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Finalização
    //--------------------------------------------------------------------------------------
    UnloadTexture(explosion);   // Libera a memória alocada para a textura.
    UnloadSound(fxBoom);        // Libera a memória alocada para o som.

    CloseAudioDevice();         // Fecha o dispositivo de áudio.

    CloseWindow();              // Fecha janela e contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}