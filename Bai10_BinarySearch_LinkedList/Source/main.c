#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "binarySearch_LinkedList.h"


int main() {
    Node *head = NULL;

//tao ngau nhien 10000 node
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        int value = rand() % 10000 + 1;
        add_node(&head, value);
    }

    add_node(&head, 5639);

    print_list(head);

    CenterPoint *ptr = centerPoint(head);

    int value = 5639;
    CenterPoint *result = binarySearch(ptr, value);
    if (result != NULL) {
        printf("Tim thay %d\n", result->value);
    } else {
        printf("Khong tim thay\n");
    }

    return 0;
}
