
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// Checks whether we can allocate books to the given number
// of students without any student exceeding the page limit.
bool isPossible(vector<int>& pages, int students, int limit) {

    int studentCount = 1;  // Start with the first student
    int currentPages = 0;  // Pages assigned to the current student

    for (int i = 0; i < pages.size(); i++) {

        // If this book fits within the current student's limit,
        // assign the book to that student.
        if (currentPages + pages[i] <= limit) {
            currentPages += pages[i];
        }
        else {
            // Otherwise, assign this book to a new student.
            studentCount++;
            currentPages = pages[i];
        }

        // If we need more students than available,
        // this page limit is not feasible.
        if (studentCount > students) {
            return false;
        }
    }

    // All books were allocated using the allowed number of students.
    return true;
}


int allocateBooks(vector<int>& pages, int students) {

    // Each student must receive at least one book.
    // Therefore, more students than books is impossible.
    if (students > pages.size()) {
        return -1;
    }

    // Minimum possible maximum:
    // At least one student must take the largest book.
    int start = *max_element(pages.begin(), pages.end());

    // Maximum possible maximum:
    // One student could receive all the books.
    int end = accumulate(pages.begin(), pages.end(), 0);

    int ans = -1;  // Stores the best feasible answer found so far

    // Binary search for the minimum feasible page limit.
    while (start <= end) {

        // Calculate the middle of the search range safely.
        int mid = start + (end - start) / 2;

        // Check whether this page limit is feasible.
        if (isPossible(pages, students, mid)) {

            // This limit works, so save it.
            ans = mid;

            // Try to find an even smaller feasible limit.
            end = mid - 1;
        }
        else {

            // This limit is too small.
            // Increase the minimum allowed page limit.
            start = mid + 1;
        }
    }

    // Return the minimum possible maximum pages.
    return ans;
}


int main() {

    vector<int> pages = {12, 34, 67, 90};
    int students = 2;

    cout << allocateBooks(pages, students) << endl;

    return 0;
}
