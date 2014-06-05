#define		BOOST_TEST_DYN_LINK
#include	<boost/test/unit_test.hpp>
#include	<iostream>
#include	"../Headers/Geometry/BoundingBox.h"
#include	"../Headers/Geometry/Vector2.h"

BOOST_AUTO_TEST_CASE(BoundingBox)
{
  C::Geometry::BoundingBox a = C::Geometry::BoundingBox(C::Geometry::Vector2(0, 0),
							C::Geometry::Vector2(0, 10),
							C::Geometry::Vector2(10, 10),
							C::Geometry::Vector2(10, 0));

  C::Geometry::BoundingBox b = C::Geometry::BoundingBox(C::Geometry::Vector2(11, 11),
							C::Geometry::Vector2(11, 21),
							C::Geometry::Vector2(11, 21),
							C::Geometry::Vector2(21, 11));

  C::Geometry::BoundingBox c = C::Geometry::BoundingBox(C::Geometry::Vector2(2, 3),
							C::Geometry::Vector2(2, 7),
							C::Geometry::Vector2(15, 7),
							C::Geometry::Vector2(15, 3));

  std::cout << "===================== Test BoudingBox  ======================" << std::endl;
  
  std::cout << "                      Start Equals" << std::endl;
  BOOST_CHECK(!(a.Equals(b)));
  //BOOST_CHECK(a.Equals(b));
  std::cout << "                      End Equals" << std::endl;

  std::cout << "                      Start Center" << std::endl;
  C::Geometry::Vector2	center = C::Geometry::Vector2(5, 5);
  BOOST_CHECK(a.Center().Equals(center));
  std::cout << "                      End Center" << std::endl;

  std::cout << "                      Start Intersection" << std::endl;
  BOOST_CHECK(!(a.Intersect(b)));
  BOOST_CHECK(a.Intersect(c));
  std::cout << "                      End Intersection" << std::endl;
}
