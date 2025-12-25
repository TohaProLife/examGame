#include "Artist.h"
#include <iostream>

Artist::Artist(std::string _name, int _artworks) : artworks(_artworks) {
    this->name = _name;
    this->energy = 70;
    this->mood = 80;
}

void Artist::live() {
    std::cout << name << " the Artist is creating a masterpiece..." << std::endl;
    artworks++;
    mood -= 5;
    if (mood < 0) mood = 0;
}

std::string Artist::interact(std::shared_ptr<ICharacter> other) {
    std::string result = name + " shows their art to " + other->getName();
    energy -= 10;
    if (energy < 0) energy = 0;
    mood += 10;
    other->setMood(other->getMood() + artworks);
    return result;
}

std::string Artist::getType() const {
    return "Artist";
}

int Artist::getArtworks() const {
    return artworks;
}

Artist::~Artist() {
    std::cout << "Artist " << name << " is leaving the village" << std::endl;
}