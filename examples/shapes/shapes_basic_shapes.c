/*******************************************************************************************
*
*   raylib [formas] exemplo - Desenha formas básicas (retângulo, círculo, linha...)
*
*   Exemplo originalmente criado com raylib 1.0, última atualização com raylib 4.2
*
*   Exemplo licenciado sob uma licença zlib/libpng não modificada, que é uma licença do tipo BSD 
*   certificada pela OSI que permite vinculação estática com software de código fechado
*
*   Copyright (c) 2015-2024 Ramon Santamaria (@raysan5)
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
    const int screenWidth = 800; // Define valor constante para screenWidth (Largura da tela)
    const int screenHeight = 450; // Define valor constante para screenHeight (Altura da tela)

    InitWindow(screenWidth, screenHeight, "raylib [formas] exemplo - Desenha formas básicas"); // Inicializa a janela, define valores para altura e largura da janela

    float rotation = 0.0f; // Cria a variável "rotation" (rotação) para utilizar ela como definidora da velocidade de rotação das formas apresentadas.

    SetTargetFPS(60);               // Define nosso jogo para rodar a 60 quadros por segundo
    //--------------------------------------------------------------------------------------

    // Loop do jogo principal
    while (!WindowShouldClose())    // Detecta um botão de fechar janela ou tecla ESC
    {
        // Atualizar/modificar
        //----------------------------------------------------------------------------------
        rotation += 0.2f;
        //----------------------------------------------------------------------------------

        // Desenhar o conteúdo da janela
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE); // Define cor de fundo de janela/espaço

            DrawText("algumas formas básicas disponíveis na raylib", 20, 20, 20, DARKGRAY); // Escreve na tela (esta função recebe os parâmetros de coordenadas X e Y, tamanho da fonte e a cor)

            // Formas e linhas circulares
            DrawCircle(screenWidth/5, 120, 35, DARKBLUE); // Desenha círculo preenchido por cor, recebendo os parâmetros de: ordenadas x e y, tamanho (raio) e cor.
            DrawCircleGradient(screenWidth/5, 220, 60, GREEN, SKYBLUE); // Desenha círculo, preenchido por cores em modo gradiente, recebendo os parâmetros de: ordenadas x e y, tamanho (raio) e cores que serão gradientes (primeiro cor interna e dps externa).
            DrawCircleLines(screenWidth/5, 340, 80, DARKBLUE); // Desenha só linha do círculo, recebendo os parâmetros de: ordenadas x e y, tamanho (raio) e cor da linha.

            // Formas e linhas retangulares
            DrawRectangle(screenWidth/4*2 - 60, 100, 120, 60, RED); // Desenha retângulo preenchido por cor, recebendo os parâmetros de: ordenadas x e y, largura da forma, altura da forma e cor.
            DrawRectangleGradientH(screenWidth/4*2 - 90, 170, 180, 130, MAROON, GOLD); // Desenha retângulo preenchido por cor, recebendo os parâmetros de: ordenadas x e y, largura da forma, altura da forma e cores que serão gradientes (primeiro cor interna e dps externa).
            DrawRectangleLines(screenWidth/4*2 - 40, 320, 80, 60, ORANGE);  // Desenha só linhas do retângulo, recebendo os parâmetros de: ordenadas x e y, altura e largura da forma e cor da linha. 

            // Formas e linhas triangulares
            DrawTriangle((Vector2){ screenWidth/4.0f *3.0f, 50.0f }, // Desenha um triângulo colorido (vértices no sentido anti-horário) - três parâmetros do tipo Vector2 (que são coordenadas 2D) representando os vértices do triângulo, além de uma cor para preenchê-lo. - v1
                         (Vector2){ screenWidth/4.0f *3.0f - 60.0f, 150.0f }, // Localiza vértice 2.  - v2
                         (Vector2){ screenWidth/4.0f *3.0f + 60.0f, 150.0f }, VIOLET); // Localiza vértice 2. - v3
                                                                                       // v1, v2, v3 são as coordenadas dos três vértices do triângulo, no formato Vector2 {x, y}.

            DrawTriangleLines((Vector2){ screenWidth/4.0f*3.0f, 160.0f }, // Desenha linhas de triângulo (vértices no sentido anti-horário) - três parâmetros do tipo Vector2 (que são coordenadas 2D) representando os vértices do triângulo, além de uma cor da linha. Localiza vértice 1 - v1
                              (Vector2){ screenWidth/4.0f*3.0f - 20.0f, 230.0f }, // Localiza vértice 2.  - v2
                              (Vector2){ screenWidth/4.0f*3.0f + 20.0f, 230.0f }, DARKBLUE); // Localiza vértice 2. - v3

            // Polygon shapes and lines
            //DrawPoly((Vector2){ screenWidth/4.0f*3, 330 }, 6, 80, rotation, BROWN); // desenha polígono regular de 6 lados, com um raio de 80 pixels, centrado em um ponto na tela calculado como 75% da largura da tela (em screenWidth/4.0f*3) e 330 pixels de altura. O polígono será rotacionado pelo valor da variável rotation (em radianos) e será preenchido com a cor marrom (BROWN).
            DrawPolyLines((Vector2){ screenWidth/4.0f*3, 330 }, 6, 90, rotation, BROWN); // Desenha um polígono de 6 lados com raio de 90 pixels, centrado em `(screenWidth/4.0f*3, 330)`, rotacionado pelo valor rotation, com linhas de cor marrom.
            DrawPolyLinesEx((Vector2){ screenWidth/4.0f*3, 330 }, 6, 85, rotation, 6, BEIGE); // Desenha um polígono de 6 lados com raio de 85 pixels, centrado em (screenWidth/4.0f*3, 330), rotacionado pelo valor rotation, com espessura de linha 6 e cor bege (BEIGE).

            // OBSERVAÇÃO: Desenhamos todas as formas baseadas em LINHAS juntas para otimizar o desenho interno, 
            // dessa forma, todas as LINHAS são renderizadas em uma única passada de desenho.
            DrawLine(18, 42, screenWidth - 18, 42, BLACK); // Desenha uma linha na tela, logo abaixo do título do exemplo. 
        EndDrawing(); //Finaliza o desenho
        //----------------------------------------------------------------------------------
    }

    // Finalização
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha janela e contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}