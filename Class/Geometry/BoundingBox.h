/*
 * BoundingBox.h
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_

#include	"Vector2.h"
#include	<string>
#include	<sstream>

namespace C
{
  namespace Geometry
  {
    class BoundingBox {
      
    public:
      Vector2	topLeft;
      Vector2	topRight;
      Vector2	bottomLeft;
      Vector2	bottomRight;

      /* Cplien Form*/
      BoundingBox();
      BoundingBox(const Vector2 &, const Vector2 &, const Vector2 &, const Vector2 &);
      BoundingBox(const BoundingBox &);
      BoundingBox	&operator=(const BoundingBox &);
      virtual	~BoundingBox();

      /* Others Functions*/
      const std::string	toString() const;
      bool		Equals(const BoundingBox &) const;

      /*ToDo*/
      // Center
      // Intersect
    };
  }
}
#endif /* BOUDINGBOX_H_ */
