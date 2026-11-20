#include "PDGame.h"

PDGame::PDGame() {
    m_gameOver = false;
    m_gameScore = 0;

    m_myTurn.setParentGame(this);
}

int PDGame::getGameScore() const {
    return m_gameScore;
}