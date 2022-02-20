//Author:   Rasul Khanbayov GGUSA3
//Date:     2020.04.12.
//Title:    8

#include "angler.h"

using namespace std;

void AnglerEnor::next(){
    if( !(_end = _tt.end()) ){
    _cur.id = _tt.current().angler;
    _cur.num = 0;
    for( ; !_tt.end() && _tt.current().angler == _cur.id ; _tt.next() ){
            _cur.num += _tt.current().counter;
        }
    }
}
