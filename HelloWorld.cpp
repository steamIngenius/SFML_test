#include <SFML/Graphics.hpp>


int main(int argc, char** argv) {
  sf::RenderWindow renderWindow(sf::VideoMode(1920, 1080), "Hello, funkjin");

  sf::Font font;
  sf::Texture texture;
  sf::Shader shader;
  if (!texture.loadFromFile("skull.png") ||
      !font.loadFromFile("AnonymousPro-Regular.ttf") ||
      !shader.loadFromFile("shader.vert", "shader.frag")) {
    renderWindow.close();
    return 42; // Don't Panic
  }

  sf::Sprite sprite(texture);
  sprite.setPosition(0,0);

  sf::Text text("hi funkjin", font, 128);
  text.setColor(sf::Color::Green);
  /* Get the text object's physical dimentions and use them to center the
     text in our window
     By default, things are drawn relative to their top left corner and
     can be changed by calling setOrigin()
   */
  sf::FloatRect bounds(text.getLocalBounds());
  text.setPosition(renderWindow.getSize().x / 2 - (bounds.left + bounds.width / 2),
                   renderWindow.getSize().y / 2 - (bounds.top + bounds.height / 2));

  float opacity = 1.0f;
  shader.setParameter("texture", sf::Shader::CurrentTexture);
  shader.setParameter("opacity", opacity);

  sf::Event event;
  sf::Clock clock;
  while (renderWindow.isOpen()) {
    while (renderWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
          renderWindow.close();
      }

      if (event.type == sf::Event::KeyPressed) {
        // Event driven input handling
        if (event.key.code == sf::Keyboard::Left)
          sprite.move(-5, 0);
        if (event.key.code == sf::Keyboard::Right)
          sprite.move(5, 0);
        if (event.key.code == sf::Keyboard::Up)
          sprite.move(0, -5);
        if (event.key.code == sf::Keyboard::Down)
          sprite.move(0, 5);
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(renderWindow)));

    if (clock.getElapsedTime().asSeconds() > 0.1) {
      opacity -= 0.05;
      if (opacity < 0.0)
        opacity = 1.0;

      clock.restart();
      shader.setParameter("opacity", opacity);
    }

    renderWindow.clear(sf::Color::White);
    renderWindow.draw(text);
    renderWindow.draw(sprite, &shader);
    renderWindow.display();
  }
}
