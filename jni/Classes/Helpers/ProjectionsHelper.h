/*
 * ProjectionsHelper.h
 *
 *  Created on: May 21, 2014
 *      Author: romain
 */

#ifndef PROJECTIONSHELPER_H_
#define PROJECTIONSHELPER_H_

#include	<proj_api.h>

namespace C
{
  namespace Helpers
  {
    class ProjectionsHelper {
    private:
      ProjectionsHelper();
      ProjectionsHelper(const ProjectionsHelper &);
      
    public:
      static projPJ	WGS84;
      static projPJ	EPSG3857;

      /* Coplien Form*/
      ProjectionsHelper	&operator=(const ProjectionsHelper &);
      virtual	~ProjectionsHelper();

    };
  }
}
#endif /* PROJECTIONSHELPER_H_ */
