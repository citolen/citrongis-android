/*
 * Point.cpp
 *
 *  Created on: May 8, 2014
 *      Author: romain
 */

#include "Viewport.h"

C::System::Viewport::Viewport()
{
  this->Width = 0;
  this->Height = 0;
  this->Resolution = 0;
  this->Extent = C::Geometry::BoundingBox();
}

C::System::Viewport::Viewport(const Viewport &other)
{
  this->Width = other.Width;
  this->Height = other.Height;
  this->Resolution = other.Resolution;
  this->Extent = other.Extent;
}

C::System::Viewport	&C::System::Viewport::operator=(const Viewport &other)
{
  if (this != &other)
    {
      this->Width = other.Width;
      this->Height = other.Height;
      this->Resolution = other.Resolution;
      this->Extent = other.Extent;
    }
  return (*this);
}

C::System::Viewport::~Viewport()
{

}
