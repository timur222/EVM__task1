#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
double NormSol(double * Matrix, double* InvMatrix, int n);
int Gauss(double* Matrix, double* InvMatrix, int* swap, int n);
int Input(double *A,char *file_name,int n, double* Norm);
double generate(int k, int n, int i, int j);
void POut(double *Matrix,int l,int n,int m);
#endif // FUNC_H_INCLUDED

