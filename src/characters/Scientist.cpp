#include "Scientist.h"
#include <iostream>

Scientist::Scientist(std::string _name, int _inventionLevel) : inventionLevel(_inventionLevel) {
    this->name = _name;
    this->energy = 80;
    this->mood = 60;
}

void Scientist::live() {
    std::cout << name << " the Scientist is inventing something..." << std::endl;
    inventionLevel++;
    mood -= 5;
    if (mood < 0) mood = 0;
}

std::string Scientist::interact(std::shared_ptr<ICharacter> other) {
    std::string result = name + " shares scientific knowledge with " + other->getName();
    energy -= 10;
    if (energy < 0) energy = 0;
    mood += 5;
    other->setMood(other->getMood() + inventionLevel);
    return result;
}

std::string Scientist::getType() const {
    return "Scientist";
}

int Scientist::getInventionLevel() const {
    return inventionLevel;
}

Scientist::~Scientist() {
    std::cout << "Scientist " << name << " left the village" << std::endl;
}