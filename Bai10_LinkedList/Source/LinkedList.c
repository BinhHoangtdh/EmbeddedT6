/*
* File: LinkedList.c
* Author: Binh Hoang
* Date: 08/07/2023
* Description: This is a file writed for linked list
*/

#include "LinkedList.h"

/*
* Function: CreateNode()
* Description: This function is used to create a element or node in linked list.
* Input:
*   int value - Value is needed to insert
* Output:
*   returns a address of element.
*/
NODE *CreateNode(int value)
{
    NODE *temp; 
    temp = (NODE*)malloc(sizeof(NODE));
    temp->next = NULL;
    temp->data = value;
    return temp;
}

/*
* Function: push_front()
* Description: This function is used to adds a new element at the beginning of the list
* Input:
*   NODE **head - Pointer to poiter with data type is NODE - List to add new element
*   int value - Value is needed to insert
* Output:
*   returns a new element at the beginning of the list.
*/
void push_front(NODE **head, int value)
{
    NODE *temp = CreateNode(value);
    if(*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

/*
* Function: push_back()
* Description: This function is used to adds a new element at the end of the list
* Input:
*   NODE **head - Pointer to poiter with data type is NODE - List to add new element
*   int value - Value is needed to insert
* Output:
*   returns a new element at the end of the list.
*/
void push_back(NODE **head, int value)
{
    NODE *temp,*p;
    temp = CreateNode(value);
    if(*head == NULL){
        *head = temp;
    }
    else
    {
        p  = *head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

/*
* Function: get_value()
* Description: This function is used to get a value at the any position of the list
* Input:
*   NODE **head - Pointer with data type is NODE - List to get value
*   int index - Position to get value
* Output:
*   return p->data: returns the desired position.
*   return -1: Search result not found
*/
int get_value(NODE *head, int index)
{
    int i = 0;
    for(NODE *p = head; p != NULL; p = p->next)
    {
        if(i == index) return p->data;
        i++;
    }
    return -1;
}

/*
* Function: insert()
* Description: This function is used to inserts new elements 
*              in the list before the element at a specified position.
* Input:
*   NODE **head - Pointer to poiter with data type is NODE- List to insert
*   int value - Value is needed to insert
*   int index - Position to insert
* Output:
*   void: Not returns value.
*/
void insert(NODE **head, int value, int index)
{
   int i = 0;
   NODE *temp, *p_node;
   p_node = CreateNode(value);

    if(index == 0)
    {
        p_node->next = *head;
        *head = p_node;
    }
    else
    {
        for(NODE *p = *head; p != NULL; p = p->next)
        {
            if( i == index - 1)
            {
                temp = p->next;
                p->next = p_node;
                p->next->next = temp;
                break;  
            } 
            i++;  
        }
    }
}

/*
* Function: pop_front()
* Description: This function is used to removes the first element of the list
* Input:
*   NODE **head - Pointer to poiter with data type is NODE - List that contain element to remove
* Output:
*   returns the removed list  .
*/
void pop_front(NODE **head)
{
    NODE *temp;
    if(*head == NULL)
    {
        printf("Mang dang rong!\n");
    }
    else
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
    
}

/*
* Function: pop_back()
* Description: This function is used to removes the last element of the list
* Input:
*   NODE **head - Pointer to poiter with data type is NODE - List that contain element to remove
* Output:
*   returns the removed list.
*/
void pop_back(NODE **head)
{
    NODE *p, *temp;
    p = *head;

    if(*head == NULL|| (*head)->next == NULL) return pop_front(head);
    while(p->next->next != NULL)
    {
        p = p->next;
    }
    temp = p->next;
    p->next = p->next->next;
    
    free(temp);
}

/*
* Function: erase()
* Description: This function is used to removes the element at any position in list
* Input:
*   NODE **head - Pointer to poiter with data type is NODE - List that contain element to remove
*   int index - The position to remove
* Output:
*   returns the removed list.
*/
void erase(NODE **head, int index)
{
    int i = 0;
    NODE *temp;

    if(index == 0)
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
    else
    {
        for(NODE *p = *head; p != NULL; p = p->next)
            {
                if( i == index - 1)
                {
                    temp = p->next;
                    p->next = p->next->next;
                    free(temp);
                    break;  
                }
            }
    } 
}

/*
* Function: size()
* Description: This function is used to returns the number of elements in the list
* Input:
*   NODE *head - head pointer with data type is NODE - List to get value
* Output:
*    Returns the number of elements in the list.
*/
int size(NODE *head)
{
    int size = 0;
    for(NODE *p = head; p != NULL; p = p->next)
    {
        size++;
    }
    return size;
}

/*
* Function: print()
* Description: This function is used to print the element in the list
* Input:
*   NODE *head - head pointer with data type is NODE - List to print
* Output:
*   returns the value of the the elements in the list.
*/
void print(NODE *head)
{
    for(NODE *p = head; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
}
