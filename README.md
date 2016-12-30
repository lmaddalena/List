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

## License

The code is available under the [MIT license](LICENSE.txt).