#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students] = Student(name, id, midterm, final);
    ++num_of_students;
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int index = findStudentByID(id);
    // 소멸자로 객체 삭제?
    // 배열 재정렬
    for (int i=index+1; i<num_of_students; i++) {
        students[i-1] = students[i];
    }
    --num_of_students;
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int id = student.getID();
    int index = findStudentByID(id);
    students[index].updateRecord(student.getName().c_str(), student.getRecord().getMidterm(), student.getRecord().getFinal());
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    int index = -1;
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getID() == id) {
            return i;
        }
    }
    return index;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    float best_score = 0.0f;
    int best_student = 0;
    float score = 0.0f;
    for (int i=0; i<num_of_students; i++) {
        score = students[i].getRecord().getMidterm();
        if (score > best_score) {
            best_score = score;
            best_student = i;
        }
    }
    return best_student;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    float best_score = 0.0f;
    int best_student = 0;
    float score = 0.0f;
    for (int i=0; i<num_of_students; i++) {
        score = students[i].getRecord().getFinal();
        if (score > best_score) {
            best_score = score;
            best_student = i;
        }
    }
    return best_student;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    float best_score = 0.0f;
    int best_student = 0;
    float score = 0.0f;
    for (int i=0; i<num_of_students; i++) {
        score = students[i].getRecord().getTotal();
        if (score > best_score) {
            best_score = score;
            best_student = i;
        }
    }
    // std::cout << "findBestStudent: " << best_student
    //           << ", name: " << students[best_student].getName() << std::endl;
    return best_student;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float sum = 0.0f;
    for (int i=0; i<num_of_students; i++) {
        sum += students[i].getRecord().getMidterm();
    }
    return sum / num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float sum = 0.0f;
    for (int i=0; i<num_of_students; i++) {
        sum += students[i].getRecord().getFinal();
    }
    return sum / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float sum = 0.0f;
    for (int i=0; i<num_of_students; i++) {
        sum += students[i].getRecord().getTotal();
    }
    return sum / num_of_students;
}

