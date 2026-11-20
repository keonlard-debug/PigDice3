#include <iostream>
#include "Turn.h"
#include "PDGame.h"

Turn::Turn() {
    m_turnCount = 0;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = '\0';
    m_parentGame = nullptr;
}

void Turn::setParentGame(PDGame* parentGame) {
    m_parentGame = parentGame;
}

void Turn::takeTurn() {
    m_turnCount++;
    m_scoreThisTurn = 0;
    m_turnOver = false;

    while (!m_turnOver) {
        std::cout << "roll or hold? (r/h): ";
        std::cin >> m_choice;

        if (m_choice == 'r' || m_choice == 'R') {
            roll();
        }
        else if (m_choice == 'h' || m_choice == 'H') {
            m_turnOver = true;
        }
        else {
            std::cout << "Invalid choice!\n";
        }
    }

    std::cout << "Score Banked This Turn: "
              << m_scoreThisTurn << "\n";
}

int Turn::getScoreThisTurn() const {
    return m_scoreThisTurn;
}

void Turn::resetTurnOver() {
    m_turnOver = false;
}

int Turn::getTurnCount() const {
    return m_turnCount;
}

void Turn::resetScoreThisTurn() {
    m_scoreThisTurn = 0;
}

void Turn::roll() {
    m_myDie.rollDie();

    std::cout << "Die: " << m_myDie.getDieValue();

    if (m_myDie.getDieValue() == 1) {
        std::cout << "\nTurn over. No score.\n";
        m_scoreThisTurn = 0;
        m_turnOver = true;
    }
    else {
        m_scoreThisTurn += m_myDie.getDieValue();

        std::cout << " - Running score this turn: "
                  << m_scoreThisTurn << "\n";
    }
}