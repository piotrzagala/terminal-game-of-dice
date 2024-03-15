#include "classes.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int stop;

    std::cout << "Game of Dice!" << std::flush;
    stop = _getch();
    system("cls");

    std::string decision;
    std::string player1Name;
    std::string player2Name;
    int player1Points = 0;
    int player2Points = 0;

    try {
        while (true) {
            std::cout << "Do you want to continue the previous game?" << std::endl;
            std::cout << "Decision (Yes / No): ";
            std::cin >> decision;

            if (decision == "Yes") {
                std::ifstream file("data.txt");
                if (!file) {
                    throw std::runtime_error("File does not exist.");
                }

                file >> player1Name >> player1Points >> player2Name >> player2Points;
                file.close();

                system("cls");
                break;
            }
            else if (decision == "No") {
                system("cls");
                std::cout << "First player name: ";
                std::cin >> player1Name;
                std::cout << "Second player name: ";
                std::cin >> player2Name;
                std::cout << std::endl;
                system("cls");

                break;
            }
            else {
                std::cout << "Try again." << std::endl;
                stop = _getch();
                system("cls");
            }
        }

        Player player1(player1Name, player1Points);
        Player player2(player2Name, player2Points);
        Game game;

        int choice = 0;
        int numberOfThrows;

        do {
            std::cout << "Game options:" << std::endl;
            std::cout << "1. The highest number of stitches" << std::endl;
            std::cout << "2. Guess the value" << std::endl;
            std::cout << "3. Display informations about players" << std::endl;
            std::cout << "4. Exit Game" << std::endl;
            std::cout << "Your choice: ";

            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            system("cls");

            switch (choice) {
            case 1:
                std::cout << "THE HIGHEST NUMBER OF STITCHES" << std::endl << std::endl;

                do {
                    std::cout << "How many times do you want to roll the dice?" << std::endl;
                    std::cout << "Decision: ";

                    if (!(std::cin >> numberOfThrows)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Wrong value. Try again." << std::flush;
                        stop = _getch();
                        system("cls");
                    }
                    else {
                        system("cls");

                        break;
                    }

                } while (true);

                game.playHighestNumberOfStitches(player1, player2, numberOfThrows);

                break;
            case 2:
                std::cout << "GUESS THE VALUE" << std::endl << std::endl;

                game.playGuessTheValue(player1, player2);

                break;
            case 3:
                std::cout << "INFORMATIONS ABOUT PLAYERS" << std::endl << std::endl;

                player1.displayInfo();
                player2.displayInfo();

                stop = _getch();
                system("cls");

                break;
            case 4:
            {
                std::ofstream file("data.txt");
                if (!file) {
                    throw std::runtime_error("Cannot create file.");
                }
                file << player1Name << std::endl;
                file << player1.getPoints() << std::endl;
                file << player2Name << std::endl;
                file << player2.getPoints() << std::endl;
                file.close();
            }
            break;
            default:
                std::cout << "Try again." << std::endl << std::endl;

                break;
            }

        } while (choice != 4);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
