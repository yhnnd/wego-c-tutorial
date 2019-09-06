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

union studentOrTeacher {
	struct student stu;
	struct teacher tch;
};

enum jobType {student, teacher};

struct person {
	enum jobType job;
	union studentOrTeacher sot;
};

int main() {
	struct person persons[] = {
		{
			job: student,
			sot: {
				stu: {
					studentNumber: 10001,
					studentName: "Tom Hanks",
					gender: 'M'
				}
			}
		},
		{
			job: teacher,
			sot: {
				tch: {
					workerNumber: 101,
					teacherName: "Nick Cave",
					department: "Institute Of Foreign Language"
				}
			}
		}
	};
	struct person * ptr = NULL;
	const int personLength = sizeof(persons) / sizeof(persons[0]);
	for (int i = 0; i < personLength; ++i) {
		ptr = &persons[i];
		if (ptr->job == student) {
			printf("persons[%d].job = student\n", i);
			printf("persons[%d].sot.stu.studentNumber = %d\n", i, ptr->sot.stu.studentNumber);
			printf("persons[%d].sot.stu.studentName = %s\n", i, ptr->sot.stu.studentName);
			printf("persons[%d].sot.stu.gender = %c\n", i, ptr->sot.stu.gender);
		} else if (ptr->job == teacher) {
			printf("persons[%d].job = teacher\n", i);
			printf("persons[%d].sot.tch.workerNumber = %d\n", i, ptr->sot.tch.workerNumber);
			printf("persons[%d].sot.tch.teacherName = %s\n", i, ptr->sot.tch.teacherName);
			printf("persons[%d].sot.tch.department = %s\n", i, ptr->sot.tch.department);
		}
		if (i + 1 < personLength) {
			printf("\n");
		}
	}
	ptr = NULL;
}
