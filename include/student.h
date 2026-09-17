// include/student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

constexpr int assignment_count{5};

/**
 * @brief One student's name and their score on each assignment.
 */
struct Student {
    std::string name;
    double scores[assignment_count]{};
};

#endif
