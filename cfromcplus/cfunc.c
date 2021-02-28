//
// Created by peter on 2/28/2021.
//
#include <stdio.h>
#include "cfunc.h"

double cfunc (double x)
{
    double result;
    result = x*x;
    printf("c from cplus(computing result = %g)\n", result);
    return result;
}
