#include <iostream>
#include <iomanip>
#define N 8

using namespace std;
int sol[N][N];

bool val(int x, int y, int sol[N][N]) {     
   return ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

void displaywork() {
   for (int x = 0; x < N; x++) {
      for (int y = 0; y < N; y++)
         cout << setw(3) << sol[x][y] << " ";
      cout << endl;
   }
}

int knighttour(int x, int y, int move, int sol[N][N], int xMove[N], int yMove[N]) {
   int xNext, yNext;
   if (move == N*N)     
      return true;

   for (int k = 0; k < 8; k++) {
      xNext = x + xMove[k];
      yNext = y + yMove[k];
      if (val(xNext, yNext, sol)) {     
         sol[xNext][yNext] = move;
         if (knighttour(xNext, yNext, move+1, sol, xMove, yMove) == true)
            return true;
         else
            sol[xNext][yNext] = -1;
      }
   }
   return false;
}

bool findtour() {
   for (int x = 0; x < N; x++)     
      for (int y = 0; y < N; y++)
         sol[x][y] = -1;
  
   int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
   int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
   sol[0][0]  = 0;     

   if (knighttour(0, 0, 1, sol, xMove, yMove) == false) {
      cout << "Solution does not exist";
      return false;
   } else
      displaywork();
   return true;
}

int main() {
   findtour();
}