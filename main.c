#include <stdio.h>
#include <stdlib.h>
#include "konstanten.h"
#include "balancebot.h"
#include "haengebruecke.h"


int main(void)
{
	Haengebruecke* hb = (Haengebruecke*)malloc(sizeof(Haengebruecke));
	HaengebrueckeInit(hb);
	while (hb->bb->x != MAXBREITE-1)
	{
		HaengebrueckeCPrint(hb);
		HaengebrueckeFPrint(hb, "bruecke.txt", "a+");
		int richtung = BalancebotZufallsRichtung(hb->bb);
		BalancebotBewege(hb->bb, richtung);
	}
	HaengebrueckeCPrint(hb);
	HaengebrueckeFPrint(hb, "bruecke.txt", "a+");
	getchar();
	return EXIT_SUCCESS;
}