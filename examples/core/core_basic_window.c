/*******************************************************************************************
*
*   raylib [núcleo] exemplo - Janela básica
*   
*   Bem-vindo à raylib!
*
*   Para testar os exemplos, pressione F6 e para executar o script raylib_compile_execute 
*   Observe que o executável compilado é colocado na mesma pasta que o arquivo .c
*
*   Você pode encontrar todos os exemplos básicos na pasta C:\raylib\raylib\examples ou
*   na página oficial do raylib: www.raylib.com
*
*   Aproveite o uso da raylib. :)
*
*   Exemplo originalmente criado com raylib 1.0, última atualização com raylib 1.0
*
*   Exemplo licenciado sob uma licença zlib/libpng não modificada, que é uma licença do tipo BSD 
*   certificada pela OSI que permite vinculação estática com software de código fechado
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*   Tradução e comentários adicionais por Caio Fabio (@caioffx)
*
********************************************************************************************/

#include <raylib.h>

//------------------------------------------------------------------------------------
// Ponto de entrada do programa principal (main)
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialização
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800; //Define valor constante para screenWidth (Largura da tela)
    const int screenHeight = 450; //Define valor constante para screenHeight (Altura da tela)

    InitWindow(screenWidth, screenHeight, "raylib [núcleo] exemplo - Janela básica"); //Inicializa a janela, define valores para altura e largura da janela

    SetTargetFPS(60);               // Define nosso jogo para rodar a 60 quadros por segundo
    //--------------------------------------------------------------------------------------

    // Loop do jogo principal
    while (!WindowShouldClose())    // Detecta um botão de fechar janela ou tecla ESC
    {
        // Atualizar/modificar
        //----------------------------------------------------------------------------------
        // Para fazer: atualize e insira suas variáveis aqui
        //----------------------------------------------------------------------------------

        // Desenhar o conteúdo da janela
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKGRAY); //Define cor de fundo de janela

            DrawText("Parabéns! Você criou sua primeira janela!", 190, 200, 20, SKYBLUE); //Define mensagem mostrada na janela, a posição e a cor da mensagem 

        EndDrawing(); //Finaliza o desenho
        //----------------------------------------------------------------------------------
    }

    // Finalização
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha janela e contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}