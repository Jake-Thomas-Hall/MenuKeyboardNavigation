#include "Utilities.h"

void util::Pause() {
    std::cout << "Press any key to continue...\n";
    auto value = _getch();
}