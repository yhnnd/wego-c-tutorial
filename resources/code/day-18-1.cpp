#include <stdio.h>

int main() {
	int n, i, j;
	printf("输入 0 设置星期的第一天为星期日\n");
	printf("输入 1 设置星期的第一天为星期一\n");
	scanf("%d", &n);
	printf("中文      English    日本語\n");
	for (i = n; i < n + 7; ++i) {
		j = i % 7;
		if (j < 0) j += 7;
		switch (j) {
			case 0:
				printf("星期日    Sunday     にちようび");
				break;
			case 1:
				printf("星期一    Monday     げつようび");
				break;
			case 2:
				printf("星期二    Tuesday    かようび");
				break;
			case 3:
				printf("星期三    Wednesday  すいようび");
				break;
			case 4:
				printf("星期四    Thursday   もくようび");
				break;
			case 5:
				printf("星期五    Friday     きんようび");
				break;
			case 6:
				printf("星期六    Saturday   どようび");
				break;
			default:
				printf("error!");
		}
		printf("\n");
	}
	return 0;
}
