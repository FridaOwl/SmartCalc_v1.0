#ifndef SMARTCALC_V1_0_BACKEND
#define SMARTCALC_V1_0_BACKEND

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 256

typedef enum {
  PLUS = 1,
  SUB,
  MUL,
  DIV,
  POW,
  MOD,
  LEFT_BRACES,
  RIGHT_BRACES,
  SIN,
  COS,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG,
  UNDEFINED
} my_operator;

// Приоритеты операций
typedef enum priority {
  left_bracket_priority,
  sum_priority,
  sub_priority = 1,
  mul_priority,
  mod_priority = 2,
  div_priority = 2,
  sqrt_priority,
  pow_priority = 3,
  sincos_priority,
  unar_sum_priority,
  unar_sub_priority = 5,
  right_bracket_priority,
} priority;

typedef struct {
  const char *str;
  my_operator op;
} str_op;

typedef struct {
  my_operator buf[MAX_STACK_SIZE];
  int size;
} stack_operators;

typedef struct {
  double buf[MAX_STACK_SIZE];
  int size;
} stack_numbers;

// stack
void stack_init_op(stack_operators *stack);
void stack_init_num(stack_numbers *stack);
int stack_push_op(stack_operators *stack, const my_operator *new_ptr);
int stack_push_num(stack_numbers *stack, const double *new_ptr);
int stack_pop_op(stack_operators *stack, my_operator *new_ptr);
int stack_pop_num(stack_numbers *stack, double *new_ptr);
int stack_top_op(stack_operators *stack, my_operator *new_ptr);
int stack_top_num(stack_numbers *stack, double *new_ptr);

// calculator
int skip_numbers(char *input_string, int index, int size);
double add(stack_numbers *stack_num, double result);
double plus(stack_numbers *stack_num, double result);
double sub(stack_numbers *stack_num, stack_operators *stack_op, double result);
double mul(stack_numbers *stack_num, double result);
double division(stack_numbers *stack_num, double result);
double exponentiation(stack_numbers *stack_num, double result);
double sinus(stack_numbers *stack_num, double result);
double cosinus(stack_numbers *stack_num, double result);
double tangens(stack_numbers *stack_num, double result);
double cotan(stack_numbers *stack_num, double result);
double arcsin(stack_numbers *stack_num, double result);
double arccos(stack_numbers *stack_num, double result);
double square(stack_numbers *stack_num, double result);
double natural_logarithm(stack_numbers *stack_num, double result);
double decimal_logarithm(stack_numbers *stack_num, double result);
double remainder_of_the_div(stack_numbers *stack_num, double result);
double calculator(stack_numbers *stack_num, stack_operators *stack_op);

// parser
my_operator get_operator(const char *c, int *index);
int action_priority(my_operator op);
void process_number(char *expr, int *i, stack_numbers *stack_num,
                    stack_operators *stack_op);
double parsing(char *expr, stack_numbers *stack_num, stack_operators *stack_op,
               double x);
void handleOperator(char *c, int counter_op, stack_numbers *stack_num,
                    stack_operators *stack_op, int *i, int *braces);
void handleRightBraces(stack_numbers *stack_num, stack_operators *stack_op,
                       int *braces);
void handleNonBracesOperator(my_operator temp, my_operator op_down,
                             stack_numbers *stack_num,
                             stack_operators *stack_op);
void processRemainingOperations(stack_numbers *stack_num,
                                stack_operators *stack_op);
double getResult(stack_numbers *stack_num);

#endif  // SMARTCALC_V1_0_BACKEND
