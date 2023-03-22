#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <math.h>
#include <malloc.h>

#define DATA int
#define nodeinit node=GetFirstNode(node) 
#define NULL 0
#define TRUE 
#define FALSE

GetAmountElements() ; 
struct LinkedListNode* GetLastNode(struct LinkedListNode* node) ; 
struct LinkedListNode* GetFirstNode(struct LinkedListNode* node) ;
struct LinkedListNode* CreateLinkedList(struct LinkedListNode *node) ; 
struct LinkedListNode* AppendNode(struct LinkedListNode* node, struct LinkedListNode* Data) ;
struct LinkedListNode* GetNthNode(struct LinkedListNode *node, int ElementNumber) ; 
struct LinkedListNode* InsertNode(int InsertPosition, struct LinkedListNode *node, struct LinkedListNode *data)  ;
struct LinkedListNode* FindData(struct LinkedListNode *node, int data_val) ;
struct LinkedListNode Sort_list_ascend(struct LinkedListNode *node) ;
void *InvertList (struct LinkedListNode *node) ;
struct LinkedListNode LinkedList ;
int Sort_list_ascend_efficient(struct LinkedListNode *node) ;;
int primechk(int number) ;
struct LinkedListNode* AppendNode(struct LinkedListNode* node, struct LinkedListNode* Data) ;
struct CircularLinkedListNode* CreateCircularLinkedList(struct CircularLinkedListNode *node) ;
struct LinkedListNode* Copy_Nodes(struct LinkedListNode *src, struct LinkedListNode *dest) ;
struct LinkedListNode *Duplicate_list(struct LinkedListNode *node) ;
struct LinkedListNode* Concatenate_lists(struct LinkedListNode *list_1, struct LinkedListNode *list_2) ;
int Interchange_nodes(struct LinkedListNode *Interchange_Node_1, struct LinkedListNode *Interchange_Node_2)  ; 
void *InvertList (struct LinkedListNode *node) ;

struct LinkedListNode
{
	struct LinkedListNode *next ; 
	struct LinkedListNode *prev ; 
	int data ;
} ;

struct LinkedStackNode
{
	struct LinkedStackNode *next ;
	struct LinkedStackNode *prev ;
	int data ;
} ; 

struct CircularLinkedListNode
{
	struct CircularLinkedList *next ; 
	struct CircularLinkedList *prev ; 
	int data ; 
} ;

int main() 
{	
	struct LinkedListNode s ; 
	struct LinkedListNode *p = NULL ; 
	struct LinkedListNode *list = NULL ; 
	int i = 0 ; 
	
	s.data = 10 ; 
	list = CreateLinkedList(&s) ; 


	s.data = 11 ;
	p = AppendNode(list,&s) ;
	s.data = 17 ;
	p = AppendNode(list,&s) ;
	s.data = 13 ;	
	p = AppendNode(list,&s) ;
	s.data = 14 ;	
	p = AppendNode(list,&s) ;
	s.data = 15 ;	
	p = AppendNode(list,&s) ;
	
	p = GetNthNode(list,4) ;
	
	printf("The data is %d \n\n", p->data) ; 
	
	p = list ; 
	
	printf("The data is : ") ; 
	
	while (p != NULL)
	{
		printf("%d, ", p->data) ; 
		p = p -> next ; 
	}
	
	printf("\n\n") ; 
	
	s.data = 255 ;
	p = InsertNode(3,list,&s) ; 
	p = list ; 
	
	printf("The data after inserting is : ") ; 
	
	while (p != NULL)
	{
		printf("%d, ", p->data) ; 
		p = p -> next ; 
	}
	
	printf("\n\n") ; 
	
	DeleteNode(list,3) ; 
	p = list ; 
	
	printf("\n\nThe data after deleting is : ") ; 

	while (p != NULL)
	{
		printf("%d, ", p->data) ; 
		p = p -> next ; 
	}
	
	GetNthNode(list,2) -> data = 78 ; 
	
	printf("\nData : %d",FindData(list,78) -> data) ;
	printf("\n\n") ;
	printf("The data before sorting is : ") ; 
	p = list ;
	
	while (p != NULL)
	{
		printf("%d, ", p->data) ; 
		p = p -> next ; 
	}
	
	printf("\n\n") ;
	Sort_list_ascend_efficient(list) ; 
	printf("The data after sorting is : ") ; 
	p = list ;
	
	while (p != NULL)
	{
		printf("%d, ", p->data) ; 
		p = p -> next ; 
	}
	
	/*printf("\n\n") ;
	printf("The data before reversing is : ") ; 
	p = list ;
	
	while (p != NULL)
	{
		printf("%d, ", p->data) ; 
		p = p -> next ; 
	}
	
	printf("\n\n") ;
	InvertList(list) ;
	printf("The data after reversing is : ") ; 
	p = list ;
	
	while (p != NULL)
	{
		printf("%d, ", p->data) ; 
		p = p -> next ; 
	}*/
}

void CopyData(struct LinkedListNode *src, struct LinkedListNode *dest)
{
	dest -> data = src -> data ; 
}

short LinkedListCheck(struct LinkedListNode *node) 
{
	if (node == NULL)
	{
		return 0 ; 
	}
	
	else
	{
		return 1 ; 
	}
}

struct LinkedListNode *CreateLinkedList(struct LinkedListNode *node)
{
	struct LinkedListNode *ReturnPtr = NULL ; 
	
	ReturnPtr = (struct LinkedListNode *) malloc(sizeof(struct LinkedListNode)) ;
	
	if (ReturnPtr != NULL)
	{
		ReturnPtr -> next = NULL ; 
		ReturnPtr -> prev = NULL ; 
		CopyData(node, ReturnPtr) ;
	}
	
	return ReturnPtr ; 
}

struct LinkedListNode *CreateLinkedListOfNode(int node_num)
{
	struct LinkedListNode *ReturnPtr = NULL ; 

	if (node_num == 0)
	{
		return ReturnPtr ; 
	}
	
	ReturnPtr = (struct LinkedListNode *) malloc(sizeof(struct LinkedListNode) * node_num) ;
	ReturnPtr = GetFirstNode(ReturnPtr) ; 
	
	return ReturnPtr ; 
}

struct LinkedListNode* GetFirstNode(struct LinkedListNode* node)
{
	while ((node -> prev) != NULL)
	{
		node = node -> prev ;
	}
	
	return node ; 
}

struct LinkedListNode* GetLastNode(struct LinkedListNode* node)
{
	while ((node -> next) != NULL)
	{
		node = node -> next ;
	}
	
	return node ; 
}

struct LinkedListNode* AppendNode(struct LinkedListNode* node, struct LinkedListNode* Data)
{
	struct LinkedListNode * ReturnPtr = NULL ; 
	
	node = GetLastNode(node) ; 
	
	ReturnPtr = (struct LinkedListNode *) malloc(sizeof(struct LinkedListNode)) ;
	
	if (ReturnPtr != NULL)
	{
		node -> next = ReturnPtr ; 
		ReturnPtr -> prev = node ; 
		ReturnPtr -> next = NULL ;
		CopyData(Data, ReturnPtr) ;
	}
	
	return ReturnPtr ; 
}  

struct LinkedListNode* GetNthNode(struct LinkedListNode *node, int ElementNumber)
{
	struct LinkedListNode *FirstElement ; 
	int i = 0 ; 
	
	FirstElement = GetFirstNode(node) ; 
	
	/* 
	by the end of this loop, the variable firstele will point to the address of the  first element of the link list
	*/
	
	for (i = 0 ; i < ElementNumber ; i++)
	{
		if ((FirstElement -> next) != NULL)
		{	
			FirstElement = FirstElement -> next ;
		}
		
		else
		{
			FirstElement = NULL ; 
			break ;
		}
	}
	
	return FirstElement ; 
} 

struct LinkedListNode* InsertNode(int InsertPosition, struct LinkedListNode *node, struct LinkedListNode *data) 
{
	struct LinkedListNode * ReturnPtr = NULL ;
	
	node = GetNthNode(node, InsertPosition) ;
	
	if (node != NULL)
	{
		ReturnPtr = (struct LinkedListNode *) malloc(sizeof(struct LinkedListNode)) ;
		
		if (ReturnPtr != NULL) 
		{
			ReturnPtr -> prev = node ;
			ReturnPtr -> next = node -> next ; 
			node -> next = ReturnPtr ; 
			ReturnPtr -> next -> prev = ReturnPtr ;
			CopyData(data,ReturnPtr) ;
		}
		
		else
		{
			node = NULL ; 
		}
	}
	
	return node ; 
}

int DeleteNode (struct LinkedListNode *node, int DeletePos) 
{
	int nReturnVal = 0 ;
	struct LinkedListNode * ReturnPtr = NULL ;
	struct LinkedListNode *Prev = NULL ; 
	struct LinkedListNode *Next = NULL ; 
	
	ReturnPtr = GetNthNode(node,DeletePos) ;
	
	
	if (ReturnPtr != NULL)
	{
		if(Prev == NULL)
		{
			Next -> prev == NULL ;
			//free (ReturnPtr) ;
		}
		
		if(Next == NULL)
		{
			Prev -> next == NULL ;
			//free (ReturnPtr) ;
		}
		
		else
		{
			Prev = ReturnPtr -> prev ;
			Next = ReturnPtr -> next ; 
			
			Prev -> next = Next ;
			Next -> prev = Prev ; 
			
			free (ReturnPtr) ;
			
			nReturnVal = 1 	;
		}
	}
	
	return nReturnVal ; 
}

struct LinkedListNode *FindData(struct LinkedListNode *node, int data_val)
{
	struct LinkedListNode *ReturnPtr = NULL ; 
	node = GetFirstNode(node) ; 
	
	do
	{
		if(node -> data == data_val)
		{
			ReturnPtr = node ; 
		}
		
		node = node -> next ; 
	}
	
	while (node -> next != NULL) ; 
	
	return ReturnPtr ;
} 

int GetAmountElements (struct LinkedListNode *node)
{
	int count = 0 ;
	node = GetFirstNode(node) ; 
	
	do
	{
		node = node -> next ; 
		count ++ ;
	}
	
	while (node -> next != NULL) ; 
	
	return count ; 
}

int DeleteLinkedList (struct LinkedListNode *node)
{
	int condition = GetAmountElements(node) ; 
	int i ; 
	
	for (i = 0 ; i < condition ; i++)
	{
		free(GetNthNode(node,i)) ; 
	}
	
	return 1 ; 
}

short Interchange (struct LinkedListNode *src, struct LinkedListNode *dest)
{
	int data ; 
	short return_val = 0 ; 
	
	if(src != NULL && dest != NULL)
	{
		data = src -> data ;
		src -> data = dest -> data ; 
		dest -> data = data ;
		return_val = 1 ; 
	}
	
	return return_val ; 
}

struct LinkedListNode Sort_list_ascend(struct LinkedListNode *node)
{
	/*
	1. Get the size of the linked list //Done
	2. Use the same i and j as indexes
	3. Use node -> next to get the pointer 
	4. Create a function to interchange(*src, *dest) //Done
	*/
		
	struct LinkedListNode *ptr ; 
	struct LinkedListNode *ptr1 ; 
	int temp ;
	
	/*Insert data elements here*/
	
	ptr = node ;
	
	while(node -> next != NULL)
	{
		ptr1 = ptr -> next ; 
		
		while (ptr1 != NULL)
		{
			
	/*
	TODO : Make this into a function like Interchange
	*/
			
			if (ptr -> data < ptr1 -> data)
			{
				temp = ptr -> data ; 
				ptr -> data = ptr1 -> data ; 
				ptr1 -> data = temp ;
			}
			
			ptr = ptr1 ;
			ptr1 = ptr -> next ;
		}
	}
	
}

int Sort_list_ascend_efficient(struct LinkedListNode *node) 
{
	int node_num ; 
	int data_holder ; 
	struct LinkedListNode *ptr ;  
	struct LinkedListNode *ptr1 ;
	
	nodeinit ; 
	node_num = GetAmountElements(node) ;
	ptr = node ; 
	ptr1 = node -> next ; 
	
	for(int i = 0 ; i < node_num ; i++)
	{
		for(int j = 0 ; j < (node_num - i + 1) ; j++)
		{
			if(ptr -> data > ptr1 -> data)
			{	
				Interchange_nodes(ptr,ptr1) ;
			}
			
			if (ptr1 -> next != NULL)
			{
				ptr = ptr -> next ;
				ptr1 = ptr1 -> next ;
			}
			
			else
			{
				break ;
			}
		}
	}
	
	return 1 ; 
}

int Find_Special(struct LinkedListNode *node, short find_type)
{
	/*
	 * 1 : Greatest
	 * 2 : Lessest 
	 * 3 : Greatest even and odd
	 * 4 : lessest even and odd
	*/
	
	short illegal_chk = 6 ; 
	
	if (find_type > illegal_chk)
 	{
		return 0 ; 
	}
	
	else if (find_type == 0)
	{
		return 0 ; 
	}
	
	else
	{
		if (find_type == 1)
		{
			
		}
	}
}

struct LinkedListNode* Find_Special_Greatest(struct LinkedListNode *node) 
{
	struct LinkedListNode *ptr ;
	struct LinkedListNode *Return_ptr ;
	
	if (node -> next == NULL)
	{
		Return_ptr = node ; 
	}
	
	while (node -> next != NULL)
	{
		ptr = node -> next ;
		
		if (node -> data > ptr -> data)
		{
			Return_ptr = node ; 
		}
		
		else if (ptr -> data > node -> data)
		{
			Return_ptr = ptr ;
		}
		
		else if (ptr -> data == node -> data)
		{
			Return_ptr = ptr ;
		}
				
		node = node -> next ;
	}
	
	return Return_ptr ;
}

struct LinkedListNode* Find_Special_Lessest(struct LinkedListNode *node) 
{
	struct LinkedListNode *ptr ;
	struct LinkedListNode *Return_ptr ;
	
	if (node -> next == NULL)
	{
		Return_ptr = node ; 
	}
	
	while (node -> next != NULL)
	{
		ptr = node -> next ;
		
		if (node -> data < ptr -> data)
		{
			Return_ptr = node ; 
		}
		
		else if (ptr -> data < node -> data)
		{
			Return_ptr = ptr ;
		}
		
		else if (ptr -> data == node -> data)
		{
			Return_ptr = ptr ;
		}
				
		node = node -> next ;
	}
	
	return Return_ptr ;
}

struct LinkedListNode* Find_Special_Greatest_even(struct LinkedListNode *node) 
{
	struct LinkedListNode *ptr ;
	struct LinkedListNode *Return_ptr ;
	
	if (node -> next == NULL)
	{
		Return_ptr = node ; 
	}
	
	while (node -> next != NULL)
	{
		ptr = node -> next ;
		
		if (node -> data > ptr -> data && node -> data % 2 == 0)
		{
			Return_ptr = node ; 
		}
		
		else if (ptr -> data > node -> data && ptr -> data % 2 == 0)
		{
			Return_ptr = ptr ;
		}
		
		else if (ptr -> data == node -> data && ptr -> data % 2 == 0)
		{
			Return_ptr = ptr ;
		}
		
		else
		{
			Return_ptr = NULL ; 
		}
				
		node = node -> next ;
	}
	
	return Return_ptr ;
}

struct LinkedListNode* Find_Special_Greatest_odd(struct LinkedListNode *node) 
{
	struct LinkedListNode *ptr ;
	struct LinkedListNode *Return_ptr ;
	
	if (node -> next == NULL)
	{
		Return_ptr = node ; 
	}
	
	while (node -> next != NULL)
	{
		ptr = node -> next ;
		
		if (node -> data > ptr -> data && node -> data % 2 != 0)
		{
			Return_ptr = node ; 
		}
		
		else if (ptr -> data > node -> data && ptr -> data % 2 != 0)
		{
			Return_ptr = ptr ;
		}
		
		else if (ptr -> data == node -> data && ptr -> data % 2 != 0)
		{
			Return_ptr = ptr ;
		}
		
		else
		{
			Return_ptr = NULL ; 
		}
				
		node = node -> next ;
	}
	
	return Return_ptr ;
}

struct LinkedListNode* Find_Special_Lessest_even(struct LinkedListNode *node) 
{
	struct LinkedListNode *ptr ;
	struct LinkedListNode *Return_ptr ;
	
	if (node -> next == NULL)
	{
		Return_ptr = node ; 
	}
	
	while (node -> next != NULL)
	{
		ptr = node -> next ;
		
		if (node -> data < ptr -> data && node -> data % 2 == 0)
		{
			Return_ptr = node ; 
		}
		
		else if (ptr -> data < node -> data && ptr -> data % 2 == 0)
		{
			Return_ptr = ptr ;
		}
		
		else if (ptr -> data == node -> data && ptr -> data % 2 == 0)
		{
			Return_ptr = ptr ;
		}
		
		else
		{
			Return_ptr = NULL ; 
		}
				
		node = node -> next ;
	}
	
	return Return_ptr ;
}

struct LinkedListNode* Find_Special_Lessest_odd(struct LinkedListNode *node) 
{
	struct LinkedListNode *ptr ;
	struct LinkedListNode *Return_ptr ;
	
	if (node -> next == NULL)
	{
		Return_ptr = node ; 
	}
	
	while (node -> next != NULL)
	{
		ptr = node -> next ;
		
		if (node -> data < ptr -> data && node -> data % 2 != 0)
		{
			Return_ptr = node ; 
		}
		
		else if (ptr -> data < node -> data && ptr -> data % 2 != 0)
		{
			Return_ptr = ptr ;
		}
		
		else if (ptr -> data == node -> data && ptr -> data % 2 != 0)
		{
			Return_ptr = ptr ;
		}
		
		else
		{
			Return_ptr = NULL ; 
		}
				
		node = node -> next ;
	}
	
	return Return_ptr ;
}

int Interchange_nodes(struct LinkedListNode *Interchange_Node_1, struct LinkedListNode *Interchange_Node_2) 
{
	struct LinkedListNode *ptr ; 
	struct LinkedListNode *ptr1 ;
	
	if (Interchange_Node_1 == NULL)
	{
		return 0 ; 
	}
	
	else if (Interchange_Node_2 == NULL) 
	{
		return 0 ; 
	}
		
	else
	{
		ptr = Interchange_Node_1 -> next ; 
		ptr1 = Interchange_Node_1 -> prev ; 
		Interchange_Node_1 -> next = Interchange_Node_2 -> next ;
		Interchange_Node_1 -> prev = Interchange_Node_2 -> prev ; 
		Interchange_Node_2 -> next = ptr ;
		Interchange_Node_2 -> prev = ptr1 ;
	}
	
	return 1 ; 
}

void *InvertList (struct LinkedListNode *node)
{
	int n = GetAmountElements(node) ; 
	struct LinkedListNode *node_last ; 
	struct LinkedListNode *node_first ;
	
	node_first = GetFirstNode(node) ;  
	node_last = GetLastNode(node) ; 
	
	for (int i = 0 ; i < n/2 ; i++)
	{
		Interchange_nodes(node_first,node_last) ;
		node_first = node_first -> next ; 
		node_last = node_last -> prev ; 
	}
}

struct LinkedListNode* Concatenate_lists(struct LinkedListNode *list_1, struct LinkedListNode *list_2)
{
	struct LinkedListNode *list_3 ; 
	struct LinkedListNode *list_4 ;	
	int list_1_no ; 
	int list_2_no ; 
	
	list_1_no = GetAmountElements(list_1) ; // Initialise the amount of elements to int list_1_no
	list_2_no = GetAmountElements(list_2) ;
	list_3 = CreateLinkedListOfNode(list_3,list_1_no) ; // Create the two linked lists 
	list_4 = CreateLinkedListOfNode(list_4,list_2_no) ; 
	list_3 = list_1 ; // Initialise the data to both the linkedlist
	list_4 = list_2 ; 
	GetLastNode(list_3) -> next = GetFirstNode(list_4) ; // Append both the linkedlists
	GetFirstNode(list_4) -> prev = GetLastNode(list_3) ; 
}    

struct LinkedListNode *Duplicate_list(struct LinkedListNode *node)
{
	struct LinkedListNode *NewNode = NULL ; 
	int node_num ;
	
	node_num = GetAmountElements(node) ; 
	NewNode = CreateLinkedListOfNode(NewNode,node_num) ; 
	NewNode = node ; 
	
	return NewNode ; 
} 

struct LinkedListNode* Copy_Nodes(struct LinkedListNode *src, struct LinkedListNode *dest)
{
	dest = src ; 
	
	return dest ; 
} 

/// Linked Stacks 

struct LinkedStackNode *Stack_Create_List() 
{
	struct LinkedStackNode *ReturnPtr ; 
	
	ReturnPtr = malloc((int) sizeof(struct LinkedStackNode)) ;
	
	return ReturnPtr ;
} 

struct LinkedStackNode *Stack_Push(struct LinkedStackNode *lstack_ptr, int data) 
{
	struct stack *NewNode
	
	NewNode = malloc((int) sizeof(struct LinkedStackNode)) ;
	lstack_ptr = Stack_GetFirstNode(lstack_ptr) ; 
	NewNode -> next = lstack_ptr ; 
	NewNode -> prev = NULL ; 
	lstack_ptr -> prev = NewNode ; 
	NewNode -> data = data ;
	
	return NewNode ; 
}

struct LinkedStackNode *Stack_Pop(struct LinkedStackNode *lstack_ptr) 
{
	struct stack *dealloc_ptr ;
	
	lstack_ptr = Stack_GetFirstNode(lstack_ptr) ;
	dealloc_ptr = lstack_ptr ; 
	lstack_ptr = lstack_ptr -> next ;
	lstack_ptr -> prev = NULL ; 
	free(dealloc_ptr) ; 
}

struct LinkedStackNode *Stack_GetFirstNode(struct LinkedStackNode *lstack_ptr_) 
{
	while (lstack_ptr_ -> prev != NULL)
	{
		lstack_ptr_ = lstack_ptr_ -> prev ; 
	}
	
	return lstack_ptr_ ; 
} 

struct LinkedStackNode *Stack_GetLastNode(struct LinkedStackNode *lstack_ptr_) 
{
	while (lstack_ptr_ -> prev != NULL)
	{
		lstack_ptr_ = lstack_ptr_ -> prev ; 
	}
	
	return lstack_ptr_ ; 
} 

struct LinkedStackNode *Stack_ChkSpace(struct stack *lstack_ptr) 
{
	struct stack *ReturnPtr = NULL ; 
	
	lstack_ptr = GetFirstNode(lstack_ptr) ; 
	
	while (lstack_ptr -> next != NULL)
	{
		if (lstack_ptr -> data == 0)
		{
			ReturnPtr = lstack_ptr ; 
			
			break ; 
		}
		
		lstack_ptr = lstack_ptr -> next ;
	}
	
	return ReturnPtr ; 
}

struct LinkedStackNode *Stack_GetNode_B(struct stack *lstack_ptr, int element_number) 
{
	
}

struct LinkedStackNode *Stack_GetNode_F(struct stack *lstack_ptr, int element_number) 
{
	
}
//DONE
// Circular Linked List Functions 
/*
struct CircularLinkedListNode* CreateCircularLinkedList(struct CircularLinkedListNode *node) 
{
	struct CircularLinkedListNode *ReturnPtr = NULL ; 
	
	ReturnPtr = (struct CircularLinkedListNode *) malloc(sizeof(struct CircularLinkedListNode)) ;
	
	if (ReturnPtr != NULL)
	{
		ReturnPtr -> next = ReturnPtr ; 
		ReturnPtr -> prev = NULL ; 
		CopyData(node, ReturnPtr) ;
	}
	
	return ReturnPtr ; 
}

struct CircularLinkedListNode* AppendNode(struct CircularLinkedListNode* node, struct CircularLinkedListNode* Data)
{
	struct LinkedListNode * ReturnPtr = NULL ; 
	
	node = GetLastNode(node) ; 
	
	ReturnPtr = (struct CircularLinkedListNode *) malloc(sizeof(struct CircularLinkedListNode)) ;
	
	if (ReturnPtr != NULL)
	{
		node -> next = ReturnPtr ; 
		ReturnPtr -> prev = node ; 
		ReturnPtr -> next = node ;
		CopyData(Data, ReturnPtr) ;
	}
	
	return ReturnPtr ; 
}*/
