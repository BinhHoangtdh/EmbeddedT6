# MACRO - FUNCTION
## 1. MACRO
- Macro xảy ra ở quá trình tiền xử lý. Sau quá trình tiền xử lý thì các đoạn (các biến, các hàm) được định nghĩa sẽ được thay bằng các giá trị tương ứng. Nó không phải là code
- Khi gọi macro nhiều lần thì tốn kích thước bộ nhớ, nhưng tốc độ chạy của chương trình nhanh
## 2. FUNCTION
- Sử dụng function thì chỉ tốn một vùng nhớ cố định để lưu cho nên khi gọi hàm thì chương trình ít tốn bộ nhớ nhưng tốc độ chạy của chương trình lại chậm.
- Khi chương trình chạy từ trên xuống dưới trong hàm main, nếu gặp lệnh gọi function thì **Stack pointer** sẽ lưu địa chỉ hiện tại sau đó **Program counter** sẽ nhảy đến địa chỉ đinh nghĩa hàm function. Khi xử lý xong thì Program counter nhận giá trị của Stack pointer lúc trước và tiếp tục thực hiện chương trình. Bước nhảy của **Program counter** phụ thuộc vào cấu trúc VDK.
- Fuction được thực hiện ở quá trình compiler

<p align="center">
  <img src="https://github.com/BinhHoangtdh/EmbeddedT6/assets/90816265/08f2b48b-611b-4dab-9b62-e32b2371b9ca">
</p>

# USER-DEFINED DATA TYPE
## 1. STRUCT
- Struct là một kiểu dữ liệu do người dùng tự định nghĩa, nó có thể chứa các thành phần- member với các kiểu dữ liệu khác nhau.
- Cú pháp:
  
`struct structureName`

`{`

 `   dataType member1;`
    
  `  dataType member2;`
    
  `  ...`
    
`};`

- Mỗi member trong kiểu struct có môt địa chỉ độc lập nên giá trị của mỗi member là riêng biệt.
- Kích thước của một biến kiểu struct bằng kích thước các member + bộ nhớ đệm (nếu có). Để tính kích thước nó thường lấy member có kích thước **kiểu dữ liệu lớn nhất** để quét.
- Để truy cập đến các thành phần trong Struct ta làm như sau:
  -  Đối với biến thường: <Tên_biến_thường>.<Tên_member>
  -  Đối với biến con trỏ Pointer: <Tên_Pointer>-><Tên_member>
## 2. UNION
- Union là một kiểu dữ liệu do người dùng tự định nghĩa, nó có thể chứa các thành phần- member với các kiểu dữ liệu khác nhau.
- Cú pháp:
  
`union UnionName`

`{`

 `   dataType member1;`
    
  `  dataType member2;`
    
  `  ...`
    
`};`

- Mỗi member trong kiểu Union có chung một địa chỉ nên giá trị của các member là chung. Vì vậy tại một thời điểm chỉ truy cập được một member nhất định
- Kích thước của một biến kiểu Union bằng **kích thước của member lớn nhất**.
- Để truy cập đến các thành phần trong Union ta làm như sau:
  -  Đối với biến thường: <Tên_biến_thường>.<Tên_member>
  -  Đối với biến con trỏ Pointer: <Tên_Pointer>-><Tên_member>
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

`int count = 1;// stack segment`

`return 0;`

`}`
## 5. Heap

– Quyền truy cập là read-write.

– Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …

– Sẽ được giải phóng khi gọi hàm free,…

**Lưu ý: Khi sử dụng lệnh cấp phát bộ nhớ động thì sau khi dùng xong thì phải giải phóng bộ nhớ bằng lệnh free() để tránh lỗi tràn bộ nhớ.**

Ví dụ: 

`int main(int argc, char const * argv[]){ `

`int cout = 0; // stack segment`
    
`int *array = (int *)malloc(sizeof(int)*4); // Automatic Memory allocation` 

`array = (int *)realloc(array, sizeof(int)*7); // Automatic Memory allocation, tăng vùng nhớ lên cho array`
    
`free(array); // Giải phóng bộ nhớ con trỏ array`
    
`return 0;`
    
`}`
# BIẾN STATIC
## 1. Biến static trong khai báo biến cục bộ
- Được khởi tạo 1 lần duy nhất trong cả chương trình.
- Giá trị được giữ nguyên cả khi ra khỏi hàm.
- Chỉ được sử dụng bên trong hàm khai báo nó.
## 2. Biến static trong khai báo biến toàn cục
- Sử dụng tương tự như biến toàn cục
- Chỉ được sử dụng trong file khai báo nó, các file khác không được truy cập.
## 3. Biến static trong khai báo hàm
- Chỉ được sử dụng trong file khai báo nó, các file khác không được truy cập.
# BIẾN VOLATILE
- Volatile đại diện cho các biến có thể thay đổi bất thường mà không thông qua nguồn source code. Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler.
- Một biến cần được khai báo dưới dạng biến volatile khi:
  -  Memory-mapped peripheral registers (thanh ghi ngoại vi có ánh xạ đến ô nhớ). Ví dụ như biến đọc giá trị kết quả chuyển đổi ADC (từ thanh ghi Data của vi điều khiển);
  -  Biến toàn cục được truy xuất từ các tiến trình con xử lý ngắt (interrupt service routine): Ví dụ như khai báo biến đếm count, biến này thay đổi giá trị khi ta bấm nút xảy ra ngắt ngoài từ một chân của VĐK.
  -  Biến toàn cục được truy xuất từ nhiều tác vụ trong một ứng dụng đa luồng.
# BIẾN EXTERN
Để có thể truy cập giá trị một biến toàn cục, một mảng hay một hàm ở 1 file khác ta sử dụng từ khóa EXTERN.

Ví dụ: 

- Ở file main.c
  
  `int x = 0;`
  
  `void tang_bien(){`
  
  `x++;`
  
  `}`
  
- File test.c muốn sử dụng biến x của file main.c thì ta làm như sau:

  `extern int x;`
  
  `void giam_bien(){`
  
  `x--;`
  
  `}`
# LINKED LIST - DANH SÁCH LIÊN KẾT
## Định nghĩa
Danh sách liên kết đơn là một tập hợp các Node được phân bố động, được sắp xếp theo cách sao cho mỗi Node chứa “một giá trị”(Data) và “một con trỏ”(Next). Con trỏ sẽ trỏ đến phần tử kế tiếp của danh sách liên kết đó. Nếu con trỏ mà trỏ tới NULL, nghĩa là đó là phần tử cuối cùng của linked list.

<p align="center">
  <img src="https://github.com/BinhHoangtdh/EmbeddedT6/assets/90816265/e8f6d4fc-3c14-419c-b621-f42feb5e6a77">
</p>

Khai báo cấu trúc node cho linked list:

`struct <Tên_LinkedList>{`

    <Kiểu_dữ_liệu> <Tên_data>;
    
    struct <Tên_LinkedList> *<tên_Pointer>;
    
 `};`
 
 Ví dụ:

 `struct LinkedList{`
 
    int data;
    
    struct LinkedList *next;
    
 `};`
## So sánh ưu nhược điểm của danh sách liên kết với mảng 1 chiều:
### Danh sách liên kết
- Ưu điểm:
  - Việc thêm và xóa phần tử đơn giản chỉ cần thay đổi mối liên kết giữa các node với nhau
  - Không cần biết trước số lượng phần tử -> Kích thước tối đa phụ thuộc vào bộ nhớ, Kích thước thay đổi trong quá trình thêm/ xóa phần tử
  - Cấp phát bộ nhớ động: Bộ nhớ được cấp phát trong quá trình chạy
  - Các phần tử không cần nằm liên tiếp nhau trong bộ nhớ máy tính. Do đó khắc phục tình trạng phân mảnh bộ nhớ
- Nhược điểm:
  - Không thể truy xuất đến từng phần tử của danh sách thông qua toán tử chỉ số mà phải duyệt tuần tự thông qua các phần tử
  - Tốn bộ nhớ do chứa thêm con trỏ để liên kết các node với nhau
### Mảng một chiều
- Ưu điểm:
  - Truy xuất đến từng phần tử trong mảng thông qua toán tử chỉ số
  - Ít tốn bộ nhớ
- Nhược điểm:
  - Việc thêm và xóa phần tử bản chất không phải thêm hoặc xóa thật sự mà đó chỉ là thay đổi vị trí các phần tử với nhau
  - Phải biết trước số lượng phần tử mảng-> kích thước cố định -> Cần chỉ rõ kích thước trong khi khai báo
  - Cấp phát bộ nhớ tĩnh: Bộ nhớ được cấp phát trong quá trình biên dịch
  - Các phần tử phải nằm liên tiếp nhau trong bộ nhớ máy tính. Do đó dẫn đến tình trạng phân mảnh bộ nhớ
# C++
## CLASS
+ Class là một kiểu dữ liệu do người dùng tự định nghĩa, là một mô tả trừu tượng của nhóm các đối tượng (object) có
cùng bản chất. Một class sẽ bao gồm các thuộc tính (Property) và phương thức (Method).

+ Có 3 phạm vi truy cập trong C++ là public, private và protected.
 
  + Private: Khi không muốn người khác tùy ý gán giá trị hoặc muốn xử lý trước khi trả về giá trị
  
  + Pulic: Các thuộc tính và phương thức khai báo có thể được truy cập trực tiếp, các property có thể tùy ý gán giá trị hoặc không cần xử lý trước khi trả về giá trị
  
  + Protected: khi muốn các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.
  
+ Static member là Property được sử dụng chung cho tất cả object khác nhau thuộc class đó

+ Constructor là một hàm đặc biệt, được gọi khi khởi tạo object

+ Deconstructor là hàm được gọi trước khi thu lại vùng nhớ của object

+ Ví dụ khai báo class và cách sử dụng:

`class Person {`

`public:`

`string firstName; // property`

`string lastName; // property`

`int age; // property`

`void fullname() { // method`

`cout << firstName << ' ' << lastName;`

`}`

`};`

`Person nv; // nv được gọi là object`
# CÁC ĐẶC TÍNH HƯỚNG ĐỐI TƯỢNG
## TÍNH KẾ THỪA
 
PUBLIC: 

             public(class cha) --> public( class con)
             
             protected (class cha) --> protected( class con)
             
             private ko kế thừa được
             
PROTECTED:

              public(class cha) --> protected( class con)
              
              protected (class cha) --> protected( class con)
              
PRIVATE:

              public(class cha) --> private( class con)
              
              protected (class cha) --> private( class con)
              
## TÍNH ĐÓNG GÓI
Các PROPERTY (biến) phải được nằm trong PROTECTED hoặc PRIVATE ko được nằm trong pulic (trong pulic chỉ có method thôi). Thông qua những method để truy cập đến PROPERTY.
## TÍNH TRỪU TƯỢNG
Là khi một method đóng vai trò là một quá trình trung gian (chương trình con) góp phần tạo ra kết quả cuối cùng cho medthod chính thì nó phải được nằm trong PROTECTED hoặc PRIVATE.
              
