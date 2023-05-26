#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogos{
	char times[10];	
	int placar_es;
	int placar_ti;
}JOGOS[10];

int main(){
	
	int tem, i, pontos =0 ;
	char esc[20];
	FILE *file;
	file = fopen("brasileirao.txt", "w");
	
	printf("Qual o seu time? ");
	gets(esc);
	system("cls");
	printf("Quantos jogos seu time jogou nessa temporada?: ");
	scanf("%d", &tem);
	system("cls");
	for(i = 0; i < tem; i++){
	printf("Adversario do jogo[%d]: ", i+1);
		scanf("%s", &JOGOS[i].times); 
	}
	
	printf("Placar: \n");
	for(i = 0; i < tem; i++){
		printf("Jogo contra: %s", JOGOS[i].times);
		printf("\n%s: ", esc);
		scanf("%d", &JOGOS[i].placar_es);
		printf("\n%s: ", JOGOS[i].times);
		scanf("%d", &JOGOS[i].placar_ti);
		
		if(JOGOS[i].placar_es > JOGOS[i].placar_ti){
			pontos = pontos + 3;
		} else {
			if (JOGOS[i].placar_es == JOGOS[i].placar_ti){
				pontos = pontos + 1;
			} 	
		}
		system("cls");
	}
	
	printf("Pontos que %s tem: ", esc);
	printf("%d", pontos);
	
	for(i = 0; i < tem; i++){ 
		fprintf(file, "|%s x ", esc);
		fputs(JOGOS[i].times, file);
		fprintf(file, "|: %dx%d; \n", JOGOS[i].placar_es, JOGOS[i].placar_ti);
	}
	fprintf(file, "\nPontos do %s: %d", esc, pontos);
	fprintf(file, "\nPalmeiras não tem mundial");
	
	
	
	return 0;
}
