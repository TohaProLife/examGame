#include "Farmer.h"
#include <iostream>

Farmer::Farmer(std::string _name, int _gardening) : gardening(_gardening) {
    this->name = _name;
    this->energy = 90;
    this->mood = 70;
}

void Farmer::live() {
    std::cout << name << " the Farmer is working in the garden..." << std::endl;
    gardening++;
    mood -= 5;
    if (mood < 0) mood = 0;
}

std::string Farmer::interact(std::shared_ptr<ICharacter> other) {
    std::string result = name + " shares fresh vegetables with " + other->getName();
    energy -= 10;
    if (energy < 0) energy = 0;
    mood += 4;
    other->setMood(other->getMood() + gardening);
    return result;
}

std::string Farmer::getType() const {
    return "Farmer";
}

int Farmer::getGardening() const {
    return gardening;
}

Farmer::~Farmer() {
    std::cout << "Farmer " << name << " left the village" << std::endl;
}
