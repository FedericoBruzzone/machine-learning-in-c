#ifndef LOSS_FUNCTION_
#define LOSS_ 

#include <math.h>

// ===== Regression losses =====
float absolute_loss(float y_hat, float y);
float quadratic_loss(float y_hat, float y);

#endif // LOSS_ 

#ifdef LOSS_FUNCTION_IMPLEMENTATION_

// ===== Regression losses =====
float absolute_loss(float y_hat, float y) {
    return fabs(y_hat - y);
}

float quadratic_loss(float y_hat, float y) {
    return pow(y_hat - y, 2);
}

// ===== Classification losses =====
// TODO

#endif // LOSS_IMPLEMENTATION_

