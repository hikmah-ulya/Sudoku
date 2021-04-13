
#ifndef gameManager_h
#define gameManager_h

#pragma once
#include <iostream>
#include <stdlib.h>
#include "board.h"
#include "player.h"
#include "invoker.h"
#include "fillBoard.h"

class gameManager {
    bool playing = true;
    Board* b;
    Player* p;
    Invoker* inv;
    char isi;
    int brs, klm;

public:
    gameManager();
    void inputPemain();
    void startGame();
    void loadGame();
    void saveGame();
    void cekMenang();
    void cekKalah();
    void playGame();
    void undo();
};

gameManager::gameManager(){
    p = new Player();
    b = new Board();
    inv = new Invoker();
}

void gameManager::inputPemain() {
   // b->changeColor(6);
    cout << endl;
    cout << "isi baris berapa? "; cin >> brs;
  //  b->changeColor(2);
    cout << "isi kolom berapa? "; cin >> klm;
   // b->changeColor(7);
    cout << "isi angka berapa? "; cin >> isi;

    FillBoard* command = new FillBoard(*b, isi, brs, klm);
    command->excecute();
    inv->pushCommand(*command);
}

void gameManager::undo() {
    inv->popCommand();
}
void gameManager::playGame() {
    int jawab;
    b->setKotak();
    b->tampil();
    cout << "Sedang bermain: " << p->getName() << endl;
    cout << "Pilih apa?\n1-> isi kotak\n2-> undo\n3-> redo\nPilihan anda : ";
    cin >> jawab;
    switch (jawab) {
    case (1): {
        inputPemain();
        break;
    }
    case(2): {
        undo();
        break;
    }
    case(3): {
        b->redo(b->getBaris(), b->getKolom());
        break;
    }
    }
    //    betul = true;
    b->cekTerisi(brs, klm);
    b->cekArea(klm, brs, isi);
    b->cekBaris(brs, isi);
    b->cekKolom(klm, isi);
    b->simpan(b->getIsi());

    cekKalah();
    //    cekMenang(p, b);
    saveGame();
}

void gameManager::saveGame() {
    std::ofstream board;
    board.open("sudokuBoard.txt", std::ofstream::out | std::ofstream::trunc);
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            board << b->getKotak(i, j);
        }
        board << endl;
    }
    board << "/" << p->getName();
    board.close();
}

void gameManager::startGame() {
    b->resetBoard();
    while (playing) {
        playGame();
    }
}

void gameManager::loadGame() {
    ifstream myfile1;
    string data1;
    myfile1.open("sudokuBoard.txt");
    while (getline(myfile1, data1, '\0'));
    p->setName(data1.substr(data1.find("/") + 1));
    while (playing) {
        playGame();
    }
    myfile1.close();
}

void gameManager::cekMenang() {
    ifstream myfile1;
    string data1;
    myfile1.open("sudokuBoard.txt");
    while (getline(myfile1, data1)) {
        if (!data1.find("0")) {
            cout << endl << p->getName() << " menang!" << endl;
            b->resetBoard();
            saveGame();
            exit(EXIT_FAILURE);
        }
    }
    myfile1.close();
}

void gameManager::cekKalah() {
    if (b->getNyawa() == 0) {
        cout << endl << p->getName() << " kalah!" << endl;
        b->resetBoard();
        saveGame();
        exit(EXIT_FAILURE);
    }
}


#endif /* gameManager_h */
