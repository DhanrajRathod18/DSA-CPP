#include <bits/stdc++.h>
using namespace std;

/*
    Function: countStudents

    Purpose:
    --------
    Given a maximum number of pages that one student can get,
    find how many students are required to distribute all books.

    Example:
    arr = [10, 20, 30, 40]
    pages = 60

    Distribution:
    Student 1 -> 10 + 20 + 30 = 60
    Student 2 -> 40

    So, answer = 2 students.
*/

int countStudents(vector<int>& arr, int pages) {

    // Initially, we have one student
    int students = 1;

    // Stores the total pages given to the current student
    long long pagesStudent = 0;

    // Traverse all the books
    for(int i = 0; i < arr.size(); i++) {

        /*
            Check if the current book can be given
            to the current student.

            If adding this book does not exceed
            the maximum allowed pages:
                Add it to the current student.
        */
        if(pagesStudent + arr[i] <= pages) {

            pagesStudent += arr[i];
        }

        /*
            If the current book cannot fit with
            the current student:

            1. Create a new student.
            2. Give the current book to the new student.

            We don't lose the current book.
            It becomes the first book of the new student.
        */
        else {

            students += 1;

            pagesStudent = arr[i];
        }
    }

    // Return the total number of students required
    return students;
}


/*
    Function: findPages

    Purpose:
    --------
    Find the minimum possible value of the maximum
    number of pages assigned to any student.

    We use Binary Search on Answer.

    Example:
    arr = [10, 20, 30, 40]
    m = 2 students

    Possible answer lies between:

    low  = maximum element = 40
    high = total sum       = 100
*/

int findPages(vector<int>& arr, int n, int m) {

    // If there are more students than books,
    // it is impossible to give at least one book to each student.
    if(m > n)
        return -1;


    /*
        LOW = maximum element in the array.

        Why?

        The answer cannot be smaller than the
        largest book.

        Example:
        [10, 20, 30, 40]

        Even if everything is distributed perfectly,
        somebody must take the book with 40 pages.

        Therefore:
        low = 40
    */
    int low = *max_element(arr.begin(), arr.end());


    /*
        HIGH = sum of all elements.

        Why?

        In the worst case, one student may get
        all the books.

        Example:
        10 + 20 + 30 + 40 = 100

        Therefore:
        high = 100
    */
    int high = accumulate(arr.begin(), arr.end(), 0);


    /*
        Binary Search

        We search for the minimum possible maximum
        number of pages.
    */
    while(low <= high) {

        // Find the middle value
        int mid = (low + high) / 2;


        /*
            Check whether 'mid' can be the answer.

            countStudents() tells us how many students
            are required if each student can get at most
            'mid' pages.
        */
        int students = countStudents(arr, mid);


        /*
            CASE 1:
            Required students > available students

            Example:
            Required = 3 students
            Available = 2 students

            This means 'mid' is too small.

            We need to allow more pages per student.

            Therefore, search on the RIGHT side.
        */
        if(students > m) {

            low = mid + 1;
        }


        /*
            CASE 2:
            Required students <= available students

            This means 'mid' is possible.

            But we want the MINIMUM possible answer,
            so we try to find an even smaller value.

            Therefore, search on the LEFT side.
        */
        else {

            high = mid - 1;
        }
    }


    /*
        When the loop ends:

        low > high

        'low' represents the smallest possible
        maximum page allocation.

        Example:
        Answer = 60
    */
    return low;
}


/*
    Main function for testing
*/

int main() {

    // Number of pages in each book
    vector<int> arr = {10, 20, 30, 40};

    // Number of students
    int m = 2;

    // Number of books
    int n = arr.size();

    // Find the minimum possible maximum pages
    int answer = findPages(arr, n, m);

    // Print the answer
    cout << "Minimum possible maximum pages = "
         << answer << endl;

    return 0;
}


/*
    OUTPUT:
    -------
    Minimum possible maximum pages = 60


    Explanation:

    Books = [10, 20, 30, 40]
    Students = 2

    Optimal distribution:

    Student 1 -> [10, 20, 30] = 60 pages
    Student 2 -> [40]          = 40 pages

    The maximum pages assigned to any student = 60.

    Therefore, the answer is 60.


    TIME COMPLEXITY:
    ----------------
    countStudents() -> O(n)

    Binary Search -> O(log(sum - max))

    Overall -> O(n * log(sum))


    SPACE COMPLEXITY:
    -----------------
    O(1) extra space
*/