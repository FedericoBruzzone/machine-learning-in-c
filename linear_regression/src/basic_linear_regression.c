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

float generate_rand_float(void) 
{
    return (float)rand() / (float)RAND_MAX;
}

int main(void) 
{
    srand(time(0));
    float weight = generate_rand_float()*10.0f;
    float rate = 1e-1;
   
    printf("Mean absolute error = %f with weight = %f\n", 
            mean_absolute_error(TRAINING_SET_SIZE, training_set, weight), 
            weight);
    printf("Mean squared error = %f with weight = %f\n", 
            mean_squared_error(TRAINING_SET_SIZE, training_set, weight), 
            weight);

    printf("Derivative cost with quadratic_loss = %f with weight = %f\n", 
            derivative_cost_function(TRAINING_SET_SIZE, training_set, quadratic_loss, weight), 
            weight);
    
    printf("---------------------------------------------\n");

    for(size_t i = 0; i < 50; ++i) {
        float cost = mean_squared_error(TRAINING_SET_SIZE, training_set, weight);
        float derivative_cost = derivative_cost_function(TRAINING_SET_SIZE, training_set, quadratic_loss, weight);
        printf("Cost = %f, weight = %f\n", cost, weight);
        weight -= rate * derivative_cost;
    }
    
    printf("Weight = %f\n", weight);

    return 0;
}
