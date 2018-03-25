#include <iostream>

using namespace std;


int main(){
	char c[2];                             //c[0] starting char , c[1] ending char
	int n,i;                               //n duration of rotation -number of spins-, i index for starting char
	cin>>c[0]>>c[1]>>n;

	if(!(n%2)){cout<<"undefined";return 0;} //if n is even then the results of clockwise and counter-clockwise are the same

	char arr[4]={'v','<','^','>'};          //example: if the duration = 1 we add 1 to the index

	for(i=0 ; c[0]!=arr[i] ; ++i);          //to make i = index of starting char
	
	if(c[1]==arr[(i+n)%4])                  //(i+n) number of rotations to the index %4 to go to first pos after the last one
		cout<<"cw";                         //adding mean spinning in clockwise direction -take a look to the order in our array-
	else                                    //It is guaranteed that the ending position is a result of n spins in any of the directions
		cout<<"ccw";                        //so it is ccw if not cw

	return 0;
}