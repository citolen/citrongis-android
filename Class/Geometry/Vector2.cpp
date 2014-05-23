/*
 * Vector2.cpp
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#include	<Vector2.h>

C::Geometry::Vector2::Vector2()
{
  this->X = 0;
  this->Y = 0;
}

C::Geometry::Vector2::Vector2(const Vector2 &other)
{
  this->X = other.X;
  this->Y = other.Y;
}

C::Geometry::Vector2::Vector2(double X, double Y)
{
  this->X = X;
  this->Y = Y;
}

C::Geometry::Vector2	&C::Geometry::Vector2::operator=(const Vector2 &other)
{
  if (this != &other)
    {
      this->X = other.X;
      this->Y = other.Y;
    }
  return (*this);
}

C::Geometry::Vector2::~Vector2()
{
}

bool	C::Geometry::Vector2::Equals(const Vector2 &other) const
{
  if (C::Utils::Comparison::Equals(this->X, other.X) && C::Utils::Comparison::Equals(this->Y, other.Y))
    return (true);
  return (false);
}

bool	C::Geometry::Vector2::Equals(const Vector2 &Va, const Vector2 &Vb)
{
  return (Va.Equals(Vb));
}

double	C::Geometry::Vector2::Distance(const Vector2 &other) const
{
  return (sqrt(pow(this->X - other.X, 2) + pow(this->Y - other.Y, 2)));
}

double	C::Geometry::Vector2::Distance(const Vector2 &Va, const Vector2 &Vb)
{
  return (Va.Distance(Vb));
}

double	C::Geometry::Vector2::DotProduct(const Vector2 &other) const
{
  return (this->X * other.X + this->Y * other.Y);
}

double	C::Geometry::Vector2::DotProduct(const Vector2 &Va, const Vector2 &Vb)
{
  return (Va.DotProduct(Vb));
}

const std::string	C::Geometry::Vector2::toString() const
{
  std::stringstream tmp;
 
  tmp << "{ x:" << this->X  << ", y:" << this->Y << " }";

  return (tmp.str());
}
