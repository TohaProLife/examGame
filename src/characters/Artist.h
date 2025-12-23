#ifndef ARTIST_H
#define ARTIST_H

#include "ICharacter.h"
#include <memory>

class Artist : public ICharacter {
private:
    int artworks;

public:
    Artist(std::string _name, int _artworks = 0);
    void live() override;
    std::string interact(std::shared_ptr<ICharacter> other) override;
    std::string getType() const override;
    int getArtworks() const;
    ~Artist();
};

#endif