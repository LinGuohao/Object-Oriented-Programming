/*
Task: An input file contains the results of students. Each line of the file begins with the name of the student
(string without spaces), then a subjectname (does not including spaces) and the results of the student in the given
subject follow. Each result consists of a task and a grade obtained for the task.
The file is ordered by the name of students.

Input file sample:

Adam literature written-exam 4 oral-exam 1 essay 2 presentation 4
Adam mathematics proof 2 exam 4 homework 5
Kate physics test 2 exam 2 homework 1

Sort out the students who obtained a failing grade in each subject together with their total number of obtained 5s.
*/
/*
When solving this problem, algorithmic pattern + enumerator (one cannot use an algorithmic pattern without traversing
some kind of elements) will be used at three levels:
1. In the main program, summation will be used over the elements of an enumerator that produces
essential data for each student: name of the student, total number of 5s obtained by the student, a boolean value
indicating whether it is that the student has a failing grade in all of his/her subjects.

2. ...


3. ...

Everything else is the same as it was in the "mostNumberOf5s_hasA1InEachSubject" problem.
*/

#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"

using namespace std;

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
    int numberOf5s;
    bool fail;
    Result() {}
    Result(int n,bool f): numberOf5s(n), fail(f) {}
};

class LineSum : public Summation<Mark,Result>
{
    Result func(const Mark &e) const override { return Result((e.grade==5) ? 1 : 0, e.grade==1); }
    Result neutral() const override { return Result(0, false); }
    Result add(const Result &a, const Result &b) const override { return Result(a.numberOf5s+b.numberOf5s, a.fail ||b.fail);}
};

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
        LineSum pr;
        StringStreamEnumerator<Mark> enor(ss);
        pr.addEnumerator(&enor);
        pr.run();
        line.numberOf5s = pr.result().numberOf5s;
        line.fail = pr.result().fail;
        return is;
    }
};

class DoubleSummation : public Summation<Line, Result>
{
private:
    string _name;
public:
    DoubleSummation(const string &name) : _name(name) {}
protected:
    Result func(const Line &e) const override { return Result(e.numberOf5s, e.fail); }
    Result neutral() const override { return Result(0, true); }
    Result add(const Result &a, const Result &b) const override { return Result(a.numberOf5s+b.numberOf5s, a.fail && b.fail);}
    bool whileCond(const Line &e) const override { return e.name==_name; }
    void first() override {}
};

struct Student
{
    string name;
    int totalNumberOf5s;
    bool failInEachSubject;
};

class StudentEnumerator : public Enumerator<Student>
{
private:
    SeqInFileEnumerator<Line> *_f;
    // _f->first(): steps on the first element in the file containing Lines, this method is
    //              given in the class SeqInFileEnumerator
    // first(): method of the class StudentEnumerator, steps on the first element
    //          in the enumeration of Students, we have to implement this method
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
        DoubleSummation pr(_student.name);
        pr.addEnumerator(_f);
        pr.run();
        _student.totalNumberOf5s = pr.result().numberOf5s;
        _student.failInEachSubject = pr.result().fail;
    }
}

// In case we can enumerate the total number of obtained 5s for each student together with the boolean value indicating whether the
// student has a failing grade in each subject, the given problem can be solved easily, using a (conditional) summation.
// That version of the summation template class is used where the type of the second parameter is ostream.
// See the slides of the 10. lecture for more details (slides 23-25).
class Write : public Summation<Student,ostream>{
public:
    Write(ostream* o) : Summation<Student, ostream> (o) {}
protected:
    string func(const Student &e) const override {
        ostringstream os;
        os << e.name << " " << e.totalNumberOf5s <<endl;
        return os.str();
    }
    // In our summation we do not want to take into account all enumerated elements, only those which satisfy the given condition.
    // If the condition is missing, all students will be listed together with his/her total number of obtained grades.
    bool cond(const Student &e) const override { return e.failInEachSubject; }
};

int main()
{
    try
    {
        StudentEnumerator enor("input.txt");
        Write w(&cout);
        w.addEnumerator(&enor);
        w.run();
    }
    catch (SeqInFileEnumerator<Line>::Exceptions exc)
    {
        cout << "The file does not exist.\n";
    }
    return 0;
}
