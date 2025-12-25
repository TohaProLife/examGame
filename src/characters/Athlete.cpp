#include "Athlete.h"
#include <iostream>

Athlete::Athlete(std::string _name, int _fitness) : fitness(_fitness) {
    this->name = _name;
    this->energy = 100;
    this->mood = 70;
}

void Athlete::live() {
    std::cout << name << " the Athlete is training..." << std::endl;
    fitness += 2;
    mood -= 5;
    if (mood < 0) mood = 0;
}

std::string Athlete::interact(std::shared_ptr<ICharacter> other) {
    std::string result = name + " plays sports with " + other->getName();
    mood += 8;
    energy -= 5;
    other->setMood(other->getMood() + fitness / 10);
    other->setEnergy(other->getEnergy() - 3);
    return result;
}

std::string Athlete::getType() const {
    return "Athlete";
}

int Athlete::getFitness() const {
    return fitness;
}

Athlete::~Athlete() {
    std::cout << "Athlete " << name << " left the village" << std::endl;
}