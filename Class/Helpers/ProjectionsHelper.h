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
      //      static projPJ	WGS84 = pj_init_plus("+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs");
      //      static projPJ	EPSG3857 = pj_init_plus("+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +wktext  +no_defs");

      /* Coplien Form*/
      ProjectionsHelper	&operator=(const ProjectionsHelper &);
      virtual	~ProjectionsHelper();

    };
  }
}
#endif /* PROJECTIONSHELPER_H_ */
