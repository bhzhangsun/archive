#ifndef _UNIVERSAL_LINK_LIST_H_
#define _UNIVERSAL_LINK_LIST_H_


/**
typedef struct _list_node /
{
	void *next;
	...
}_node;
*/
void destroy_list(void *head);

bool is_empty(void *head);

int list_lenth(void *head);

void insert_head(void **head, void **src);

void insert_tail(void **head, void **src);

//void *find_node(void **head, void *arg, bool (*match)(void const *dst, void const *src));

void delete_node(void **head, void *dst);

void replace_data(void **head, void *dst, void **src);

void sort_list(void *head, int (*cmp)(void const *src, void const *dst));
#endif
