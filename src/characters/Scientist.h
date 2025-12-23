#ifndef SCIENTIST_H
#define SCIENTIST_H

#include "ICharacter.h"
#include <memory>

class Scientist : public ICharacter {
private:
    int inventionLevel;

public:
    Scientist(std::string _name, int _inventionLevel = 0);
    void live() override;
    std::string interact(std::shared_ptr<ICharacter> other) override;
    std::string getType() const override;
    int getInventionLevel() const;
    ~Scientist();
};

#endif