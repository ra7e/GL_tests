#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int counter = 0;
	if(atoi(argv[2]) != 0){
		for(int i = 0; i < atoi(argv[1]); i++){
				if(i % ((atoi(argv[2]))+1)==0){ //For example,Giant starts from 0 stair
					counter++;									//and skip 2 stairs.It means that he skip
				}															// first and second, therefore he stand on
		}																	// third. That means that it should be
		cout << counter << endl;					// i % N+1; 
	}else
		cout<< argv[1] << endl;


	return 0;
}
