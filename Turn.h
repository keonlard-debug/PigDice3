#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H

#include "Die.h"

class PDGame;

class Turn {
private:
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
    PDGame* m_parentGame;

public:
    Turn();
    void setParentGame(PDGame* parentGame);
    void takeTurn();
    int getScoreThisTurn() const;
    void resetTurnOver();
    int getTurnCount() const;
    void resetScoreThisTurn();

private:
    void roll();
};

#endif // PIGDICE_TURN_H