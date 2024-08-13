#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
typedef struct {
char name[50];
int rollNumber;
int feesStatus; // 1 for Paid, 0 for Unpaid
int attendance; // percentage
} Student;
Student students[MAX_STUDENTS];
int studentCount = 0;
int requiredAttendance = 75; // Default eligibility criteria
void execute();
void add();
void print_student();
void delete_student();
void eligibleStudents();
void update_eligibility_criteria();
int main() {
execute();
return 0;
}
void execute() {
int choice;
do {
printf("\nExamination Management System\n");
printf("1. Add Student Details\n");
printf("2. Show Eligible Students\n");
printf("3. Delete Student Record\n");
printf("4. Update Eligibility Criteria\n");
printf("5. Print Details of Students\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
getchar(); // Consume the newline character left by scanf
switch (choice) {
case 1:
add();
break;
case 2:
eligibleStudents();
break;
case 3:
delete_student();
break;
case 4:
update_eligibility_criteria();
break;
case 5:
print_student();
break;
case 6:
printf("Exiting...\n");
break;
default:
printf("Invalid choice! Please try again.\n");
}
} while (choice != 6);
}
void add() {
if (studentCount >= MAX_STUDENTS) {
printf("Student list is full!\n");
return;
}
Student newStudent;
int i, unique = 1;
printf("Enter name of student: ");
fgets(newStudent.name, sizeof(newStudent.name), stdin);
newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove trailing newline
printf("Enter roll number: ");
scanf("%d", &newStudent.rollNumber);
getchar(); // Consume the newline character left by scanf
// Check for unique roll number
for (i = 0; i < studentCount; i++) {
if (students[i].rollNumber == newStudent.rollNumber) {
unique = 0;
printf("Roll number already exists!\n");
break;
}
}
if (unique) {
printf("Enter fees status (1 for Paid, 0 for Unpaid): ");
scanf("%d", &newStudent.feesStatus);
getchar(); // Consume the newline character left by scanf
printf("Enter attendance percentage: ");
scanf("%d", &newStudent.attendance);
getchar(); // Consume the newline character left by scanf
students[studentCount++] = newStudent;
printf("Student added successfully!\n");
}
}
void print_student() {
if (studentCount == 0) {
printf("No student records available.\n");
return;
}
printf("\nStudent Details:\n");
for (int i = 0; i < studentCount; i++) {
printf("Name: %s\n", students[i].name);
printf("Roll Number: %d\n", students[i].rollNumber);
printf("Fees Status: %s\n", students[i].feesStatus ? "Paid" : "Unpaid");
printf("Attendance: %d%%\n", students[i].attendance);
printf("-----------------------\n");
}
}
void delete_student() {
int rollNumber;
int found = 0;
printf("Enter roll number of student to delete: ");
scanf("%d", &rollNumber);
getchar(); // Consume the newline character left by scanf
for (int i = 0; i < studentCount; i++) {
if (students[i].rollNumber == rollNumber) {
for (int j = i; j < studentCount - 1; j++) {
students[j] = students[j + 1];
}
studentCount--;
// Optional: Clear the last record
memset(&students[studentCount], 0, sizeof(Student));
found = 1;
printf("Student record deleted successfully!\n");
break;
}
}
if (!found) {
printf("Student with roll number %d not found!\n", rollNumber);
}
}
void eligibleStudents() {
printf("\nEligible Students (Attendance >= %d%% and Fees Paid):\n", requiredAttendance);
int found = 0;
for (int i = 0; i < studentCount; i++) {
if (students[i].attendance >= requiredAttendance && students[i].feesStatus == 1) {
printf("Name: %s\n", students[i].name);
printf("Roll Number: %d\n", students[i].rollNumber);
printf("-----------------------\n");
found = 1;
}
}
if (!found) {
printf("No students meet the eligibility criteria.\n");
}
}
void update_eligibility_criteria() {
printf("Enter new required attendance percentage for eligibility: ");
scanf("%d", &requiredAttendance);
getchar(); // Consume the newline character left by scanf
printf("Eligibility criteria updated to %d%%.\n", requiredAttendance);
eligibleStudents(); // Show eligible students with updated criteria
}

