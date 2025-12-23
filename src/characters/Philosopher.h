#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include "ICharacter.h"
#include <memory>

class Philosopher : public ICharacter {
private:
    int wisdom;

public:
    Philosopher(std::string _name, int _wisdom = 30);
    void live() override;
    std::string interact(std::shared_ptr<ICharacter> other) override;
    std::string getType() const override;
    int getWisdom() const;
    ~Philosopher();
};

#endif