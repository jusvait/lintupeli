#include "Pipe.h"

Pipe::Pipe(Orientation dir, float x, float y, float speed)
    : dir_(dir), pos_(std::make_pair(x,y)), speed_(speed) {
}

void Pipe::Move() {
    pos_.first += speed_;
}

