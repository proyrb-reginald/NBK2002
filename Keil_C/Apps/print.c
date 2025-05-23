#include "print.h"
#include "UART_Circular_Buffer.h"

/**
 * 格式化字符串缓冲区，支持%s和%u格式化
 * @param buf 目标缓冲区
 * @param size 缓冲区大小
 * @param format 格式字符串
 * @param ... 可变参数列表
 * @return 实际需要写入的字符数（不包括终止符）
 */
int print(const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    
    char buf[64] = "";
    size_t size = 64;

    int index = 0;          // 当前写入位置
    int total_length = 0;   // 总字符数

    // 临时缓冲区用于数字转换
    char num_str[12];  

    // 遍历格式字符串
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++; // 移动到格式符
            if (format[i] == '\0') break; // 格式字符串意外结束

            if (format[i] == 's') {
                // 处理字符串格式符
                const char *s = va_arg(ap, const char *);
                if (!s) s = "(null)"; // 处理空指针
                
                while (*s != '\0') {
                    total_length++;
                    if (index < size - 1) {
                        buf[index++] = *s;
                    }
                    s++;
                }
            } 
            else if (format[i] == 'u') {
                // 处理无符号整数格式符
                unsigned int num = va_arg(ap, unsigned int);
                char *p = num_str;
                
                // 数字转换
                if (num == 0) {
                    *p++ = '0';
                } else {
                    char temp[12];
                    int j = 0;
                    // 逆序生成数字字符
                    while (num > 0) {
                        temp[j++] = '0' + (num % 10);
                        num /= 10;
                    }
                    // 反转得到正确顺序
                    while (j > 0) {
                        *p++ = temp[--j];
                    }
                }
                *p = '\0'; // 字符串终止符
                
                // 复制转换后的数字到目标缓冲区
                int k = 0;
                while (num_str[k] != '\0') {
                    total_length++;
                    if (index < size - 1) {
                        buf[index++] = num_str[k];
                    }
                    k++;
                }
            } 
            else {
                // 未知格式符，原样输出%和当前字符
                total_length += 2;
                if (index < size - 1) {
                    buf[index++] = '%';
                }
                if (index < size - 1) {
                    buf[index++] = format[i];
                }
            }
        } 
        else {
            // 普通字符直接复制
            total_length++;
            if (index < size - 1) {
                buf[index++] = format[i];
            }
        }
    }

    // 确保字符串终止
    if (size > 0) {
        if (index >= size) {
            index = size - 1; // 截断处理
        }
        buf[index] = '\0';
    }

    va_end(ap);
    
    UART_Buffer_WriteMulti(&uart, (const uint8_t *)buf, total_length);
    
    return total_length;
}
