#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include <SFML/Graphics.hpp>

class EdgeDetector {
private:
  sf::Color greyscalePixel(int x, int y);
  sf::Image greyscaleImage();
  bool pixelInBounds(int x, int y);
  float gradientValue(int x, int y);
public:
  EdgeDetector(sf::Image source_image);
  sf::Image source_image;
  sf::Image greyscaled_image;
  sf::Image detect();
};


#endif /* EDGE_DETECTOR_H */
