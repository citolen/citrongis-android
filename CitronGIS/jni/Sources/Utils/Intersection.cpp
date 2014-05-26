/*
 * Intersection.h
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#include	"Utils/Intersection.h"

C::Utils::Intersection::Intersection()
{
}

C::Utils::Intersection::Intersection(const Intersection &other)
{
}

C::Utils::Intersection	&C::Utils::Intersection::operator=(const Intersection &other)
{
	return (*this);
}

C::Utils::Intersection::~Intersection()
{
}

bool	C::Utils::Intersection::Test(const C::Geometry::Vector2 &a,
				     const C::Geometry::Vector2 &b,
				     const C::Geometry::Vector2 &p)
{
  if ((a.Y > p.Y) != (b.Y > p.Y) && (p.X < (b.X - a.X) * (p.Y - a.Y) / (b.Y - a.Y) + a.X))
    return (true);
  return (false);
}

bool	C::Utils::Intersection::Test(const C::Geometry::Vector2 &a,
				     const C::Geometry::Vector2 &b,
				     const C::Geometry::Point &p)
{
  if ((a.Y > p.Y) != (b.Y > p.Y) && (p.X < (b.X - a.X) * (p.Y - a.Y) / (b.Y - a.Y) + a.X))
    return (true);
  return (false);
}

bool	C::Utils::Intersection::IsPointInsideRectangle(const C::Geometry::Vector2 &a,
						       const C::Geometry::Vector2 &b,
						       const C::Geometry::Vector2 &c,
						       const C::Geometry::Vector2 &d,
						       const C::Geometry::Vector2 &p)
{
  if (C::Utils::Intersection::Test(a, b, p) ||
      C::Utils::Intersection::Test(b, c, p) ||
      C::Utils::Intersection::Test(c, d, p) ||
      C::Utils::Intersection::Test(d, a, p))
    return (true);
  return (false);
}

bool	C::Utils::Intersection::IsPointInsideRectangle(const C::Geometry::Vector2 &a,
						       const C::Geometry::Vector2 &b,
						       const C::Geometry::Vector2 &c,
						       const C::Geometry::Vector2 &d,
						       const C::Geometry::Point &p)
{
  if (C::Utils::Intersection::Test(a, b, p) ||
      C::Utils::Intersection::Test(b, c, p) ||
      C::Utils::Intersection::Test(c, d, p) ||
      C::Utils::Intersection::Test(d, a, p))
    return (true);
  return (false);
}
