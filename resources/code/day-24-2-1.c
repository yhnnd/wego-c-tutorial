#include <stdio.h>
#include <string.h>

struct student {
	char firstname[32];
	char lastname[32];
};

int main() {
	// ���� student ���͵Ľṹ�� stu
	struct student stu;
	// ���� student * ���͵Ľṹ��ָ�� pstu
	struct student * pstu;
	// ��ָ�� pstu ָ�� stu
	pstu = &stu;
	// ��ָ�� pstu ָ��� student �ṹ��� firstname ���Ը�ֵ
	strcpy(pstu->firstname, "Tom");
	// ��ָ�� pstu ָ��� student �ṹ��� lastname ���Ը�ֵ
	strcpy(pstu->lastname, "Hanks");
	// ��� stu �� firstname ���Ժ� lastname ����
	printf("%s %s\n", stu.firstname, stu.lastname);
	return 0;
}
