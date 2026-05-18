#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string department;
    float gpa;
};

Student students[100];
int countStudents = 0;

// Add Student
void addStudent() {
    cout << "Enter ID: ";
    cin >> students[countStudents].id;

    cout << "Enter Name: ";
    cin >> students[countStudents].name;

    cout << "Enter Age: ";
    cin >> students[countStudents].age;

    cout << "Enter Department: ";
    cin >> students[countStudents].department;

    cout << "Enter GPA: ";
    cin >> students[countStudents].gpa;

    countStudents++;
}

// Display All Students
void displayStudents() {
    if (countStudents == 0) {
        cout << "No students found.\n";
        return;
    }

    for (int i = 0; i < countStudents; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Department: " << students[i].department << endl;
        cout << "GPA: " << students[i].gpa << endl;
    }
}

// Search by ID
void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++) {
        if (students[i].id == id) {
            cout << "Found Student:\n";
            cout << "Name: " << students[i].name << endl;
            cout << "GPA: " << students[i].gpa << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

// Update Student
void updateStudent() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++) {
        if (students[i].id == id) {
            cout << "Enter new name: ";
            cin >> students[i].name;

            cout << "Enter new age: ";
            cin >> students[i].age;

            cout << "Enter new department: ";
            cin >> students[i].department;

            cout << "Enter new GPA: ";
            cin >> students[i].gpa;

            cout << "Updated successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

// Delete Student
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++) {
        if (students[i].id == id) {
            for (int j = i; j < countStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            countStudents--;
            cout << "Deleted successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

// Highest GPA
void highestGPA() {
    if (countStudents == 0) {
        cout << "No students.\n";
        return;
    }

    int index = 0;
    for (int i = 1; i < countStudents; i++) {
        if (students[i].gpa > students[index].gpa) {
            index = i;
        }
    }

    cout << "Top Student:\n";
    cout << "Name: " << students[index].name << endl;
    cout << "GPA: " << students[index].gpa << endl;
}

// Average GPA
void averageGPA() {
    if (countStudents == 0) {
        cout << "No students.\n";
        return;
    }

    float sum = 0;

    for (int i = 0; i < countStudents; i++) {
        sum += students[i].gpa;
    }

    cout << "Average GPA = " << sum / countStudents << endl;
}

// Menu
void menu() {
    cout << "\n===== Student System =====\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Highest GPA\n";
    cout << "7. Average GPA\n";
    cout << "8. Exit\n";
}

int main() {
    int choice;

    do {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: highestGPA(); break;
            case 7: averageGPA(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}