// include/grading.h
#ifndef GRADING_H
#define GRADING_H

#include "student.h"

/**
 * @brief Calculates one student's mean score across all assignments.
 *
 * @post student is not modified.
 *
 * @param[in] student  The student to average.
 * @return The mean of that student's assignment scores.
 */
[[nodiscard]] double student_average(const Student& student);

/**
 * @brief Calculates the mean score on one assignment across all students.
 *
 * @pre students points to at least student_count records.
 * @pre student_count is not negative.
 * @pre assignment_index is in the range [0, assignment_count).
 * @post No student is modified.
 *
 * @param[in] students          Pointer to the first student in the roster.
 * @param[in] student_count     How many students the roster holds.
 * @param[in] assignment_index  Which assignment to average.
 * @return The mean score earned on that assignment, or 0.0 for an empty roster.
 */
[[nodiscard]] double assignment_average(const Student* students,
                                        int student_count,
                                        int assignment_index);

/**
 * @brief Calculates the mean of every score in the roster.
 *
 * @pre students points to at least student_count records.
 * @pre student_count is not negative.
 * @post No student is modified.
 *
 * @param[in] students       Pointer to the first student in the roster.
 * @param[in] student_count  How many students the roster holds.
 * @return The mean of all student_count * assignment_count scores,
 *         or 0.0 for an empty roster.
 */
[[nodiscard]] double class_average(const Student* students, int student_count);

/**
 * @brief Finds one student's lowest and highest assignment scores.
 *
 * @post lowest holds that student's minimum score.
 * @post highest holds that student's maximum score.
 * @post student is not modified.
 *
 * @param[in]  student  The student to examine.
 * @param[out] lowest   Receives the minimum score.
 * @param[out] highest  Receives the maximum score.
 */
void find_extremes(const Student& student, double& lowest, double& highest);

/**
 * @brief Counts how many students earned a given letter grade.
 *
 * @pre students points to at least student_count records.
 * @pre student_count is not negative.
 * @pre target is one of 'A', 'B', 'C', 'D', or 'F'.
 * @post No student is modified.
 *
 * @param[in] students       Pointer to the first student in the roster.
 * @param[in] student_count  How many students the roster holds.
 * @param[in] target         The letter grade to count.
 * @return The number of students whose average earns that letter.
 */
[[nodiscard]] int count_grade(const Student* students, int student_count, char target);

/**
 * @brief Reports whether a student earned a perfect score on any assignment.
 *
 * @post student is not modified.
 *
 * @param[in] student  The student to examine.
 * @return true if any of that student's scores is 100 or above.
 */
[[nodiscard]] bool has_perfect_score(const Student& student);

/**
 * @brief Reports whether a student is academically at risk.
 *
 * A student is at risk when their average is below 70, or when any
 * single assignment score is below 50.
 *
 * @post student is not modified.
 *
 * @param[in] student  The student to examine.
 * @return true if either at-risk condition holds.
 */
[[nodiscard]] bool is_at_risk(const Student& student);

#endif
