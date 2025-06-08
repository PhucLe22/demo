#include <iostream>
#include <conio.h>  // Thư viện hỗ trợ _kbhit() và _getch()
#include <windows.h>

using namespace std;

// Hàm xử lý khi có ngắt bàn phím
void keyboard_interrupt_handler() {
    char ch = _getch();  // Lấy phím vừa nhấn
    cout << "\nPhím bạn vừa nhấn: " << ch << endl;
}

int main() {
    cout << "Chương trình đang chạy... Nhấn một phím để kích hoạt ngắt." << endl;

    while (true) {
        if (_kbhit()) {  // Kiểm tra nếu có phím nào đó được nhấn
            keyboard_interrupt_handler();
        }
        Sleep(100);  // Giảm tải CPU (tránh vòng lặp chạy quá nhanh)
    }

    return 0;
}
