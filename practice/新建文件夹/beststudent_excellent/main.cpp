/*
Task: An input file contains the results of students. Each line of the file begins with the name of the student
(string without spaces), then a subjectname (does not including spaces) and the results of the student in the given
subject follow. Each result consists of a task and a grade obtained for the task.
The file is ordered by the name of students.

Input file sample:

Adam literature written-exam 4 oral-exam 1 essay 2 presentation 4
Adam mathematics proof 2 exam 4 homework 5
Kate physics test 2 exam 2 homework 1
kate

Provide the student who obtained the best total average.

*/
#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"

using namespace std;

// Each line of the inputfile contains (besides a studentname and a subjectname) elements of type Mark.
// A Mark type record includes a task and a grade obtained for the given task.
struct Mark
{
    string task;
    int grade;
    friend istream &operator>>(istream& is,Mark &m)
    {
        is >> m.task >> m.grade;
        return is;
    }
};

struct Result
{
    int sum;
    int count;
    Result() {}
    Result(int s,int c):sum(s),count(c) {}
};

// Using only a single loop (exactly one algorithmic pattern), we calculate the sum and the number of grades
// contained in a certain line of a file.
// We do not calculate average yet, as all the grades have to be added and counted that belongs to the same student
// and are placed in consecutive lines of the input file.


//The func function assigns a Result type element to a Mark type element.
class LineSum : public Summation<Mark,Result>
{
    Result func(const Mark &e) const override { return Result(e.grade, 1); }
    Result neutral() const override { return Result(0, 0); }
    Result add(const Result &a, const Result &b) const override { return Result(a.sum+b.sum, a.count+b.count);}
};

struct Line
{
    string name;
    int sum;
    int count;
    friend istream& operator>>(istream &is, Line &line)
    {
        string str, course;
        getline(is, str);
        stringstream ss(str);
        ss >> line.name;
        ss >> course;
        // Now variable ss contains only task-grade pairs (which we can consider as Marks as we overdefined the >>
        // operator for them).
        LineSum pr;
        StringStreamEnumerator<Mark> enor(ss);
        pr.addEnumerator(&enor);
        pr.run();
        line.sum = pr.result().sum;
        line.count = pr.result().count;
        return is;
    }
};

class Average : public Summation<Line, Result>
{
private:
    string _name;
public:
    Average(const string &name) : _name(name) {}
protected:
    Result func(const Line &e) const override { return Result(e.sum, e.count); }
    Result neutral() const override { return Result(0, 0); }
    Result add(const Result &a, const Result &b) const override { return Result(a.sum+b.sum, a.count+b.count);}

    bool whileCond(const Line &e) const override { return e.name==_name; }
    // The run() method of the Procedure class describes the general algorithm of algorithmic patterns.
    // The loop of run() traverses the enumerated elements, where the method first() stpes on the first element
    // of the iterator. By default, first() is _enor->first()
    // In our case, when the next() method started, a Line type of element (the first that belongs to a certain student)
    // was taken. There is no need to take an other element, that line is not processed yet.
    // Therefore, the first() method of Average (inherited from the Procedure) class should be
    // overriden by the SKIP program
    void first() override {}
};

struct Student
{
    string name;
    double avr;
};

// In order to solve the original problem, we enumerate Student type of elements, providing the total
// average per students.
// The enumerated elements are constructed by traversing Line type of elements produced by a file.
class StudentEnumerator : public Enumerator<Student>
{
private:
    SeqInFileEnumerator<Line> *_f;
    Student _student;
    bool _end;
public:
    StudentEnumerator(const string &fname) { _f = new SeqInFileEnumerator<Line>(fname); }
    ~StudentEnumerator() { delete _f; }
    void first() override { _f->first(); next();}
    void next() override;
    Student current() const override { return _student; }
    bool end() const override { return _end; }
};

void StudentEnumerator::next()
{
    if (_f->end())
    {
        _end=true;
    }
    else
    {
        _end=false;
        _student.name = _f->current().name;
        // Calculating the sum of grades and the number of grades, where the grades come from lines that belong
        // to the same student
        Average pr(_student.name);
        pr.addEnumerator(_f);
        pr.run();
        if (pr.result().count == 0) _student.avr = 0.0;
        else _student.avr = double(pr.result().sum) / pr.result().count;
    }
}

// The original problem can by solved by applying a maximum search, as we can enumerate the total average of students.
// Obviously, the function - whose maximum value we are looking for - is not else but a function that assigns the
// average component to an enumerated Student type of element.
class BestStudent : public MaxSearch<Student,double>
{
protected:
    double func(const Student &e) const override { return e.avr; }
};

int main()
{
    try
    {
    BestStudent pr;
    StudentEnumerator enor("input.txt");
    pr.addEnumerator(&enor);
    pr.run();
    if (pr.found()) cout << "Best student: " << pr.optElem().name << ", average: "<< pr.opt() << endl;
    else cout << "The file is empty.\n";
    } catch (SeqInFileEnumerator<Line>::Exceptions exc)
    {
        cout << "The file does not exist.\n";
    }
    return 0;
}
