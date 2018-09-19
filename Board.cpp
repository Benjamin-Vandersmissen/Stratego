//
// Created by benji on 19/09/18.
//

#include "Board.h"

Board::Board() {
    m_map.reserve(10);
    for(int i = 0; i < 10; ++i){
        std::vector<Piece> temp;
        temp.reserve(10);
        for(int j = 0; j < 10; ++j){
            temp.emplace_back();
        }
        m_map.push_back(temp);
    }
    for(int i = 4; i != 6; ++i){
        for(int j = 2; j < 10; j+= 4){
            m_map[i][j] = {Piece::NONE, Piece::INACCESSIBLE};
            m_map[i][j+1] = {Piece::NONE, Piece::INACCESSIBLE};
        }
    }



}

Piece Board::pos(int x, int y) {
    if(x > 9 or x < 0 or y > 9 or y < 0)
        return {};
    return m_map[x][y];
}

void Board::print() {
    for(int x = 0; x < 10; ++x){
        for(int y = 0; y < 10; ++y){
            std::cout << m_map[x][y] << ' ';
        }
        std::cout << '\n';
    }
}

void Board::initRedPieces() {
    m_redPieces = initPieces(Piece::RED);
}

void Board::initBluePieces() {
    m_bluePieces = initPieces(Piece::BLUE);
}

std::vector<Piece> Board::initPieces(int color) {
    std::vector<Piece> pieces;

    pieces.emplace_back(color, Piece::FLAG);
    pieces.emplace_back(color, Piece::SPY);
    for(int i = 0; i < 6; ++i) pieces.emplace_back(color, Piece::BOMB);
    for(int i = 0; i < 8; ++i) pieces.emplace_back(color, Piece::SCOUT);
    for(int i = 0; i < 5; ++i) pieces.emplace_back(color, Piece::MINER);
    for(int i = 0; i < 4; ++i) pieces.emplace_back(color, Piece::SERGEANT);
    for(int i = 0; i < 4; ++i) pieces.emplace_back(color, Piece::LIEUTENANT);
    for(int i = 0; i < 4; ++i) pieces.emplace_back(color, Piece::CAPTAIN);
    for(int i = 0; i < 3; ++i) pieces.emplace_back(color, Piece::MAJOR);
    for(int i = 0; i < 2; ++i) pieces.emplace_back(color, Piece::COLONEL);
    pieces.emplace_back(color, Piece::GENERAL);
    pieces.emplace_back(color, Piece::MARSHAL);

    return pieces;
}

void Board::move(int x1, int y1, int x2, int y2) {
    Piece piece1 = pos(x1, y1);
    Piece piece2 = pos(x2, y2);

    if(!piece1.canMove()) //piece can't be moved,
        return;
    if(piece1.canKill(piece2) && piece2.canKill(piece1)){//both die
        m_map[x1][y1] = {};
        m_map[x2][y2] = {};
    }
    if(piece1.canKill(piece2) && !piece2.canKill(piece1)){ //piece1 is stronger, piece2 dies and piece1 moves to x2,y2
        m_map[x2][y2] = m_map[x1][y1];
        m_map[x1][y1] = {};
    }
    if(!piece1.canKill(piece2) && piece2.canKill(piece1)){ //piece2 is stronger, piece1 dies
        m_map[x1][y1] = {};
    }
    if(!piece1.canKill(piece2) && !piece2.canKill(piece1)){ // they can't kill each other
        return;
    }
}
