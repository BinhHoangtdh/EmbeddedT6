#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "LinkedList.h"


int main()
{
    int index;
    NODE *head = NULL;
    push_front(&head, 24);
    push_front(&head, 12);
    push_front(&head, 5);

    push_back(&head, 11);
    push_back(&head, 7);

    insert(&head,22, 0);

    pop_front(&head);

    pop_back(&head);

    erase(&head,1);
    
    printf("Cac phan tu co trong danh sach la:\n");
    print(head);
    printf("\nSo luong phan tu trong mang la: %d\n", size(head));
    
    printf("Nhap index phan tu can doc gia tri: ");
    scanf("%d", &index);
    int ketqua = get_value(head,index);
    if(ketqua == -1)
        printf("Gia tri index nhap vao khong hop le hoac danh sach dang trong!\n");
    else
        printf("Gia tri cua phan tu thu %d la: %d\n", index, ketqua);
   
    return 0;
}

