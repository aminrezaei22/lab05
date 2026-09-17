// include/printing.h
#ifndef PRINTING_H
#define PRINTING_H

#include "student.h"

constexpr int name_width{14};

/**
 * @brief Prints the column header for the full grade report.
 *
 * @post Writes to standard output.
 */
void print_header(const int num_students, const int num_assignments);

/**
 * @brief Prints one student's row of the full grade report.
 *
 * The row shows the padded name, each assignment score, the average,
 * the letter grade, and markers for a perfect score or at-risk status.
 *
 * @post student is not modified.
 * @post Writes to standard output.
 *
 * @param[in] student  The student to print.
 */
void print_student_row(const Student& student);

/**
 * @brief Prints a bar chart of how many students earned each letter grade.
 *
 * @pre students points to at least student_count records.
 * @pre student_count is not negative.
 * @post No student is modified.
 * @post Writes to standard output.
 *
 * @param[in] students       Pointer to the first student in the roster.
 * @param[in] student_count  How many students the roster holds.
 */
void print_histogram(const Student* students, int student_count);

/**
 * @brief Prints the mean score for each assignment.
 *
 * Assignments averaging below 70 are flagged for review.
 *
 * @pre students points to at least student_count records.
 * @pre student_count is not negative.
 * @post No student is modified.
 * @post Writes to standard output.
 *
 * @param[in] students       Pointer to the first student in the roster.
 * @param[in] student_count  How many students the roster holds.
 */
void print_assignment_summary(const Student* students, int student_count);

/**
 * @brief Prints each student's initials beside their full name.
 *
 * @pre students points to at least student_count records.
 * @pre student_count is not negative.
 * @post No student is modified.
 * @post Writes to standard output.
 *
 * @param[in] students       Pointer to the first student in the roster.
 * @param[in] student_count  How many students the roster holds.
 */
void print_roster(const Student* students, int student_count);

#endif
