#include "basic_linear_regression.h" 

#define LOSS_FUNCTION_IMPLEMENTATION_
#include "loss.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 2
float training_set[ROWS][COLS] = {
    {0.0f, 0.0f},
    {1.0f, 2.0f},
    {2.0f, 4.0f},
    {3.0f, 6.0f},
    {4.0f, 8.0f},
};
#define TRAINING_SET_SIZE (sizeof(training_set) / sizeof(training_set[0]))


float cost_function(float weight, float (*loss)(float y_hat, float y)) 
{
    float cost = 0.0f;    
    for (size_t i = 0; i < TRAINING_SET_SIZE; ++i) {
        
    }

    return 0.0f;
}

float generate_rand_float(void) 
{
    return (float)rand() / (float)RAND_MAX;
}

int main(void) 
{
    srand(time(0));
    float weight = generate_rand_float()*10.0f;
    /* float rate = 1e-1; */
   
    printf("cost = %f\n", cost_function(weight, absolute_loss));
    printf("sizeof(training_set) = %lu", TRAINING_SET_SIZE);

    return 0;
}
