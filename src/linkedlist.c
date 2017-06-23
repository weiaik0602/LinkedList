#include <stdio.h>
#include "linkedlist.h"
#include "student.h"

void listInit(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void listAdd(LinkedList *list,Item *item){
    // Implement your code here...
    //
    if(list->len==0){
    list->head=item;
    list->tail=item;
    }
    else{
      list->tail=item;
    } 
    list->len +=1;
    item->next=NULL;
}

void listInitV2(LinkedList *list,Item *item){
    // Implement your code here...
    list->head=item;
    list->tail=item;
    list->len +=1;
    item->next=NULL;
}

int Compare(LinkedList list, char name){
  Student student;
  student=(Student*)(list->head);
  int result=strcmp(student.name,name);
  return result;
}
int ListFind(LinkedList list, char name)
{
  //Item temp;
  //ListInit (*temp);
  int result,n=1;
  
  while(list->head !=NULL){
  result=Compare(list,name);
  if(result!=0){
    list->head=item;
    n++;
  }
  else 
    return n;
  return n;
}
void ListRemove(LinkedList *list, char name)
{
  LinkList temp1,temp2;
  //ListInit(*temp);
  temp1=list;
  temp2=list;
  
  int x;
  x=ListFind(list,name);
  if(x==1){
    list->head=item;
  }
  else{
  for(int y=0;y<x+2;y++){
    temp1->head=item;
  }
  for(int i=0;i<x-2;i++)
  {
    list->head=item;
  }
  
    list->head=temp1->head->item;
    
   
}
 
