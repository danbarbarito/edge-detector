#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "edge_detector.hpp"

void help() {
  std::cout << "usage: edge-detection <image_path>" << std::endl;
  exit(1);
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    help();
  }

  std::string command = argv[1];

  if (command.compare("--help") == 0) {
    help();
  }
    
  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Edge detection", sf::Style::Close | sf::Style::Titlebar);

  // load the image
  sf::Image image;
  bool loadedImage = image.loadFromFile(command);
  if (!loadedImage) {
    return 1;
  }

  // Initialize EdgeDetector
  EdgeDetector edgeDetector(image);
  sf::Image edgedImage = edgeDetector.detect();

  // create texture from image
  sf::Texture texture;
  texture.loadFromImage(edgedImage);

  // assign texture to sprite
  sf::Sprite sprite;
  sprite.setTexture(texture);

  // center sprite on screen
  sprite.setPosition((window.getSize().x / 2) - (texture.getSize().x / 2), (window.getSize().y / 2) - (texture.getSize().y / 2));


  // run the program as long as the window is open
  while (window.isOpen())
  {
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear(sf::Color::White);

    // draw image onto screen
    window.draw(sprite);

    // end the current frame
    window.display();
  }

  return 0;
}
