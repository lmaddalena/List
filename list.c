#include "list.h"
#include <stdlib.h>		// malloc, free


//
// costruttore
//
t_list *list_ctor(void){
	t_list *list = (t_list*)malloc(sizeof(t_list));
	list->listitem = NULL;
	return list;
}

//
// distruttore
//
void list_dtor(t_list *list) {

	t_listitem *p, *q;
	for (p = list->listitem; p != NULL; p = q){
		q = p->next;
		free(p);
	}

	free(list);
}

//
// aggiunge un elemento alla lista
//
void list_add(t_list *list, void *item)
{
	if (list == NULL || item == NULL)
		return;

	// crea l'elemento della lista
	t_listitem *litem = (t_listitem*)malloc(sizeof(t_listitem));
	litem->item = item;
	litem->next = NULL;

	if (list->listitem == NULL)
	{
		list->listitem = litem;
	}
	else
	{

		t_listitem *last = NULL;

		// si posiziona alla fine
		for (last = list->listitem; last->next != NULL; last = last->next)
			;

		// aggiunge l'elemento alla lista
		last->next = litem;
	}


};

void list_addint(t_list *list, int i) {
    
    int *p = (int*)malloc(sizeof(int));
    *p = i;
    list_add(list, p);
}

//
// crea l'iteratore per la lista specificata
//
t_iterator *list_getiterator(t_list *list) {

	t_iterator *iter = (t_iterator*)malloc(sizeof(t_iterator));

	iter->list = list;
	iter->curr = list->listitem;
	return iter;
}

//
// restituisce il successivo elemento della lista associata all'iteratore
//
void *list_getnext(t_iterator *iter) {

	if (iter->curr != NULL)
	{
		void *item = iter->curr->item;
		iter->curr = iter->curr->next;
		return item;
	}
	else
	{
		return NULL;
	}
} 

//
// Restituisce l'elemento alla posizione specificata
//
void *list_getelementat(t_list *list, int index)
{
	if (list == NULL || index < 0)
		return NULL;

	void *item = NULL;
    t_iterator *iter = list_getiterator(list);
    
	while (index-- >= 0)
		item = list_getnext(iter);

	return item;
}

//
// restituisce il numero di elementi presenti nella lista
//
size_t list_getsize(t_list *list){

	void *item = NULL;
	size_t c = 0;
    
    t_iterator *iter = list_getiterator(list);
   	while ((item = list_getnext(iter)) != NULL)
	{
		c++;
	}

	return c;
}

//
// restituisce il primo elemento della lista
//
void *list_first(t_list *list) {
    
    if(list->listitem != NULL)
        return list->listitem->item;
    else
        return NULL;
}

//
// restituisce l'ultimo elemento della lista
//
void *list_last(t_list *list) {
    
    if(list->listitem != NULL)
    {
        t_listitem *litem = NULL;
        
        for(litem = list->listitem; litem->next != NULL; litem = litem->next)
            ;
                    
        return litem->item;
        
    }
    else
        return NULL;
}