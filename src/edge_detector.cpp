#include "edge_detector.hpp"

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>


EdgeDetector::EdgeDetector(sf::Image source_image) {
  this->source_image = source_image;
  this->greyscaled_image = this->greyscaleImage();
}

sf::Color EdgeDetector::greyscalePixel(int x, int y) {
  sf::Color existingColor = this->source_image.getPixel(x, y);

  int r = existingColor.r;
  int g = existingColor.g;
  int b = existingColor.b;

  float average = (r + g + b) / 3;

  return sf::Color(average, average, average);
}

sf::Image EdgeDetector::greyscaleImage() {
  sf::Image greyscaled_image = this->source_image;
  sf::Vector2u size = greyscaled_image.getSize();
  for (int x = 0; x < size.x; x++) {
    for (int y = 0; y < size.y; y++) {
      // sf::Color existingColor = this->source_image.getPixel(x, y);
      sf::Color newColor = this->greyscalePixel(x, y);
      greyscaled_image.setPixel(x, y, newColor);
    }
  }
  return greyscaled_image;
}

bool EdgeDetector::pixelInBounds(int x, int y) {
  sf::Vector2u size = this->source_image.getSize();
  if (x < 0 || y < 0 || x > (int)size.x || y > (int)size.y) return false;
  return true;
}

float EdgeDetector::gradientValue(int x, int y) {
  float gradientValue = 0;
  // Gradient X
  

  // Gradient Y
  // TODO

  return gradientValue;
}

sf::Image EdgeDetector::detect() {
  sf::Image edgedImage = this->greyscaled_image;
  sf::Vector2u size = edgedImage.getSize();
  for (int x = 0; x < size.x; x++) {
    for (int y = 0; y < size.y; y++) {
      sf::Color existingColor = edgedImage.getPixel(x, y);
      this->source_image.setPixel(x, y, existingColor);
    }
  }
  return edgedImage;
}
