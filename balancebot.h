#ifndef BALANCEBOT_H_
#define BALANCEBOT_H_
#include "konstanten.h"
typedef struct Balancebot {
	int x;
	int y;
	char symobl;
}Balancebot;
void BalancebotInit(Balancebot* bb) { 
	bb->x = 0;
	bb->y = MAXHOEHE / 2;
	bb->symobl = BOTSYMBOL;
}
void BalancebotBewege(Balancebot* bb, int richtung) {
	switch (richtung) {
	case HOCH:
		bb->y -= 1;
		break;
	case RECHTS:
		bb->x += 1;
		break;
	case RUNTER:
		bb->y += 1;
		break;
	}
}
int BalancebotZufallsRichtung(const Balancebot* bb) {
	int richtung = rand() % 3;
	 while (bb->y == 1 && richtung == HOCH || bb->y == MAXHOEHE - 2 && richtung == RUNTER) {
		 richtung = rand() % 3;
		 //return BalancebotZufallsRichtung(bb);
	 } 
	 /*if (bb->y == MAXHOEHE - 2 && RUNTER) {
		 
		 //return BalancebotZufallsRichtung(bb);
	 }*/
	 return richtung;
}

#endif /* BALANCEBOT_H_ */