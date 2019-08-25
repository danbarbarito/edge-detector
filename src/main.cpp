#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

void help() {
  std::cout << "usage: edge-detection <image_path>" << std::endl;
  exit(1);
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cout << "ERROR: No image specified" << std::endl;
    help();
  }

  std::string command = argv[1];

  if (command.compare("--help") == 0) {
    help();
  }

    
  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Edge detection");

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

    // draw everything here...
    // window.draw(...);

    // end the current frame
    window.display();
  }

  return 0;
}
