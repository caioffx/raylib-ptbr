/*******************************************************************************************
*
*   raylib [texturas] exemplo - Carregamento de imagem e criação de textura
*
*   NOTA: Imagens são carregadas na memória da CPU (RAM); texturas placa de vídeo (VRAM)
*
*   Exemplo originalmente criado com raylib 1.3, última atualização com raylib 1.3
*
*   Exemplo licenciado sob a licença zlib/libpng não modificada, que é uma licença certificada pela OSI, 
*   similar à BSD, que permite a vinculação estática com software de código fechado
*
*   Copyright (c) 2015-2024 Ramon Santamaria (@raysan5)
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
    InitWindow(screenWidth, screenHeight, "raylib [texturas] exemplo - Carregamento de imagem");

    // NOTA: As texturas DEVEM ser carregadas após a inicialização da janela (o contexto OpenGL é necessário)

    Image image = LoadImage("resources/raylib_logo.png");     // Carregado na memória da CPU (RAM)
    Texture2D texture = LoadTextureFromImage(image);          // Imagem convertida em textura, memória GPU (VRAM)
    UnloadImage(image);   // Depois que a imagem for convertida em textura e carregada na VRAM, ela pode ser descarregada da RAM (liberar mermória)

    SetTargetFPS(60);     // Define nosso jogo para rodar a 60 quadros por segundo
    //---------------------------------------------------------------------------------------

    // Loop do jogo principal
    while (!WindowShouldClose())    // Define nosso jogo para rodar a 60 quadros por segundo
    {
        // Atualizar/modificar
        //----------------------------------------------------------------------------------
        // Para fazer: atualize e insira suas variáveis aqui
        //----------------------------------------------------------------------------------

        // Desenhar o conteúdo da janela
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            // Renderiza a textura carregada no centro da tela, ajustando sua posição horizontal e vertical de acordo com as dimensões da tela e da textura.
            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);

            // Exibe o texto fornecido na tela, na posição (300, 370), com tamanho 10 e na cor cinza.    
            DrawText("Esta é uma textura carregada de uma imagem!", 300, 370, 10, GRAY);

        EndDrawing();    // Finaliza o desenho do frame
        //----------------------------------------------------------------------------------
    }

    // Finalização
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);       // Libera a memória alocada para a textura.

    CloseWindow();                // Fecha janela e contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}
