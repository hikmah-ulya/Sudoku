
#ifndef fillBoard_h
#define fillBoard_h

#pragma once
#include "board.h"
#include "command.h"

class FillBoard : public Command {
private:
    Board* b;
    int brs, klm;
    char input;

public:
    FillBoard() = default;
    FillBoard(Board& board, char input, int brs, int klm);
    void excecute();
    void undo();
};

FillBoard::FillBoard(Board& board, char input, int brs, int klm) {
    this->b = &board;
    this->input = input;
    this->brs = brs;
    this->klm = klm;
}

void FillBoard::excecute() {
    b->isiKotak(input, brs, klm);
}

void FillBoard::undo() {
    b->hapusCell(brs, klm);
}

#endif /* fillBoard_h */
