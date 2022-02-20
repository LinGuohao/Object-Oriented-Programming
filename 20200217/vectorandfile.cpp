#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void fillUpFromFile(vector<int>& vec, const string fileName);
bool condMaxSearch(vector<int> vec, int& max, unsigned int& ind);

int main(){
	
	vector<int> heights;
	
	fillUpFromFile(heights, "infile.txt");
	
	int deepestDent;
	unsigned int deepestInd;
	
	bool found =condMaxSearch (heights,deepestDent,deepestInd);	
	if (found){
		cout << "Volt, meghozza: " << deepestDent << "m, es az indexe: " << deepestInd << endl;
	} else {
		cout << "Nem volt" << endl;
	}
	
	return 0;
}

void fillUpFromFile(vector<int>& vec, const string fileName){
	ifstream file("input.txt");
	int tmp;
	while (file >> tmp){
		vec.push_back(tmp);
	}
	
	file.close();
	
}

bool condMaxSearch(vector<int> vec, int& max, unsigned int& ind){
	bool l = false;
	unsigned int n = vec.size();
	for (unsigned int i = 1; i <= n-2; i++){
	     if(vec[i]<vec[i+1] && vec[i]<vec[i-1]&& l == false)
	     {
	     	max= vec[i];
	     	ind = i;
	     	l = true;
		 }
        if(vec[i]<vec[i+1] && vec[i]<vec[i-1]&& l == true)
        {
        	if(vec[i]>max)
        	{
        		max=vec[i];
        		ind = i;
			}
		}
	}
	return l;
}


