#include "BirdGame.h"

#include <cstdlib>
#include <ctime>


BirdGame::BirdGame()
    : pipes_(), player_() {
}

void BirdGame::Update(sf::Time & elapsed) {
    player_.Fall(elapsed);
}

void BirdGame::SpawnPipe() {
    /*
    std::srand(std::time(nullptr));
    pipes_.push_back(Pipe(Orientation::up, 0,0));
    */
}

bool BirdGame::PipeHitsPlayer(Pipe & pipe) {
    auto player_pos = player_.GetPos();

   return [&pipe, &player_pos](){
        auto pipe_pos = pipe.GetPos();

        switch (pipe.GetOrientation()) {
            case Orientation::up : {

                return false;
            }
            case Orientation::down : {

                return false;
            }
            default : return false;
        }
    }();
}

