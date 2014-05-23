/*
 * Point.cpp
 *
 *  Created on: May 8, 2014
 *      Author: romain
 */

#include "Geometry/Point.h"

C::Geometry::Point::Point() {
  this->X = 0;
  this->Y = 0;
  this->Z = 0;
  this->CRS = NULL;
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

C::Geometry::Point::Point(const double X, const double Y, const double Z, const std::string proj)
{
  this->X = X;
  this->Y = Y;
  this->Z = Z;
  if ((this->CRS = pj_init_plus(proj.c_str())) == NULL)
    {
      /*
      ** Execption ??
      ** Display Errno : std::cout << pj_strerrno(*(pj_get_errno_ref())) << std::endl;
      */
      exit (EXIT_FAILURE);
    }
}

C::Geometry::Point::Point(const double X, const double Y, const double Z, const projPJ CRS)
{
  this->X = X;
  this->Y = Y;
  this->Z = Z;
  this->CRS = CRS;
}

C::Geometry::Point::~Point() {
  if (this->CRS != NULL)
    pj_free(this->CRS);
}

const std::string	&C::Geometry::Point::toString() const
{
  /*
    Exemple of print
    return ("{ x: " + this.X + ", y: " + this.Y + ", z: " + this.Z + ", CRS: " + (this.CRS.name || this.CRS.title || this.CRS) + "}");
  */
}
