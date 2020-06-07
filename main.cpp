#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    VideoMode vm(800,600);
    RenderWindow window(vm, "Bird", Style::Default);

    // Background
    Texture textureBG;
    textureBG.loadFromFile("resources/placeholder_bg.png");
    Sprite spriteBG;
    spriteBG.setTexture(textureBG);
    spriteBG.setPosition(0,0);

    // Pipe
    Texture texturePipe;
    texturePipe.loadFromFile("resources/pipe_up.png");
    Sprite spritePipe;
    spritePipe.setTexture(texturePipe);
    spritePipe.setPosition(336, 472);



    while(window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        window.clear();

        window.draw(spriteBG);
        window.draw(spritePipe);

        window.display();
    }

    return 0;
}