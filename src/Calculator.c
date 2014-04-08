#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "CException.h"
#include "Token.h"
#include "Stack.h"
#include "Error.h"
#include "Calculator.h"

int evaluate(char *expression, Stack *operatorStack, Stack *dataStack){
	Tokenizer *tokenizer;
	Token *token;
	NumberToken *number;
	OperatorToken *operator;
	NumberToken *result;
	
	tokenizer = tokenizerNew(expression);
	for(;;){
		number = (NumberToken *)nextToken(tokenizer);
		if(number == NULL){
			evaluateAllOperatorsOnStack(operatorStack,dataStack);
			break;
		}
		else if(number->type != NUMBER_TOKEN){
			Throw(ERR_NOT_DATA);
		}
		else{
			push(dataStack,number);
		}
		operator = (OperatorToken *)nextToken(tokenizer);
		if(operator==NULL){
			evaluateAllOperatorsOnStack(operatorStack,dataStack);
			break;
		}
		else if(operator->type != OPERATOR_TOKEN){
			Throw(ERR_NOT_OPERATOR);
		}
		else{
			tryEvaluateOperatorsOnStackThenPush(operatorStack,dataStack,operator);
		}
		// number = (NumberToken *)nextToken(tokenizer);
		// if(number == NULL){
			// Throw(ERR_INVALID_EXPRESSION);
		// }
	}
	result = pop(dataStack);
	
	// operator = (OperatorToken *)nextToken(tokenizer);
	// number = (NumberToken *)nextToken(tokenizer);
	// operator = (OperatorToken *)nextToken(tokenizer);
	// number = (NumberToken *)nextToken(tokenizer);
	// token 
	
	return result->value;
}

void tryEvaluateOperatorsOnStackThenPush(Stack *operatorStack, Stack *dataStack, OperatorToken *Operator){
	OperatorToken *OP = pop(operatorStack);
	while(OP!=NULL){
		if(OP->precedence >= Operator->precedence){
			evaluateOperator(dataStack, OP);
			OP = pop(operatorStack);
		}
		else{
			push(operatorStack,OP);
			break;
		}
	}
	push(operatorStack,Operator);
}


void evaluateAllOperatorsOnStack(Stack *operatorStack, Stack *dataStack){
	OperatorToken *OP = pop(operatorStack);
	
	while(OP != NULL){
		evaluateOperator(dataStack,OP);
		OP = pop(operatorStack);
	}
	
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
		result = createNumberToken(right->value-left->value);
		push(dataStack, result);
	}
	else if(strcmp(Operator->name,"*")==0){
		result = createNumberToken(left->value*right->value);
		push(dataStack, result);
	}
	else if(strcmp(Operator->name,"/")==0){
		result = createNumberToken(right->value/left->value);
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
