#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    int numSecreto, chute, flag=0, tentativa=1;
    float pontuacao = 500;

    srand(time(0)); //seed para o numero aleatorio da função rand
    numSecreto = rand() % 100;  //rand gera um numero aleatorio. O resto
                                //da divisão por 100 garante que seja um numero
                                //menor que 100

    printf("******************************************\n");
    printf("* Bem Vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n\n\n");

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
    printf("Obrigado por Jogar!");
    return 0;
}
