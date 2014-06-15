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
  projPJ proj = pj_init_plus("+proj=sterea +lat_0=52.15616055555555 +lon_0=5.38763888888889 +k=0.9999079 +x_0=155000 +y_0=463000 +ellps=bessel +units=m +no_defs");
  C::Geometry::Point p = C::Geometry::Point(4.913029, 52.342404, 0, C::Helpers::ProjectionsHelper::WGS84);

  if (proj == NULL)
    std::cout << "Proj NULL" << std::endl;
  if (p.CRS == NULL)
    std::cout << "CRS NULL" << std::endl;
}

