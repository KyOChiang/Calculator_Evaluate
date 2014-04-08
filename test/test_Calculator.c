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
	
	pop_ExpectAndReturn(&dataStack, &no_2);
	pop_ExpectAndReturn(&dataStack, &no_3);
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
	
	pop_ExpectAndReturn(&dataStack, &no_2);
	pop_ExpectAndReturn(&dataStack, &no_3);
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

void test_evaluate_should_evaluate_an_expression_1_plus_2_and_compute_result(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	CEXCEPTION_T ERR;
	int result;
	
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken no_1 = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken no_2 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	
	tokenizerNew_ExpectAndReturn("1 + 2",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&no_1);
	push_Expect(&dataStack,(Token *)&no_1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,(Token *)&plus);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&no_2);
	push_Expect(&dataStack,(Token *)&no_2);
	
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	pop_ExpectAndReturn(&operatorStack,&plus);
	
	pop_ExpectAndReturn(&dataStack,&no_1);
	pop_ExpectAndReturn(&dataStack,&no_2);
	createNumberToken_ExpectAndReturn(3, &no_3);
	push_Expect(&dataStack, &no_3);
	pop_ExpectAndReturn(&operatorStack,NULL);
	pop_ExpectAndReturn(&dataStack,&no_3);
	
	result = evaluate("1 + 2", &operatorStack, &dataStack);
	TEST_ASSERT_EQUAL(3,result);
}

void test_evaluate_should_evaluate_an_expression_4_mul_3_and_compute_result(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	CEXCEPTION_T ERR;
	int result;
	
	OperatorToken mul = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	NumberToken no_12 = {.type = NUMBER_TOKEN, .value = 12};
	NumberToken no_4 = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	
	tokenizerNew_ExpectAndReturn("4 * 3",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&no_4);
	push_Expect(&dataStack,(Token *)&no_4);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&mul);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,(Token *)&mul);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&no_3);
	push_Expect(&dataStack,(Token *)&no_3);
	
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	pop_ExpectAndReturn(&operatorStack,&mul);
	
	pop_ExpectAndReturn(&dataStack,&no_3);
	pop_ExpectAndReturn(&dataStack,&no_4);
	createNumberToken_ExpectAndReturn(12, &no_12);
	push_Expect(&dataStack, &no_12);
	pop_ExpectAndReturn(&operatorStack,NULL);
	pop_ExpectAndReturn(&dataStack,&no_12);
	
	result = evaluate("4 * 3", &operatorStack, &dataStack);
	TEST_ASSERT_EQUAL(12,result);
}

void test_evaluate_should_evaluate_an_expression_3_plus_4_plus_5_minus_6_and_compute_result(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	CEXCEPTION_T ERR;
	int result;

	OperatorToken plus1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken plus2 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken minus = {.type = OPERATOR_TOKEN, .name = "-", .precedence = 70};
	NumberToken no_3 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken no_4 = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken no_5 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken no_6 = {.type = NUMBER_TOKEN, .value = 6};
	NumberToken no_7 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken no_12 = {.type = NUMBER_TOKEN, .value = 12};
	NumberToken no_66 = {.type = NUMBER_TOKEN, .value = 6};

	//3 + 4 + 5 - 6 = 6
	tokenizerNew_ExpectAndReturn("3 + 4 + 5 - 6", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_3);
	push_Expect(&dataStack, &no_3);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&plus1);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &plus1);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_4);
	push_Expect(&dataStack, &no_4);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&plus2);
	pop_ExpectAndReturn(&operatorStack, &plus1);
	pop_ExpectAndReturn(&dataStack, &no_4);
	pop_ExpectAndReturn(&dataStack, &no_3);
	createNumberToken_ExpectAndReturn(7, &no_7);
	push_Expect(&dataStack, &no_7);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &plus2);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_5);
	push_Expect(&dataStack, &no_5);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&minus);
	pop_ExpectAndReturn(&operatorStack, &plus2);
	pop_ExpectAndReturn(&dataStack, &no_5);
	pop_ExpectAndReturn(&dataStack, &no_7);
	createNumberToken_ExpectAndReturn(12, &no_12);
	push_Expect(&dataStack, &no_12);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &minus);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_6);
	push_Expect(&dataStack, &no_6);

	nextToken_ExpectAndReturn(&tokenizer, NULL);

	pop_ExpectAndReturn(&operatorStack, &minus);
	pop_ExpectAndReturn(&dataStack, &no_6);
	pop_ExpectAndReturn(&dataStack, &no_12);
	createNumberToken_ExpectAndReturn(6, &no_6);
	push_Expect(&dataStack, &no_6);
	pop_ExpectAndReturn(&operatorStack, NULL);

	pop_ExpectAndReturn(&dataStack, &no_6);

	Try{
		result = evaluate("3 + 4 + 5 - 6", &operatorStack, &dataStack);
	}Catch(ERR){
		TEST_FAIL_MESSAGE("Error Exception!");
	}

	TEST_ASSERT_EQUAL(6, result);
}

void test_evaluate_should_evaluate_an_expression_111_divide_12_plus_13_and_14_and_compute_result(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	NumberToken *number;
	CEXCEPTION_T ERR;
	int result;

	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken divide = {.type = OPERATOR_TOKEN, .name = "/", .precedence = 100};
	OperatorToken and = {.type = OPERATOR_TOKEN, .name = "&", .precedence = 20};
	NumberToken no_111 = {.type = NUMBER_TOKEN, .value = 111};
	NumberToken no_12 = {.type = NUMBER_TOKEN, .value = 12};
	NumberToken no_13 = {.type = NUMBER_TOKEN, .value = 13};
	NumberToken no_14 = {.type = NUMBER_TOKEN, .value = 14};
	NumberToken no_9 = {.type = NUMBER_TOKEN, .value = 9};
	NumberToken no_22 = {.type = NUMBER_TOKEN, .value = 22};
	NumberToken no_6 = {.type = NUMBER_TOKEN, .value = 6};

	// ((111 / 12) + 13) & 14
	tokenizerNew_ExpectAndReturn("111 / 12 + 13 & 14", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_111);
	push_Expect(&dataStack, &no_111);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&divide);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &divide);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_12);
	push_Expect(&dataStack, &no_12);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&plus);
	pop_ExpectAndReturn(&operatorStack, &divide);
	pop_ExpectAndReturn(&dataStack, &no_12);
	pop_ExpectAndReturn(&dataStack, &no_111);
	createNumberToken_ExpectAndReturn(9, &no_9);
	push_Expect(&dataStack, &no_9);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &plus);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_13);
	push_Expect(&dataStack, &no_13);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&and);
	pop_ExpectAndReturn(&operatorStack, &plus);
	pop_ExpectAndReturn(&dataStack, &no_13);
	pop_ExpectAndReturn(&dataStack, &no_9);
	createNumberToken_ExpectAndReturn(22, &no_22);
	push_Expect(&dataStack, &no_22);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &and);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_14);
	push_Expect(&dataStack, &no_14);

	nextToken_ExpectAndReturn(&tokenizer, NULL);

	pop_ExpectAndReturn(&operatorStack, &and);
	pop_ExpectAndReturn(&dataStack, &no_14);
	pop_ExpectAndReturn(&dataStack, &no_22);
	createNumberToken_ExpectAndReturn(6, &no_6);
	push_Expect(&dataStack, &no_6);
	pop_ExpectAndReturn(&operatorStack, NULL);

	pop_ExpectAndReturn(&dataStack, &no_6);

	Try{
		result = evaluate("111 / 12 + 13 & 14", &operatorStack, &dataStack);
	}Catch(ERR){
		TEST_FAIL_MESSAGE("Error Exception!");
	}

	TEST_ASSERT_EQUAL(6, result);
}

void test_evaluate_should_evaluate_an_expression_211_and_22_xor_23_plus_24_mul_25_and_compute_result(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	CEXCEPTION_T ERR;
	int result;

	OperatorToken and = {.type = OPERATOR_TOKEN, .name = "&", .precedence = 20};
	OperatorToken xor = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken no_211 = {.type = NUMBER_TOKEN, .value = 211};
	NumberToken no_22 = {.type = NUMBER_TOKEN, .value = 22};
	NumberToken no_23 = {.type = NUMBER_TOKEN, .value = 23};
	NumberToken no_24 = {.type = NUMBER_TOKEN, .value = 24};
	NumberToken no_47 = {.type = NUMBER_TOKEN, .value = 47};
	NumberToken no_57 = {.type = NUMBER_TOKEN, .value = 57};
	NumberToken no_17 = {.type = NUMBER_TOKEN, .value = 17};

	// 211 & (22 ^ (23 + 24))
	tokenizerNew_ExpectAndReturn("211 & 22 ^ 23 + 24", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_211);
	push_Expect(&dataStack, &no_211);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&and);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &and);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_22);
	push_Expect(&dataStack, &no_22);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&xor);
	pop_ExpectAndReturn(&operatorStack, &and);
	push_Expect(&operatorStack, &and);
	push_Expect(&operatorStack, &xor);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_23);
	push_Expect(&dataStack, &no_23);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&plus);
	pop_ExpectAndReturn(&operatorStack, &xor);
	push_Expect(&operatorStack, &xor);
	push_Expect(&operatorStack, &plus);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_24);
	push_Expect(&dataStack, &no_24);

	nextToken_ExpectAndReturn(&tokenizer, NULL);
	pop_ExpectAndReturn(&operatorStack, &plus);

	pop_ExpectAndReturn(&dataStack, &no_24);
	pop_ExpectAndReturn(&dataStack, &no_23);
	createNumberToken_ExpectAndReturn(47, &no_47);
	push_Expect(&dataStack, &no_47);

	pop_ExpectAndReturn(&operatorStack, &xor);
	pop_ExpectAndReturn(&dataStack, &no_47);
	pop_ExpectAndReturn(&dataStack, &no_22);
	createNumberToken_ExpectAndReturn(57, &no_57);
	push_Expect(&dataStack, &no_57);

	pop_ExpectAndReturn(&operatorStack, &and);
	pop_ExpectAndReturn(&dataStack, &no_57);
	pop_ExpectAndReturn(&dataStack, &no_211);
	createNumberToken_ExpectAndReturn(17, &no_17);
	push_Expect(&dataStack, &no_17);

	pop_ExpectAndReturn(&operatorStack, NULL);

	pop_ExpectAndReturn(&dataStack, &no_17);

	Try{
		result = evaluate("211 & 22 ^ 23 + 24", &operatorStack, &dataStack);
	}Catch(ERR){
		TEST_FAIL_MESSAGE("Error Exception!");
	}

	TEST_ASSERT_EQUAL(17, result);
}

void test_evaluate_should_evaluate_an_expression_266_or_27_xor_28_plus_29_and_30_and_compute_result(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	CEXCEPTION_T ERR;
	int result;

	OperatorToken or = {.type = OPERATOR_TOKEN, .name = "|", .precedence = 10};
	OperatorToken xor = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken and = {.type = OPERATOR_TOKEN, .name = "&", .precedence = 20};
	NumberToken no_266 = {.type = NUMBER_TOKEN, .value = 266};
	NumberToken no_27 = {.type = NUMBER_TOKEN, .value = 27};
	NumberToken no_28 = {.type = NUMBER_TOKEN, .value = 28};
	NumberToken no_29 = {.type = NUMBER_TOKEN, .value = 29};
	NumberToken no_30 = {.type = NUMBER_TOKEN, .value = 30};
	NumberToken no_57 = {.type = NUMBER_TOKEN, .value = 57};
	NumberToken no_34 = {.type = NUMBER_TOKEN, .value = 34};
	NumberToken no_2 = {.type = NUMBER_TOKEN, .value = 2};
	
	// 266 | ((27 ^ (28 + 29)) & 30)
	tokenizerNew_ExpectAndReturn("266 | 27 ^ 28 + 29 & 30", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_266);
	push_Expect(&dataStack, &no_266);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&or);
	pop_ExpectAndReturn(&operatorStack, NULL);
	push_Expect(&operatorStack, &or);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_27);
	push_Expect(&dataStack, &no_27);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&xor);
	pop_ExpectAndReturn(&operatorStack, &or);
	push_Expect(&operatorStack, &or);
	push_Expect(&operatorStack, &xor);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_28);
	push_Expect(&dataStack, &no_28);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&plus);
	pop_ExpectAndReturn(&operatorStack, &xor);
	push_Expect(&operatorStack, &xor);
	push_Expect(&operatorStack, &plus);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_29);
	push_Expect(&dataStack, &no_29);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&and);
	pop_ExpectAndReturn(&operatorStack, &plus);
	pop_ExpectAndReturn(&dataStack, &no_29);
	pop_ExpectAndReturn(&dataStack, &no_28);
	createNumberToken_ExpectAndReturn(57, &no_57);
	push_Expect(&dataStack, &no_57);

	pop_ExpectAndReturn(&operatorStack, &xor);
	pop_ExpectAndReturn(&dataStack, &no_57);
	pop_ExpectAndReturn(&dataStack, &no_27);
	createNumberToken_ExpectAndReturn(34, &no_34);
	push_Expect(&dataStack, &no_34);

	pop_ExpectAndReturn(&operatorStack, &or);
	push_Expect(&operatorStack, &or);
	push_Expect(&operatorStack, &and);

	nextToken_ExpectAndReturn(&tokenizer, (Token *)&no_30);
	push_Expect(&dataStack, &no_30);

	nextToken_ExpectAndReturn(&tokenizer, NULL);

	pop_ExpectAndReturn(&operatorStack, &and);
	pop_ExpectAndReturn(&dataStack, &no_30);
	pop_ExpectAndReturn(&dataStack, &no_34);
	createNumberToken_ExpectAndReturn(2, &no_2);
	push_Expect(&dataStack, &no_2);

	pop_ExpectAndReturn(&operatorStack, &or);
	pop_ExpectAndReturn(&dataStack, &no_2);
	pop_ExpectAndReturn(&dataStack, &no_266);
	createNumberToken_ExpectAndReturn(266, &no_266);
	push_Expect(&dataStack, &no_266);

	pop_ExpectAndReturn(&operatorStack, NULL);

	pop_ExpectAndReturn(&dataStack, &no_266);

	Try{
		result = evaluate("266 | 27 ^ 28 + 29 & 30", &operatorStack, &dataStack);
	}Catch(ERR){
		TEST_FAIL_MESSAGE("Error Exception!");
	}

	TEST_ASSERT_EQUAL(266, result);
}

void test_evaluate_should_throw_ERR_NOT_DATA_with_plus_only(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	NumberToken *number;
	CEXCEPTION_T ERR;
	
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	tokenizerNew_ExpectAndReturn("+",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	
	Try{
		evaluate("+", &operatorStack, &dataStack);
	}Catch(ERR){
		TEST_ASSERT_EQUAL(ERR_NOT_DATA,ERR);
	}
}

void test_evaluate_should_throw_ERR_NOT_OPERATOR_for_38_space_39(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	NumberToken *number;
	CEXCEPTION_T ERR;
	
	NumberToken no_39 = {.type = NUMBER_TOKEN, .value = 39};
	NumberToken no_38 = {.type = NUMBER_TOKEN, .value = 38};
	
	tokenizerNew_ExpectAndReturn("38 39",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&no_38);
	push_Expect(&dataStack,&no_38);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&no_39);
	
	Try{
		evaluate("38 39", &operatorStack, &dataStack);
	}Catch(ERR){
		TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,ERR);
	}
}

void test_evaluate_should_throw_ERR_NOT_DATA_for_40_plus_mul(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	NumberToken *number;
	CEXCEPTION_T ERR;
	
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken mul = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	NumberToken no_40 = {.type = NUMBER_TOKEN, .value = 40};
	NumberToken no_38 = {.type = NUMBER_TOKEN, .value = 38};
	
	
	tokenizerNew_ExpectAndReturn("40+*",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&no_40);
	push_Expect(&dataStack,&no_40);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&plus);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&mul);
	
	Try{
		evaluate("40+*", &operatorStack, &dataStack);
	}Catch(ERR){
		TEST_ASSERT_EQUAL(ERR_NOT_DATA,ERR);
	}
}

void test_evaluate_should_throw_ERR_INVALID_EXPRESSION_with_43_HASH(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	NumberToken *number;
	CEXCEPTION_T ERR;
	NumberToken no_43 = {.type = NUMBER_TOKEN, .value = 43};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	tokenizerNew_ExpectAndReturn("43#",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&no_43);
	push_Expect(&dataStack,&no_43);
	
	nextToken_ExpectAndThrow(&tokenizer,ERR_INVALID_EXPRESSION);
	
	Try{
		evaluate("43#", &operatorStack, &dataStack);
	}Catch(ERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_EXPRESSION,ERR);
	}
}

void test_evaluate_should_throw_ERR_INVALID_EXPRESSION_with_42_XOR_2_minus(){
	Stack dataStack;
	Stack operatorStack;
	Tokenizer tokenizer;
	NumberToken *number;
	CEXCEPTION_T ERR;
	NumberToken no_42 = {.type = NUMBER_TOKEN, .value = 42};
	NumberToken no_2 = {.type = NUMBER_TOKEN, .value = 2};
	OperatorToken xor = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	OperatorToken minus = {.type = OPERATOR_TOKEN, .name = "-", .precedence = 70};
	
	tokenizerNew_ExpectAndReturn("42^2-",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&no_42);
	push_Expect(&dataStack,&no_42);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&xor);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&xor);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&no_2);
	push_Expect(&dataStack,&no_2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&minus);
	pop_ExpectAndReturn(&operatorStack,&xor);
	push_Expect(&operatorStack,&xor);
	push_Expect(&operatorStack,&minus);
	
	nextToken_ExpectAndThrow(&tokenizer,ERR_INVALID_EXPRESSION);
	
	Try{
		evaluate("42^2-", &operatorStack, &dataStack);
	}Catch(ERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_EXPRESSION,ERR);
	}
}

























