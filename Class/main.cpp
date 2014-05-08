#include <iostream>
#include <proj_api.h>

using namespace std;

int main()
{
  double x = 138494.92605;
  double y = 467792.640021;

  char *srid28992 = "+proj=sterea +lat_0=52.15616055555555 +lon_0=5.38763888888889 +k=0.9999079 +x_0=155000 +y_0=463000 +ellps=bessel +towgs84=565.04,49.91,465.84,-1.9848,1.7439,-9.0587,4.0772 +units=m +no_defs";
  char *srid4326 = "+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs";

  projPJ source = pj_init_plus(srid28992);
  projPJ target = pj_init_plus(srid4326);

  if(source==NULL || target==NULL)
    return false;

  //  x *= DEG_TO_RAD;
  //  y *= DEG_TO_RAD;

  int success = pj_transform(source, target, 1, 1, &x, &y, NULL );

  x *= RAD_TO_DEG;
  y *= RAD_TO_DEG;

  cout << success << endl << x << endl << y << endl;
}
