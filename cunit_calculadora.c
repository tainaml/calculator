#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "calculadora.h"

/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{
   if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}

void test_soma (void){
    CU_ASSERT(calculadora('+',1,1) == 2);
    CU_ASSERT(calculadora('+',-2,-2) == -4);
    CU_ASSERT(calculadora('+',10,-10) == 0);
}

void test_subtracao (void){
    CU_ASSERT(calculadora('-',1,-1) == 0);
    CU_ASSERT(calculadora('-',-2,-2) == 0);
    CU_ASSERT(calculadora('-',10,-10)== 20);
}

void test_multiplicacao (void){

    CU_ASSERT(calculadora('*',1,-1) == -1);
    CU_ASSERT(calculadora('*',-2,-2) == 2);
    CU_ASSERT(calculadora('*',10,-10) == -100);
}

void test_divisao (void){
    CU_ASSERT(calculadora('/',1,-1) == -1);
    CU_ASSERT(calculadora('/',-2,-2) == 1);
    CU_ASSERT(calculadora('/',10,-10) == -1);
}

int main(){

   CU_pSuite pSuite = NULL;

   /* inicializando o registro de testes do cunit */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* adicionando o registro a suite de testes */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* adicionando testes a suite */
   if ((NULL == CU_add_test(pSuite, "teste soma", test_soma)) ||
       (NULL == CU_add_test(pSuite, "test subtracao", test_subtracao)) ||
       (NULL == CU_add_test(pSuite, "test multiplicacao", test_multiplicacao)) ||
       (NULL == CU_add_test(pSuite, "test divisao", test_divisao))){

      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Executa todos os testes usando a lib CUnit Basic */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
