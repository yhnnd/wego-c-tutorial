#include <stdio.h>

int main() {
	char s [101];
	FILE * fp = fopen("temp.txt", "w");// 写文件(覆盖)
	fclose(fp);
	fp = fopen("temp.txt", "a");// 写文件(追加)
	fclose(fp);
	fp = fopen("temp.txt", "r");// 读文件
	fclose(fp);
	return 0;
}
