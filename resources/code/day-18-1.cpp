#include <stdio.h>

int main() {
	int n, i, j;
	printf("���� 0 �������ڵĵ�һ��Ϊ������\n");
	printf("���� 1 �������ڵĵ�һ��Ϊ����һ\n");
	scanf("%d", &n);
	printf("����      English    �ձ��Z\n");
	for (i = n; i < n + 7; ++i) {
		j = i % 7;
		if (j < 0) j += 7;
		switch (j) {
			case 0:
				printf("������    Sunday     �ˤ��褦��");
				break;
			case 1:
				printf("����һ    Monday     ���Ĥ褦��");
				break;
			case 2:
				printf("���ڶ�    Tuesday    ���褦��");
				break;
			case 3:
				printf("������    Wednesday  �����褦��");
				break;
			case 4:
				printf("������    Thursday   �⤯�褦��");
				break;
			case 5:
				printf("������    Friday     ����褦��");
				break;
			case 6:
				printf("������    Saturday   �ɤ褦��");
				break;
			default:
				printf("error!");
		}
		printf("\n");
	}
	return 0;
}
