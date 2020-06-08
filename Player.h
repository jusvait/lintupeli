#ifndef BIRD_PLAYER_H
#define BIRD_PLAYER_H

#include <SFML/System/Time.hpp>

#include <utility>

class Player {
public:
    Player();

    const std::pair<float,float> & GetPos() const {
        return pos_;
    }

    float GetAngle() const;

    void Flap();

    void Fall(sf::Time & elapsed);

private:
    float h_speed_;

    std::pair<float, float> pos_;
};


#endif //BIRD_PLAYER_H
