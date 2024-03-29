/*
 * CoordinatesHelper.h
 *
 *  Created on: May 11, 2014
 *      Author: romain
 */

#ifndef COORDINATESHELPER_H_
#define COORDINATESHELPER_H_

#include	"Geometry/Point.h"
#include	<proj_api.h>
#include	<string>

namespace C
{
  namespace Helpers
  {
    class CoordinatesHelper {      
    private:
      CoordinatesHelper();
      CoordinatesHelper(const CoordinatesHelper &);
      
    public:
      
      /* Coplien Form*/
      CoordinatesHelper	&operator=(const CoordinatesHelper &);
      virtual	~CoordinatesHelper();

      static C::Geometry::Point	TransformTo(const C::Geometry::Point &pt, const projPJ &CRS);
      static C::Geometry::Point	TransformTo(const C::Geometry::Point &pt, const std::string &proj);
    };
  }
}
#endif /* COORDINATESHELPER_H_ */
