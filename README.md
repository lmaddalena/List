Ansi C Generic List
====================================================================

Ansi C implementation of a generic linked list.

## Type Definitions
'''C
typedef struct list {
	t_listitem *listitem;
} t_list;
'''
'''C
typedef struct listitem {
	void *item;
	struct listitem *next;
} t_listitem
'''
'''C
typedef struct iterator {
	t_list *list;
	t_listitem *curr;
} t_iterator;
'''

## License

The code is available under the [MIT license](LICENSE.txt).