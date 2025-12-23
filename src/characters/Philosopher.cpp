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
    energy -= 5;
    mood += 2;
    if (energy < 0) energy = 0;
    if (mood > 100) mood = 100;
}

std::string Philosopher::interact(std::shared_ptr<ICharacter> other) {
    std::string result = name + " gives wise advice to " + other->getName();
    mood += 3;
    other->setMood(other->getMood() + 10);
    return result;
}

std::string Philosopher::getType() const {
    return "Philosopher";
}

int Philosopher::getWisdom() const {
    return wisdom;
}

Philosopher::~Philosopher() {
    std::cout << "Philosopher " << name << " is leaving the village" << std::endl;
}