#include <cstdio>
#include <windows.h>
#include <conio.h>

void go_to_xy(const short x, const short y) {
    HANDLE h_console_output = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console output handle
    COORD coord; // Create a COORD structure to hold the coordinates
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(h_console_output, coord); // Set the cursor position to the specified coordinates
}

void create_player(short x, short y) {
    go_to_xy(x, y - 1);
    printf("%c", 219);
    go_to_xy(x, y);
    printf("%c", 219);
    go_to_xy(x, y + 1);
    printf("%c", 219);
}

int main() {
    short x = 10, y = 10;
    char c = -37;
    bool game = true;

    while (game) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'w') y--;
            if (key == 's') y++;
        }
        create_player(x, y);
    }
}
