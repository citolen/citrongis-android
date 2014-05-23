/*
 * BoundingBox.h
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#include	"Geometry/BoundingBox.h"

C::Geometry::BoundingBox::BoundingBox()
{
  this->TopLeft = C::Geometry::Vector2();
  this->TopRight = C::Geometry::Vector2();
  this->BottomLeft = C::Geometry::Vector2();
  this->BottomRight = C::Geometry::Vector2();
}

C::Geometry::BoundingBox::BoundingBox(const BoundingBox &other)
{
  this->TopLeft = other.TopLeft;
  this->TopRight = other.TopRight;
  this->BottomLeft = other.BottomLeft;
  this->BottomRight = other.BottomRight;
}

C::Geometry::BoundingBox	&C::Geometry::BoundingBox::operator=(const BoundingBox &other)
{
  if (this != &other)
    {
      this->TopLeft = other.TopLeft;
      this->TopRight = other.TopRight;
      this->BottomLeft = other.BottomLeft;
      this->BottomRight = other.BottomRight;
    }
  return (*this);
}

C::Geometry::BoundingBox::~BoundingBox()
{
}

C::Geometry::BoundingBox::BoundingBox(const Vector2 &BottomLeft, const Vector2 &TopLeft, const Vector2 &TopRight, const Vector2 &BottomRight)
{
  this->TopLeft = TopLeft;
  this->TopRight = TopRight;
  this->BottomLeft = BottomLeft;
  this->BottomRight = BottomRight;
}

const std::string		C::Geometry::BoundingBox::toString() const
{
  std::stringstream		tmp;
  
  tmp << "{ BottomLeft:" << this->BottomLeft.toString() << ", TopLeft:" << this->TopLeft.toString() << ", TopRight:" << this->TopRight.toString() << ", BottomRight:" << this->BottomRight.toString() << "}";
  return (tmp.str());
}

bool				C::Geometry::BoundingBox::Equals(const BoundingBox &other) const
{
  if (this->BottomLeft.Equals(other.BottomLeft) && this->BottomRight.Equals(other.BottomRight) &&
      this->TopLeft.Equals(other.TopLeft) && this->TopRight.Equals(other.TopRight))
    return (true);
  return (false);
}

const C::Geometry::Vector2	C::Geometry::BoundingBox::Center() const
{
  double			X = (this->BottomLeft.X + this->BottomRight.X + this->TopLeft.X + this->TopRight.X) / 4.0;
  double			Y = (this->BottomLeft.Y + this->BottomRight.Y + this->TopLeft.Y + this->TopRight.Y) / 4.0;

  return (C::Geometry::Vector2(X, Y));
}

bool				C::Geometry::BoundingBox::Intersect(const BoundingBox &other) const
{
  if (C::Utils::Intersection::IsPointInsideRectangle(this->TopLeft, this->TopRight, this->BottomRight, this->BottomLeft, other.TopLeft) ||
      C::Utils::Intersection::IsPointInsideRectangle(this->TopLeft, this->TopRight, this->BottomRight, this->BottomLeft, other.TopRight) ||
      C::Utils::Intersection::IsPointInsideRectangle(this->TopLeft, this->TopRight, this->BottomRight, this->BottomLeft, other.BottomRight) ||
      C::Utils::Intersection::IsPointInsideRectangle(this->TopLeft, this->TopRight, this->BottomRight, this->BottomLeft, other.BottomLeft))
    return (true);
  return (false);
}

bool				C::Geometry::BoundingBox::Intersect(const Point &other) const
{
  return (C::Utils::Intersection::IsPointInsideRectangle(this->TopLeft, this->TopRight, this->BottomRight, this->BottomLeft, other));
}
