/*
 * ProjectionsHelper.h
 *
 *  Created on: May 21, 2014
 *      Author: romain
 */

#include	"ProjectionsHelper.h"

projPJ	C::Helpers::ProjectionsHelper::WGS84 = pj_init_plus("+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs");
projPJ	C::Helpers::ProjectionsHelper::EPSG3857 = pj_init_plus("+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +wktext  +no_defs");

C::Helpers::ProjectionsHelper::ProjectionsHelper()
{

}

C::Helpers::ProjectionsHelper::ProjectionsHelper(const ProjectionsHelper &other)
{

}

C::Helpers::ProjectionsHelper &C::Helpers::ProjectionsHelper::operator=(const ProjectionsHelper &other)
{
  return (*this);
}

C::Helpers::ProjectionsHelper::~ProjectionsHelper()
{

}
