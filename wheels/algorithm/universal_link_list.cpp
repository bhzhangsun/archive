#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "universal_link_list.h"


void destroy_list(void *head)
{
	void *temp = NULL;
	while (NULL != head)
	{
		temp = *(void **)head;
		free(head);
		head = temp;
	}
}

bool is_empty(void *head)
{
	return head;
}

int list_lenth(void *head)
{
	int count = 0;
	while (NULL != head)
	{
		count++;
	}
	return count;
}



void insert_head(void **head, void **src)
{
	assert(NULL != head && NULL != src);
	void *temp = src;
	*src = *head;
	*head = temp;

}

void insert_tail(void **head, void **src) 
{
	assert(NULL != head && NULL != src);

	void *cur = head;

	while (NULL != *(void **)cur)    
	{
		cur = *(void **)cur;
	}
	*src = NULL;
	*(void **)cur = *src;

}

//void *find_node(void **head, void *arg, bool(*match)(void const *dst, void const *src))
//{
//	assert(NULL != head && NULL != match);
//
//	void *cur = head;
//	while (NULL != *(void **)cur)
//	{
//
//	}
//	return NULL;
//}

void delete_node(void **head, void *dst)
{
	void *temp = NULL;
	void *cur = head;
	while (NULL != cur)
	{
		if (dst == cur)
		{
			cur = *(void **)dst;
			free(dst);
			return;
		}		
	}
}

void replace_data(void **head, void *dst, void **src)
{
	assert(NULL != head && NULL != dst && NULL != src);

	void *cur = head;

	while (NULL != cur)    
	{
		if (dst == cur)
		{
			*src = *(void **)dst;
			cur = *src;
			free(dst);
		}
		cur = *(void **)cur;
	}
		
}

void sort_list(void **head, int(*cmp)(void const *src, void const *dst))
{
	assert(NULL != head && NULL != cmp);
	
	void *ibef = head;	
	for (void *icur = head; NULL != icur; icur = *(void **)icur)
	{
		void *jbef = icur;
		void *kcur = icur;
		void *kbef = jbef;
		for (void *jcur = *(void **)icur; NULL != jcur; jcur = *(void **)jcur)
		{ 
			
			if (0 < cmp(kcur, jcur))
			{
				kcur = jcur;
				kbef = jbef;
				jbef = jcur;				
			}
		} 
		ibef = &kcur;
		kbef = &icur;
		void *temp = icur;
		icur = kcur;
		kcur = temp;
		ibef = icur;	
	}
}