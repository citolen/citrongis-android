/*
 * Viewport.h
 *
 *  Created on: May 25, 2014
 *      Author: romain
 */

#ifndef VIEWPORT_H_
#define VIEWPORT_H_

#include	"Geometry/BoundingBox.h"

namespace C
{
  namespace System
  {
    class Viewport {      
      
    public:
      int			Width;
      int			Height;
      double			Resolution;
      C::Geometry::BoundingBox	Extent;
      
      /* Cplien Form*/
      Viewport();
      Viewport(const Viewport &);
      Viewport	&operator=(const Viewport &);
      virtual	~Viewport();

    };
  }
}
#endif /* VIEWPORT_H_ */
