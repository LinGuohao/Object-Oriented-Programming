//Author:   Rasul Khanbayov GGUSA3
//Date:     2020.04.12.
//Title:    8

#include <iostream>
#include "angler.h"

using namespace std;

bool MaximumSearch(const string &file, Angler &b){
    AnglerEnor t (file);
    t.first();
    b=t.current();
    t.next();
    while(!t.end()){
        if(t.current().num > b.num){
            b=t.current();
        }
        t.next();
    }
    if(b.num!=0){
        return true;
    }
    else{
    return false;
    }
}

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    Angler maxi;
    try {
    if(MaximumSearch ("t4.txt",maxi)){
        cout << maxi.id << " has caught the most Tuna : " <<  maxi.num << " Tuna" << endl;
    }
    else{
        cout << "No one has caught the Tuna! " << endl;
    }
    }catch(ContestEnor::Errors err)
    {
        if(err==ContestEnor::FILEERROR){
            cout<<"The file is not available or cannot be opened.\n";
        }
    }
    return 0;
}



#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("empty file", "t0.txt") {
    Angler b;
    CHECK_FALSE(MaximumSearch("t0.txt", b));
}

TEST_CASE("1 angler who has caught 2 Tuna", "t2.txt") {
    Angler b;
    CHECK(MaximumSearch("t2.txt", b));
}

TEST_CASE("more anglers more contests", "t4.txt") {
    Angler b;
    CHECK(MaximumSearch("t4.txt", b));
}

TEST_CASE("first angler who caught most Tuna ", "t4.txt") {
    Angler b;
    CHECK(MaximumSearch("t4.txt", b));
}

TEST_CASE("last angler who caught most Tuna", "t5.txt") {
    Angler b;
    CHECK(MaximumSearch("t5.txt", b));
}

TEST_CASE("There is an angler who caught one Tuna ", "t6.txt") {
    Angler b;
    CHECK(MaximumSearch("t6.txt", b));
}


TEST_CASE("There are anglers but no one caught Tuna ", "t6.txt") {
    Angler b;
    CHECK_FALSE(MaximumSearch("t7.txt", b));
}

/// counting

TEST_CASE("no catch", "t1.txt") {
    ContestEnor tt("t1.txt");
    tt.first();
    CHECK(tt.current().counter == 0);
}

TEST_CASE("1 catch", "t12.txt") {
    ContestEnor tt("t12.txt");
    tt.first();
    CHECK(tt.current().counter == 0);
}

TEST_CASE("more catches", "t9.txt") {
    ContestEnor tt("t9.txt");
    tt.first();
    CHECK(tt.current().counter == 0);
}

TEST_CASE("first catch is Tuna", "t8.txt") {
    ContestEnor tt("t8.txt");
    tt.first();
    CHECK(tt.current().counter == 1);
}

TEST_CASE("last catch is Tuna", "t3.txt") {
    ContestEnor tt("t3.txt");
    tt.first();
    CHECK(tt.current().counter == 1);
}

TEST_CASE("no Tuna", "t9.txt") {
    ContestEnor tt("t9.txt");
    tt.first();
    CHECK(tt.current().counter == 0);
}

TEST_CASE("1 Tuna", "t10.txt") {
    ContestEnor tt("t10.txt");
    tt.first();
    CHECK(tt.current().counter == 1);
}

TEST_CASE("Line containing more caught Tuna", "t11.txt") {
    ContestEnor tt("t11.txt");
    tt.first();
    CHECK(tt.current().counter == 3);
}

#endif
