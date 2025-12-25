#ifndef FARMER_H
#define FARMER_H

#include "ICharacter.h"
#include <memory>

class Farmer : public ICharacter {
private:
    int gardening;

public:
    Farmer(std::string _name, int _gardening = 25);
    void live() override;
    std::string interact(std::shared_ptr<ICharacter> other) override;
    std::string getType() const override;
    int getGardening() const;
    ~Farmer();
};

#endif
