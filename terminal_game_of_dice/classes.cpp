#include "classes.h"

Player::Player(std::string name_, int playerPionts) : name(name_), sumThrow(0), points(playerPionts), prediction(0), stop(0) {}

void Player::displayInfo() const {
    std::cout << "Name: " << name << " Points: " << points << std::endl;
}

int Player::throwTheDices() {
    int throw1 = rand() % 6 + 1;
    int throw2 = rand() % 6 + 1;
    sumThrow = throw1 + throw2;

    std::cout << name << " throws:" << std::endl;
    std::cout << "[" << throw1 << "]";
    std::cout << "[" << throw2 << "]" << std::endl;
    std::cout << "Sum: " << sumThrow << std::endl;
    std::cout << std::endl;

    return sumThrow;
}

int Player::throwTheDicesGuessTheValue() {
    int throw1 = rand() % 6 + 1;
    int throw2 = rand() % 6 + 1;
    sumThrow = throw1 + throw2;

    std::cout << name << " throws:" << std::endl;
    std::cout << "[?][?]" << std::endl << std::endl;
    //std::cout << "Sum: " << sumThrow << std::endl;

    return sumThrow;
}

int Player::makePrediction() {
    do {
        std::cout << "What is your prediction, " << name << "?" << std::endl;
        std::cout << "Prediction: ";

        if (!(std::cin >> prediction)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong value. Try again." << std::flush;
            stop = _getch();
            std::cout << "\r                   \r";
        }
        else {
            std::cout << std::endl;
            break;
        }

    } while (true);

    return prediction;
}

int Player::getPoints() const {

    return points;
}

void Player::setPoints(int value) {
    points = value;
}

std::string Player::getName() const {

    return name;
}

Game::Game() : stop(0) {}

void Game::playHighestNumberOfStitches(Player& player1, Player& player2, int numberOfThrows) {
    int player1Points = 0;
    int player2Points = 0;

    for (int i = 0; i < numberOfThrows; i++) {

        int sumThrow1 = player1.throwTheDices();
        int sumThrow2 = player2.throwTheDices();

        if (sumThrow1 > sumThrow2) {
            player1.setPoints(player1.getPoints() + 1);
            std::cout << player1.getName() << " " << player1.getPoints() << " : " << player2.getPoints() << " " << player2.getName() << std::endl << std::endl;
            player1Points++;
        }
        else if (sumThrow1 < sumThrow2) {
            player2.setPoints(player2.getPoints() + 1);
            std::cout << player1.getName() << " " << player1.getPoints() << " : " << player2.getPoints() << " " << player2.getName() << std::endl << std::endl;
            player2Points++;
        }
        else {
            std::cout << "Overtime" << std::endl << std::endl;
        }
        stop = _getch();
        system("cls");
    }
}

void Game::playGuessTheValue(Player& player1, Player& player2) {
    int player1Points = 0;
    int player2Points = 0;

    do {
        int sumThrow1 = player1.throwTheDicesGuessTheValue();
        int prediction1 = player1.makePrediction();
        system("cls");

        int sumThrow2 = player2.throwTheDicesGuessTheValue();
        int prediction2 = player2.makePrediction();
        system("cls");

        if (prediction1 == sumThrow1 && prediction2 == sumThrow2 || prediction1 != sumThrow1 && prediction2 != sumThrow2) {
            std::cout << "Overtime" << std::flush;
            stop = _getch();
            system("cls");
        }
        else if (prediction1 == sumThrow1 && prediction2 != sumThrow2) {
            std::cout << player1.getName() << " wins a game!" << std::flush;
            stop = _getch();
            system("cls");
            player1.setPoints(player1.getPoints() + 1);
            player1Points++;
        }
        else if (prediction2 == sumThrow2 && prediction1 != sumThrow1) {
            std::cout << player2.getName() << " wins a game!" << std::flush;
            stop = _getch();
            system("cls");
            player2.setPoints(player2.getPoints() + 1);
            player2Points++;
        }
    } while (player1Points < 1 && player2Points < 1);
}