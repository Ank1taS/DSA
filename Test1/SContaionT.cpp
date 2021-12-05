#include<iostream>
#include<cstring>
using namespace std;
// #include "solution.h"

bool checksequenece(char large[] , char*small) {
    bool result;

    if (strlen(small) == 0) {
        return true;
    }

    if (strlen(large) == 0) {
        return false;
    }

    if (large[0] == small[0]) {
        result = checksequenece(large + 1, small + 1);
    }
    else {
        result = checksequenece(large + 1, small);
    }
    return result;
}


int main()
{
	char large[10000];
	char small[10000];
	
    cin>>large;
	cin>>small;
	
    bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
