#include "characters/ICharacter.h"
#include "characters/Scientist.h"
#include "characters/Artist.h"
#include "characters/Athlete.h"
#include "characters/Philosopher.h"
#include "characters/Fashionista.h"
#include "characters/Farmer.h"
#include "Village.h"

#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    std::unique_ptr<Village> village(new Village());

    srand(time(0));

    std::vector<std::shared_ptr<ICharacter>> allCharacters;
    allCharacters.push_back(std::make_shared<Scientist>("Pin", rand() % 20 + 1));
    allCharacters.push_back(std::make_shared<Scientist>("Losyash", rand() % 20 + 1));
    allCharacters.push_back(std::make_shared<Artist>("Barash", rand() % 10 + 1));
    allCharacters.push_back(std::make_shared<Athlete>("Sovunya", rand() % 50 + 30));
    allCharacters.push_back(std::make_shared<Athlete>("Krosh", rand() % 50 + 30));
    allCharacters.push_back(std::make_shared<Athlete>("Ezhik", rand() % 50 + 30));
    allCharacters.push_back(std::make_shared<Fashionista>("Nyusha", rand() % 25 + 10));
    allCharacters.push_back(std::make_shared<Farmer>("Kopatych", rand() % 30 + 15));
    allCharacters.push_back(std::make_shared<Philosopher>("Kar-Karych", rand() % 30 + 5));

    std::cout << "=== Village Simulator ===" << std::endl;
    std::cout << "\nAvailable characters:" << std::endl;
    std::cout << "1. Pin (Scientist, invention level: "
              << std::static_pointer_cast<Scientist>(allCharacters[0])->getInventionLevel() << ")" << std::endl;
    std::cout << "2. Losyash (Scientist, invention level: "
              << std::static_pointer_cast<Scientist>(allCharacters[1])->getInventionLevel() << ")" << std::endl;
    std::cout << "3. Barash (Artist, artworks: "
              << std::static_pointer_cast<Artist>(allCharacters[2])->getArtworks() << ")" << std::endl;
    std::cout << "4. Sovunya (Athlete, fitness: "
              << std::static_pointer_cast<Athlete>(allCharacters[3])->getFitness() << ")" << std::endl;
    std::cout << "5. Krosh (Athlete, fitness: "
              << std::static_pointer_cast<Athlete>(allCharacters[4])->getFitness() << ")" << std::endl;
    std::cout << "6. Ezhik (Athlete, fitness: "
              << std::static_pointer_cast<Athlete>(allCharacters[5])->getFitness() << ")" << std::endl;
    std::cout << "7. Nyusha (Fashionista, style: "
              << std::static_pointer_cast<Fashionista>(allCharacters[6])->getStyle() << ")" << std::endl;
    std::cout << "8. Kopatych (Farmer, gardening: "
              << std::static_pointer_cast<Farmer>(allCharacters[7])->getGardening() << ")" << std::endl;
    std::cout << "9. Kar-Karych (Philosopher, wisdom: "
              << std::static_pointer_cast<Philosopher>(allCharacters[8])->getWisdom() << ")" << std::endl;

    std::cout << "\nEnter character numbers to add (separated by space, press Enter to finish):" << std::endl;

    std::string line;
    std::getline(std::cin, line);

    int choice;
    int pos = 0;
    while (pos < line.length()) {
        if (line[pos] >= '1' && line[pos] <= '9') {
            choice = line[pos] - '0';
            allCharacters[choice - 1]->setMood(rand() % 80 + 20);
            village->addCharacter(allCharacters[choice - 1]);
        }
        pos++;
    }

    int days;
    std::cout << "\nEnter number of days to simulate: ";
    std::cin >> days;

    std::cout << "\nStarting simulation for " << days << " days..." << std::endl;
    for (int i = 0; i < days; i++) {
        village->simulate();
    }

    std::cout << "\nSimulation complete!" << std::endl;
    std::cout << "Population: " << village->getPopulation() << std::endl;

    return 0;
}