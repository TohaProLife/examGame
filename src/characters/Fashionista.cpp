#include "Fashionista.h"
#include <iostream>

Fashionista::Fashionista(std::string _name, int _style) : style(_style) {
    this->name = _name;
    this->energy = 75;
    this->mood = 85;
}

void Fashionista::live() {
    std::cout << name << " the Fashionista is creating a new style..." << std::endl;
    style++;
    mood -= 5;
    if (mood < 0) mood = 0;
}

std::string Fashionista::interact(std::shared_ptr<ICharacter> other) {
    std::string result = name + " shares fashion tips with " + other->getName();
    energy -= 10;
    if (energy < 0) energy = 0;
    mood += 5;
    other->setMood(other->getMood() + style);
    return result;
}

std::string Fashionista::getType() const {
    return "Fashionista";
}

int Fashionista::getStyle() const {
    return style;
}

Fashionista::~Fashionista() {
    std::cout << "Fashionista " << name << " left the village" << std::endl;
}
