#include "Player.h"

Player::Player()
    : h_speed_(0), pos_(std::make_pair<float,float>(0,0)) {
}

float Player::GetAngle() const {
    return ((h_speed_ / 400) * 90);
}

void Player::Flap() {
    if (h_speed_ >= 0) {
        h_speed_ = -300;
    }
}

void Player::Fall(sf::Time & elapsed) {
    h_speed_ += 400*elapsed.asSeconds();

    pos_.second += h_speed_*elapsed.asSeconds();

    if (pos_.second > 552) {
        pos_.second = 552;
    }
}

