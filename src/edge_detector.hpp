#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include <SFML/Graphics.hpp>

class EdgeDetector {
private:
  sf::Color greyscalePixel(sf::Image* image, int x, int y);
  sf::Image greyscaleImage(sf::Image* image);
  bool pixelInBounds(sf::Image* image, int x, int y);
  float gradientValue(sf::Image* image, int x, int y);
public:
  EdgeDetector(sf::Image* source_image);
  sf::Image* source_image;
  sf::Image greyscaled_image;
  sf::Image detect();
};


#endif /* EDGE_DETECTOR_H */
