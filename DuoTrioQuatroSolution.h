#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define PI 3.1415926535

int input_degree(void);
long double* input_coeffs(int, long double*);
void first_degree_equation(long double*);
void second_degree_equation(long double*, int);

typedef struct number
{
	long double real_part;
	long double imagine_part;

}NUMBER;

long double third_degree_equation(long double*, char, int);
void fourth_degree_equation(long double*);


void sixth_degree_equation(long double*);
void second_change_sixth_degree(long double*, int);
void third_change_sixth_degree(long double*, int);
void compl_root_finder(NUMBER, int, int);

void eighth_degree_equation(long double*);
void change_eighth_and_twelve_degree(long double*, int);
void second_degree_for_eighth_and_tw(long double*, int, NUMBER*);

void ninth_degree_equation(long double*);
void third_change_ninth_degree(long double*);

long double twelve_degree_equation(long double*);

