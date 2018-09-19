//
// Created by benji on 19/09/18.
//

#ifndef STRATEGO_BOARD_H
#define STRATEGO_BOARD_H

#include "Piece.h"

#include <vector>

class Board {
private:
    std::vector<std::vector<Piece> > m_map;

    int m_state = RED_BUILDING;

    std::vector<Piece> m_redPieces;

    std::vector<Piece> m_bluePieces;
public:
    Board();

    Piece pos(int x, int y);

    void print();

    enum states{
        RED_BUILDING,
        BLUE_BUILDING,
        RED_ATTACKING,
        BLUE_ATTACKING
    };

    void initRedPieces();

    void initBluePieces();

    std::vector<Piece> initPieces(int color);

    void move(int x1, int y1, int x2, int y2);
};


#endif //STRATEGO_BOARD_H
