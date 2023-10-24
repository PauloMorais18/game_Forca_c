#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//variaveis globais
char palavrasecreta[20];
char chutes[11];
int tentativas = 0;

//abertura e fechamento de parenteses diz para o codigo que é uma função
void abertura(){
	printf("*******************\n");
	printf("*  jogo de forca  *\n");
	printf("*******************\n");
}

void chuta(){
	char chute;
		printf ("\nChute uma letra\n");
		scanf (" %c", &chute); //"espaço" ignora o enter
		
		chutes[tentativas] = chute;
		tentativas++;
}

int jachutou (char letra) {
	
	int achou = 0;
			
			//ARRAYYYYYY
			// compara o valor de cada array "chutes" e compara se é igual a "palavrasecreta"
			//esse é igual a esse, se sim, imprime a letra, se não, não faz nada
			for(int j = 0; j < tentativas; j++) {
				if(chutes[j] == letra){
					achou = 1;
					break;
				}
			}
	return achou;
}

void desenhaforca() {

    printf("\nVoce ja deu %d chutes\n", tentativas);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
			
	}
		printf("\n");
		
}

void escolhepalavra() {
    FILE *file;

    file = fopen("palavras.txt", "r");
    if(file == 0) {
    	printf("Desculpe, banco de dados não disponivel\n\n");
    	exit(1);
	}

    int qtddepalavras;
    fscanf(file, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(file, "%s", palavrasecreta);
    }

    fclose(file);
}


//vai conferir com todas as letras se ela existe
int acertou(){
	for(int i = 0; i < strlen(palavrasecreta); i++){
		if(!jachutou(palavrasecreta[i])){
			return 0;
		}
	}
	//todas as letras foram chutadas
	return 1;
}

int enforcou(){
	
	int erros = 0;
	
	for(int i = 0; i < tentativas; i++) {
		int existe = 0;
		
		for(int j = 0; j < strlen(palavrasecreta); j++) {
			if(chutes[i] == palavrasecreta[j]) {
				
				existe = 1;
				break;
			}
		}
	
	if (!existe) erros++;
	}
	
	return erros >= 7;
}


int main() {

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());

    if(acertou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

}


