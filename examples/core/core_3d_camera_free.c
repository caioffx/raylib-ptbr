/*******************************************************************************************
*
*   raylib [núcleo] exemplo - Inicializa câmera-livre em 3d
*
*   Exemplo originalmente criado com raylib 1.3, última atualização com raylib 1.3
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

    InitWindow(screenWidth, screenHeight, "raylib [núcleo] exemplo - câmera-livre em 3d"); // Inicializa a janela, define valores para altura e largura da janela

    // Define a struct de câmera 3D para olhar para o espaço tridimensional gerado para o jogo
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Posição da câmera (struct Vector 3 dentro da struct Camera3D - ordenadas x - horizontal, y - vertical, z - profundidade)
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Posição inicial do alvo da câmera que é observado
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Vetor de câmera para cima (rotação sobre seu eixo do alvo)
    camera.fovy = 45.0f;                                // Abertura do campo de visão da câmera em Y (graus) em perspectiva, usada como largura próxima ao plano em ortográfico
    camera.projection = CAMERA_PERSPECTIVE;             // Tipo de projeção da câmera (neste caso, de perspectiva, ou seja, )

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f }; //Define que "cubePosition" (ou seja, a posição do cubo que será observado através da câmera 3D definida acima) será uma struct Vector3, com três variáveis do tipo float, o primeiro para x (posição no eixo horizontal x), o segundo para y (posição no eixo vertical y) e o terceiro para z (posição no eixo profundidade z).

    DisableCursor();                    // Limita o cursor ao movimento relativo dentro da janela

    SetTargetFPS(60);                   // Define nosso jogo para rodar a 60 quadros por segundo
    //--------------------------------------------------------------------------------------

    // Loop do jogo principal
    while (!WindowShouldClose())        // Detecta um botão de fechar janela ou tecla ESC
    {
        // Atualizar/modificar
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_FREE); // Atualizar posição da câmera para o modo selecionado

        if (IsKeyPressed('Z')) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f }; // Retorna posição de câmera para posição inicial (0,0,0)
        //----------------------------------------------------------------------------------

        // Desenhar o conteúdo da janela
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE); //Define cor de fundo de janela/espaço

            BeginMode3D(camera); //Inicia o modo de câmera 3D observando um espaço

                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED); //Desenha o cubo (recebe parâmetro da posição que ele se encontrará nos eixos x, y, z, após, recebe em floats a largura, altura e profundidade do cubo e por fim sua cor)
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON); //Desenha as arestas do cubo (recebe parâmetro da posição que ele se encontrará nos eixos x, y, z, após, recebe em floats a largura, altura e profundidade do cubo e por fim sua cor)

                DrawGrid(10, 1.0f); // Desenha a grade onde o cubo fica posicionado

            EndMode3D(); // Finaliza o modo de câmera 3D observando um espaço

            DrawRectangle( 10, 10, 320, 93, Fade(SKYBLUE, 0.5f)); // Desenha retângulo para organizar e destacar comandos padrões para a câmera-livre (parâmetros de posição X, pos Y, altura e largura, além de escolher cor)
            DrawRectangleLines( 10, 10, 320, 93, BLUE); // Desenha linhas de contorno do retângulo para organizar e destacar comandos padrões para a câmera-livre (parâmetros de posição X, pos Y, altura e largura, além de escolher cor)

            DrawText("Comandos padrões para câmera-livre:", 20, 20, 10, BLACK); // Escreve na tela (esta função recebe os parâmetros de posição X e Y, tamanho da fonte e a cor)
            DrawText("- Roda do mouse para +/- zoom", 40, 40, 10, DARKGRAY); 
            DrawText("- Pressionar roda do mouse para panorâmica", 40, 60, 10, DARKGRAY);
            DrawText("- Z para retornar a alvo (0, 0, 0)", 40, 80, 10, DARKGRAY);

        EndDrawing(); //Finaliza o desenho
        //----------------------------------------------------------------------------------
    }

    // Finalização
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha janela e contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}