/*
* File: binarySearch_LinkedList.h
* Author: Binh Hoang
* Date: 10/07/2023
* Description: This file contains all the functions prototypes 
*              for the binary search by use linked list.
*/

#ifndef __BINARYSEARCH_LINKEDLIST_H
#define __BINARYSEARCH_LINKEDLIST_H
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct CenterPoint {
    int value;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;

void add_node(Node **head, int value);
CenterPoint *buildTree(Node *head, int start, int end);
CenterPoint *centerPoint(Node *head);
CenterPoint *binarySearch(CenterPoint *root, int value);
void print_list(Node *head);

#endif
