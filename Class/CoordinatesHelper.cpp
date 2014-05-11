/*
 * Point.h
 *
 *  Created on: May 11, 2014
 *      Author: romain
 */

#include	"CoordinatesHelper.h"


C::Helpers::CoordinatesHelper::CoordinatesHelper()
{

}

C::Helpers::CoordinatesHelper::CoordinatesHelper(const CoordinatesHelper &other)
{

}

C::Helpers::CoordinatesHelper	&C::Helpers::CoordinatesHelper::operator=(const CoordinatesHelper &other)
{
  return (*this);
}

C::Helpers::CoordinatesHelper::~CoordinatesHelper()
{

}

C::Geometry::Point	C::Helpers::CoordinatesHelper::TransformTo(const C::Geometry::Point pt, const projPJ CRS)
{
  double	tmpX = pt.X;
  double	tmpY = pt.Y;
  double	tmpZ = pt.Z;

  if (pj_is_latlong(pt.CRS))
    {
      tmpX *= DEG_TO_RAD;
      tmpY *= DEG_TO_RAD;
      tmpZ *= DEG_TO_RAD;
    }
  if (pj_transform(pt.CRS, CRS, 1, 1, &tmpX, &tmpY, &tmpZ))
    {
      // Exception FAILURE ??
      exit(EXIT_FAILURE);
    } 
  if (pj_is_latlong(CRS))
    {
      tmpX *= RAD_TO_DEG;
      tmpY *= RAD_TO_DEG;
      tmpZ *= RAD_TO_DEG;
    }
  return (C::Geometry::Point(tmpX, tmpY, tmpZ, CRS));
}

C::Geometry::Point C::Helpers::CoordinatesHelper::TransformTo(const C::Geometry::Point pt, const std::string proj)
{
  double	tmpX = pt.X;
  double	tmpY = pt.Y;
  double	tmpZ = pt.Z;
  projPJ	target = pj_init_plus(proj.c_str());


  if (!target)
    {
      // Exception FAILURE ??
      exit(EXIT_FAILURE);
    }
  if (pj_is_latlong(pt.CRS))
    {
      tmpX *= DEG_TO_RAD;
      tmpY *= DEG_TO_RAD;
      tmpZ *= DEG_TO_RAD;
    }
  if (pj_transform(pt.CRS, target, 1, 1, &tmpX, &tmpY, &tmpZ))
    {
      // Exception FAILURE ??
      exit(EXIT_FAILURE);
    } 
  if (pj_is_latlong(target))
    {
      tmpX *= RAD_TO_DEG;
      tmpY *= RAD_TO_DEG;
      tmpZ *= RAD_TO_DEG;
    }
  return (C::Geometry::Point(tmpX, tmpY, tmpZ, target));
}
