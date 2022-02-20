#include <iostream>
#include <vector>
#include <fstream>
#include "point.h"
#include "circle.h"

using namespace std;

int main()
{
    Circle c(Point(0, 0), 5);
    vector<Point> points;

    ///in each iteration of the loop two doubles are read from the file input.txt and
    ///put them into the vector as a Point object p
    ifstream f("input.txt");
    double xcoord, ycoord;
    while (f >> xcoord >> ycoord)
    {
            Point p(xcoord, ycoord);
            points.push_back(p);
            //cout << xcoord << " " << ycoord << endl;
    }

    ///linear search for finding the first point in the vector points ...

    bool l = false;
    int ind;
    unsigned int i = 0;
    while(l==false && i<points.size()){
        l=c.isInside(points[i]);
        ind=i;
        i=i+1;
    }
    if(l==true){
    cout << ind << endl;
    cout << points[ind-1].getX() << " " << points[ind-1].getY();
    }
    else{
        cout << "There is no such elements" << endl;
    }
    return 0;
}
