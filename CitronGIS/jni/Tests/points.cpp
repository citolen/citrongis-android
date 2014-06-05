#define		BOOST_TEST_DYN_LINK
#include	<boost/test/unit_test.hpp>
#include	<iostream>
#include	"../Headers/Geometry/Point.h"
#include	"../Headers/Helpers/ProjectionsHelper.h"

/*
** All the time true in BOOST_CHECK !!!
 */

BOOST_AUTO_TEST_CASE(Points)
{
  std::cout << "Proj4 Version : " << pj_get_release()  << std::endl << std::endl;

  std::cout << "===================== Test Points ======================" << std::endl;
  projPJ proj = pj_init_plus("PROJCS[\"Amersfoort / RD New\", GEOGCS[\"Amersfoort\", DATUM[\"Amersfoort\", SPHEROID[\"Bessel 1841\",6377397.155,299.1528128, AUTHORITY[\"EPSG\",\"7004\"]], AUTHORITY[\"EPSG\",\"6289\"]], PRIMEM[\"Greenwich\",0, AUTHORITY[\"EPSG\",\"8901\"]], UNIT[\"degree\",0.01745329251994328, AUTHORITY[\"EPSG\",\"9122\"]], AUTHORITY[\"EPSG\",\"4289\"]], UNIT[\"metre\",1, AUTHORITY[\"EPSG\",\"9001\"]], PROJECTION[\"Oblique_Stereographic\"], PARAMETER[\"latitude_of_origin\",52.15616055555555], PARAMETER[\"central_meridian\",5.38763888888889], PARAMETER[\"scale_factor\",0.9999079], PARAMETER[\"false_easting\",155000], PARAMETER[\"false_northing\",463000], AUTHORITY[\"EPSG\",\"28992\"], AXIS[\"X\",EAST], AXIS[\"Y\",NORTH]]");
  C::Geometry::Point p = C::Geometry::Point(4.913029, 52.342404, 0, C::Helpers::ProjectionsHelper::WGS84);

  if (proj == NULL)
    std::cout << "Proj NULL" << std::endl;
  if (p.CRS == NULL)
    std::cout << "CRS NULL" << std::endl;
}

