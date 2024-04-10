#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 8
#define ready 0
#define running 1
#define finished 2

typedef struct process p_t;

struct process {
	char pid[max_len+1];
	int time_arr;
	int time_rem;
	int memory;
	int state;
	p_t* next;
};

typedef struct {
	p_t* head;
	p_t* foot;
}list_t;

list_t* make_empty_list() {
	list_t* list = malloc(sizeof(list_t));
	assert(list != NULL);
	list->head = NULL;
	list->foot = NULL;
	return list;
}

list_t* insert_foot(list_t* list, p_t* new_p) {
	if (list->head == NULL) {
		list->head = new_p;
		list->foot = new_p;
	}
	else {
		list->foot->next = new_p;
		list->foot = new_p;
	}
	return list;
};

p_t* create_process(char* pid, int time_arr, int time_rem, int memory) {
	p_t* new_p = malloc(sizeof(p_t));
	new_p->time_arr = time_arr;
	new_p->time_rem = time_rem;
	new_p->memory = memory;
	strcpy(new_p->pid, pid);
	new_p->state = ready;
	new_p->next = NULL;
	return new_p;
};

