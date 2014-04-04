#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "CException.h"
#include "Token.h"
#include "Stack.h"
#include "Error.h"
#include "Calculator.h"

int evaluate(char *expression){
	return 0;
}

void evaluateOperator(Stack *dataStack, OperatorToken *Operator){
	NumberToken *result;
	NumberToken *left = pop(dataStack);
	NumberToken *right = pop(dataStack);
	
	if(strcmp(Operator->name,"+")==0){
		result = createNumberToken(right->value+left->value);
		push(dataStack, result);
	}
	else if(strcmp(Operator->name,"-")==0){
		result = createNumberToken(left->value-right->value);
		push(dataStack, result);
	}
	else if(strcmp(Operator->name,"*")==0){
		result = createNumberToken(left->value*right->value);
		push(dataStack, result);
	}
	else if(strcmp(Operator->name,"/")==0){
		result = createNumberToken(left->value/right->value);
		push(dataStack, result);
	}
	else if(strcmp(Operator->name,"%")==0){
		result = createNumberToken(left->value%right->value);
		push(dataStack, result);
	}
	else if(strcmp(Operator->name,"^")==0){
		result = createNumberToken(left->value^right->value);
		push(dataStack, result);
	}
	else if(strcmp(Operator->name,"|")==0){
		result = createNumberToken(left->value|right->value);
		push(dataStack, result);
	}
	else if(strcmp(Operator->name,"&")==0){
		result = createNumberToken(left->value&right->value);
		push(dataStack, result);
	}
}
