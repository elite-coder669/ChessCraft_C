#include <stdio.h>

#include <graphics.h>

#include <conio.h>

#include <time.h>

void chessboard(int, int, int);
void moveCircle(int, int, int, int);
int main() {
  int gd = DETECT, gm;
  char ch;
  int rows = 8, cols = 8, size = 50;
  clrscr();
  initgraph( & gd, & gm, "//tc//bgi");
  chessboard(rows, cols, size);
  moveCircle(rows, cols, size, 250);
  while ((ch = getch()) != 'q') {}
  closegraph(); /* To close the graphics window after drawing the chessboard */
  return 0;
}
void chessboard(int rows, int cols, int size) {
  int i, j, x1, x2, y1, y2;
  int points[8];
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      x1 = j * size;
      y1 = i * size;
      x2 = x1 + size;
      y2 = y1 + size;
      points[0] = x1;
      points[1] = y1;
      points[2] = x2;
      points[3] = y1;
      points[4] = x2;
      points[5] = y2;
      points[6] = x1;
      points[7] = y2;
      if ((i + j) % 2 == 0) {
        setfillstyle(SOLID_FILL, WHITE);
      } else {
        setfillstyle(SOLID_FILL, BLACK);
      }
      fillpoly(4, points);
    }
  }
}
void moveCircle(int rows, int cols, int size, int delayTime) {
  int i, j, x1, x2, y1, y2;
  int midx, midy, prevx = 0, prevy = 0;
  int prevcolor = WHITE;
  int increment, startJ;
  srand(time(NULL)); // Seed for random colors
  for (i = 0; i < rows; i++) {
    int increment = (i % 2 == 0) ? 1 : -1; // To adjust the direction of
    movement
    int startJ = (i % 2 == 0) ? 0 : cols - 1;
    for (j = startJ;
      (j >= 0 && j < cols); j += increment) {
      x1 = j * size;
      y1 = i * size;
      x2 = x1 + size;
      y2 = y1 + size;
      midx = (x1 + x2) / 2;
      midy = (y1 + y2) / 2;
      setfillstyle(SOLID_FILL, rand() % 15 + 1);
      /*SOLID_FILL can be replaced with rand()%15+1 to get random patterns of random
      colors. */
      fillellipse(midx, midy, 23, 23);
      setfillstyle(SOLID_FILL, prevcolor);
      bar(prevx - size / 2, prevy - size / 2, prevx + size / 2, prevy + size / 2);
      if ((i + j) % 2 == 0) {
        setcolor(BLACK);
        10
        prevcolor = WHITE;
      } else {
        setcolor(WHITE);
        prevcolor = BLACK;
      }
      prevx = midx;
      prevy = midy;
      delay(delayTime);
    }
  }
}
