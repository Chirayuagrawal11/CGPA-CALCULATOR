#include<iostream>
#include <vector>
using namespace std;

struct Course {
    string name;
    int credit;
    float gradePoint;
};

float calculateSGPA(const vector<Course>& courses) {
    float totalCredits = 0;
    float weightedGradePoints = 0;

    for (const auto& course : courses) {
        weightedGradePoints += course.gradePoint * course.credit;
        totalCredits += course.credit;
    }

    return totalCredits == 0 ? 0 : (weightedGradePoints / totalCredits);
}

int main() {
    vector<Course> subjects(5);
    vector<Course> practicals(5);

    cout << "Enter details for 5 Subjects:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "\nSubject " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> subjects[i].name;
        cout << "Credits: ";
        cin >> subjects[i].credit;
        cout << "Grade Point (out of 10): ";
        cin >> subjects[i].gradePoint;
    }

    cout << "\nEnter details for 5 Practicals:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "\nPractical " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> practicals[i].name;
        cout << "Credits: ";
        cin >> practicals[i].credit;
        cout << "Grade Point (out of 10): ";
        cin >> practicals[i].gradePoint;
    }

    vector<Course> allCourses = subjects;
    allCourses.insert(allCourses.end(), practicals.begin(), practicals.end());

    float sgpa = calculateSGPA(allCourses);
    float cgpa = sgpa; // For one semester

    cout << "\nYour SGPA is: " << sgpa << endl;
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}
