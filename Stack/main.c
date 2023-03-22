#include <stdio.h>

//Globals 
int total_nodes ; 

struct stack *create_stack(int node_num) ;
void push_stack(struct stack *stackptr) ;
void display_stack(struct stack *stackptr, short new_line) ;
void pop_stack(struct stack *stackptr) ;
struct stack *get_stack_node(struct stack *stackptr, int node_num) ; 

struct stack
{
	int data ; 
} ; 

int main() 
{
	struct stack *ptr ; 
	int *array ; 
	int i ; 
	int l = 0 ; 
	
	ptr = create_stack(2) ;
	ptr[0].data = 1 ; 
	ptr[1].data = 2 ; 
	printf("Element 1 : %d\n",ptr[0].data) ;
	printf("Element 2 : %d\n",ptr[1].data) ; 
	array = malloc(sizeof(int) * 32) ;
	push_stack(ptr) ; 
	ptr[2].data = 3 ; 
	printf("Element after pushing (element 3) : %d\n\n",ptr[2].data) ;
	printf("\n\nReal location 1  = %d\n\n\n",&ptr[0]) ; 
	printf("\n\nReal location 2 = %d\n\n\n",&ptr[1]) ; 
	printf("\n\nReal location 3 = %d\n\n\n",&ptr[2]) ; 
		
	printf("\nObtaining element 1's location : ") ;
	i = get_stack_node(ptr,0) ; 
	printf("%d",i) ; 
	printf("\nObtaining element 2's location : ") ;
	i = get_stack_node(ptr,1) ; 
	printf("%d",i) ; 
	printf("\nObtaining element 3's location : ") ;
	i = get_stack_node(ptr,2) ; 
	printf("%d",i) ; 
}

struct stack *create_stack(int node_num)
{
	struct stack *ReturnPtr ; 
	
	ReturnPtr = malloc(sizeof(struct stack) * node_num) ; 
	total_nodes = node_num ; 
	
	return ReturnPtr ; 
}

void push_stack(struct stack *stackptr) 
{
	int realloc_size ; 
	struct stack *ReturnPtr ; 

	realloc_size = (total_nodes * sizeof(struct stack)) + sizeof(struct stack) ; 
	realloc(stackptr,realloc_size) ; 
	total_nodes = total_nodes + 1 ;
}

void pop_stack(struct stack *stackptr) 
{
	int realloc_size ; 
	struct stack *ReturnPtr ; 

	realloc_size = (total_nodes * sizeof(struct stack)) - sizeof(struct stack) ; 
	realloc(stackptr,realloc_size) ; 
	total_nodes = total_nodes - 1 ;
}

void display_stack(struct stack *stackptr, short new_line) 
{
	int i ; 
	
	for(i = 0 ; i < total_nodes ; i++)
	{
		///New data elements here
		printf("%d ",stackptr[i].data) ;
		
		if(new_line == 1) 
		{
			printf("\n") ; 
		}
		
		else
		{
			//Do absaloutely nothing
		}
	}
} 

struct stack *get_stack_node(struct stack *stackptr, int node_num)
{
	int element_number ;
	int temp ; 
	struct stack *ReturnPtr ; 
	
	temp = total_nodes - 1 ; 
	
	if(node_num > temp)
	{
		ReturnPtr = NULL ; 
	}
	
	else if (node_num < 0)
	{
		ReturnPtr = NULL ; 
	}
	
	else 
	{
		element_number = temp - node_num ; 
		ReturnPtr = &stackptr[element_number] ;
	}
	
	return ReturnPtr ; 
}