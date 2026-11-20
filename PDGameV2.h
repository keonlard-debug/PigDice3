#ifndef PIGDICE_PDGAMEV2_H
#define PIGDICE_PDGAMEV2_H

#include <string>
#include "PDGame.h"

class PDGameV2 : public PDGame {
private:
    std::string m_playerName;

public:
    explicit PDGameV2(const std::string& playerName);

    std::string getPlayerName() const;
    int getTurnCount() const;

    void playGame();
    void displayRules() const;
};

#endif // PIGDICE_PDGAMEV2_H
