/*
 * Point.h
 *
 *  Created on: May 8, 2014
 *      Author: romain
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <string>
#include <proj_api.h>

namespace C
{
  namespace Geometry
  {
    class Point {      
      
    public:
      double	X;
      double	Y;
      double	Z;
      projPJ	CRS;
      
      /* Cplien Form*/
      Point();
      Point(const Point &);
      Point	&operator=(const Point &);
      virtual	~Point();

      Point(double X, double Y, double Z, std::string proj);
      void	ToString();
    };
  }
}
#endif /* POINT_H_ */
