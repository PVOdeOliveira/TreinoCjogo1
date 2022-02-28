#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void titulo(){
    printf("   _       _ _       _       _                     _        \n");
    printf("  /_\\   __| (_)_   _(_)_ __ | |__   __ _ _ __   __| | ___   \n");
    printf(" //_\\\\ / _` | \\ \\ / / | '_ \\| '_ \\ / _` | '_ \\ / _` |/ _ \\  \n");
    printf("/  _  \\ (_| | |\\ V /| | | | | | | | (_| | | | | (_| | (_) | \n");
    printf("\\_/ \\_/\\__,_|_| \\_/ |_|_| |_|_| |_|\\__,_|_| |_|\\__,_|\\___/  \n\n\n"); //Asc2 art generator patorjk.com
}

void jogar(int dificuldade, char player[10]){
    int numSecreto, chute, flag=0, tentativa=1;
    float pontuacao = 500;

    srand(time(0)); //seed para o numero aleatorio da função rand
    numSecreto = rand() % 100;  //rand gera um numero aleatorio. O resto
                                //da divisão por 100 garante que seja um numero
                                //menor que 100

    titulo();
    printf("Voce deve adivinhar o numero:\n");

    while(flag==0){
        printf("** %da. Tentativa **\n", tentativa);
        printf("Digite o seu chute: ");
        scanf("%d",&chute);

        if(chute == numSecreto){
            printf("Parabens! Voce acertou o numero!\n\n");
            flag=1;
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
    }

    printf("Sua pontuacao: %.2f\n",pontuacao);
    printf("Obrigado por Jogar!\n\n");
}

void menu(){
    int op,flag=0,dificuldade;
    char player[10];

    do{
        titulo();
        printf("1. Jogar\n");
        printf("2. Instrucoes\n");
        printf("3. Recordes\n");
        printf("4. Sair\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                jogar(dificuldade,player);
                break;
            case 2:
                //instrucoes
                break;
            case 3:
                //recordes
                break;
            case 4:
                flag=1;
                break;
            default:
                printf ("Valor invalido!\n");

        }
    }while(flag==0);
}

int main(){
    menu();
    return 0;
}
