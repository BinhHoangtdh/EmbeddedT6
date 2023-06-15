# COMPILER
Quy trình biên dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Quá trình này gồm các giai đoạn sau: Preprocessor, Compiler, Assembler và Linker.
<p align="center">
  <img src="https://github.com/BinhHoangtdh/EmbeddedT6/assets/90816265/bcfd1a11-29d6-42c8-9e15-16badd2f64ef">
</p>

## 1. Giai đoạn tiền xử lý – Preprocessor
Giai đoạn này sẽ thực hiện:
* Nhận mã nguồn
* Xóa bỏ tất cả chú thích, comments của chương trình
* Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý như: #include, #define,...

*Cú pháp thực hiện quá trình từ file .c sang .i trong terminal: gcc -E main.c -o main.i*
## 2. Giai đoạn Dịch ngôn ngữ bậc cao sang ngôn ngữ Assembly – Compiler
* Phân tích cú pháp (syntax) của mã nguồn ngôn ngữ bậc cao
* Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

*Cú pháp thực hiện quá trình từ file .i sang .s trong terminal: gcc main.i -S -o main.s*
## 3. Giai đoạn Assembler
* Dich chương trình => Sang mã máy 0 và 1
* Một tệp mã máy (.o) sinh ra trong hệ thống sau đó.

*Cú pháp thực hiện quá trình từ file .s sang .o trong terminal: gcc -c main.s -o main.o*
## 4. Giai đoạn liên kết các object file – Linker
* Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
* Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
# POINTER
## 1. Khái niệm
Con trỏ trong C cũng chỉ là biến, cũng có thể khai báo, khởi tạo và lưu trữ giá trị và có địa chỉ của riêng nó. Nhưng biến con trỏ không lưu giá trị bình thường, nó là biến trỏ tới 1 địa chỉ khác, tức mang giá trị là 1 địa chỉ trong RAM.
* Kiểu dữ liệu của con trỏ: Kiểu dữ liệu của con trỏ trùng với kiểu dữ liệu tại vùng nhớ mà nó trỏ đến.
* Giá trị của con trỏ: chứa địa chỉ vùng nhớ mà con trỏ trỏ đến.

Ví dụ: biến "tuổi" (int tuoi) và biến con trỏ "pointerTuoi" (int *pointerTuoi = &tuoi) trỏ đến biến "tuoi"
<p align="center">
  <img src="https://github.com/BinhHoangtdh/EmbeddedT6/assets/90816265/ff3f1827-a509-4cb8-aebc-75d459550ac2">
</p>

## 2. Khai báo con trỏ
### Khai báo con trỏ biến: 

`<kiểu dữ liệu> * <tên biến con trỏ>;`

`Ví dụ: int *pointer = NULL;`
  * Kiểu dữ liệu có thể là: int, char, void, double,.... **Lưu ý: con trỏ kiểu void có thể trỏ đến các vùng nhớ kiểu dữ liệu khác nhau nhưng khi dùng con trỏ kiểu "void" để truy xuất giá trị thì phải ép kiểu con trỏ để lấy giá trị của vùng nhớ mà con trỏ trỏ đến.**
  * Dấu * trước tên biến là ký hiệu báo cho trình biên dịch biết ta đang khai báo con trỏ.

**Lưu ý: Khi khai báo con trỏ thì phải gán địa chỉ cho nó. Nếu chưa dùng đến thì gán con trỏ NULL cho nó.**
### Khai báo con trỏ hàm: 

Khi khai báo con trỏ đến hàm thì phải đúng các cấu trúc, Input Para của hàm đó

`Cú pháp: <Kiểu trả về> (*pointer)(Tham số đầu vào);`

`Ví dụ: Cho hàm tổng 2 số nguyên sau:`

<p align="center">
  <img src="https://github.com/BinhHoangtdh/EmbeddedT6/assets/90816265/71c169a0-50b0-420b-bac3-d41a4440bf24">
</p>

Ta khai báo con trỏ ptr hàm dạng như sau:
<p align="center">
  <img src="https://github.com/BinhHoangtdh/EmbeddedT6/assets/90816265/7c809b2b-f5de-43c0-a82c-9b32b1e4e885">
</p>

## 3. Ép kiểu con trỏ

### Ép kiểu sang con trỏ biến

Cú pháp: (<kiểu dữ liệu> *)<tên con trỏ>

Ví dụ:

`int i =2;`

`void *pointer = NULL; // Khai báo con trỏ "pointer" kiểu void`

`pointer = &i; // pointer có giá trị là địa chỉ của i`

`Printf("Gia tri cua i la: %d\n", *(int *)pointer); // Ép kiểu pointer sang int để lấy giá trị của i`

### Ép kiểu sang con trỏ hàm

Ví dụ: 
<p align="center">
  <img src="https://github.com/BinhHoangtdh/EmbeddedT6/assets/90816265/71c169a0-50b0-420b-bac3-d41a4440bf24">
</p>

<p align="center">
  <img src="https://github.com/BinhHoangtdh/EmbeddedT6/assets/90816265/643eb753-98bf-4c3e-94d9-a0a1429d68ab">
</p>

## 4. Pointer to Pointer

`int *ptr = NUll;`

`int **ptp = &ptr; // ptp chứa địa chỉ của ptr`
## 5. Kích thước con trỏ

Kích thươc con trỏ phụ thuộc vào kiến trúc của vi xử lý.
# PHÂN VÙNG NHỚ TRONG RAM

<p align="center">
  <img src="https://github.com/BinhHoangtdh/EmbeddedT6/assets/90816265/7940b5ff-b982-4f56-ad05-108fa6159358">
</p>

## 1. Text

– Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.

– Chứa khai báo hằng số trong chương trình (.rodata)

Ví dụ:

`#include <stdio.h>`

`const int i = 10; // text segment`

`int main(int argc, char const * argv[]){`
## 2. Data (Initialized Data)

– Quyền truy cập là read-write.
– Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.
– Được giải phóng khi kết thúc chương trình.

Ví dụ:

`#include <stdio.h>`

`int k = 10; // Data segment`

`static int i = 5; // Data segment`

`void tong(){`

    `static int i= 2; // Data segment`
   
`}`

`int main(int argc, char const * argv[]){`

    `return 0;`
   
`}`
## 3. BSS (Uninitialized Data)

– Quyền truy cập là read-write.

– Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.

– Được giải phóng khi kết thúc chương trình.

Ví dụ:

`#include <stdio.h>`

    `int k ; // bss segment`

    `static int i ; // bss segment`

`void tong(){`

   `static int i; // bss segment`
   
`}`

`int main(int argc, char const * argv[]){`

    `return 0;`
   
`}`
## 4. Stack

– Quyền truy cập là read-write.

– Được sử dụng cấp phát cho biến local, input parameter của hàm,…

– Sẽ được giải phóng khi ra khỏi block code/hàm

Ví dụ: 

`#include <stdio.h>`

`void tong(){`

    `int i; // stack segment`
   
`}`

`int main(int argc, char const * argv[]){`

    `int count = 1;`// stack segment

    `return 0;`

`}`
## 5. Heap

– Quyền truy cập là read-write.

– Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …

– Sẽ được giải phóng khi gọi hàm free,…

**Lưu ý: Khi sử dụng lệnh cấp phát bộ nhớ động thì sau khi dùng xong thì phải giải phóng bộ nhớ bằng lệnh free() để tránh lỗi tràn bộ nhớ.**
