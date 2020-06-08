#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "BirdGame.h"

#include <iostream>

using namespace sf;

int main()
{

    // Window
    VideoMode vm(400,600);
    RenderWindow window(vm, "Bird", Style::Default);
    window.setFramerateLimit(60);

    // Background music
    SoundBuffer buffer;
    buffer.loadFromFile("resources/music.wav");
    Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);

    // Background
    Texture textureBG;
    textureBG.loadFromFile("resources/background.png");
    textureBG.setRepeated(true);
    Sprite spriteBG;
    spriteBG.setTextureRect(IntRect(0,0,1600,600));
    spriteBG.setTexture(textureBG);
    spriteBG.setPosition(0,0);

    // Pipe
    Texture t_bird;
    t_bird.loadFromFile("resources/bird.png");
    Sprite s_bird;
    s_bird.setTexture(t_bird);
    s_bird.setOrigin(24,24);
    s_bird.setPosition(200, 300);

    float parallax_bg = 0;
    float parallax_bg_speed = 2;

    Clock clock;

    BirdGame game;

    sound.play();

    while(window.isOpen() && game.GameOver())
    {
        Time elapsed = clock.getElapsedTime();
        clock.restart();

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        } else if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            game.player_.Flap();
        }



        // Update game state
        game.Update(elapsed);
        parallax_bg -= parallax_bg_speed;

        if (parallax_bg == -800) {
            parallax_bg = 0;
        }

        // Draw game
        window.clear();

        std::pair<float, float> player_pos = game.player_.GetPos();

        s_bird.setPosition(player_pos.first, player_pos.second);
        s_bird.setRotation(game.player_.GetAngle());

        spriteBG.setPosition(parallax_bg, 0);

        window.draw(spriteBG);
        window.draw(s_bird);

        window.display();


    }

    if (window.isOpen()) {
        window.close();
    }

    sound.stop();

    return 0;
}