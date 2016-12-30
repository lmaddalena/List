Ansi C Generic List
====================================================================

Ansi C implementation of a generic linked list.

## Type Definitions
`t_list` represents the generic list.
```C
typedef struct list {
	t_listitem *listitem;
} t_list;
```
`t_listitem` is a list's element.
```C
typedef struct listitem {
	void *item;
	struct listitem *next;
} t_listitem
```

Use `t_iterator` to iterate the list's elements.
```C
typedef struct iterator {
	t_list *list;
	t_listitem *curr;
} t_iterator;
```
### API
```C
` List costructor
' Create the list
t_list *list_ctor(void);

' List distructor
' Destroy the list and the contained items (free the memory)
void list_dtor(t_list *);

' Add item
' Add a generic item to the list
void list_add(t_list *, void *);

' Add integer
' Add a integer to the list
void list_addint(t_list *, int);

' Get next
' It allows to iterate the list. Each call retrieve the next item if exists, NULL otherwise
void *list_getnext(t_iterator *);

' Get iterator
' Get the iterator for the specified list
t_iterator *list_getiterator(t_list *);

' Get size_t
' Get the size of the list
size_t list_getsize(t_list *list);

' Get element at
' Get the element at the specified position (0 based)
void *list_getelementat(t_list *, int);

' Fist
' Get the first element of the list
void *list_first(t_list *);

' Last
' Get the last element of the list
void *list_last(t_list *);
```

## License

The code is available under the [MIT license](LICENSE.txt).