#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 700), "SFML works!");
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        sf::Event event;

        // process events
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // run update
        ImGui::SFML::Update(window, deltaClock.restart());


        window.clear(sf::Color::Black);
        //window.draw(shape);


        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return EXIT_SUCCESS;
}