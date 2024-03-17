#include "calculator.h"

void stack_init_op(stack_operators *stack) {
  stack->size = 0;
  for (int i = 0; i < MAX_STACK_SIZE; i++) {
    stack->buf[i] = 0;
  }
}

void stack_init_num(stack_numbers *stack) {
  stack->size = 0;
  for (int i = 0; i < MAX_STACK_SIZE; i++) {
    stack->buf[i] = 0;
  }
}

int stack_push_op(stack_operators *stack, const my_operator *new_ptr) {
  int result = 1;
  if (stack->size >= MAX_STACK_SIZE)
    result = 0;
  else {
    stack->buf[stack->size] = *new_ptr;
    stack->size += 1;
  }
  return result;
}

int stack_push_num(stack_numbers *stack, const double *new_ptr) {
  int result = 1;
  if (stack->size >= MAX_STACK_SIZE)
    result = 0;
  else {
    stack->buf[stack->size] = *new_ptr;
    stack->size += 1;
  }
  return result;
}

int stack_pop_op(stack_operators *stack, my_operator *new_ptr) {
  int result = 1;
  if (stack->size <= 0) {
    result = 0;
  } else {
    *new_ptr = stack->buf[stack->size - 1];
    stack->buf[stack->size - 1] = 0;
    stack->size -= 1;
  }
  return result;
}

int stack_pop_num(stack_numbers *stack, double *new_ptr) {
  int result = 1;
  if (stack->size <= 0) {
    result = 0;
  } else {
    *new_ptr = stack->buf[stack->size - 1];
    stack->buf[stack->size - 1] = 0;
    stack->size -= 1;
  }
  return result;
}

int stack_top_op(stack_operators *stack, my_operator *new_ptr) {
  int result = 0;
  if (stack->size > 0) {
    *new_ptr = stack->buf[stack->size - 1];
    result = 1;
  } else {
    *new_ptr = UNDEFINED;
  }
  return result;
}

int stack_top_num(stack_numbers *stack, double *new_ptr) {
  int result = 0;

  if (stack->size > 0) {
    *new_ptr = stack->buf[stack->size - 1];
    result = 1;
  }

  return result;
}