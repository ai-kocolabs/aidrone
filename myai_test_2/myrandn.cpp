#include "myrandn.h"

double randn(void) {

  double u, v, r, c;

  do {
    u =  ((double) rand() / RAND_MAX) * 2 - 1; // -1.0 ~ 1.0 까지의 값
    v =  ((double) rand() / RAND_MAX) * 2 - 1; // -1.0 ~ 1.0 까지의 값
  
    r = u * u + v * v;
  } while (r == 0 || r >= 1);
  
  c = sqrt( (-2 * log(r)) / r );

  return u * c;

}
