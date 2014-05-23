/*
 * Vector3.h
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include	<cmath>
#include	<sstream>
#include	<string>
#include	"Comparison.h"
namespace C
{
  namespace Geometry
  {
    class Vector3 {

    public:
      double X;
      double Y;
      double Z;

      /* Coplien Form*/
      Vector3();
      Vector3(double, double, double);
      Vector3(const Vector3 &);
      Vector3	&operator=(const Vector3 &);
      virtual	~Vector3();

      /* Others Functions*/
      bool		Equals(const Vector3 &) const;
      double		Distance(const Vector3 &) const;
      double		DotProduct(const Vector3 &) const;
      const std::string	toString() const;
      static bool	Equals(const Vector3 &, const Vector3 &);    
      static double	Distance(const Vector3 &, const Vector3 &);
      static double	DotProduct(const Vector3 &, const Vector3 &);
    };
  }
}
#endif /* VECTOR3_H_ */
