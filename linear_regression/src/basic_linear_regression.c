#include "basic_linear_regression.h" 

#define LOSS_FUNCTION_IMPLEMENTATION_
#include "loss.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 2
float x2_training_set[ROWS][COLS] = {
    {0.0f, 0.0f},
    {1.0f, 2.0f},
    {2.0f, 4.0f},
    {3.0f, 6.0f},
    {4.0f, 8.0f},
    {5.0f, 10.0f},
};
float square_training_set[ROWS][COLS] = {
    {0.0f, 0.0f},
    {1.0f, 1.0f},
    {2.0f, 4.0f},
    {3.0f, 9.0f},
    {4.0f, 16.0f},
    {5.0f, 25.0f},
};
/* #define TRAINING_SET_SIZE (sizeof(training_set) / sizeof(training_set[0])) */
float *training_set = (float *)square_training_set;

float generate_rand_float(void) 
{
    return (float)rand() / (float)RAND_MAX;
}

int main(void) 
{
    /* Matrix *m = make_matrix_from_array(ROWS, COLS, *x2_training_set); */
    Matrix *m = make_matrix_from_array(ROWS, COLS, training_set);
    print_matrix(m);

    srand(time(0));
    float weight = generate_rand_float()*10.0f;
    float rate = 1e-1;

    printf("Mean absolute error = %f with weight = %f\n", 
            mean_absolute_error(m, weight), 
            weight);
    printf("Mean squared error = %f with weight = %f\n", 
            mean_squared_error(m, weight), 
            weight);
    printf("Derivative cost with quadratic_loss = %f with weight = %f\n", 
            derivative_cost_function(m, quadratic_loss, weight), 
            weight);
    
    printf("---------------------------------------------\n");

    for(size_t i = 0; i < 1000; ++i) {
        float cost = mean_squared_error(m, weight);
        float derivative_cost = derivative_cost_function(m, quadratic_loss, weight);
        printf("Cost = %f, weight = %f\n", cost, weight);
        weight -= rate * derivative_cost;
    }
     
    printf("Weight = %f\n", weight);

    return 0;
}

