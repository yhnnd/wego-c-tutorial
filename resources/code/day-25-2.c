#include <stdio.h>

typedef char string [64];

struct student {
	int studentNumber;
	string studentName;
	char gender;
};

struct teacher {
	int workerNumber;
	string teacherName;
	string department;
};

enum jobType {student, teacher};

struct person {
	enum jobType job;
	union {
		struct student stu;
		struct teacher tch;
	};
};

int main() {
	struct person persons[] = {
		{
			job: student,
			stu: {
				studentNumber: 10001,
				studentName: "Tom Hanks",
				gender: 'M'
			}
		},
		{
			job: teacher,
			tch: {
				workerNumber: 101,
				teacherName: "Nick Cave",
				department: "Institute Of Foreign Language"
			}
		}
	};
	struct person * ptr = NULL;
	const int personLength = sizeof(persons) / sizeof(persons[0]);
	for (int i = 0; i < personLength; ++i) {
		ptr = &persons[i];
		if (ptr->job == student) {
			printf("persons[%d].job = student\n", i);
			printf("persons[%d].stu.studentNumber = %d\n", i, ptr->stu.studentNumber);
			printf("persons[%d].stu.studentName = %s\n", i, ptr->stu.studentName);
			printf("persons[%d].stu.gender = %c\n", i, ptr->stu.gender);
		} else if (ptr->job == teacher) {
			printf("persons[%d].job = teacher\n", i);
			printf("persons[%d].tch.workerNumber = %d\n", i, ptr->tch.workerNumber);
			printf("persons[%d].tch.teacherName = %s\n", i, ptr->tch.teacherName);
			printf("persons[%d].tch.department = %s\n", i, ptr->tch.department);
		}
		if (i + 1 < personLength) {
			printf("\n");
		}
	}
	ptr = NULL;
}
