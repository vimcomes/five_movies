#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

void showInfo (nlohmann::json& dict) {
    std::string movie;
    std::string pos;
    std::string info;
    std::cout << "Enter the name of the movie: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, movie);
    std::cout << "Select the position: \"actors\", \"authors\", \"country\", \"data\", \"director\", \"producers\", \"studio\"" << std::endl;
    std::cin >> pos;
    if (dict[movie][pos] == nullptr) {
        std::cout << "No information available" << std::endl;
    } else {
        info = dict[movie][pos];
        std::cout << info << std::endl;
    }
}

void showInfo (nlohmann::json& dict, int) {
    std::string actor;
    std::string info;
    std::cout << "Enter the actor's last name or first name: " << std::endl;
    std::cin >> actor;
    if (dict[actor] == nullptr) {
        std::cout << "No information available" << std::endl;
    } else {
        info = dict[actor];
        std::cout << info << std::endl;
    }
}

int main() {
    std::ifstream file("5movies.json");
    nlohmann::json dict;
    file >> dict;
    while (true) {
        int command;
        std::cout << "Choose command: movie - 1, actor - 2, exit - 0" << std::endl;
        std::cin >> command;
        if (command == 1) {
            showInfo(dict);
        } else if (command == 2) {
            showInfo(dict, 0);
        } else if (command == 0) {
            break;
        } else {
            std::cout << "Input error. Try again" << std::endl;
        }
    }
    return 0;
}