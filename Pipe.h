#ifndef BIRD_PIPE_H
#define BIRD_PIPE_H

#include <utility>

enum Orientation {up, down};

class Pipe {
public:
    Pipe(Orientation dir, float x, float y, float speed_ = 2);

    void Move();

private:
    Orientation dir_;
    std::pair<float, float> pos_;
    float speed_;
};


#endif //BIRD_PIPE_H
