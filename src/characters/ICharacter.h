#ifndef ICHARACTER_H
#define ICHARACTER_H

#include <string>
#include <memory>

class ICharacter {
public:
    ICharacter() = default;

    virtual void live() = 0;
    virtual std::string interact(std::shared_ptr<ICharacter> other) = 0;
    virtual std::string interact(std::shared_ptr<ICharacter> other, int helpAmount) {
        std::string result = name + " helps " + other->getName();
        energy -= helpAmount;
        other->setEnergy(other->getEnergy() + helpAmount);
        return result;
    }

    virtual std::string getType() const = 0;

    virtual int getEnergy() const { return energy; }
    virtual int getMood() const { return mood; }
    virtual std::string getName() const { return name; }

    virtual void setEnergy(int value) { energy = value; }
    virtual void setMood(int value) { mood = value; }

    virtual bool shouldLeave() const { return mood <= 0 || energy <= 0; }

    virtual ~ICharacter() = default;

protected:
    std::string name;
    int energy = 100;
    int mood = 50;
};

#endif