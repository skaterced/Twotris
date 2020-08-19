#ifndef BACKGROUND_H
#define BACKGROUND_H

void drawBackground();
void drawBackground1P();
void affScore(bool P1);
void zeroPrint(unsigned int score);
void zeroPrint1P(unsigned int score);
void drawStillSquares();
void checkFullLines(byte minY, byte maxY, bool p1);
void removeBlinkingLines(bool p1);

#endif
