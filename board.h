#include <iostream>
#include <fstream>
#pragma once
#include <windows.h> 
using namespace std;
class Board {
	char kotak[9][9], pool;
	bool betul = true;
	bool menang;
	int k;
	int b;
	char isi;
	int nyawa = 3;

public:
	void isiKotak(char input, int baris, int kolom);
	void cekArea(int kolom, int baris, char input);
	void cekBaris(int kolom, char input);
	void cekKolom(int baris, char input);
	void tampil();
	void changeColor(int color);
	void cekTerisi(int baris, int kolom);
	void setKotak();
	char getIsi();
	int getKolom();
	int getBaris();
	char getKotak(int i, int j);
	void resetBoard();
	void hapusCell(int i, int j);
	void redo(int i, int j);
	void simpan(char c);
	char getPool();
	void cekKotak(char isi, int brs, int klm);
	int getNyawa();
};

void Board::cekKotak(char isi, int brs, int klm){
	betul = true;
	cekTerisi(brs, klm);
	cekArea(klm, brs, isi);
	cekBaris(brs, isi);
	cekKolom(klm, isi);
	simpan(getIsi());
}
int Board::getNyawa() {
	return nyawa;
}
int Board::getBaris() {
	return b;
}

int Board::getKolom() {
	return k;
}

void Board::resetBoard() {
	string myText;
	std::ofstream sudokuBaru;
	ifstream daftarNama("data.txt");
	sudokuBaru.open("sudokuBoard.txt", std::ofstream::out | std::ofstream::trunc);
	while (getline(daftarNama, myText)) {
		sudokuBaru << myText << endl;
	}
	daftarNama.close();
}

char Board::getKotak(int i, int j) {
	return kotak[i][j];
}

char Board::getIsi() {
	return isi;
}

void Board::cekTerisi(int baris, int kolom) {
	if (kotak[baris][kolom] == '0') {
		cout << kotak[baris][kolom];
		betul = true;
	}
	else {
		cout << "T";
		betul = false;
	}
}

void Board::changeColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Board::cekArea(int kolom, int baris, char input) {
	int startBaris = baris - baris % 3,
		startKolom = kolom - kolom % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (kotak[i + startBaris][j + startKolom] == input) {
					cout << "a";
				betul = false;
				cout << nyawa << endl;
			}
}

void Board::cekBaris(int baris, char input) {
	for (int x = 0; x <= 8; x++)
		if (kotak[baris][x] == input) {
			cout << "b";
			betul = false;
			cout << nyawa << endl;
		}
}

void Board::cekKolom(int kolom, char input) {
	for (int x = 0; x <= 8; x++)
		if (kotak[x][kolom] == input) {
			cout << "k";
			betul = false;
			cout << nyawa << endl;
		}
}

void Board::isiKotak(char input, int baris, int kolom) {
	cekKotak(input, baris, kolom);
	if (betul) {
		kotak[baris][kolom] = input;
	}
	else {
		cout << "Input salah!";
		nyawa--;
	}
}

void Board::simpan(char c) {
	pool = c;
}

char Board::getPool() {
	return pool;
}

void Board::hapusCell(int i, int j) {
	kotak[i][j] = '0';
}

void Board::redo(int i, int j)
{
	cout << "Redo dilakukan! ";
	betul = true;
	cekTerisi(i, j);
	cekArea(j, i, pool);
	cekBaris(i, pool);
	cekKolom(j, pool);

	if (betul) {
		kotak[i][j] = pool;
	}
	else {
		cout << "Input salah! ";
		nyawa--;
	}
}

void Board::tampil() {
	changeColor(2);
//	system("cls");
	cout << "Sisa nyawa : " << nyawa << endl;
	cout << "  0   1   2   3   4   5   6   7   8\n";

	for (int i = 0; i < 9; i++) {
		changeColor(6);
		cout << i << " ";
		for (int j = 0; j < 9; j++) {
			changeColor(7);
			cout << kotak[i][j] << " | ";
		}
		cout << "\n  --+---+---+---+---+---+---+---+---" << endl;
	}
}

void Board::setKotak() {
	string arrCopy;
	ifstream myfile1;
	string data1;
	myfile1.open("sudokuBoard.txt");
	while (getline(myfile1, data1, '\0')) {
		arrCopy = data1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				kotak[i][j] = arrCopy[(j)+(i * 10)];
			}
		}
	}
	myfile1.close();
}
