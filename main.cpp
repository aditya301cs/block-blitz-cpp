#include "game.h"

int main() {
    while (1) {
        system("cls");
        gotoxy(10, 5); std::cout << "===============================";
        gotoxy(10, 6); std::cout << "         BRICK BREAKER        ";
        gotoxy(10, 7); std::cout << "===============================";
        gotoxy(10, 9); std::cout << "1. Start Game";
        gotoxy(10,10); std::cout << "2. Instructions";
        gotoxy(10,11); std::cout << "3. Quit";
        gotoxy(10,13); std::cout << "Select option: ";

        char op = getche();
        if (op == '1') {
            // Reset values before starting
            initGame();
            play();
        } else if (op == '2') {
            instructions();
        } else if (op == '3') {
            exit(0);
        }
    }
    
    return 0;
}