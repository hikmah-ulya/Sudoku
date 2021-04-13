
#ifndef player_h
#define player_h
#pragma once

#include <iostream>
#include <string.h>

using namespace std;

class Player {
    string name;
    int score;

public:
    Player(){
        string s;
        cout<<"Masukkan nama pemain! "; cin>>s;
        score = 0;
        setName(s);
    }
    string getName() {
        return name;
    }
    void setName(string s) {
        name = s;
    }
};


#endif /* player_h */
