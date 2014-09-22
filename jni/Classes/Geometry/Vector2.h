/*
 * Vector2.h
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_

#include	<cmath>
#include	<sstream>
#include	<string>
#include	"Utils/Comparison.h"

namespace C
{
  namespace Geometry
  {
    class Vector2 {

    public:
      double X;
      double Y;

      /* Coplien Form*/
      Vector2();
      Vector2(double, double);
      Vector2(const Vector2 &);
      Vector2	&operator=(const Vector2 &);
      virtual	~Vector2();

      /* Others Functions*/
      bool		Equals(const Vector2 &) const;
      double		Distance(const Vector2 &) const;
      double		DotProduct(const Vector2 &) const;
      const std::string	toString() const;
      static bool	Equals(const Vector2 &, const Vector2 &);    
      static double	Distance(const Vector2 &, const Vector2 &);
      static double	DotProduct(const Vector2 &, const Vector2 &);
    };
  }
}
#endif /* VECTOR2_H_ */
