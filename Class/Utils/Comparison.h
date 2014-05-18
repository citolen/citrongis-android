/*
 * Comparison.h
 *
 *  Created on: May 18, 2014
 *      Author: romain
 */

#ifndef COMPARISON_H_
#define COMPARISON_H_

#include	<cmath>

namespace C
{
  namespace Utils
  {
    class Comparison {
    private:
      Comparison();
      Comparison(const Comparison &);
      
    public:      
      /* Coplien Form*/
      Comparison	&operator=(const Comparison &);
      virtual	~Comparison();

      /*Others Functions*/
      static bool	Equals(double, double);
    };
  }
}
#endif /* COMPARISON_H_ */
