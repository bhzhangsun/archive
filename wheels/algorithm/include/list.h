#ifndef _LIST_H_
#define _LIST_H_

typedef int v_type;

typedef struct link_node
{
	v_type data;
	struct link_node *pnext;
}lnode, *list;

list list_init();

int push_front(list l, v_type d);
int push_back(list l, v_type d);

int pop_front(list l);
int pop_back(list l);

void destroy(list l);

void show(list l);

#endif
