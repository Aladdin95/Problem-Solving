#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::cout;

void process_queries() {
    vector<string> result;
    vector<string> contacts (1e7,"not found");

	int n;
    cin >> n;
	string type;
	int number;
	for (int i = 0; i < n; ++i) 
	{
        cin >> type;
		cin >> number;
        if (type == "add")
            cin >> contacts[number];
        else if (type == "del")
			contacts[number] = "not found";
		else if (type == "find")
			cout << contacts[number] <<"\n";
	}
}

int main()
{
	process_queries();
    return 0;
}
