#include "Human.hpp"

Human::Human(const string S, ChessBoard * const B, const int BW){
    name=S;
    lastx=lasty=-1;
    PlayerBoard=B;
    BlackWhite=BW;
}

void Human::NextChess(int& x, int& y){
    if(PlayerBoard->LegalStep(x, y)){
        lastx=x;
        lasty=y;
        PlayerBoard->SetLast(lastx, lasty, BlackWhite);
        PlayerBoard->Set(x, y, BlackWhite);
    }
}
