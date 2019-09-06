#include <stdio.h>
#include <string.h>

struct student {
	char firstname[32];
	char lastname[32];
};

int main() {
	// 声明 student 类型的结构体 stu
	struct student stu;
	// 声明 student * 类型的结构体指针 pstu
	struct student * pstu;
	// 让指针 pstu 指向 stu
	pstu = &stu;
	// 给指针 pstu 指向的 student 结构体的 firstname 属性赋值
	strcpy(pstu->firstname, "Tom");
	// 给指针 pstu 指向的 student 结构体的 lastname 属性赋值
	strcpy(pstu->lastname, "Hanks");
	// 输出 stu 的 firstname 属性和 lastname 属性
	printf("%s %s\n", stu.firstname, stu.lastname);
	return 0;
}
