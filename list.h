#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct listitem {
	void *item;
	struct listitem *next;
} t_listitem;

typedef struct list {
	t_listitem *listitem;
} t_list;

typedef struct iterator {
	t_list *list;
	t_listitem *curr;
} t_iterator;


t_list *list_ctor(void);
void list_dtor(t_list *);
void list_add(t_list *, void *);
void list_addint(t_list *, int);
void *list_getnext(t_iterator *);
t_iterator *list_getiterator(t_list *);
size_t list_getsize(t_list *list);
void *list_getelementat(t_list *, int);
void *list_first(t_list *);
void *list_last(t_list *);
#endif