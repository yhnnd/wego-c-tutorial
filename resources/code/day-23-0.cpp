#include <stdio.h>

int main() {
	char s [101];
	FILE * fp = fopen("temp.txt", "w");// д�ļ�(����)
	fclose(fp);
	fp = fopen("temp.txt", "a");// д�ļ�(׷��)
	fclose(fp);
	fp = fopen("temp.txt", "r");// ���ļ�
	fclose(fp);
	return 0;
}
