#ifndef ICHARACTER_H
#define ICHARACTER_H

#include <string>
#include <memory>

class ICharacter {
public:
    ICharacter() = default;

    virtual void live() = 0;
    virtual std::string interact(std::shared_ptr<ICharacter> other) = 0;
    virtual std::string getType() const = 0;

    virtual int getEnergy() const { return energy; }
    virtual int getMood() const { return mood; }
    virtual std::string getName() const { return name; }

    virtual void setEnergy(int value) { energy = value; }
    virtual void setMood(int value) { mood = value; }

    virtual ~ICharacter() = default;

protected:
    std::string name;
    int energy = 100;
    int mood = 50;
};

#endif