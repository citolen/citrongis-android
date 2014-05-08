/*
 * Point.cpp
 *
 *  Created on: May 8, 2014
 *      Author: romain
 */

#include "Point.h"

C::Geometry::Point::Point() {
  this->X = 0;
  this->Y = 0;
  this->Z = 0;
}

C::Geometry::Point::Point(const Point &cpy) {
  this->X = cpy.X;
  this->Y = cpy.Y;
  this->Z = cpy.Z;
  this->CRS = cpy.CRS;
}

C::Geometry::Point &C::Geometry::Point::operator=(const Point &other)
{
  if (this != &other)
    {
      this->X = other.X;
      this->Y = other.Y;
      this->Z = other.Z;
      this->CRS = other.CRS;
    }
  return (*this);
}

C::Geometry::Point::Point(double X, double Y, double Z, std::string proj)
{
  this->X = X;
  this->Y = Y;
  this->Z = Z;
  this->CRS = pj_init_plus(proj.c_str());
}

C::Geometry::Point::~Point() {
  pj_free(this->CRS);
}

void	C::Geometry::Point::ToString()
{
  /*
    Exemple of print
    return ("{ x: " + this.X + ", y: " + this.Y + ", z: " + this.Z + ", CRS: " + (this.CRS.name || this.CRS.title || this.CRS) + "}");
  */
}
