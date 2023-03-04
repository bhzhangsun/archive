#include <stdio.h>
#include <stdlib.h>
#include "list.h"


list list_init()
{
	lnode *lt = (lnode *)malloc(sizeof(lnode));
	lt->pnext = NULL;
	lt->data = 0;
	return lt;
}

static lnode *alloc_node()
{
	return (lnode *)malloc(sizeof(lnode));
}

static void free_node(lnode *nptr)
{
	free(nptr);
	nptr = NULL;
}

static int insert(list lt, int pos, v_type d)
{
	if(NULL == lt || pos < -1)
		return -1;

	lnode *curptr = lt;
	int i = 0;
	if(pos > -1)
		for(; NULL != curptr->pnext && i < pos; ++i)
			curptr = curptr->pnext;
	else
		while(NULL != curptr->pnext)
			curptr = curptr->pnext;

	lnode *tmptr = alloc_node();
	tmptr->data = d;
	tmptr->pnext = curptr->pnext;
	curptr->pnext = tmptr;
	return 0;
}

int push_front(list l, v_type d)
{
	return insert(l, 0, d);
}
int push_back(list l, v_type d)
{
	return insert(l, -1, d);
}

static int erase(list l, int pos)
{

	if(NULL == l || pos < -1)
		return -1;

	lnode *curptr = l;
	int i = 0;
	if(pos > -1)
		for(; NULL != curptr->pnext && i < pos; ++i)
			curptr = curptr->pnext;
	else
		while(NULL != curptr->pnext && NULL != curptr->pnext->pnext)
			curptr = curptr->pnext;

	lnode *tmptr = curptr->pnext;
	if(NULL == tmptr)
		return -1;
	curptr->pnext = tmptr->pnext;
	free_node(tmptr);
	return 0;
}

int pop_front(list l)
{
	return erase(l, 0);	
}
int pop_back(list l)
{
	return erase(l, -1);
}

void destroy(list l)
{
	while(-1 != pop_back(l));
	free_node(l);
	l = NULL;
}

void show(list l)
{
	lnode *curptr = l->pnext;
	while (NULL != curptr)
	{
		printf("%d\t", curptr->data);
		curptr = curptr->pnext;
	}
		
	printf("\n");
}

