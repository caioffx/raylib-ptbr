/*******************************************************************************************
*
*   raylib [texturas] exemplo - Carregando e desenhando a imagem em tela
*
*   NOTA: Imagens são carregadas na memória da CPU (RAM); texturas placa de vídeo (VRAM)
*
*   Exemplo originalmente criado com raylib 1.4, última atualização com raylib 1.4
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
    InitWindow(screenWidth, screenHeight, "raylib [texturas] exemplo - Carrega e desenha imagem em tela");

    // NOTA: As texturas DEVEM ser carregadas após a inicialização da janela (o contexto OpenGL é necessário)

    Image cat = LoadImage("resources/cat.png");             // Carrega uma imagem para a memória da CPU (RAM)
    ImageCrop(&cat, (Rectangle){ 100, 10, 280, 380 });      // Recorta um pedaço da imagem
    ImageFlipHorizontal(&cat);                              // Inverte horizontalmente a imagem recortada
    ImageResize(&cat, 150, 200);                            // Redimensiona a imagem invertida e recortada

    Image parrots = LoadImage("resources/parrots.png");     // Carrega outra imagem para a memória da CPU (RAM)

    // Desenha uma imagem sobre a outra com escala de 1.5x
    ImageDraw(&parrots, cat, (Rectangle){ 0, 0, (float)cat.width, (float)cat.height }, (Rectangle){ 30, 40, cat.width*1.5f, cat.height*1.5f }, WHITE);
    // Copia a imagem "cat" sobre a imagem "parrots", redimensionando a área de destino com escala 1.5x.
    ImageCrop(&parrots, (Rectangle){ 0, 50, (float)parrots.width, (float)parrots.height - 100 }); 
    // Recorta novamente a imagem "parrots", removendo 50 pixels do topo e 100 da base.

    // Desenhar na imagem usando métodos de desenho de imagem
    ImageDrawPixel(&parrots, 10, 10, RAYWHITE);               // Desenha um pixel branco na posição (10, 10)
    ImageDrawCircleLines(&parrots, 10, 10, 5, RAYWHITE);      // Desenha um círculo apenas com linhas ao redor do pixel
    ImageDrawRectangle(&parrots, 5, 20, 10, 10, RAYWHITE);    // Desenha um retângulo branco de 10x10 pixels

    UnloadImage(cat);       // Descarrega a imagem "cat" da RAM

    // Carrega uma fonte personalizada para desenhar sobre a imagem
    Font font = LoadFont("resources/custom_jupiter_crash.png");

    // Desenha texto na imagem usando a fonte personalizada
    ImageDrawTextEx(&parrots, font, "PARROTS & CAT", (Vector2){ 300, 230 }, (float)font.baseSize, -2, WHITE);

    UnloadFont(font);       // Descarrega a fonte personalizada da memória

    Texture2D texture = LoadTextureFromImage(parrots);      // Converte a imagem para textura e a envia à memória da GPU (VRAM)
    UnloadImage(parrots);   // Após ser carregada como textura, a imagem original pode ser descartada da RAM

    SetTargetFPS(60);       // Define nosso jogo para rodar a 60 quadros por segundo
    //---------------------------------------------------------------------------------------

    // Loop do jogo principal
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Atualizar/modificar
        //----------------------------------------------------------------------------------
        // Para fazer: atualize e insira suas variáveis aqui
        //----------------------------------------------------------------------------------

        // Desenhar o conteúdo da janela
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Desenha a textura na posição central da janela, ajustando coordenadas
            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2 - 40, WHITE);

            // Desenha um retângulo ao redor da textura para destacá-la visualmente
            DrawRectangleLines(screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2 - 40, texture.width, texture.height, DARKGRAY);

            DrawText("Desenhando uma textura a partir de várias imagens compostas!", 240, 350, 10, DARKGRAY);
            DrawText("Imagens originais foram cortadas, dimensionadas, invertidas e copiadas uma sobre a outra.", 190, 370, 10, DARKGRAY);

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
