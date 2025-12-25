#include "Village.h"
#include <iostream>
#include <random>

Village::Village() : day(0) {}

void Village::addCharacter(std::shared_ptr<ICharacter> character) {
    characters.push_back(character);
    std::cout << "Added " << character->getName() << " ("
              << character->getType() << ") to the village" << std::endl;
}

void Village::simulate() {
    day++;
    std::cout << "\n=== Day " << day << " ===" << std::endl;

    for (auto& character : characters) {
        character->live();
    }

    if (characters.size() >= 2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, characters.size() - 1);

        for (int i = 0; i < 3; i++) {
            int idx1 = dis(gen);
            int idx2 = dis(gen);

            while (idx1 == idx2) {
                idx2 = dis(gen);
            }

            std::string interaction = characters[idx1]->interact(characters[idx2]);
            std::cout << ">> " << interaction << std::endl;
        }
    }

    auto it = characters.begin();
    while (it != characters.end()) {
        if ((*it)->shouldLeave()) {
            std::cout << "!! " << (*it)->getName() << " left the village (mood reached 0)" << std::endl;
            it = characters.erase(it);
        } else {
            ++it;
        }
    }

    displayStats();
}

void Village::displayStats() {
    std::cout << "\n--- Village Statistics ---" << std::endl;
    for (const auto& character : characters) {
        std::cout << character->getName() << " (" << character->getType() << "): "
                  << "Energy=" << character->getEnergy()
                  << ", Mood=" << character->getMood() << std::endl;
    }
}

int Village::getDay() const {
    return day;
}

size_t Village::getPopulation() const {
    return characters.size();
}

Village::~Village() {
    std::cout << "\nVillage simulation ended after " << day << " days" << std::endl;
}