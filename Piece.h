//
// Created by benji on 19/09/18.
//

#ifndef STRATEGO_PIECE_H
#define STRATEGO_PIECE_H

#include <iostream>

class Piece {
private:
    int m_color;

    int m_type;
public:
    enum colors{
        NONE,
        RED,
        BLUE
    };
    enum types{
        INACCESSIBLE,
        OPEN,
        BOMB,
        FLAG,
        SPY,
        SCOUT,
        MINER,
        SERGEANT,
        LIEUTENANT,
        CAPTAIN,
        MAJOR,
        COLONEL,
        GENERAL,
        MARSHAL
    };

    Piece();

    Piece(int color, int type);

    int color() const;

    int type() const;

    bool canKill(const Piece& piece);

    bool canMove();

};

std::ostream& operator<<(std::ostream& stream, const Piece& piece);
#endif //STRATEGO_PIECE_H
