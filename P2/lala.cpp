#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[]){

	ifstream fi;
	float a;

	fi.open("Sonic.ply");

	while(!fi.eof()){

		for(int i=0; i < 3; ++i){
			fi >> a;
			cout << a << " ";
		}
	
		cout << endl;

		for(int i=0; i < 11; ++i)
			fi >> a;

	}

	fi.close();

	return 0;
}
