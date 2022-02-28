#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

void titulo(){
    system("cls");
    printf("            _       _ _       _       _                     _        \n");
    printf("           /_\\   __| (_)_   _(_)_ __ | |__   __ _ _ __   __| | ___   \n");
    printf("          //_\\\\ / _` | \\ \\ / / | '_ \\| '_ \\ / _` | '_ \\ / _` |/ _ \\  \n");
    printf("         /  _  \\ (_| | |\\ V /| | | | | | | | (_| | | | | (_| | (_) | \n");
    printf("         \\_/ \\_/\\__,_|_| \\_/ |_|_| |_|_| |_|\\__,_|_| |_|\\__,_|\\___/  \n\n\n"); //Asc2 art generator patorjk.com
}

void jogar(int dificuldade, char player[10]){
    int numSecreto, chute, flag=0, tentativa=1,chances;
    float pontuacao = 500;

    srand(time(0)); //seed para o numero aleatorio da função rand
    numSecreto = rand() % 100;  //rand gera um numero aleatorio. O resto
                                //da divisão por 100 garante que seja um numero
                                //menor que 100

    if (dificuldade==1){
        chances=15;
    }
    else if(dificuldade==2){
        chances=9;
    }
    else{
        chances=5;
    }

    titulo();
    printf("Voce deve adivinhar o numero:\n");

    while(flag==0){
        if(tentativa==chances){
            printf("** ULTIMA TENTATIVA **\n");
        }
        else{
            printf("**  %da. Tentativa  **\n", tentativa);
        }
        printf("Digite o seu chute: ");
        scanf("%d",&chute);

        if(chute == numSecreto){
            flag=1; //fim de jogo vitoria
        }
        else if(chute < numSecreto){
            printf("O numero secreto e MAIOR que %d!\n\n",chute);
        }
        else{
            printf("O numero secreto e MENOR que %d!\n\n",chute);
        }
        tentativa++;

        pontuacao -= (abs(numSecreto-chute));   //A cada tentativa, é tirado a diferenca
                                                //do chute pelo numSecreto da pontuaçao total

        if(tentativa>chances){
            flag=1; //fim de jogo derrota
            pontuacao=0;
        }
    }

    titulo();
    if(tentativa>chances){ //perdeu
        printf("Voce perdeu!! O numero secreto era %d\n", numSecreto);
    }
    else{ //venceu
        printf("Parabens!! Você descobriu o numero secreto!! ** %d **\n", numSecreto);
    }

    printf("Sua pontuacao: %.2f\n",pontuacao);
    printf("Obrigado por Jogar!\n");

    getchar(); //limpar buffer
    printf("\nPressione enter para voltar ao menu: \n");
    getchar();
}

void menu(){
    int op,flag=0,dificuldade;
    char player[10];

    do{
        titulo();
        printf("Digite o numero da opcao desejada:\n");
        printf("1. Jogar\n");
        printf("2. Instrucoes\n");
        printf("3. Recordes\n");
        printf("4. Sair\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                titulo();

                printf("Digite o nick do jogador: ");
                scanf("%s",&player);

                printf("\nEscolha a dificuldade: \n");
                printf("1. Facil    (15 tentativas)\n");
                printf("2. Medio    (09 tentativas)\n");
                printf("3. Dificil  (05 tentativas)\n");
                scanf("%d",&dificuldade);

                jogar(dificuldade,player); //função onde o jogo acontece.

                break;
            case 2:
                titulo();

                printf("    O jogo consiste em adivinhar um numero secreto. O numero e gerado \n");
                printf("aleatoriamente no inicio de cada partida. Apos cada jogada, e mostrado\n");
                printf("se o jogador acertou ou se o numero secreto e maior ou menor que o chu\n");
                printf("te digitado.\n");
                printf("    A pontuacao e calculada pela diferenca entre o chute e o numero se\n");
                printf("creto. A pontuacao maxima e de 500 pontos, e a cada jogada a diferenca\n");
                printf("e deduzida dessa pontuacao.\n");

                getchar(); //limpar buffer
                printf("\nPressione enter para voltar ao menu: \n");
                getchar();
                break;
            case 3:
                titulo();
                printf("Em breve!!\n");

                getchar(); //limpar buffer
                printf("\nPressione enter para voltar ao menu: \n");
                getchar();
                break;
            case 4:
                flag=1;
                break;
            default:
                titulo();
                printf ("Valor invalido!\n");
                getchar(); //limpar buffer
                printf("\nPressione enter para voltar ao menu: \n");
                getchar();


        }
    }while(flag==0);
}

int main(){

    menu();

    return 0;
}
