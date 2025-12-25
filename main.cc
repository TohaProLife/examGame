#include "characters/ICharacter.h"
#include "characters/Scientist.h"
#include "characters/Artist.h"
#include "characters/Athlete.h"
#include "characters/Philosopher.h"
#include "Village.h"

#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<Village> village = std::make_unique<Village>();

    std::shared_ptr<ICharacter> pin = std::make_shared<Scientist>("Pin", 10);
    std::shared_ptr<ICharacter> losyash = std::make_shared<Scientist>("Losyash", 15);
    std::shared_ptr<ICharacter> barash = std::make_shared<Artist>("Barash", 5);
    std::shared_ptr<ICharacter> sovunya = std::make_shared<Athlete>("Sovunya", 40);
    std::shared_ptr<ICharacter> krosh = std::make_shared<Athlete>("Krosh", 60);
    std::shared_ptr<ICharacter> ezhik = std::make_shared<Athlete>("Ezhik", 55);
    std::shared_ptr<ICharacter> nyusha = std::make_shared<Philosopher>("Nyusha", 8);
    std::shared_ptr<ICharacter> kopatych = std::make_shared<Philosopher>("Kopatych", 35);

    village->addCharacter(pin);
    village->addCharacter(losyash);
    village->addCharacter(barash);
    village->addCharacter(nyusha);
    village->addCharacter(krosh);
    village->addCharacter(ezhik);
    village->addCharacter(sovunya);
    village->addCharacter(kopatych);

    std::cout << "\nStarting simulation..." << std::endl;
    for (int i = 0; i < 3; i++) {
        village->simulate();
    }

    std::cout << "\nSimulation complete!" << std::endl;
    std::cout << "Population: " << village->getPopulation() << std::endl;

    return 0;
}