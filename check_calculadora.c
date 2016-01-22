#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "calculadora.h"

START_TEST(test_soma)
{
    ck_assert_int_eq(calculadora('+',1,1), 2);
    ck_assert_int_eq(calculadora('+',-2,-2), -4);
    ck_assert_int_eq(calculadora('+',10,-10), 0);
}
END_TEST

START_TEST(test_subtracao)
{
    ck_assert_int_eq(calculadora('-',1,-1), 0);
    ck_assert_int_eq(calculadora('-',-2,-2), 0);
    ck_assert_int_eq(calculadora('-',10,-10), 20);
}
END_TEST

START_TEST(test_multiplicacao)
{
    ck_assert_int_eq(calculadora('*',1,-1), -1);
    ck_assert_int_eq(calculadora('*',-2,-2), 4);
    ck_assert_int_eq(calculadora('*',10,-10), -100);
}
END_TEST

START_TEST(test_divisao)
{
    ck_assert_int_eq(calculadora('/',1,-1), -1);
    ck_assert_int_eq(calculadora('/',-2,-2), 1);
    ck_assert_int_eq(calculadora('/',10,-10), -1);
}
END_TEST

Suite * calculadora_suite(void){
    Suite *s;
    TCase *tc_core;

    s = suite_create("Calculadora");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_soma);
    tcase_add_test(tc_core, test_subtracao);
    tcase_add_test(tc_core, test_multiplicacao);
    tcase_add_test(tc_core, test_divisao);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(){
     int number_failed;
     Suite *s;
     SRunner *sr;

     s = calculadora_suite();
     sr = srunner_create(s);

     srunner_run_all(sr, CK_NORMAL);
     number_failed = srunner_ntests_failed(sr);
     srunner_free(sr);
     return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
