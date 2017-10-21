#include <SFML/Graphics.hpp>

int main(int argc, char** argv) {
  sf::RenderWindow renderWindow(sf::VideoMode(1920, 1080), "Dingus in France");

  sf::Event event;
  sf::Image image;
  image.loadFromFile("RPGCharacterSprites32x32.png");
  image.createMaskFromColor(sf::Color::Magenta);

  sf::Texture texture;
  texture.loadFromImage(image);

  int offset = 32;
  sf::IntRect rectSourceSprite(0, 96, offset, offset);
  sf::Sprite sprite(texture, rectSourceSprite);
  sprite.setScale(4.0f, 4.0f);
  sf::Clock clock;

  while (renderWindow.isOpen()) {
    while (renderWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        renderWindow.close();
    }

    if (clock.getElapsedTime().asSeconds() > 0.33f) {
      if (rectSourceSprite.left == 64 || (rectSourceSprite.left == 0 && offset < 0))
        offset = -offset;

      rectSourceSprite.left += offset;
      sprite.setTextureRect(rectSourceSprite);
      clock.restart();
    }

    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}
