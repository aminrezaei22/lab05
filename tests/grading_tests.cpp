#include <gtest/gtest.h>

#include "grading.h"
#include "student.h"
#include "utilities.h"

// Every Student holds exactly assignment_count (5) scores. Always write all
// five: a shorter brace list compiles and fills the rest with 0.0.

TEST(GradingEdgeCases, OneStudent) {
    const Student students[]{
        {"Solo Student", {85.0, 85.0, 85.0, 85.0, 85.0}}
    };

    EXPECT_DOUBLE_EQ(student_average(students[0]), 85.0);
    EXPECT_DOUBLE_EQ(assignment_average(students, 1, 0), 85.0);
    EXPECT_DOUBLE_EQ(class_average(students, 1), 85.0);

    double lowest, highest;
    find_extremes(students[0], lowest, highest);
    EXPECT_DOUBLE_EQ(lowest, 85.0);
    EXPECT_DOUBLE_EQ(highest, 85.0);

    EXPECT_FALSE(is_at_risk(students[0]));
    EXPECT_FALSE(has_perfect_score(students[0]));
}

TEST(GradingEdgeCases, MixedScores) {
    const Student student{"Mixed Scores", {100.0, 45.0, 45.0, 90.0, 70.0}};

    EXPECT_DOUBLE_EQ(student_average(student), 70.0);

    // Has multiple failing assignments (< 50)
    EXPECT_TRUE(is_at_risk(student));
    EXPECT_TRUE(has_perfect_score(student));
}

TEST(GradingEdgeCases, ZeroesAndNegativeValues) {
    const Student students[]{
        {"Zero Scores", {0.0, 0.0, 0.0, 0.0, 0.0}},
        {"Negative Scores", {-10.0, -50.0, -5.0, -5.0, -5.0}}
    };

    EXPECT_DOUBLE_EQ(class_average(students, 2), -75.0 / 10.0);

    double lowest, highest;
    find_extremes(students[1], lowest, highest);
    EXPECT_DOUBLE_EQ(lowest, -50.0);
    EXPECT_DOUBLE_EQ(highest, -5.0);

    EXPECT_TRUE(is_at_risk(students[1]));
}

TEST(GradingEdgeCases, AtRiskVariations) {
    const Student low_one{"Low One", {80.0, 80.0, 80.0, 80.0, 49.0}};      // Avg 73.8, but one assignment < 50
    const Student low_average{"Low Average", {55.0, 55.0, 55.0, 55.0, 55.0}}; // All > 50, but avg < 70
    const Student low_many{"Low Many", {40.0, 45.0, 90.0, 90.0, 90.0}};    // Avg 71, multiple assignments < 50
    const Student passing{"Just Passing", {70.0, 70.0, 70.0, 70.0, 70.0}};   // Avg 70, no assignments < 50

    EXPECT_TRUE(is_at_risk(low_one));
    EXPECT_TRUE(is_at_risk(low_average));
    EXPECT_TRUE(is_at_risk(low_many));
    EXPECT_FALSE(is_at_risk(passing));
}

TEST(GradingEdgeCases, PerfectScoreVariations) {
    const Student almost{"Almost Perfect", {99.9, 99.9, 99.9, 99.9, 99.9}};  // No 100
    const Student one{"One Perfect", {100.0, 0.0, 0.0, 0.0, 0.0}};           // Exactly one 100
    const Student many{"Many Perfect", {105.0, 100.0, 102.0, 100.0, 100.0}}; // Multiple >= 100

    EXPECT_FALSE(has_perfect_score(almost));
    EXPECT_TRUE(has_perfect_score(one));
    EXPECT_TRUE(has_perfect_score(many));
}

TEST(GradingEdgeCases, EmptyRoster) {
    EXPECT_DOUBLE_EQ(class_average(nullptr, 0), 0.0);
    EXPECT_DOUBLE_EQ(assignment_average(nullptr, 0, 0), 0.0);
    EXPECT_EQ(count_grade(nullptr, 0, 'A'), 0);
}

TEST(GradingEdgeCases, TwoStudentRoster) {
    const Student students[]{
        {"Top Student", {90.0, 90.0, 90.0, 90.0, 90.0}},
        {"Low Student", {50.0, 50.0, 50.0, 50.0, 50.0}}
    };

    EXPECT_DOUBLE_EQ(assignment_average(students, 2, 4), 70.0);
    EXPECT_DOUBLE_EQ(class_average(students, 2), 70.0);
    EXPECT_EQ(count_grade(students, 2, 'A'), 1);
    EXPECT_EQ(count_grade(students, 2, 'F'), 1);
    EXPECT_EQ(count_grade(students, 2, 'C'), 0);
}
