#include "../lib/bor.h"

void solution(std::istream& in, std::ostream& out) {
    Bor bor;
    std::string command;

    while(true) {
        in >> command;

        if (command == "add") {
            in >> command;
            out << bor.addWord(command) << '\n';
        }

        if (command == "clean") {
            bor.clean();
        }

        if (command == "write") {
            in >> command;
            bor.writeWord(command);
        }

        if (command == "stop") {
            break;
        }

        if (command == "help") {
            in >> command;
            out << bor.help(command) << '\n';
        }
    }
}

int main() {
    solution(std::cin, std::cout);
    return 0;
}