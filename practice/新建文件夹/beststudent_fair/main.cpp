/*
Task: An input file contains the results of students. Each line of the file begins with the name of the student
(string without spaces), then a subjectname (does not including spaces) and the results of the student in the given
subject follow. Each result consists of a task and a grade obtained for the task.
The file is ordered by the name of students.

Input file sample:

Adam literature written-exam 4 oral-exam 1 essay 2 presentation 4
Adam mathematics proof 2 exam 4 homework 5
Kate physics test 2 exam 2 homework 1

Provide the student who obtained the best average in any subject. Also provide the subject in which
the best average is obtained.
*/

#include <iostream>
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/stringstreamenumerator.hpp"

using namespace std;

// Each line of the inputfile contains (besides a studentname and a subjectname) elements of type Mark.
// A Mark type record includes a task and a grade obtained for the given task.
struct Mark
{
    string task;
    int grade;
    // The number of Marks is not fixed, it varies line by line.
    // This is why we can read them by using a loop, more precisely - as we are not allowed to use loop -, we enumerate
    // them as elements of a file.
    // However, we cannot enumerate elements of two different types, therefore, overdefining the >> operator is
    // necessary, as we intend to read the string and integer components as a whole, as a Mark type of element
    friend istream &operator>>(istream& is,Mark &m)
    {
        is >> m.task >> m.grade;
        return is;
    }
};

// We have to calculate the average obtained in a given subject. In order to do that, we keep track of
// the sum of the grades and the number of grades read. Both of them can be achieved by using an algorithmic pattern.
// We cannot traverse the elements of a line twice (except if we put them into a vector, but remember, to do that,
// you have to identify an algorithmic pattern and use the template library).
// Instead, we combine the two algorithmic patterns into a Summation, where the f (func) function of Summation
// gives a multiple value: one component for the sum of the grades, the other is for the number of grades.
struct Result
{
    int sum;
    int count;
    Result() {}
    Result(int s,int c):sum(s),count(c) {}
};

// So we have to do a summation and a counting at the same time.
// Here comes the summation mentioned above. Its func function assigns a Result type element to a Mark type element.
// Let us suppose we have three grades: 2, 5, 4.
// In order to calculate their sum and count them, we need to add the following Result type elements:
// (2,1), (5,1), (4,1)
// We override the methods considering this.
class Average : public Summation<Mark,Result>
{
    Result func(const Mark& e) const override
    {
        return Result(e.grade,1);
    }
    // The neutral element of the counting and calculating the sum of grades is also 0.
    Result neutral() const override { return Result(0,0); }
    Result add( const Result& a, const Result& b) const override
    {
        return Result(a.sum+b.sum,a.count+b.count);
    }
};

// In order to solve the original problem, we should enumerate Student type of elements, where each student record
// stores the name of the student, a coursename, and the average obtained by the student from the given course.
// The inputfile contains different type of elements: each line is composed by a studentname, a subjectname and
// a sequence of task-grade pairs. Based on the latter, the average of the student can be calculated.
// In other words, our iterator will enumerate the same number of Students as the number of lines the inputfile has,
// let us say we convert the sequence of task-grade pairs into a single number, the average of the grades.
struct Student
{
    string name;
    string course;
    double avg;
    // Besides providing the studentname and the coursename, we also provide the average the student obtained from
    // the course (and do not provide the task-grade pairs). By doing this, we extract only the essential data
    // stored in a line.
    friend istream &operator>>(istream& is,Student &st)
    {
        string line;
        getline(is,line);
        stringstream ss(line);
        ss >> st.name;
        ss >> st.course;
        // Now variable ss contains only task-grade pairs (which we can consider as Marks as we overdefined the >>
        // operator for them).
        Average pr;
        StringStreamEnumerator<Mark> enor(ss);
        pr.addEnumerator(&enor);
        pr.run();
        // The type of the value provided by pr.result() is Result. It is a record with a sum and a count
        // components, respectively. We calculate the average in a way to avoid dividing by zero:
        Result res = pr.result();
        if (res.count == 0)
            st.avg = 0;
        else st.avg = double(res.sum) / res.count; // int/int=int
        return is;
    }
};

// The original problem can by solved by applying a maximum search, as we can enumerate the averages
// per students and courses.
// Obviously, the function - whose maximum value we are looking for - is not else but a function that assigns the
// average component to an enumerated Student type of element.
class BestStudent : public MaxSearch<Student,double>
{
    double func(const Student& e) const override
    {
        return e.avg;
    }
};

int main()
{
    // recall: SeqInFileEnumerator has an Exceptions type member
    try
    {
        SeqInFileEnumerator<Student> enor("input.txt");
        BestStudent bs;
        bs.addEnumerator(&enor);
        bs.run();
        // In case of maximum search the condition cond is true by default; we are looking for the maximum value that
        // can be taken at any element (for which the true condition holds).
        // The found() method can be used in case of a maximum search as well (not only in case of conditional maximum
        // search), in order to decide whether there was an enumerated element for which the cond condition holds,
        // i.e. the enumeration is not empty.
        if (bs.found())
        {
            // max value - opt(), in our case it is an average of grades
            // max element - optElem(), in our case it is a Student type of element with a course and a name components
            cout << "Best student: "<< bs.optElem().name << " Course: " << bs.optElem().course
                 << " Average: "<< bs.opt() << endl;
        }
    }
    catch (SeqInFileEnumerator<Student>::Exceptions err)
    {
        cout<<"File not found.";
    }
    return 0;
}
