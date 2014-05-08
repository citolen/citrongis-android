/*
 * Point.h
 *
 *  Created on: May 8, 2014
 *      Author: romain
 */

#ifndef POINT_H_
#define POINT_H_

namespace C
{
  namespace Geometry
  {
    class Point {      
      
    public:
      double	X;
      double	Y;
      double	Z;
      
      /*CRS -> reference sur la projection*/
      Point();
      virtual ~Point();
    };
  }
}
#endif /* POINT_H_ */
