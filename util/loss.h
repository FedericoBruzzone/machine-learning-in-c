#ifndef LOSS_FUNCTION_
#define LOSS_ 

#include "matrix.h"

#include <math.h>
#include <stdlib.h>


typedef float (*loss_function)(float, float);

/**
 * The function derivative_loss calculates the derivative of the loss function with respect to the predicted value y_hat.
 *
 * @param y_hat: the predicted value
 * @param y: the true value
 * @param loss: the loss function
 * @return the derivative of the loss function with respect to y_hat
 */
float derivative_loss(float y_hat, float y, loss_function loss);

/**
 * The function derivative_cost_function calculates the derivative of the cost function with respect to the weight.
 *
 * @param m: the training set
 * @param loss: the loss function
 * @param weight: the weight
 * @return the derivative of the cost function with respect to the weight
 */
float derivative_cost_function(Matrix *m, loss_function loss, float weight);

// ============================== REGRESSION LOSSES ==============================
/**
 * The function absolute_loss calculates the absolute loss between the predicted value y_hat and the true value y.
 *
 * @param y_hat: the predicted value
 * @param y: the true value
 * @return the absolute loss between y_hat and y
 */
float absolute_loss(float y_hat, float y);

/**
 * The function quadratic_loss calculates the quadratic loss between the predicted value y_hat and the true value y.
 *
 * @param y_hat: the predicted value
 * @param y: the true value
 * @return the quadratic loss between y_hat and y
 */
float quadratic_loss(float y_hat, float y);

// TODO: Huber Loss
// TODO: Log-Cosh Loss
// TODO: Quantile Loss

// ============================== CLASSIFICATION LOSSES ==============================
// TODO: Binary Cross-Entropy Loss / Log Loss
// TODO: Hinge Loss


// ============================= COST FUNCTIONS =============================
/*
 * The function cost_function calculates the cost function of the training set.
 *
 * @param m: the training set
 * @param loss: the loss function
 * @param weight: the weight
 * @return the cost function of the training set
 */
float cost_function(Matrix *m, loss_function loss, float weight);

/**
 * The function mean_squared_error calculates the mean squared error of the training set.
 *
 * @param m: the training set
 * @param weight: the weight
 * @return the mean squared error of the training set
 */
float mean_squared_error(Matrix *m, float weight);

/**
 * The function mean_absolute_error calculates the mean absolute error of the training set.
 *
 * @param m: the training set
 * @param weight: the weight
 * @return the mean absolute error of the training set
 */
float mean_absolute_error(Matrix *m, float weight);

#endif // LOSS_ 





#ifdef LOSS_FUNCTION_IMPLEMENTATION_

float derivative_loss(float y_hat, float y, loss_function loss)
{
    float h = 1e-6;
    return (loss(y_hat + h, y) - loss(y_hat - h, y)) / (2*h);
}

float derivative_cost_function(Matrix *m, loss_function loss, float weight) 
{
    float derivative_cost = 0.0f;    
    for (size_t i = 0; i < m->rows; ++i) {
        float y_hat = weight * m->data[i][0];
        float y = m->data[i][1];
        derivative_cost += derivative_loss(y_hat, y, loss);
    }
    derivative_cost /= m->rows;
    return derivative_cost;
}

// ============================== REGRESSION LOSSES ==============================
float absolute_loss(float y_hat, float y) 
{
    return fabs(y_hat - y);
}

float quadratic_loss(float y_hat, float y) 
{
    return pow(y_hat - y, 2);
}

// ============================= CLASSIFICATION LOSSES =============================
// TODO

// ============================= COST FUNCTIONS =============================
float cost_function(Matrix *m, loss_function loss, float weight) 
{
    float cost = 0.0f;    
    for (size_t i = 0; i < m->rows; ++i) {
        float y_hat = weight * m->data[i][0] + bias;
        float y = m->data[i][1];
        cost += loss(y_hat, y); 
    }
    cost /= m->rows;
    return cost;
}

float mean_squared_error(Matrix *m, float weight) 
{
    return cost_function(m, quadratic_loss, weight);
}

float mean_absolute_error(Matrix *m, float weight) 
{
    return cost_function(m, absolute_loss, weight);
}

#endif // LOSS_IMPLEMENTATION_

