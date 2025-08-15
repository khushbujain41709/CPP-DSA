#include <iostream>
#include <string>
using namespace std;

void drawBox(int size) {
    if (size < 1)
        return;

    // Draw back line on top surface
    cout << string(size + 1, ' ') << "+" << string(size * 2, '-') << "+" << endl;

    // Draw top surface
    for (int i = 0; i < size; i++) {
        cout << string(size - i, ' ') << "/" << string(size * 2, ' ') << "/" << string(i, ' ') << "|" << endl;
    }

    // Draw top line on front surface
    cout << "+" << string(size * 2, '-') << "+" << string(size, ' ') << "+" << endl;

    // Draw front surface
    for (int i = size - 1; i >= 0; i--) {
        cout << "|" << string(size * 2, ' ') << "|" << string(i, ' ') << "/" << endl;
    }

    // Draw bottom line on front surface
    cout << "+" << string(size * 2, '-') << "+" << endl;
}

int main() {
    for (int i = 1; i <= 5; i++) {
        drawBox(i);
        cout << endl;
    }
    return 0;
}
