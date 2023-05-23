#ifndef LOSS_
#define LOSS_ 

#include <stdlib.h>
#include <math.h>

float absolute_loss(float y1, float y2);

#endif // LOSS_ 

#ifndef LOSS_IMPLEMENTATION_
#define LOSS_IMPLEMENTATION_

float absolute_loss(float y1, float y2) {
    return fabs(y1 - y2);
}

#endif // LOSS_IMPLEMENTATION_

