//This i a grade 5 level problem.
/*
Task: An input file contains the results of students. Each line of the file begins with the name of the student
(string without spaces), then a subjectname (does not including spaces) and the results of the student in the given
subject follow. Each result consists of a task and a grade obtained for the task.
The file is ordered by the name of students.

Input file sample:

Adam literature written-exam 4 oral-exam 1 essay 2 presentation 4
Adam mathematics proof 2 exam 4 homework 5
Kate physics test 2 exam 2 homework 1

Find the student who obtained the most total number of 5 grades among the students who obtained grade 1
in each of their subject.
*/
/*
When solving this problem, algorithmic pattern + enumerator (one cannot use an algorithmic pattern without traversing
some kind of elements) will be used at three levels:
1. In the main program, conditional maximum search will be used over the elements of an enumerator that produces
essential data for each student: name of the student, total number of 5s obtained by the student, a boolean value
indicating whether it is true that the student has a failing grade in all of his/her subjects.

2. The enumerated elements of the mentioned enumerator are provided by the next() method of the enumerator.
In the next() method we process Line type of elements, where a Line type of element is a record capturing
the main information from a line in the file: name of the student, number of 5s obtained by the student in the
given subject, a boolean value indicating whether the student got a failing grade in the given subject. In other
words, we have the same number of enumerated Line type of elements as many lines the input file has.
A Line type of record represents a line of the input file, storing its essential data only.

In order to count the total number of 5s a student obtained, we have to traverse the Line type of elements
that belong to the same student and calculate the sum of number of 5s. In order to decide whether the student
has a failing grade in each of his/her subject, we traverse the same Line type of elements and calculate a big
logical AND, denoting whether it is always true that the logical component of a Line type of element (indicating
the student has a failing grade in a given subject) is true.

3.
We produce the Line type of elements by traversing the task-grade pairs of a line of an inputfile and
determining the sum of 5s in the line and a logical value indicating whether there is a failing grade in the line.
*/
#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"

using namespace std;

// In each line of the inputfile there are Mark type of pairs (after the name of the student and the name of the course)
struct Mark
{
    string task;
    int grade;
    // It is not fixed, how many task-grade pairs a line of the inputfile contains, the number of pairs varies
    // line by line. Of course, we will apply an algorithmic pattern (summation) in order to read the pairs.
    // In case we use a template class from the library, we have to provide the type of the elements we intend to
    // traverse, this is why it is useful to handle a task-grade pairs together and be able to read them as a whole.
    friend istream &operator>>(istream& is,Mark &m)
    {
        is >> m.task >> m.grade;
        return is;
    }
};

// The type Result is needed to denote the type of the result value of the function of the summation that calculates
// for each line the number of 5s and the logical value indicating whether there is a failing grade in the line
struct Result
{
    int numberOf5s;
    bool fail;
    Result() {}
    Result(int n,bool f): numberOf5s(n), fail(f) {}
};

// Using only a single loop (exactly one algorithmic pattern), we calculate the number of 5s and the boolean variable
// indicating whether there is a faling grade among the grades in a given course.
// These two values will be used later, when accumulate the total result for each student.
// In fact, we calculate the logical value by using a summation (calculating a big logical OR), in order to traverse
// the elements once by combining the two summation. In this case the function of the summation has to produce two values
// for each Mark type of element.
class LineSum : public Summation<Mark,Result>
{
// The func function of the summation assigns a Result type of element to a Mark type of element.
// The component holding the number of grades has to be 1 if the grade part of the processed Mark is 5, otherwise
// it has to be zero.
// The component holding the boolean value indicating whether there was a failing grade has to be true if the grade
// part of the processed Mark is 1, otherwise it has to be false.
    Result func(const Mark &e) const override { return Result((e.grade==5) ? 1 : 0, e.grade==1); }
    Result neutral() const override { return Result(0, false); }
// Notice, here we have to define how we add the values of the function func. The type of values is Result, not Mark.
    Result add(const Result &a, const Result &b) const override { return Result(a.numberOf5s+b.numberOf5s, a.fail ||b.fail);}
};

// Egyelőre a fájl egy sorából olvassuk ki a számunkra fontos információkat: hallgató neve,
// ötöseinek száma az adott tárgyból és hogy volt-e egyes a jegyei között az adott tárgyból.
// Az ilyen hármasokat jelölő rekordtípus legyen Line.

// Here we produce a Line type of elements by traversing the task-grade pairs of a line of an inputfile and
// determining the sum of 5s in the line and a logical value indicating whether there is a failing grade in the line.
struct Line
{
    string name;
    int numberOf5s;
    bool fail;
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
        line.numberOf5s = pr.result().numberOf5s;
        line.fail = pr.result().fail;
        return is;
    }
};

// By reading the lines of the inputfile, we enumerate Line type. Where the name component of two Line type of
// elements are equal, they belong to the same student.
// We have to calculate the sum of their number of 5s components (in order to get the total number of  5s the
// student obtained). Moreover, we have to connect the logical components by the operator "and" in order to get
// the answer whether it is true that the students has a failing grade in each subject.
// This will be done in the next() method of the enumerator that enumerates Student type of elements by using the
// following double summation.
class DoubleSummation : public Summation<Line, Result>
{
private:
    string _name;
public:
    DoubleSummation(const string &name) : _name(name) {}
protected:
    Result func(const Line &e) const override { return Result(e.numberOf5s, e.fail); }
    // the neutral element of the logical "and" operation is the true logical value
    Result neutral() const override { return Result(0, true); }
    Result add(const Result &a, const Result &b) const override { return Result(a.numberOf5s+b.numberOf5s, a.fail && b.fail);}
    // We have to overdefine the whilecond method in order to modify the loopcondition as we do not want to process
    // all Line type of element, only those which belong to the same student we started the process with.
    bool whileCond(const Line &e) const override { return e.name==_name; }
    // The run() method of the Procedure class describes the general algorithm of algorithmic patterns.
    // The loop of run() traverses the enumerated elements, where the method first() steps on the first element
    // of the iterator. By default, first() is _enor->first()
    // In our case, when the next() method started, a Line type of element (the first that belongs to a certain
    // student) was taken. There is no need to take an other element, that first element is not processed yet.
    // Therefore, the first() method of DoubleSummation (inherited from the Procedure) class should be
    // overriden by the SKIP program.
    void first() override {}
};

// In order to solve the original problem, we enumerate Student type of elements, providing the total
// number of 5s and a boolean value indicating whether it is true that the student got a failing grade in each of
// his/her subjects, per students.
struct Student
{
    string name;
    int totalNumberOf5s;
    bool failInEachSubject;
};

// The enumerated Student type of elements are constructed by traversing Line type of elements produced
// by the inputfile.
// As there is no class in the library that enables us to enumerate Student type of elements, we have to create our
// own enumerator by providing its first(), next(), end() and current() methods.
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

// We have to calculate the total number of 5s a student obtained together with the logical value indicating
// whether it is true that the student has a failing grade in each of his/her subject. To to this, we just have to
// use the DoubleSummation class, it will do the task for us.
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
        DoubleSummation pr(_student.name);
        pr.addEnumerator(_f);
        pr.run();
        _student.totalNumberOf5s = pr.result().numberOf5s;
        _student.failInEachSubject = pr.result().fail;
    }
}

// The original problem can by solved by applying a conditional maximum search, as we can enumerate the total
// number of 5s a student obtained and we also know for each student whether he/she has a failing grade
// in all of /his/her subjects.
// Obviously, the f function - whose maximum value we are looking for nad called func in the MaxSearch class - is
// not else than a function that assigns the total number of 5s component to an enumerated Student type of element.
// Meanwhile, the cond function gives for each Student type of element, whether the given student has a failing
// grade in each of his/her subjects.
class BestStudent : public MaxSearch<Student,int>
{
protected:
    int func(const Student &e) const override { return e.totalNumberOf5s; }
    bool cond(const Student &e) const override { return e.failInEachSubject; }
};

int main()
{
    try
    {
        BestStudent pr;
        StudentEnumerator enor("input.txt");
        pr.addEnumerator(&enor);
        pr.run();
        if (pr.found())
        {
            cout << "Student who obtained the most number of 5 grades (and got a 1 grade in each subject): " << pr.optElem().name << endl;
            cout << "Number of 5s obtained by the student: "<< pr.opt() << endl;
        }
        else cout << "The file is empty or there was no student who got a 1 in each subject.\n";
    }
    catch (SeqInFileEnumerator<Line>::Exceptions exc)
    {
        cout << "The file does not exist.\n";
    }
    return 0;
}
