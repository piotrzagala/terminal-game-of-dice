#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdexcept>

class Player {
private:
    std::string name;
    int points = 0;
    int sumThrow;
    int prediction;
    int stop;

public:
    Player(std::string name_, int playerPoints);
    void displayInfo() const;
    int throwTheDices();
    int throwTheDicesGuessTheValue();
    int makePrediction();
    int getPoints() const;
    void setPoints(int value);
    std::string getName() const;
};

class Game {
private:
    int stop;
public:
    Game();
    void playHighestNumberOfStitches(Player& player1, Player& player2, int numberOfThrows);
    void playGuessTheValue(Player& player1, Player& player2);
};

#endif // !CLASSES_H 
