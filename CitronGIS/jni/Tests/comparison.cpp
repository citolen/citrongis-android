#define		BOOST_TEST_DYN_LINK
#include	<boost/test/unit_test.hpp>
#include	<iostream>
#include	"../Headers/Utils/Comparison.h"

/*
** All the time true in BOOST_CHECK !!!
 */

BOOST_AUTO_TEST_CASE(Comparison)
{
  std::cout << "===================== Test Comparison ======================" << std::endl;
  double a = 1.0 / 6.0;
  bool result = true;
  result = result && C::Utils::Comparison::Equals(a * 6.0, 1.0);
  BOOST_CHECK(result);
}
