#include <iostream>
#include "PDGameV2.h"

PDGameV2::PDGameV2(const std::string& playerName)
    : PDGame() {
    m_playerName = playerName;
}

std::string PDGameV2::getPlayerName() const {
    return m_playerName;
}

int PDGameV2::getTurnCount() const {
    return m_myTurn.getTurnCount();
}

void PDGameV2::displayRules() const {
    std::cout << "\nLet's Play PIG Dice!\n\n";
    std::cout << "* See which player will reach 50 points in the fewest turns.\n";
    std::cout << "* Turn ends when you hold or roll a 1\n";
    std::cout << "* If you roll a 1, you lose all points for the turn.\n";
    std::cout << "* If you hold, you save all points for the turn.\n";
}

void PDGameV2::playGame() {
    std::cout << "\n"
              << m_playerName
              << " (Score:"
              << m_gameScore
              << ") - TURN "
              << m_myTurn.getTurnCount() + 1
              << "\n";

    m_myTurn.takeTurn();

    m_gameScore += m_myTurn.getScoreThisTurn();

    m_myTurn.resetTurnOver();
    m_myTurn.resetScoreThisTurn();
}