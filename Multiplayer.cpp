#include <iostream>
#include <limits>
#include <string>
#include "Multiplayer.h"

Multiplayer::Multiplayer() {
    m_gameOver = false;

    createPlayers();

    if (!m_players.empty()) {
        m_players[0].displayRules();
        mpPlayGame();
    }
}

void Multiplayer::createPlayers() {
    int numberOfPlayers = 0;

    while (numberOfPlayers < 2) {
        std::cout << "How many people are playing? ";
        std::cin >> numberOfPlayers;

        if (std::cin.fail() || numberOfPlayers < 2) {
            std::cout << "Please enter at least 2 players.\n";

            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            numberOfPlayers = 0;
        }
    }

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );

    m_players.reserve(numberOfPlayers);

    int anonymousPlayerNumber = 1;

    for (int i = 0; i < numberOfPlayers; i++) {
        std::string playerName;

        std::cout << "Enter player "
                  << i + 1
                  << "'s name: ";

        std::getline(std::cin, playerName);

        if (playerName.empty()) {
            playerName = "Anonymous Player "
                         + std::to_string(anonymousPlayerNumber);

            anonymousPlayerNumber++;
        }

        m_players.emplace_back(playerName);
    }
}

void Multiplayer::mpPlayGame() {
    while (!m_gameOver) {
        for (PDGameV2& player : m_players) {
            player.playGame();
            displayScoreBoard();
        }

        checkForWinner();
    }

    displayWinner();
}

void Multiplayer::checkForWinner() {
    for (const PDGameV2& player : m_players) {
        if (player.getGameScore() >= 50) {
            m_gameOver = true;
        }
    }
}

void Multiplayer::displayScoreBoard() const {
    std::cout << "\n";

    for (const PDGameV2& player : m_players) {
        std::cout << player.getPlayerName()
                  << " (Score:"
                  << player.getGameScore()
                  << ") | ";
    }

    std::cout << "\n";
}

void Multiplayer::displayWinner() const {
    if (m_players.empty()) {
        return;
    }

    int winnerIndex = 0;

    for (int i = 1; i < static_cast<int>(m_players.size()); i++) {
        if (m_players[i].getGameScore()
            > m_players[winnerIndex].getGameScore()) {

            winnerIndex = i;
        }
    }

    std::cout << "\nCongratulations! "
              << m_players[winnerIndex].getPlayerName()
              << " you win with a score of "
              << m_players[winnerIndex].getGameScore()
              << "\n";
}