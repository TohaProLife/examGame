#ifndef ATHLETE_H
#define ATHLETE_H

#include "ICharacter.h"
#include <memory>

class Athlete : public ICharacter {
private:
    int fitness;

public:
    Athlete(std::string _name, int _fitness = 50);
    void live() override;
    std::string interact(std::shared_ptr<ICharacter> other) override;
    std::string getType() const override;
    int getFitness() const;
    ~Athlete();
};

#endif