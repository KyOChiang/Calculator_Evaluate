#ifndef Calculator_H
#define Calculator_H

int evaluate(char *expression, Stack *operatorStack, Stack *dataStack);
void tryEvaluateOperatorsOnStackThenPush(Stack *operatorStack, Stack *dataStack, OperatorToken *Operator);
void evaluateAllOperatorsOnStack(Stack *operatorStack, Stack *dataStack);
void evaluateOperator(Stack *dataStack, OperatorToken *Operator);


#endif // Calculator_H
