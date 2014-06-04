#define		BOOST_TEST_DYN_LINK
#define		BOOST_TEST_MODULE Test-CitronGIS
#include	<boost/test/unit_test.hpp>
#include	<iostream>
#include	"../Headers/Geometry/Vector2.h"
#include	"../Headers/Geometry/Vector3.h"


/*
** All the time true in BOOST_CHECK !!!
 */
 
BOOST_AUTO_TEST_CASE(Vector2)
{
  C::Geometry::Vector2 a = C::Geometry::Vector2(5, 8);
  C::Geometry::Vector2 b = C::Geometry::Vector2(42, 10);
 
  std::cout << "===================== Test Vector2 ======================" << std::endl;

  std::cout << "                      Start Equals" << std::endl;
  BOOST_CHECK(!(a.Equals(b)));
  BOOST_CHECK(a.Equals(b));
  std::cout << "                      End Equals" << std::endl;
  
  std::cout << "                      Start Distance" << std::endl;
  double distance = a.Distance(b);
  BOOST_CHECK(C::Utils::Comparison::Equals(distance, 37.054014627297809172542799375637));
  std::cout << "                      End Distance" << std::endl;
  
  std::cout << "                      Start DotProduct" << std::endl;
  double dot = a.DotProduct(b);
  BOOST_CHECK(C::Utils::Comparison::Equals(dot, 290));
  std::cout << "                      End DotProduct" << std::endl;
}

BOOST_AUTO_TEST_CASE(Vector3)
{
  C::Geometry::Vector3 a = C::Geometry::Vector3(5, 8, 9);
  C::Geometry::Vector3 b = C::Geometry::Vector3(42, 10, 30);
 
  std::cout << "===================== Test Vector3 ======================" << std::endl;

  std::cout << "                      Start Equals" << std::endl;
  BOOST_CHECK(!(a.Equals(b)));
  BOOST_CHECK(a.Equals(b));
  std::cout << "                      End Equals" << std::endl;
  
  std::cout << "                      Start Distance" << std::endl;
  double distance = a.Distance(b);
  BOOST_CHECK(C::Utils::Comparison::Equals(distance, 42.591078878093708134734694132318));
  std::cout << "                      End Distance" << std::endl;
  
  std::cout << "                      Start DotProduct" << std::endl;
  double dot = a.DotProduct(b);
  BOOST_CHECK(C::Utils::Comparison::Equals(dot, 560));
  std::cout << "                      End DotProduct" << std::endl;
}
