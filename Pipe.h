#ifndef BIRD_PIPE_H
#define BIRD_PIPE_H

#include <utility>

enum Orientation {up, down};

class Pipe {
public:
    Pipe(Orientation dir, float x, float y, float speed_ = 2);

    const Orientation & GetOrientation() const {
        return dir_;
    }

    const std::pair<float, float> & GetPos() const {
        return pos_;
    }

    void Move();

private:
    Orientation dir_;
    std::pair<float, float> pos_;
    float speed_;
};


#endif //BIRD_PIPE_H
