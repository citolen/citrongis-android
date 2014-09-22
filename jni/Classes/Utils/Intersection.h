/*
 * Intersection.h
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include	"Geometry/Vector2.h"
#include	"Geometry/Point.h"

namespace C
{
  namespace Utils
  {
    class Intersection {

    private:
      Intersection();
      Intersection(const Intersection &);
      
    public:
      /* Coplien Form*/
      Intersection	&operator=(const Intersection &);
      virtual		~Intersection();

      /*Others Functions*/
      static bool		Test(const C::Geometry::Vector2 &,
				     const C::Geometry::Vector2 &,
				     const C::Geometry::Vector2 &);
      static bool		Test(const C::Geometry::Vector2 &,
				     const C::Geometry::Vector2 &,
				     const C::Geometry::Point &);
      static bool		IsPointInsideRectangle(const C::Geometry::Vector2 &,
						       const C::Geometry::Vector2 &,
						       const C::Geometry::Vector2 &,
						       const C::Geometry::Vector2 &,
						       const C::Geometry::Vector2 &);
      static bool		IsPointInsideRectangle(const C::Geometry::Vector2 &,
						       const C::Geometry::Vector2 &,
						       const C::Geometry::Vector2 &,
						       const C::Geometry::Vector2 &,
						       const C::Geometry::Point &);
    };
  }
}
#endif /* INTERSECTION_H_ */
