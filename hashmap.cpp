#include<stdlib.h>
#include<stdio.h>
#include<map>
#define max 12

struct element
{
	int key;
	int value;
	int hash;
};

struct node
{
	element* data;
	node* next;
};

struct hashmap
{
	int size;
	int length;
	node* head;
};

int gethashnum(int key)
{
	return key % max;
}

hashmap* create_hash(int n)
{
	hashmap* h =(hashmap*)malloc(sizeof(hashmap));
	h->size = max;
	h->length = 0;
	h->head = (node*)malloc(sizeof(node) * h->size);
	for (int i = 0; i < h->size; i++)
	{
		h->head[i].next = NULL;
	}
	return h;
}

node* find_hash(hashmap* h,int key)
{
	int a = gethashnum(key);
	node* p = h->head[a].next;
	while (p && key != p->data->key)
	{
		p = p->next;
	}
	return p;
}

void hash_insert(hashmap* h, element a)
{
	node* p = find_hash(h, a.key);
	if (!p)
	{
		node* q = (node*)malloc(sizeof(node));
		q->data = (element*)malloc(sizeof(element));
		q->data->key = a.key;
		q->data->value = a.value;
		int hashcode = gethashnum(a.key);
		q->next = h->head[hashcode].next;
		h->head[hashcode].next = q;
		h->length++;
	}
	else
	{
		printf("该关键字已存在");
	}
}

void destroy_hash(hashmap* h)
{
	node* p, *q;
	for (int i = 0; i < h->size; i++)
	{
		p = h->head[i].next;
		while (p)
		{
			q = p->next;
			free(p);
			p = q;
		}
	}
	free(h->head);
	free(h);
}

void print_hash(hashmap* h)
{
	for (int i = 0; i < h->size; i++)
	{
		node* p = h->head[i].next;
		while (p)
		{
			printf("[%d : %d]", p->data->key, p->data->value);
			p = p->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	 //printf("hello");
	element a[] = {{12,1},{3,3},{31,3},{45,4},{8,5}};
	int n = 5;
	hashmap* h = create_hash(n);
	for (int i = 0; i < n; i++)
	{
		hash_insert(h,a[i]);
	}
	print_hash(h);
	printf("%d\n\n", h->length);
	destroy_hash(h);
	return 0;

}