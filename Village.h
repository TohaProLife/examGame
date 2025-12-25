#ifndef VILLAGE_H
#define VILLAGE_H

#include "characters/ICharacter.h"
#include <vector>
#include <memory>

class Village {
private:
    std::vector<std::shared_ptr<ICharacter>> characters;
    int day;

public:
    Village();
    void addCharacter(std::shared_ptr<ICharacter> character);
    void simulate();
    void displayStats();
    int getDay() const;
    size_t getPopulation() const;
    ~Village();
};

#endif