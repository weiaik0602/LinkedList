#include "unity.h"
#include "linkedlist.h"
#include "student.h"
#include <string.h>
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_listInit_ensure_initialized_to_NULL_and_0(void){
  LinkedList list = {
    (Item *)-1,
    (Item *)-1,
    10
  };
  
  listInit(&list);
  
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
  TEST_ASSERT_EQUAL(0,list.len);
  
    
}
void test_student_listadd(void)
{
  
  LinkedList list;
    Student Ali = {
      "Ali",                        //name
      23,                           //age
      72.35,                        //weight
      1.78                          //height  
    };
    Item item = {
      (Item *)-1,                   //next
      (void *)&Ali                 //data
    };
    
    printf("address of item: %p\n", &item);
    
    listInit(&list);
    listAdd(&list,&item);
    TEST_ASSERT_EQUAL_PTR(&item,list.head);
    TEST_ASSERT_EQUAL_PTR(&item,list.tail);
    TEST_ASSERT_EQUAL(1,list.len);
    TEST_ASSERT_NULL(item.next);
    TEST_ASSERT_EQUAL_PTR(&Ali,item.data);
    
}

void test_LinkedList_LinkedList_InitV2(void)
{
  LinkedList list;
    Student Ali = {
      "Ali",                        //name
      23,                           //age
      72.35,                        //weight
      1.78                          //height  
    };
    Item item = {
      (Item *)-1,                   //next
      (void *)&Ali                 //data
    };
    
    printf("address of item: %p\n", &item);
    
    listInitV2(&list,&item);
    TEST_ASSERT_EQUAL_PTR(&item,list.head);
    TEST_ASSERT_EQUAL_PTR(&item,list.tail);
    TEST_ASSERT_EQUAL(2,list.len);
    TEST_ASSERT_NULL(item.next);
    TEST_ASSERT_EQUAL_PTR(&Ali,item.data);
}

void test_LinkedList_listAdd_on_InitV2(void)
{
  LinkedList list;
    Student Ali = {
      "Ali",                        //name
      23,                           //age
      72.35,                        //weight
      1.78                          //height  
    };
    Student Baba={
      "Baba",
      25,
      134.14,
      1.7
    };
	Student Abu={
      "Abu",
      25,
      134.14,
      1.7
    };
    Item itemAli = {
      (Item *)-1,                   //next
      (void *)&Ali                 //data
    };
    Item itemBaba={
      (Item *)-1,                   //next
      (void *)&Baba                //data
    };
    Item itemAbu={
      (Item *)-1,                   //next
      (void *)&Abu                //data
    };
    printf("address of itemAli: %p\n", &itemAli);
    printf("address of itemBaba: %p\n", &itemBaba);
    
    listInitV2(&list,&itemAli);
	TEST_ASSERT_EQUAL(2,list.len);
	listAdd(&list,&itemAbu);
	TEST_ASSERT_EQUAL_PTR(&itemAli,list.head);
	TEST_ASSERT_EQUAL_PTR(&itemAbu,list.tail);
	TEST_ASSERT_EQUAL(3,list.len);
}

void test_LinkedList_listRemoveHead_and_byName(void){
	LinkedList list,list2;
    Student Ali = {
      "Ali",                        //name
      23,                           //age
      72.35,                        //weight
      1.78                          //height  
    };
    Student Baba={
      "Baba",
      25,
      134.14,
      1.7
    };
	Student Abu={
      "Abu",
      25,
      134.14,
      1.7
    };
    Item itemAli = {
      (Item *)-1,                   //next
      (void *)&Ali                 //data
    };
    Item itemBaba={
      (Item *)-1,                   //next
      (void *)&Baba                //data
    };
	Item itemAbu={
      (Item *)-1,                   //next
      (void *)&Abu                //data
    };
	
	
	listInit(&list);
	listAdd(&list,&itemAli);
	listAdd(&list,&itemBaba);
	listAdd(&list,&itemAbu);
	list2=list;
	//checking if all initialized correctly
	TEST_ASSERT_EQUAL_PTR(&itemAli,list.head);
    TEST_ASSERT_EQUAL_PTR(&itemAbu,list.tail);
	TEST_ASSERT_EQUAL(3,list.len);
	
	//checking after remove the head(ali)
	listRemoveHead(&list);
	TEST_ASSERT_EQUAL_PTR(&itemBaba,list.head);
    TEST_ASSERT_EQUAL_PTR(&itemAbu,list.tail);
	TEST_ASSERT_EQUAL(2,list.len);
	
	
	printf("address of itemAli: %p\n", &itemAli);
    printf("address of itemBaba: %p\n", &itemBaba);
	printf("address of itemAbu: %p\n", &itemAbu);
	//int x=Compare(&itemAli,"Ali");
	//TEST_ASSERT_EQUAL(0,x);
	//checking remove by name
	listRemoveByName(&list2,"Abu");
	TEST_ASSERT_EQUAL_PTR(&itemAli,list2.head);
	TEST_ASSERT_EQUAL_PTR(&itemBaba,list2.tail);
    //TEST_ASSERT_EQUAL_PTR(&itemAbu,list2.tail);
	TEST_ASSERT_NULL(list2.tail->next);
	TEST_ASSERT_EQUAL_PTR(&itemBaba.next,&itemBaba);
	TEST_ASSERT_EQUAL(2,list.len);
}