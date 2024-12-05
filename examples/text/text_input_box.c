/*******************************************************************************************
*
*   raylib [text] exemplo - Caixa de entrada (teclado)
*
*   Exemplo originalmente criado com raylib 1.7, última atualização com raylib 3.5
*
*   Exemplo licenciado sob a licença zlib/libpng não modificada, que é uma licença certificada pela OSI, 
*   similar à BSD, que permite a vinculação estática com software de código fechado
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*   Tradução e comentários adicionais por Caio Fabio (@caioffx)
*
********************************************************************************************/

#include "raylib.h"

#define MAX_INPUT_CHARS     9 // Reserva o nome MAX_INPUT_CHARS e atribui o valor 9 para o máximo de caracteres de entrada.

//------------------------------------------------------------------------------------
// Ponto de entrada principal do programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialização
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;    // Largura da tela
    const int screenHeight = 450;   // Altura da tela

    InitWindow(screenWidth, screenHeight, "raylib [text] exemplo - Caixa de entrada"); // Inicializa a janela com o título

    char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTA: Um espaço extra (+1) é necessário para o caractere terminador nulo '\0'.
    int letterCount = 0; // Inicializa o contador de caracteres (ajuda a controlar o número máximo de caracteres).

    Rectangle textBox = { screenWidth/2.0f - 100, 180, 225, 50 }; // Gera um retângulo que será a caixa que receberá textos.
    bool mouseOnText = false; // Define que se o mouse não estiver sobre a caixa de texto, ficará o cursor padrão (seta)

    int framesCounter = 0; // Inicializa em 0 um contador de quadros (frames)

    SetTargetFPS(60);               // Define o FPS do jogo para 60 (jogo vai rodar a 60 quadros por segundo)
    //--------------------------------------------------------------------------------------

    // Loop do algoritmo principal
    while (!WindowShouldClose())    // Detecta o fechamento da janela ou pressionamento da tecla ESC
    {
        // Atualiza
        //----------------------------------------------------------------------------------
        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true; // Obtém a posição atual do cursor do mouse e verifica se o ponto representado pela posição do mouse está dentro do retângulo definido por textBox.
        else mouseOnText = false;

        if (mouseOnText) 
        {
            // Se o mouse estiver sobre a caixa de texto a função abaixo define o cursor do mouse como cursor de texto (I-Beam).
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            int key = GetCharPressed(); // Cria uma key para detectar um caractere pressionado. 

            // Verifica se mais caracteres foram pressionados no mesmo quadro
            while (key > 0)
            {
                // NOTA: O caractere está no intervalo ASCII [32..125] (evita teclas inválidas). 
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) // Se está no intervalo ASCII e o número de caracteres digitados (letterCount) ainda não ultrapassou o limite de MAX_INPUT_CHARS:

                {
                    name[letterCount] = (char)key; // O caractere é adicionado ao array name.
                    name[letterCount+1] = '\0'; // '\0' é adicionado ao final da string para garantir que ela seja válida.
                    letterCount++; // Incremento do contador de caracteres
                }

                key = GetCharPressed();  // Verifique o próximo caractere na fila
            }

            if (IsKeyPressed(KEY_BACKSPACE)) // Se o usuário pressionar a tecla Backspace:
            {
                letterCount--; // letterCount é decrementado, reduzindo o tamanho da string.
                if (letterCount < 0) letterCount = 0; //Se letterCount ficar menor que 0, ele é ajustado para 0.
                name[letterCount] = '\0'; // O caractere no final da string é substituído por '\0', apagando efetivamente o último caractere.
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT); // Senão, o mouse estiver fora a caixa de texto a função abaixo define o cursor do mouse como cursor padrão (seta).


        if (mouseOnText) framesCounter++; // Se o mouse estiver sobre a caixa de texto: framesCounter é incrementado a cada frame.
        else framesCounter = 0; // Senão, o framesCounter é zerado
        //----------------------------------------------------------------------------------

        // Desenhar na tela a caixa de texto, instruções, contador de caracteres. 
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE); // Limpa o conteúdo anterior da tela e define o fundo com a cor branca (RAYWHITE)

            DrawText("COLOQUE O MOUSE SOBRE A CAIXA DE ENTRADA!", 240, 140, 20, GRAY); // Exibir uma mensagem na tela instruindo o usuário.

            DrawRectangleRec(textBox, LIGHTGRAY); // Desenha o retângulo que representa a caixa de entrada de texto e textBox é o retângulo definido anteriormente com posição e dimensões fixas.

            // Desenha as bordas da caixa de entrada de texto: Se o mouse estiver sobre a caixa (mouseOnText == true), a borda é desenhada em vermelho (RED). Caso contrário, a borda é desenhada em cinza escuro (DARKGRAY).
            if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED); 
            else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

            DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON); // Desenha o texto que o usuário digitou na caixa de entrada.

            DrawText(TextFormat("CARACTERES: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY); // Mostra a quantidade de caracteres digitados e o limite permitido.

            // Se o mouse estiver sobre a caixa de texto:
            if (mouseOnText)
            {   
                //  Se o número de caracteres digitados (letterCount) for menor que o limite (MAX_INPUT_CHARS): um caractere "_" (sublinhado) é desenhado piscando ao lado do texto digitado.
                if (letterCount < MAX_INPUT_CHARS)
                {
                    // Draw blinking underscore char
                    if (((framesCounter/20)%2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
                }
                else DrawText("Pressione BACKSPACE para apagar caracteres...", 230, 300, 20, GRAY); // Se o limite for atingido, uma mensagem é exibida.
            }

        EndDrawing(); // Finaliza desenho
        //----------------------------------------------------------------------------------
    }

    // Desinicialização
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha a janela e o contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}

// Verifica se alguma tecla foi pressionada e retorna que foi
// NOTA: Limitamos a verificação de teclas para teclas entre 32 (KEY_SPACE) e 126 (tabela ASCII)
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}
