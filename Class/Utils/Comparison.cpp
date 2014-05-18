/*
 * Comparison.cpp
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#include	"Comparison.h"

C::Utils::Comparison::Comparison()
{
}

C::Utils::Comparison::Comparison(const Comparison &other)
{
}

C::Utils::Comparison	&C::Utils::Comparison::operator=(const Comparison &other)
{
}

C::Utils::Comparison::~Comparison()
{
}

bool			C::Utils::Comparison::Equals(double a, double b)
{
  return (std::abs(a - b) < kEpsilon);
}
