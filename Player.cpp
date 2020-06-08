#include "Player.h"

Player::Player()
    : h_speed_(0), pos_(std::make_pair<float,float>(200,300)) {
}

float Player::GetAngle() const {
    return ((h_speed_ / 800) * 75 - 10);
}

void Player::Flap() {
    h_speed_ = -300;
}

void Player::Fall(sf::Time & elapsed) {
    h_speed_ += 800*elapsed.asSeconds();

    if (h_speed_ > 800) {
        h_speed_ = 800;
    }

    pos_.second += h_speed_*elapsed.asSeconds();

    if (pos_.second > 552) {
        pos_.second = 552;
    }
}

