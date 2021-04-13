#include <iostream>
#include "gameManager.h"

using namespace std;

int main() {

    int choice;

    cout << "Sudoku" << endl;
    cout << "421091013 / 4210191010" << endl;
    cout << "1. Mulai Baru\n2. Load Game\n";
    cout << "Masukkan Pilihan! "; cin >> choice;
    gameManager gm;
    switch (choice) {
    case 1:
        gm.startGame();
    case 2:
        gm.loadGame();
    }
    return 0;
}
/*
306508400
520000000
087000031
003010080
900863005
050090600
130000250
000000074
005206300


316578492
529134768
487629531
263415987
974863125
851792643
138947256
692351874
745286319
*/

