#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    int numSecreto, chute;

    srand(time(0)); //seed para o numero aleatorio
    numSecreto = rand() % 100;  //rand gera um numero aleatorio. O resto
                                //da divisão por 100 garante que seja um numero
                                //menor que 100

	printf("******************************************\n");
	printf("* Bem Vindo ao nosso jogo de adivinhacao *\n");
	printf("******************************************\n\n");

	printf("Voce deve adivinhar o numero:\n");
	printf("Digite o seu chute: ");
	scanf("%d",&chute);

	if(chute == numSecreto){
        printf("Parabens! Voce acertou o numero!\n");
	}
	else if(chute < numSecreto){
        printf("O numero secreto e maior que %d!\n",chute);
	}
	else{
        printf("O numero secreto e menor que %d!\n",chute);
	}

	return 0;
}
