#ifndef __LIST_H__
#define __LIST_H__

// Define a structure for linked list elements.

typedef struct ListElmt_ {
	void *data;
	struct ListElmt_ *next;
} ListElmt;


// Define a structure for linked lists.

typedef struct List_ {
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	ListElmt *head;
	ListElmt *tail;
} List;

// interface for linked lists
/*****************************************************************************
* *
* --------------------------- Public Interface --------------------------- *
* *
*****************************************************************************/

// Initializes the linked list specified by list.
void list_init(List *list, void (*destroy)(void *data));

// Destroys the linked list specified by list.
void list_destroy(List *list);

// Inserts an element just after element in the linked list specified by list.
int list_ins_next(List *list, ListElmt *element, const void *data);

// Removes the element just after element from the linked list specified
// by list. If element is NULL, the element at the head of the list is removed.
int list_rem_next(List *list, ListElmt *element, void **data);

// Number of elements in the list.
int list_size(List *list);

// Element at the head of the list.
ListElmt *list_head(const List *list);

// Element at the tail of the list.
ListElmt *list_tail(const List *list);

// 1 if the element is at the head of the list, or 0 otherwise.
int list_is_head(List *list);

// 1 if the element is at the tail of the list, or 0 otherwise.
int list_is_tail(List *list);

// data stored in the element
void *list_data(const ListElmt *element);

// element following the specified element
ListElmt *list_next(const ListElmt *element);

// nasledujuce su definovane ako makra - ja si ich spravim ako funkcie
//#define list_size(list) ((list)->size)
//#define list_head(list) ((list)->head)
//#define list_tail(list) ((list)->tail)
//#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
//#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
//#define list_data(element) ((element)->data)
//#define list_next(element) ((element)->next)

#endif
