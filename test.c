#include "list.h"
#include <stdio.h>
//functions used:
//List_curr, List_next, List_count
//bug in here changes pCurrent Item to 0x1
static void display_List(List* pList){
    if(pList->numElements == 0){
        printf("List is Empty :( \n");
    }else{
        Node* oldCurrent = pList->pCurrentItem;
        pList->pCurrentItem = pList->pHead;
        printf("{");
        for(int i = 0; i < pList->numElements;i++){
            int item = *(int*)(List_curr(pList));
            printf("%d,",item);
            List_next(pList);
        }
        int numItems = List_count(pList);
        printf("}: has %d Items\n",numItems);
        pList->pCurrentItem = oldCurrent;

    }
}
static int getItem(List* l1){
    return *(int*)(List_curr(l1));
}
int main(){
    printf("Initialize Empty List's\n");   
    List* l1 = List_create();
    int x = 1;
    int y = 2;
    int z = 3;
    List_append(l1,&x);
    List_append(l1,&y);
    List_append(l1,&z);
    printf("\nTesting List_append, List_count, List_next, List_curr \n");
    display_List(l1);
    printf("\nTesting List_first, List_next\n");
    
    List_first(l1);
    int current = getItem(l1);
    printf("Current Item of l1 is %d \n",current);
    List_next(l1);
    current = getItem(l1);
    printf("Current Item of l1 is %d \n",current);
    List_next(l1);
    current = getItem(l1);
    printf("Current Item of l1 is %d \n",current);
    
    printf("\nTesting List_last, List_prev\n");
    List_last(l1);
     printf("Current Item of l1 is %d \n",current);
    List_prev(l1);
    current = getItem(l1);
    printf("Current Item of l1 is %d \n",current);
    List_prev(l1);
    current = getItem(l1);
    printf("Current Item of l1 is %d \n",current);

    printf("\nTesting insert after and before\n");
    List* l2 = List_create();
    List* l3 = List_create();
    int a = 1;
    int b = 2;
    int c = 3;
    List_insert_before(l2,&a);
    List_insert_before(l2,&b);
    List_insert_before(l2,&c);
    List_insert_after(l3,&a);
    List_insert_after(l3,&b);
    List_insert_after(l3,&c);
    display_List(l2);
    display_List(l3);
    printf("\nTesting prepend \n");
    List_prepend(l2,&a);
    List_prepend(l3,&a);
    display_List(l2);
    display_List(l3);
    
    printf("\nTesting remove at head\n");
    List_first(l2);
    List_first(l3);
    List_remove(l2);
    List_remove(l3);
    display_List(l2);
    display_List(l3);

    printf("\nTesting remove at mid\n");
    List_next(l2);
    List_next(l3);
    List_remove(l2);
    List_remove(l3);
    display_List(l2);
    display_List(l3);

    printf("\nTesting trim at tail\n");
    List_next(l2);
    List_next(l3);
    List_trim(l2);
    List_trim(l3);
    display_List(l2);
    display_List(l3);

    printf("\nTesting concat \n");
    List_concat(l2,l3);
    display_List(l2);
    List_concat(l1,l2);
    display_List(l1);
    
    

    
    
    
    
}