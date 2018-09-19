//
// Created by benji on 19/09/18.
//

#include "Piece.h"

Piece::Piece() : Piece(colors::NONE, types::OPEN){}

Piece::Piece(int color, int type) : m_color{color}, m_type{type}{}

int Piece::color() const {
    return m_color;
}

int Piece::type() const {
    return m_type;
}

bool Piece::canKill(const Piece &piece) {
    if(piece.color() == color())
        return false;
    if(type() == types::OPEN || type() == types::FLAG || type() == types::INACCESSIBLE)
        return false;
    if(type() == types::BOMB && piece.type() == types::MINER)
        return false;
    return type() >= piece.type();
}

bool Piece::canMove() {
    return type()!= types::BOMB && type() != types::FLAG && color() != colors::NONE;
}

std::ostream &operator<<(std::ostream &stream, const Piece &piece) {
    stream << piece.color() <<'-' << piece.type();
    return stream;}
