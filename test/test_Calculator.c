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
