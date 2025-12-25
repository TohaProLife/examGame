#ifndef FASHIONISTA_H
#define FASHIONISTA_H

#include "ICharacter.h"
#include <memory>

class Fashionista : public ICharacter {
private:
    int style;

public:
    Fashionista(std::string _name, int _style = 20);
    void live() override;
    std::string interact(std::shared_ptr<ICharacter> other) override;
    std::string getType() const override;
    int getStyle() const;
    ~Fashionista();
};

#endif
