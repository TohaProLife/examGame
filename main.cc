#include "characters/ICharacter.h"
#include "characters/Scientist.h"
#include "characters/Artist.h"
#include "characters/Athlete.h"
#include "characters/Philosopher.h"
#include "Village.h"

#include <memory>
#include <iostream>
#include <random>

int main() {
    std::unique_ptr<Village> village(new Village());

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> moodDist(20, 100);

    std::shared_ptr<ICharacter> pin = std::make_shared<Scientist>("Pin", 10);
    pin->setMood(moodDist(gen));

    std::shared_ptr<ICharacter> losyash = std::make_shared<Scientist>("Losyash", 15);
    losyash->setMood(moodDist(gen));

    std::shared_ptr<ICharacter> barash = std::make_shared<Artist>("Barash", 5);
    barash->setMood(moodDist(gen));

    std::shared_ptr<ICharacter> sovunya = std::make_shared<Athlete>("Sovunya", 40);
    sovunya->setMood(moodDist(gen));

    std::shared_ptr<ICharacter> krosh = std::make_shared<Athlete>("Krosh", 60);
    krosh->setMood(moodDist(gen));

    std::shared_ptr<ICharacter> ezhik = std::make_shared<Athlete>("Ezhik", 55);
    ezhik->setMood(moodDist(gen));

    std::shared_ptr<ICharacter> nyusha = std::make_shared<Philosopher>("Nyusha", 8);
    nyusha->setMood(moodDist(gen));

    std::shared_ptr<ICharacter> kopatych = std::make_shared<Philosopher>("Kopatych", 35);
    kopatych->setMood(moodDist(gen));

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