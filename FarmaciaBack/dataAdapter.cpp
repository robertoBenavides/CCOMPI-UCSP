#include "dataAdapter.h"
#include <string>
#include <vector>

vector<string> dataAdapter::split(string line)
{
	vector<string> rpta;
	string a = "";
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ',') {
			rpta.push_back(a);
			a = "";
		}
		else {
			a = a + line[i];
		}
		
	}
	rpta.push_back(a);
	return rpta;
}
