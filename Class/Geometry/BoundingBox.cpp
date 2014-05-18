/*
 * BoundingBox.h
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#include	"BoundingBox.h"

C::Geometry::BoundingBox::BoundingBox()
{
  this->topLeft = C::Geometry::Vector2();
  this->topRight = C::Geometry::Vector2();
  this->bottomLeft = C::Geometry::Vector2();
  this->bottomRight = C::Geometry::Vector2();
}

C::Geometry::BoundingBox::BoundingBox(const BoundingBox &other)
{
  this->topLeft = other.topLeft;
  this->topRight = other.topRight;
  this->bottomLeft = other.bottomLeft;
  this->bottomRight = other.bottomRight;
}

C::Geometry::BoundingBox	&C::Geometry::BoundingBox::operator=(const BoundingBox &other)
{
  if (this != &other)
    {
      this->topLeft = other.topLeft;
      this->topRight = other.topRight;
      this->bottomLeft = other.bottomLeft;
      this->bottomRight = other.bottomRight;
    }
  return (*this);
}

C::Geometry::BoundingBox::~BoundingBox()
{
}

C::Geometry::BoundingBox::BoundingBox(const Vector2 &bottomLeft, const Vector2 &topLeft, const Vector2 &topRight, const Vector2 &bottomRight)
{
  this->topLeft = topLeft;
  this->topRight = topRight;
  this->bottomLeft = bottomLeft;
  this->bottomRight = bottomRight;
}

const std::string C::Geometry::BoundingBox::toString() const
{
  std::stringstream tmp;
  
  tmp << "{ BottomLeft:" << this->bottomLeft.toString() << ", TopLeft:" << this->topLeft.toString() << ", TopRight:" << this->topRight.toString() << ", BottomRight:" << this->bottomRight.toString() << "}";
  return (tmp.str());
}

bool	C::Geometry::BoundingBox::Equals(const BoundingBox &other) const
{
  if (this->bottomLeft.Equals(other.bottomLeft) && this->bottomRight.Equals(other.bottomRight) &&
      this->topLeft.Equals(other.topLeft) && this->topRight.Equals(other.topRight))
    return (true);
  return (false);
}
