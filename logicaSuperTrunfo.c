#include <stdio.h>
#include <stdlib.h>
#define maxCarta 32

//eu sem querer fiz tudo na primeira parte do desafio, então copiei e colei aqui só para registrar!

    int contCard = 1, escolha, cartaIndice1, cartaIndice2, verif= 0, listarJ1, listarJ2, atri1, atri2, pontu1=0, pontu2=0;

    typedef struct { //estrutura das cartas
    int populacao, pontosTuristicos;
    int numero;
    float area, pib, densidade, pibPerC;
    char codigo;
    } carta;

    carta varCarta[maxCarta]; //variável varCarta do tipo carta



    void resultado(int pont1, int pont2){
        if (pont1 == pont2){
            printf("EMPATE\n");
        }
        else if (pont1 > pont2){
            printf("VITÓRIA DO JOGADOR 1\n");
        }
        else if (pont2 > pont1){
            printf("VITÓRIA DO JOGADOR 2\n");
        }
    }

    void listarJ1Func(int *listarJ1){
        printf("Selecione a carta do jogador 1: \n");
        for (int c=1; c<contCard; c++){
            printf("[%d] Carta %c-0%d\n", c, varCarta[c].codigo, varCarta[c].numero);
        }
        scanf("%d", listarJ1);
        if (*listarJ1 < 1 || *listarJ1 > contCard){
            printf("Escolha uma opção válida, por favor.\n");
            listarJ1Func(listarJ1);
        }  
    }

        void listarJ2Func(int *listarJ2, int listarJ1){
        printf("Selecione a carta do jogador 2: \n");
        for (int c=1; c<contCard; c++){
            printf("[%d] Carta %c-0%d\n", c, varCarta[c].codigo, varCarta[c].numero);
        }
        scanf("%d", listarJ2);
        if ((*listarJ2 < 1 || *listarJ2 > contCard) || listarJ1==*listarJ2){
            printf("Escolha uma opção válida, por favor.\n");
            listarJ2Func(listarJ2, listarJ1);
        }  
    }


    void cadastro(carta *card){
        do{
        printf("Por favor, digite o código do estado (A-H): ");
        scanf(" %c", &card->codigo);
        printf("Por favor, digite o número da cidade(1-4): ");
        scanf("%d", &card->numero);
        while (card->numero<1 || card->numero>4){
            printf("Digite um número válido, por favor.\n");
            printf("Por favor, digite o número da cidade(1-4): ");
            scanf("%d", &card->numero);
        }
        for (int i=0; i<contCard; i++){
            if (varCarta[i].codigo == card->codigo && varCarta[i].numero == card->numero){
                printf("código %c-0%d repetido, por favor, digite um número diferente!\n", card->codigo, card->numero);
                verif = 1;
                break;
            }
            else {
                verif = 0;
            }
        }
        }
        while (verif == 1);
            printf("Por favor, digite o número da população: ");
            scanf("%d", &card->populacao);
            printf("Por favor, digite a area da cidade: ");
            scanf("%f", &card->area);
            printf("Por favor, digite o PIB da cidade ");
            scanf("%f", &card->pib);
            printf("Por favor, digite o número de pontos turísticos na cidade: ");
            scanf("%d", &card->pontosTuristicos);
            card->densidade=card->populacao/card->area;
            card->pibPerC=card->pib/card->populacao;
            contCard++;
    }

    void selAtri(int *atri1, int *atri2){

        printf("Selecione o atributo que gostaria de comparar: ");
        printf("[1] População\n");
        printf("[2] Área em Km²\n");
        printf("[3] PIB\n");
        printf("[4] Número de pontos turísticos\n");
        printf("[5] Densidade demográfica\n");
        printf("[6] PIB per capita\n");
        printf("Primeiro atributo: \n");
        scanf("%d", atri1);
        printf("Segundo atributo: \n");
        scanf("%d", atri2);
        if ((*atri1<1 || *atri1>6) || (*atri2<1 || *atri2>6)){
            printf("Digite um valor válido. \n");
            selAtri(atri1, atri2);
        }    
    }

    void imprimir(int indice1, int indice2){
        printf("== CARTA JOGADOR 1 ==\n");
        printf("Carta %c-0%d \n", varCarta[indice1].codigo, varCarta[indice1].numero);
        printf("População: %d habitantes\n", varCarta[indice1].populacao);
        printf("Área em Km²: %.2f Km²\n", varCarta[indice1].area);
        printf("PIB: R$ %.2f \n", varCarta[indice1].pib);
        printf("Número de pontos turistícos: %d\n", varCarta[indice1].pontosTuristicos);
        printf("Densidade demográfica: %.2f hab/km²\n", varCarta[indice1].densidade);
        printf("PIB per capita: %.2f R$/hab\n", varCarta[indice1].pibPerC);

        printf("== CARTA JOGADOR 2 ==\n");
        printf("Carta %c-0%d \n", varCarta[indice2].codigo, varCarta[indice2].numero);
        printf("População: %d habitantes\n", varCarta[indice2].populacao);
        printf("Área em Km²: %.2f Km²\n", varCarta[indice2].area);
        printf("PIB: R$ %.2f \n", varCarta[indice2].pib);
        printf("Número de pontos turistícos: %d\n", varCarta[indice2].pontosTuristicos);
        printf("Densidade demográfica: %.2f hab/km²\n", varCarta[indice2].densidade);
        printf("PIB per capita: %.2f R$/hab\n", varCarta[indice2].pibPerC);
    }

    void compararCartas(int atributo, int carta1, int carta2, int *pont1, int *pont2){
        switch(atributo){
            case 1: //população
                printf("População: %d habitantes  .VS.  População: %d habitantes\n", varCarta[carta1].populacao, varCarta[carta2].populacao);
                if (varCarta[carta1].populacao > varCarta[carta2].populacao){
                    (*pont1)++;
                }
                else if (varCarta[carta2].populacao > varCarta[carta1].populacao){
                    (*pont2)++;
                }
                break;

            case 2: //área
                printf("Área em Km²: %.2f Km²  .VS.  Área em Km²: %.2f Km²\n", varCarta[carta1].area, varCarta[carta2].area);
                if (varCarta[carta1].area > varCarta[carta2].area){
                    (*pont1)++;
                }
                else if (varCarta[carta2].area > varCarta[carta1].area){
                    (*pont2)++;
                }
                break;

            case 3: // pib
                printf("PIB: R$ %.2f  .VS.  PIB: R$ %.2f\n", varCarta[carta1].pib, varCarta[carta2].pib);
                if (varCarta[carta1].pib > varCarta[carta2].pib){
                    (*pont1)++;
                }
                else if (varCarta[carta2].pib > varCarta[carta1].pib){
                    (*pont2)++;
                }
                break;

            case 4: //pontos turísticos
                printf("Número de pontos turísticos: %d  .VS.  Número de pontos turísticos: %d\n", varCarta[carta1].pontosTuristicos, varCarta[carta2].pontosTuristicos);
                if (varCarta[carta1].pontosTuristicos > varCarta[carta2].pontosTuristicos){
                    (*pont1)++;
                }
                else if (varCarta[carta2].pontosTuristicos > varCarta[carta1].pontosTuristicos){
                    (*pont2)++;
                }
                break;

            case 5: // densidade
                printf("Densidade demográfica: %.2f hab/km²  .VS.  Densidade demográfica: %.2f hab/km²\n", varCarta[carta1].densidade, varCarta[carta2].densidade);
                if (varCarta[carta1].densidade > varCarta[carta2].densidade){
                    (*pont1)++;
                }
                else if (varCarta[carta2].densidade > varCarta[carta1].densidade){
                    (*pont2)++;
                }
                break;

            case 6: //pib per capita
                printf("PIB per capita: %.2f R$/hab  .VS.  PIB per capita: %.2f R$/hab\n", varCarta[carta1].pibPerC, varCarta[carta2].pibPerC);
                if (varCarta[carta1].pibPerC > varCarta[carta2].pibPerC){
                    (*pont1)++;
                }
                else if (varCarta[carta2].pibPerC > varCarta[carta1].pibPerC){
                    (*pont2)++;
                }
                break;
}
}

    void menu(){
        printf("========================================");
        printf("= Por favor, escolha uma das opções:   =");
        printf("= [1] Cadastrar uma carta              =");
        printf("= [2] Comparar cartas                  =");
        printf("= [3] Finalizar programa               =");
        printf("========================================");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                cadastro(&varCarta[contCard]);
                menu();
                break;
            case 2:
                listarJ1Func(&listarJ1);
                listarJ2Func(&listarJ2, listarJ1);
                selAtri(&atri1, &atri2);
                imprimir(listarJ1, listarJ2);
                compararCartas(atri1, listarJ1, listarJ2, &pontu1, &pontu2);
                compararCartas(atri2, listarJ1, listarJ2, &pontu1, &pontu2);
                resultado(pontu1, pontu2);
                menu();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("opção inválida, tente novamente.\n");
                menu();
                break;
        }
    }

int main(){
    menu();
    return 0;
}