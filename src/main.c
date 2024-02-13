#include <stdio.h>
#include <string.h>
#include "estruturaDados/estruturas.h"
#include "estruturaDados/pilha_enc.h"
#include "estruturaDados/lista_enc.h"
#include "estruturaDados/lista_enc_dupla.h"
#include "raylib.h"



int main(){

   PilhaBaralho *baralho;
   baralho = criaPilhaEnc();
   inicializaBaralho(baralho);


    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib - Mostrar imagem");

    // Carrega a imagem
    Texture2D texture = LoadTexture("resources/imagens/cartas/card_0_0.png");
      
    // Configura a posição inicial para desenhar a imagem (centro da tela)
    Vector2 position = {(screenWidth - texture.width) / 2.0f, (screenHeight - texture.height) / 2.0f};

    // Define a cor de fundo da janela (opcional)
    SetTargetFPS(60); // Define a taxa de atualização da tela

    // Loop principal
    while (!WindowShouldClose()) { // Detecta o pedido de fechamento da janela
        BeginDrawing();

        ClearBackground(RAYWHITE); // Limpa a tela com cor branca

        // Desenha a imagem na posição especificada
        DrawTexture(texture, position.x, position.y, WHITE); // WHITE significa sem coloração

        EndDrawing();
    }

    // Limpeza e fechamento
    UnloadTexture(texture); // Libera a memória da textura
    CloseWindow(); // Fecha a janela

    return 0;
}
