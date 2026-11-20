#ifndef PIGDICE_MULTIPLAYER_H
#define PIGDICE_MULTIPLAYER_H

#include <vector>
#include "PDGameV2.h"

class Multiplayer {
private:
    std::vector<PDGameV2> m_players;
    bool m_gameOver;

public:
    Multiplayer();
    void mpPlayGame();

private:
    void createPlayers();
    void checkForWinner();
    void displayScoreBoard() const;
    void displayWinner() const;
};

#endif // PIGDICE_MULTIPLAYER_H