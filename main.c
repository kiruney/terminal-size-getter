#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main() {
    struct winsize w;

    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w)) {
        perror("Error getting terminal size");
        return 1;
    }

    printf("ROWS: %d\nCOLS: %d\n", w.ws_row, w.ws_col);
    return 0;
}
