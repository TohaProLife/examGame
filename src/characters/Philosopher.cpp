#include "Philosopher.h"
#include <iostream>

Philosopher::Philosopher(std::string _name, int _wisdom) : wisdom(_wisdom) {
    this->name = _name;
    this->energy = 60;
    this->mood = 75;
}

void Philosopher::live() {
    std::cout << name << " the Philosopher is contemplating life..." << std::endl;
    wisdom++;
    mood -= 5;
    if (mood < 0) mood = 0;
}

std::string Philosopher::interact(std::shared_ptr<ICharacter> other) {
    std::string result = name + " gives wise advice to " + other->getName();
    energy -= 10;
    if (energy < 0) energy = 0;
    mood += 3;
    other->setMood(other->getMood() + wisdom);
    return result;
}

std::string Philosopher::getType() const {
    return "Philosopher";
}

int Philosopher::getWisdom() const {
    return wisdom;
}

Philosopher::~Philosopher() {
    std::cout << "Philosopher " << name << " left the village" << std::endl;
}