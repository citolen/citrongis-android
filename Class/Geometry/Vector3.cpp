/*
 * Vector2.cpp
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#include	<Vector3.h>

C::Geometry::Vector3::Vector3()
{
  this->X = 0;
  this->Y = 0;
  this->Z = 0;
}

C::Geometry::Vector3::Vector3(const Vector3 &other)
{
  this->X = other.X;
  this->Y = other.Y;
  this->Z = other.Z;
}

C::Geometry::Vector3::Vector3(double X, double Y, double Z)
{
  this->X = X;
  this->Y = Y;
  this->Z = Z;
}

C::Geometry::Vector3	&C::Geometry::Vector3::operator=(const Vector3 &other)
{
  if (this != &other)
    {
      this->X = other.X;
      this->Y = other.Y;
      this->Z = other.Z;
    }
  return (*this);
}

C::Geometry::Vector3::~Vector3()
{
}

bool	C::Geometry::Vector3::Equals(const Vector3 &other) const
{
  if ((this->X == other.X) && (this->Y == other.Y) && (this->Z == other.Z))
    return (true);
  return (false);
}

bool	C::Geometry::Vector3::Equals(const Vector3 &Va, const Vector3 &Vb)
{
  return (Va.Equals(Vb));
}

double	C::Geometry::Vector3::Distance(const Vector3 &other) const
{
  return (sqrt(pow(this->X - other.X, 2) +
	       pow(this->Y - other.Y, 2) +
	       pow(this->Z - other.Z, 2)));
}

double	C::Geometry::Vector3::Distance(const Vector3 &Va, const Vector3 &Vb)
{
  return (Va.Distance(Vb));
}

double	C::Geometry::Vector3::DotProduct(const Vector3 &other) const
{
  return (this->X * other.X +
	  this->Y * other.Y +
	  this->Z * other.Z);
}

double	C::Geometry::Vector3::DotProduct(const Vector3 &Va, const Vector3 &Vb)
{
  return (Va.DotProduct(Vb));
}

const std::string	C::Geometry::Vector3::toString() const
{
  std::stringstream x;
  std::stringstream y;
  std::stringstream z;

  x << this->X;
  y << this->Y;
  y << this->Z;

  return ("{ x:" + x.str() + ", y:" + y.str() + ", z:" + z.str() + " }");
}
