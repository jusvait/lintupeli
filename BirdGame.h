#ifndef BIRD_BIRDGAME_H
#define BIRD_BIRDGAME_H

#include "Pipe.h"
#include "Player.h"

#include <vector>
#include <SFML/System/Time.hpp>

class BirdGame {
public:
    BirdGame();

    void Update(sf::Time & time);

    bool GameOver() {return flag_GameOver_;}

    std::vector<Pipe> pipes_;
    Player player_;

private:
    bool PipeHitsPlayer(Pipe & pipe);

    void SpawnPipe();

    bool flag_GameOver_;

};


#endif //BIRD_BIRDGAME_H
