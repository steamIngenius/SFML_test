#include <iostream>
#include "SFML/Graphics.hpp"


int main(int argc, char** argv) {
  sf::RenderWindow renderWindow(sf::VideoMode(1920, 1080), "Hello, funkjin");

  // Create a font object and load it from file relative
  sf::Font font;
  if (!font.loadFromFile("Georgia.ttf")) {
    return 42; // Don't Panic
  }

  // Create a Hello funkjin text object using our font and specifying a size
  sf::Text text("Hello, funkjin :)", font, 128);

  // Set the color to green
  text.setColor(sf::Color::Green);

  /* Get the text object's physical dimentions and use them to center the
     text in our window
     By default, things are drawn relative to their top left corner and
     can be changed by calling setOrigin()
   */
  sf::FloatRect bounds(text.getLocalBounds());
  text.setPosition(renderWindow.getSize().x / 2 - (bounds.left + bounds.width / 2),
                   renderWindow.getSize().y / 2 - (bounds.top + bounds.height / 2));



  while (renderWindow.isOpen()){
    sf::Event event;

    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::Closed)
        {
          renderWindow.close();
        }
    }
    renderWindow.clear(sf::Color::White);
    // Draw our text object
    renderWindow.draw(text);
    renderWindow.display();
  }
}
