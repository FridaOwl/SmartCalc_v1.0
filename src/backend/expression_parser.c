#include "calculator.h"

my_operator get_operator(const char *c, int *index) {
  static const str_op operators_strings[] = {
      {"+", PLUS},         {"-", SUB},       {"*", MUL},
      {"/", DIV},          {"÷", DIV},       {"%", MOD},
      {"mod", MOD},        {"^", POW},       {"(", LEFT_BRACES},
      {")", RIGHT_BRACES}, {"sin", SIN},     {"cos", COS},
      {"tan", TAN},        {"acos", ACOS},   {"asin", ASIN},
      {"atan", ATAN},      {"sqrt", SQRT},   {"ln", LN},
      {"log", LOG},        {NULL, UNDEFINED}};

  for (int i = 0; operators_strings[i].str; i++) {
    const char *op_str = operators_strings[i].str;
    if (strncmp(op_str, c, strlen(op_str)) == 0) {
      *index = strlen(op_str) - 1;
      return operators_strings[i].op;
    }
  }

  return UNDEFINED;
}

int action_priority(my_operator op) {
  switch (op) {
    case PLUS:
      return sum_priority;
    case SUB:
      return sub_priority;
    case MUL:
      return mul_priority;
    case DIV:
      return div_priority;
    case MOD:
      return mod_priority;
    case POW:
      return pow_priority;
    case SQRT:
      return sqrt_priority;
    case SIN:
      return sincos_priority;
    case COS:
      return sincos_priority;
    case TAN:
      return sincos_priority;
    case ACOS:
      return sincos_priority;
    case ASIN:
      return sincos_priority;
    case ATAN:
      return sincos_priority;
    case LN:
      return sincos_priority;
    case LOG:
      return sincos_priority;
    default:
      return left_bracket_priority;
  }
}

void process_number(char *expr, int *i, stack_numbers *stack_num,
                    stack_operators *stack_op) {
  char *current_pos = &expr[*i];
  double num = atof(current_pos);
  stack_push_num(stack_num, &num);
  if (expr[*i - 2] == '(' && expr[*i - 1] == '-') {
    double tmp = 0;
    stack_pop_num(stack_num, &tmp);
    tmp = -tmp;
    my_operator temp;
    stack_pop_op(stack_op, &temp);
    stack_push_num(stack_num, &tmp);
  }
  *i = skip_numbers(expr, *i, strlen(expr)) - 1;
}

double parsing(char *expr, stack_numbers *stack_num, stack_operators *stack_op,
               double x) {
  stack_init_num(stack_num);
  stack_init_op(stack_op);
  int expr_size = strlen(expr);
  int counter_op = 0;
  int braces = 0;

  for (int i = 0; i < expr_size;) {
    char *ptr = &expr[i];
    if (*ptr == 'x')
      stack_push_num(stack_num, &x);
    else if (isdigit(*ptr)) {
      process_number(expr, &i, stack_num, stack_op);
    } else if (get_operator(ptr, &counter_op) != UNDEFINED) {
      handleOperator(ptr, counter_op, stack_num, stack_op, &i, &braces);
    }
    i++;
  }

  processRemainingOperations(stack_num, stack_op);

  return getResult(stack_num);
}

void handleOperator(char *c, int counter_op, stack_numbers *stack_num,
                    stack_operators *stack_op, int *i, int *braces) {
  my_operator temp = get_operator(c, &counter_op);
  *i += counter_op;
  my_operator op_down = UNDEFINED;

  if (temp == LEFT_BRACES) {
    (*braces)++;
    stack_push_op(stack_op, &temp);
  } else if (temp == RIGHT_BRACES) {
    if (*braces > 0) {
      handleRightBraces(stack_num, stack_op, braces);
    }
  } else {
    handleNonBracesOperator(temp, op_down, stack_num, stack_op);
  }
}

void handleRightBraces(stack_numbers *stack_num, stack_operators *stack_op,
                       int *braces) {
  my_operator tmp = UNDEFINED;
  while (tmp != LEFT_BRACES) {
    calculator(stack_num, stack_op);
    stack_top_op(stack_op, &tmp);
  }
  if (tmp == LEFT_BRACES) {
    stack_pop_op(stack_op, &tmp);
  }
  (*braces)--;
}

void handleNonBracesOperator(my_operator temp, my_operator op_down,
                             stack_numbers *stack_num,
                             stack_operators *stack_op) {
  if (!stack_top_op(stack_op, &op_down)) {
    stack_push_op(stack_op, &temp);
  } else if (action_priority(temp) == action_priority(op_down) &&
             action_priority(op_down) == pow_priority) {
    stack_push_op(stack_op, &temp);
  } else if (action_priority(temp) <= action_priority(op_down)) {
    calculator(stack_num, stack_op);
    stack_push_op(stack_op, &temp);
  } else {
    stack_push_op(stack_op, &temp);
  }
}

void processRemainingOperations(stack_numbers *stack_num,
                                stack_operators *stack_op) {
  while (stack_op->size > 0 && stack_num->size > 0) {
    calculator(stack_num, stack_op);
  }
}

double getResult(stack_numbers *stack_num) {
  double result = 0.0;
  stack_top_num(stack_num, &result);
  printf("RESULT: %.7lf\n", result);

  return result;
}

// int main() {
//   stack_operators stack_op;
//   stack_numbers stack_num;
//   double x = 0.0;

//   char *expr = "tan(896)";
//   parsing(expr, &stack_num, &stack_op, x);
//   return 0;
// }