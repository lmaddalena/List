#include <stdio.h>
#include <stdlib.h>
#include "list.h"



int main(int argc, char **argv){
    
    // list of strings
    printf("List of strings:\n");
    printf("================\n");
    
    t_list *list = list_ctor();
    list_add(list, "Alfa");
    list_add(list, "Beta");
    list_add(list, "Gamma");
    
    char s[] = "Delta";    
    list_add(list, s);
       
    // iteration
    char *item;
    t_iterator *iter = list_getiterator(list);       
   	while ((item = (char*)list_getnext(iter)) != NULL)
	{
		printf("%s\n", item);
	}
    printf("\n");
    printf("first: %s\n", list_first(list));
    printf("last: %s\n", list_last(list));
    printf("element at [1]: %s\n\n", list_getelementat(list, 1));

    // list of int
    printf("List of integers:\n");
    printf("================\n");
     
    t_list *intlist = list_ctor();
    int k = 0;
    for(k = 1; k <= 10; k++)
    {
        list_addint(intlist, k);
    }
    
    // iteration
    int *i = NULL;
    iter = list_getiterator(intlist);       
   	while ((i = (int*)list_getnext(iter)) != NULL)
	{
		printf("%i\n", *i);
	}
    
    list_dtor(list);
    list_dtor(intlist);
    
    printf("\nPresse [ENTER] to quit\n");
    getchar();
    
    return 0;
}