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
## 2. Giai đoạn Dịch ngôn ngữ bậc cao sang ngôn ngữ Assembly – Compiler
* Phân tích cú pháp (syntax) của mã nguồn ngôn ngữ bậc cao
* Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
## 3. Giai đoạn Assembler
* Dich chương trình => Sang mã máy 0 và 1
* Một tệp mã máy (.o) sinh ra trong hệ thống sau đó.
## 4. Giai đoạn Dịch ngôn ngữ bậc cao sang ngôn ngữ Assembly – Compiler
* Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
* Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
