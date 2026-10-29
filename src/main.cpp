#include "minikv/store.h"

#include <iostream>
#include <sstream>
#include <string>

namespace {

void print_help() {
    std::cout
        << "Available commands:\n"
        << "  SET <key> <value>  Store a value\n"
        << "  GET <key>          Retrieve a value\n"
        << "  DEL <key>          Delete a key\n"
        << "  HELP               Show this help message\n"
        << "  EXIT               Quit MiniKV\n";
}

}  // namespace

int main() {
    minikv::Store store;

    std::string line;

    std::cout << "MiniKV - In-Memory Key-Value Store\n";
    std::cout << "Type HELP for commands.\n\n";

    while (true) {
        std::cout << "minikv> ";

        if (!std::getline(std::cin, line)) {
            break;
        }

        std::istringstream input(line);

        std::string command;
        input >> command;

        if (command.empty()) {
            continue;
        }

        if (command == "EXIT") {
            std::cout << "Goodbye!\n";
            break;
        }

        if (command == "HELP") {
            print_help();
            continue;
        }

        if (command == "SET") {
            std::string key;

            if (!(input >> key)) {
                std::cout << "Error: SET requires a key and value.\n";
                continue;
            }

            // Read the remainder of the line as the value.
            std::string value;
            std::getline(input >> std::ws, value);

            if (value.empty()) {
                std::cout << "Error: SET requires a key and value.\n";
                continue;
            }

            store.set(key, value);
            std::cout << "OK\n";

        } else if (command == "GET") {
            std::string key;
            std::string extra;

            if (!(input >> key) || (input >> extra)) {
                std::cout << "Error: Usage: GET <key>\n";
                continue;
            }

            auto value = store.get(key);

            if (value.has_value()) {
                std::cout << *value << '\n';
            } else {
                std::cout << "(nil)\n";
            }

        } else if (command == "DEL") {
            std::string key;
            std::string extra;

            if (!(input >> key) || (input >> extra)) {
                std::cout << "Error: Usage: DEL <key>\n";
                continue;
            }

            bool deleted = store.del(key);

            std::cout << "(integer) " << (deleted ? 1 : 0) << '\n';

        } else {
            std::cout << "Error: Unknown command. Type HELP.\n";
        }
    }

    return 0;
}