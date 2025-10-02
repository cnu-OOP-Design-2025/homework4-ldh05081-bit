#include <iostream>
#include "student_manager.h"
#include "student.h"

void fillSampleData(StudentManager& manager) {

    manager.addStudent("Alice", 90.7f, 91.0f);
    manager.addStudent("Bob", 68.5f, 74.8f);
    manager.addStudent("Charlie", 84.2f, 72.8f);
    manager.addStudent("David", 63.7f, 77.6f);
    manager.addStudent("Eva", 97.0f, 89.6f);
    manager.addStudent("Frank", 83.0f, 62.2f);
    manager.addStudent("Grace", 74.6f, 96.0f);
    manager.addStudent("Hannah", 89.5f, 82.4f);
    manager.addStudent("Ian", 98.4f, 91.3f);
    manager.addStudent("Jane", 65.6f, 84.0f);
    manager.addStudent("Kevin", 91.7f, 83.1f);
    manager.addStudent("Laura", 78.2f, 61.7f);
    manager.addStudent("Mike", 81.8f, 69.6f);
    manager.addStudent("Nina", 83.6f, 69.6f);
    manager.addStudent("Oscar", 63.9f, 98.7f);
    manager.addStudent("Paula", 67.4f, 81.2f);
    manager.addStudent("Quinn", 98.3f, 79.8f);
    manager.addStudent("Rachel", 89.0f, 67.7f);
    manager.addStudent("Steve", 89.4f, 96.6f);
    manager.addStudent("Tina", 95.1f, 76.8f);
    manager.addStudent("Uma", 91.7f, 77.2f);
    manager.addStudent("Victor", 93.8f, 77.3f);
    manager.addStudent("Wendy", 86.2f, 96.7f);
    manager.addStudent("Xander", 90.2f, 73.3f);
    manager.addStudent("Yvonne", 87.3f, 98.6f);
    manager.addStudent("Zack", 85.8f, 70.8f);
    manager.addStudent("Amber", 74.2f, 98.1f);
    manager.addStudent("Brian", 79.2f, 69.2f);
    manager.addStudent("Cathy", 86.1f, 82.2f);
    manager.addStudent("Derek", 73.1f, 100.0f);
    manager.addStudent("Elena", 62.1f, 84.8f);
    manager.addStudent("Fred", 65.4f, 60.7f);
    manager.addStudent("Gina", 97.7f, 91.7f);
    manager.addStudent("Harry", 66.0f, 60.3f);
    manager.addStudent("Isla", 89.7f, 62.7f);
    manager.addStudent("Jack", 95.9f, 95.1f);
    manager.addStudent("Kara", 91.4f, 86.9f);
    manager.addStudent("Liam", 74.8f, 60.1f);
    manager.addStudent("Mona", 77.8f, 76.8f);
    manager.addStudent("Noah", 86.8f, 90.3f);
    manager.addStudent("Olivia", 77.3f, 69.2f);
    manager.addStudent("Peter", 97.4f, 75.3f);
    manager.addStudent("Queen", 78.5f, 74.6f);
    manager.addStudent("Ron", 96.0f, 78.3f);
    manager.addStudent("Sara", 91.0f, 66.1f);
    manager.addStudent("Tom", 90.7f, 61.4f);
    manager.addStudent("Ursula", 66.1f, 68.0f);
    manager.addStudent("Vince", 65.1f, 89.8f);
    manager.addStudent("Will", 66.9f, 67.4f);
    manager.addStudent("Zoe", 78.1f, 76.0f);
}



void printStudentInfo(const StudentManager& manager, int id) {
    int idx = manager.findStudentByID(id);
    if (idx >= 0) {
        std::cout << "Student Info:" << std::endl;
        manager.printStudentInfo(idx);
    } 
}

void printStudentList(const StudentManager& manager) {
    std::cout << "Student List:" << std::endl;
    for (int i = 0; i < manager.getNumOfStudents(); ++i) {
        manager.printStudentInfo(i);
    }
}

void printBestStudent(const StudentManager& manager) {
    // int bestID = manager.findBestStudent();
    // int idx = manager.findStudentByID(bestID);
    int idx = manager.findBestStudent();
    if (idx >= 0) {
        std::cout << "Best Student:" << std::endl;
        manager.printStudentInfo(idx);
    } 
}

void printAverage(const StudentManager& manager) {
    std::cout << "Midterm Average: " << manager.getMidtermAverage() << std::endl;
    std::cout << "Final Average: " << manager.getFinalAverage() << std::endl;
    std::cout << "Total Average: " << manager.getTotalAverage() << std::endl;
}



void doTest1(StudentManager& manager) {
    std::cout << "---------------------------" << std::endl;
    std::cout << "Test 1" << std::endl;

    printBestStudent(manager);
    printAverage(manager);
    printStudentList(manager);
}

void doTest2(StudentManager& manager) {
    std::cout << "---------------------------" << std::endl;
    std::cout << "Test 2" << std::endl;

    Student charlie("Charlie", 1003, 70.0f, 99.0f);

    int idx = manager.findStudentByID(charlie.getID());
    if (idx >= 0) {
        manager.modifyStudent(charlie);
    }

    manager.addStudent("Ana", 88.0f, 65.0f);
    manager.addStudent("Suji", 90.0f, 93.0f);
    manager.addStudent("Zhang", 100.0f, 40.0f);

    printBestStudent(manager);
    printAverage(manager);
    printStudentList(manager);
}

void doTest3(StudentManager& manager) {
    std::cout << "---------------------------" << std::endl;
    std::cout << "Test 3" << std::endl;

    manager.deleteStudent(1011);
    manager.deleteStudent(1029);

    printBestStudent(manager);
    printAverage(manager);
    printStudentList(manager);
}


int main(int argc, char **argv) {
    StudentManager manager;
    fillSampleData(manager);

    if(argc == 2){
        int select = atoi(argv[1]);
        switch(select){
            case 1:
                doTest1(manager);
                return 0;
            case 2:
                doTest2(manager);
                return 0;
            case 3:
                doTest3(manager);
                return 0;
        }
    }

    doTest1(manager);
    doTest2(manager);
    doTest3(manager);

    return 0;
}