#include "unity.h"
#include "CException.h"
#include "mock_Token.h"
#include "mock_Stack.h"
#include "Error.h"
#include "Calculator.h"

void setUp(void){}

void tearDown(void){}

void test_evaluateOperator_should_add_2_values_when_plus_given(){

	Stack dataStack;
	OperatorToken plus = {.name = "+"};
	NumberToken no_2 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken no_1 = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	
	pop_ExpectAndReturn(&dataStack, &no_2);
	pop_ExpectAndReturn(&dataStack, &no_1);
	createNumberToken_ExpectAndReturn(3, &no_3);
	push_Expect(&dataStack, &no_3);
	
	evaluateOperator(&dataStack, &plus);
}

void test_evaluateOperator_should_subtract_2_values_when_minus_given(){

	Stack dataStack;
	OperatorToken minus = {.name = "-"};
	NumberToken no_2 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken no_1 = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	
	pop_ExpectAndReturn(&dataStack, &no_3);
	pop_ExpectAndReturn(&dataStack, &no_2);
	createNumberToken_ExpectAndReturn(1, &no_1);
	push_Expect(&dataStack, &no_1);
	
	evaluateOperator(&dataStack, &minus);
}

void test_evaluateOperator_should_multiply_2_values_when_multiply_given(){

	Stack dataStack;
	OperatorToken multiply = {.name = "*"};
	NumberToken no_2 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken no_6 = {.type = NUMBER_TOKEN, .value = 6};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	
	pop_ExpectAndReturn(&dataStack, &no_3);
	pop_ExpectAndReturn(&dataStack, &no_2);
	createNumberToken_ExpectAndReturn(6, &no_6);
	push_Expect(&dataStack, &no_6);
	
	evaluateOperator(&dataStack, &multiply);
}

void test_evaluateOperator_should_divide_2_values_when_divide_given(){

	Stack dataStack;
	OperatorToken divide = {.name = "/"};
	NumberToken no_2 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken no_1 = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	
	pop_ExpectAndReturn(&dataStack, &no_3);
	pop_ExpectAndReturn(&dataStack, &no_2);
	createNumberToken_ExpectAndReturn(1, &no_1);
	push_Expect(&dataStack, &no_1);
	
	evaluateOperator(&dataStack, &divide);
}

void test_evaluateOperator_should_modulo_2_values_when_modulo_given(){

	Stack dataStack;
	OperatorToken modulo = {.name = "%"};
	NumberToken no_1 = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken no_0 = {.type = NUMBER_TOKEN, .value = 0};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	
	pop_ExpectAndReturn(&dataStack, &no_3);
	pop_ExpectAndReturn(&dataStack, &no_1);
	createNumberToken_ExpectAndReturn(0, &no_0);
	push_Expect(&dataStack, &no_0);
	
	evaluateOperator(&dataStack, &modulo);
}

void test_evaluateOperator_should_xor_2_values_when_xor_given(){

	Stack dataStack;
	OperatorToken xor = {.name = "^"};
	NumberToken no_5 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken no_6 = {.type = NUMBER_TOKEN, .value = 6};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	
	pop_ExpectAndReturn(&dataStack, &no_5);
	pop_ExpectAndReturn(&dataStack, &no_6);
	createNumberToken_ExpectAndReturn(3, &no_3);
	push_Expect(&dataStack, &no_3);
	
	evaluateOperator(&dataStack, &xor);
}

void test_evaluateOperator_should_and_2_values_when_and_given(){

	Stack dataStack;
	OperatorToken and = {.name = "&"};
	NumberToken no_7 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken no_17 = {.type = NUMBER_TOKEN, .value = 17};
	NumberToken no_1 = {.type = NUMBER_TOKEN, .value = 1};
	
	pop_ExpectAndReturn(&dataStack, &no_7);
	pop_ExpectAndReturn(&dataStack, &no_17);
	createNumberToken_ExpectAndReturn(1, &no_1);
	push_Expect(&dataStack, &no_1);
	
	evaluateOperator(&dataStack, &and);
}

void test_evaluateOperator_should_or_2_values_when_or_given(){

	Stack dataStack;
	OperatorToken or = {.name = "|"};
	NumberToken no_8 = {.type = NUMBER_TOKEN, .value = 8};
	NumberToken no_5 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken no_13 = {.type = NUMBER_TOKEN, .value = 13};
	
	pop_ExpectAndReturn(&dataStack, &no_8);
	pop_ExpectAndReturn(&dataStack, &no_5);
	createNumberToken_ExpectAndReturn(13, &no_13);
	push_Expect(&dataStack, &no_13);
	
	evaluateOperator(&dataStack, &or);
}

void test_evaluateAllOperatorsOnStack_should_evaluate_2_plus_3_mul_4(){
	Stack dataStack;
	Stack operatorStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken multiply = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	NumberToken no_2 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken no_4 = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken no_12 = {.type = NUMBER_TOKEN, .value = 12};
	NumberToken no_14 = {.type = NUMBER_TOKEN, .value = 14};
	
	//2+3*4
	pop_ExpectAndReturn(&operatorStack, &multiply);
	pop_ExpectAndReturn(&dataStack, &no_4);
	pop_ExpectAndReturn(&dataStack, &no_3);
	createNumberToken_ExpectAndReturn(12, &no_12);
	push_Expect(&dataStack, &no_12);
	pop_ExpectAndReturn(&operatorStack, &plus);
	pop_ExpectAndReturn(&dataStack, &no_12);
	pop_ExpectAndReturn(&dataStack, &no_2);
	createNumberToken_ExpectAndReturn(14, &no_14);
	push_Expect(&dataStack, &no_14);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorsOnStack(&operatorStack, &dataStack);
}

void test_evaluateAllOperatorsOnStack_should_evaluate_5_xor_6_or_7_and_8_plus_9(){
	Stack dataStack;
	Stack operatorStack;
	OperatorToken xor = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	OperatorToken and = {.type = OPERATOR_TOKEN, .name = "&", .precedence = 20};
	OperatorToken or = {.type = OPERATOR_TOKEN, .name = "|", .precedence = 10};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken no_8 = {.type = NUMBER_TOKEN, .value = 8};
	NumberToken no_9 = {.type = NUMBER_TOKEN, .value = 9};
	NumberToken no_7 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken no_17 = {.type = NUMBER_TOKEN, .value = 17};
	NumberToken no_1 = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken no_6 = {.type = NUMBER_TOKEN, .value = 6};
	NumberToken no_5 = {.type = NUMBER_TOKEN, .value = 5};
	
	//5^6|7&8+9
	pop_ExpectAndReturn(&operatorStack, &xor);
	pop_ExpectAndReturn(&dataStack, &no_5);
	pop_ExpectAndReturn(&dataStack, &no_6);
	createNumberToken_ExpectAndReturn(3, &no_3);
	push_Expect(&dataStack, &no_3);
	pop_ExpectAndReturn(&operatorStack, &plus);
	pop_ExpectAndReturn(&dataStack, &no_8);
	pop_ExpectAndReturn(&dataStack, &no_9);
	createNumberToken_ExpectAndReturn(17, &no_17);
	push_Expect(&dataStack, &no_17);
	pop_ExpectAndReturn(&operatorStack, &and);
	pop_ExpectAndReturn(&dataStack, &no_7);
	pop_ExpectAndReturn(&dataStack, &no_17);
	createNumberToken_ExpectAndReturn(1, &no_1);
	push_Expect(&dataStack, &no_1);
	pop_ExpectAndReturn(&operatorStack, &or);
	pop_ExpectAndReturn(&dataStack, &no_3);
	pop_ExpectAndReturn(&dataStack, &no_1);
	createNumberToken_ExpectAndReturn(3, &no_3);
	push_Expect(&dataStack, &no_3);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorsOnStack(&operatorStack, &dataStack);
}

void test_tryEvaluateOperatorsOnStackThenPush_should_stop_if_pass_in_OP_has_higher_precedene(){
	Stack dataStack;
	Stack operatorStack;
	OperatorToken multiply = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken no_4 = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken no_9 = {.type = NUMBER_TOKEN, .value = 9};
	NumberToken no_12 = {.type = NUMBER_TOKEN, .value = 12};
	NumberToken no_21 = {.type = NUMBER_TOKEN, .value = 21};
	
	//3*4+9 = (3*4)+9 = 12+9 = 21
	pop_ExpectAndReturn(&operatorStack,&plus);
	push_Expect(&operatorStack,&plus);
	push_Expect(&operatorStack,&multiply);
	tryEvaluateOperatorsOnStackThenPush(&operatorStack,&dataStack,&multiply);
}

void test_tryEvaluateOperatorsOnStackThenPush_should_do_multiply_first_if_pass_in_OP_has_lower_precedene(){
	Stack dataStack;
	Stack operatorStack;
	OperatorToken multiply = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken no_4 = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken no_9 = {.type = NUMBER_TOKEN, .value = 9};
	NumberToken no_12 = {.type = NUMBER_TOKEN, .value = 12};
	NumberToken no_21 = {.type = NUMBER_TOKEN, .value = 21};
	
	//3*4+9 = (3*4)+9 = 12+9 = 21
	pop_ExpectAndReturn(&operatorStack,&multiply);
	pop_ExpectAndReturn(&dataStack, &no_3);
	pop_ExpectAndReturn(&dataStack, &no_4);
	createNumberToken_ExpectAndReturn(12, &no_12);
	push_Expect(&dataStack, &no_12);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&plus);
	
	tryEvaluateOperatorsOnStackThenPush(&operatorStack,&dataStack,&plus);
}



























