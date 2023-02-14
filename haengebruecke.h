#ifndef HAENGEBRUECKE_H_
#define HAENGEBRUECKE_H_
#include "konstanten.h"
#include "balancebot.h"
typedef struct Haengebruecke {
	char einzelfeld[MAXBREITE][MAXHOEHE];
	Balancebot* bb;
}Haengebruecke;
void HaengebrueckeInit(Haengebruecke* hb) {
	hb->bb = (Balancebot*)malloc(sizeof(Balancebot));
	BalancebotInit(hb->bb);
	for (int x = 0; x < MAXBREITE; x++) {
		hb->einzelfeld[x][0] = GELAENDER;
		hb->einzelfeld[x][(MAXHOEHE - 1)] = GELAENDER;
	}
	for (int y = 1; y < MAXHOEHE - 1; y++) {
		for (int x = 0; x < MAXBREITE; x++) {
			hb->einzelfeld[x][y] = HOLZ;
		}
	}
}
void HaengebrueckeCPrint(Haengebruecke* hb) {
	for (int y = 0; y < MAXHOEHE; y++) {
		for (int x = 0; x < MAXBREITE; x++) {
			if (x == hb->bb->x && y == hb->bb->y) {
				printf("%c", hb->bb->symobl);
			}
			else {
				printf("%c", hb->einzelfeld[x][y]);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}
void HaengebrueckeFPrint(Haengebruecke* hb, const char* dateiname, const char* modus) {
	FILE* dateiSchreiben = fopen(dateiname, modus);
	for (int y = 0; y < MAXHOEHE; y++) {
		for (int x = 0; x < MAXBREITE; x++) {
			if (x == hb->bb->x && y == hb->bb->y) {
				fputc(hb->bb->symobl, dateiSchreiben);
			}
			else {
				fputc(hb->einzelfeld[x][y], dateiSchreiben);
			}
		}
		fputc('\n', dateiSchreiben);
	}
		fputc('\n', dateiSchreiben);
		fputc('\n', dateiSchreiben);
}

#endif /* HAENGEBRUECKE_H_ */