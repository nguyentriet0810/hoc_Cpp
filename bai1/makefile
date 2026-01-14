# Trình biên dịch
CC = gcc

# Tùy chọn biên dịch
CFLAGS = -Wall -O2

# Tên file output
TARGET = bai1.exe

# Quy tắc build
$(TARGET): bai1.c
	$(CC) $(CFLAGS) bai1.c -o $(TARGET)

# Lệnh xóa file build
clean:
	del /Q $(TARGET)