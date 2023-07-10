/*
* File: binarySearch_LinkedList.h
* Author: Binh Hoang
* Date: 10/07/2023
* Description: This is a file writed for binary search by use linked list.
*/

#include "binarySearch_LinkedList.h"


/*
* Function: add_node
* Description: This function is used to create and arrange a node.
* Input:
*   Node **head: Pointer to poiter with data type is NODE - List to add new element
*   int value: Value is needed to insert
* Output:
*    returns a address of element that arranged .
*/
void add_node(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

/*
* Function: buildTree
* Description: This function is used to find center point of left and right side using recursion.
* Input:
*   Node *head: Pointer with data type is NODE - List to find center point of left and right side
*   int start - The first index of list
*   int end - The end index of list
* Output:
*   returns a pointer type data CenterPoint
*/
CenterPoint *buildTree(Node *head, int start, int end) {
    if (head == NULL || start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *node = head;
    for (int i = start; i < mid; i++) {
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }

    CenterPoint *root = (CenterPoint *) malloc(sizeof(CenterPoint));
    root->value = node->data;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);

    return root;
}

/*
* Function: centerPoint
* Description: This function is used to find center point by calculate the length of the list
* Input:
*   Node *head: Pointer with data type is NODE - List to find center point
* Output:
*   returns a pointer type data CenterPoint.
*/
CenterPoint *centerPoint(Node *head) {
    int length = 0;
    Node *node = head;
    while (node != NULL) {
        node = node->next;
        length++;
    }

    return buildTree(head, 0, length - 1);
}

/*
* Function: binarySearch
* Description: This function is used to binary search the element position in the list
* Input:
*   CenterPoint *root - The returned pointer by function buildTree
*   int value - value need to find in the list
* Output:
*   returns the pointer that contain finded value.
*/
CenterPoint *binarySearch(CenterPoint *root, int value) {
    static int loop = 0;
    loop++;
    printf("so lan lap: %d\n", loop);
    if (root == NULL) {
        return NULL;
    }

    if (root->value == value) {
        return root;
    }

    if (value < root->value) {
        return binarySearch(root->left, value);
    } else {
        return binarySearch(root->right, value);
    }
}

/*
* Function: print_list
* Description: This function is used to print the element in the list
* Input:
*   Node *head: Pointer with data type is NODE - List to print
* Output:
*   Print data of the element in the list.
*/
void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
