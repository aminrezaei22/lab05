// src/printing.cpp
#include "printing.h"

#include <iomanip>
#include <iostream>
#include <string>

#include "grading.h"
#include "utilities.h"

void print_header(const int num_students, const int num_assignments) {
    std::cout << pad_name("STUDENT", num_students);

    for (auto i{0}; i < num_assignments; i++) {
        std::cout << std::setw(5) << "A" << i;
    }

    std::cout << std::setw(8) << "AVG" << std::setw(6) << "GRADE" << '\n';

    for (auto i{0}; i < 60; i++) {
        std::cout << '-';
    }

    std::cout << '\n';
}

void print_student_row(const Student& student) {
    std::cout << pad_name(student.name, name_width);

    for (auto i{0}; i < assignment_count; i++) {
        std::cout << std::setw(6) << std::setprecision(1) << std::fixed
                  << student.scores[i];
    }

    double avg{student_average(student)};

    std::cout << std::setw(8) << std::setprecision(2) << std::fixed << avg
              << " \t" << letter_grade(avg);

    if (has_perfect_score(student)) {
        std::cout << "  *";
    }

    if (is_at_risk(student)) {
        std::cout << "  !";
    }

    std::cout << '\n';
}

void print_histogram(const Student* students, int student_count) {
    const char letters[]{'A', 'B', 'C', 'D', 'F'};

    std::cout << "\nGRADE DISTRIBUTION\n";

    for (auto letter : letters) {
        auto count{count_grade(students, student_count, letter)};

        std::cout << letter << " | ";

        for (auto i{0}; i < count; i++) {
            std::cout << '#';
        }

        std::cout << "\t\t(" << count << ")\n";
    }
}

void print_assignment_summary(const Student* students, int student_count) {
    std::cout << "\nASSIGNMENT AVERAGES\n";

    for (auto i{0}; i < assignment_count; i++) {
        auto avg{assignment_average(students, student_count, i)};

        std::cout << "  A" << i + 1 << ": " << std::setw(6)
                  << std::setprecision(2) << std::fixed << avg;

        if (avg < 70.0) {
            std::cout << "\t<-- review this assignment";
        }

        std::cout << '\n';
    }
}

void print_roster(const Student* students, int student_count) {
    std::cout << "\nROSTER\n";

    // students is a pointer to the first element; it carries no size of its
    // own, so student_count is how far we are permitted to walk
    for (auto i{0}; i < student_count; i++) {
        std::cout << initials_of(students[i].name) << '\t' << students[i].name << '\n';
    }
}
