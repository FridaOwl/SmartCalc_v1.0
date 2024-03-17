#include "calculator.h"

int skip_numbers(char *input_string, int index, int size) {
  while (index < size &&
         (isdigit(input_string[index]) || input_string[index] == '.')) {
    index++;
  }
  return index;
}

double add(stack_numbers *stack_num, double result) {
  double right_number = 0;
  double left_number = 0;
  if (!stack_pop_num(stack_num, &right_number)) return 0;
  if (!stack_pop_num(stack_num, &left_number)) {
    result = right_number;
    stack_push_num(stack_num, &result);
  } else {
    result = right_number + left_number;
    stack_push_num(stack_num, &result);
  }
  return result;
}

double plus(stack_numbers *stack_num, double result) {
  double right_number = 0;
  double left_number = 0;
  if (!stack_pop_num(stack_num, &right_number)) return 0;
  if (!stack_pop_num(stack_num, &left_number)) {
    result = right_number;
    stack_push_num(stack_num, &result);
  } else {
    result = right_number + left_number;
    stack_push_num(stack_num, &result);
  }
  return result;
}

double sub(stack_numbers *stack_num, stack_operators *stack_op, double result) {
  double right_number = 0;
  double left_number = 0;
  my_operator down;
  stack_top_op(stack_op, &down);
  if (!stack_pop_num(stack_num, &right_number)) return 0;
  if (!stack_pop_num(stack_num, &left_number)) {
    result = -right_number;
    stack_push_num(stack_num, &result);
  } else {
    result = left_number - right_number;
    stack_push_num(stack_num, &result);
  }
  return result;
}

double mul(stack_numbers *stack_num, double result) {
  double right_number = 0;
  double left_number = 0;
  stack_pop_num(stack_num, &right_number);
  stack_pop_num(stack_num, &left_number);
  result = right_number * left_number;
  stack_push_num(stack_num, &result);
  return result;
}

double division(stack_numbers *stack_num, double result) {
  double right_number = 0;
  double left_number = 0;
  stack_pop_num(stack_num, &right_number);
  stack_pop_num(stack_num, &left_number);
  result = left_number / right_number;
  stack_push_num(stack_num, &result);
  return result;
}

double exponentiation(stack_numbers *stack_num, double result) {
  double right_number = 0;
  double left_number = 0;
  stack_pop_num(stack_num, &right_number);
  stack_pop_num(stack_num, &left_number);
  result = pow(left_number, right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double sinus(stack_numbers *stack_num, double result) {
  double right_number = 0;
  stack_pop_num(stack_num, &right_number);
  result = sin(right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double cosinus(stack_numbers *stack_num, double result) {
  double right_number = 0;
  stack_pop_num(stack_num, &right_number);
  result = cos(right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double tangens(stack_numbers *stack_num, double result) {
  double right_number = 0;
  stack_pop_num(stack_num, &right_number);
  result = tan(right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double cotan(stack_numbers *stack_num, double result) {
  double right_number = 0;
  stack_pop_num(stack_num, &right_number);
  result = atan(right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double arcsin(stack_numbers *stack_num, double result) {
  double right_number = 0;
  stack_pop_num(stack_num, &right_number);
  result = asin(right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double arccos(stack_numbers *stack_num, double result) {
  double right_number = 0;
  stack_pop_num(stack_num, &right_number);
  result = acos(right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double square(stack_numbers *stack_num, double result) {
  double right_number = 0;
  stack_pop_num(stack_num, &right_number);
  result = sqrt(right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double natural_logarithm(stack_numbers *stack_num, double result) {
  double right_number = 0;
  stack_pop_num(stack_num, &right_number);
  result = log(right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double decimal_logarithm(stack_numbers *stack_num, double result) {
  double right_number = 0;
  stack_pop_num(stack_num, &right_number);
  result = log10(right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double remainder_of_the_div(stack_numbers *stack_num, double result) {
  double right_number = 0;
  double left_number = 0;
  stack_pop_num(stack_num, &right_number);
  stack_pop_num(stack_num, &left_number);
  result = fmod(left_number, right_number);
  stack_push_num(stack_num, &result);
  return result;
}

double calculator(stack_numbers *stack_num, stack_operators *stack_op) {
  my_operator ptr = UNDEFINED;
  stack_top_op(stack_op, &ptr);
  if (ptr != UNDEFINED && ptr != LEFT_BRACES && ptr != RIGHT_BRACES) {
    if (!stack_pop_op(stack_op, &ptr)) return 0;
    my_operator current = ptr;
    double result = 0;
    if (current == PLUS)
      result = add(stack_num, result);
    else if (current == SUB)
      result = sub(stack_num, stack_op, result);
    else if (current == MUL)
      result = mul(stack_num, result);
    else if (current == DIV)
      result = division(stack_num, result);
    else if (current == POW)
      result = exponentiation(stack_num, result);
    else if (current == SIN)
      result = sinus(stack_num, result);
    else if (current == COS)
      result = cosinus(stack_num, result);
    else if (current == TAN)
      result = tangens(stack_num, result);
    else if (current == ACOS)
      result = arccos(stack_num, result);
    else if (current == ASIN)
      result = arcsin(stack_num, result);
    else if (current == ATAN)
      result = cotan(stack_num, result);
    else if (current == SQRT)
      result = square(stack_num, result);
    else if (current == LN)
      result = natural_logarithm(stack_num, result);
    else if (current == LOG)
      result = decimal_logarithm(stack_num, result);
    else if (current == MOD)
      result = remainder_of_the_div(stack_num, result);
    else if (current == UNDEFINED)
      result = 0;
  }
  double result = 0;
  stack_top_num(stack_num, &result);
  return result;
}