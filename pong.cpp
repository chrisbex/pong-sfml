// compile using:
// g++ -Wall -Wextra pong.cpp -o pong.exe -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ball.h"
#include "paddle.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

Ball _ball(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
Paddle _paddle1(sf::Vector2f(5, SCREEN_HEIGHT/2 - 20));
Paddle _paddle2(sf::Vector2f(SCREEN_WIDTH - 15, SCREEN_HEIGHT/2 - 20));

void manage_events();

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong Game v0.0");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseMoved)
            {
                _paddle1.setPosition(sf::Vector2f(5, event.mouseMove.y));
                _paddle2.setPosition(sf::Vector2f(SCREEN_WIDTH - 15, event.mouseMove.y));
            }
        }

        manage_events();
       _ball.setPosition(_ball.getPosition() + _ball.getVelocity());
        window.clear();
        // we are drawing right here!
        _ball.draw(window);
        _paddle1.draw(window);
        _paddle2.draw(window);
        window.display();
    }

    return 0;
}

void manage_events()
{
    // checking collision with upper and bottom window frame
    if (_ball.getPosition().y <= 1) _ball.setVelocityY(- _ball.getVelocityY());
    if (_ball.getPosition().y >= SCREEN_HEIGHT - 10) _ball.setVelocityY(- _ball.getVelocityY());

    // checking collisions with left and right window frame - has to be deleted in full version ;-)
    if (_ball.getPosition().x <= 0) _ball.setVelocityX(- _ball.getVelocityX());
    if (_ball.getPosition().x >= SCREEN_WIDTH) _ball.setVelocityX(- _ball.getVelocityX());

    // TODO: checking collisions with paddles
    
}