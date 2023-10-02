#include <termios.h>
#include <unistd.h>

void enableRawMode() {
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw); // reads the terminal attributes that you pass through

    raw.c_lflag &= ~(ECHO); // turns off echoing 

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q'); // reads the input bit by bit
    return 0;
}