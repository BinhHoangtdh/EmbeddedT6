/*
* File: LinkedList.h
* Author: Binh Hoang
* Date: 08/07/2023
* Description: This file contains all the functions prototypes 
*              for the linked list.
*/

#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node
{
    int data; 
    struct node *next; 
} NODE;

NODE *CreateNode(int value);
void push_front(NODE **head, int value);
void push_back(NODE **head, int value);
int get_value(NODE *head, int index);
void insert(NODE **head, int value, int index);
void pop_front(NODE **head);
void pop_back(NODE **head);
void erase(NODE **head, int index);
int size(NODE *head);
void print(NODE *head);

#endif
