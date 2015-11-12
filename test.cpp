#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstdarg>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

struct Node{
	int* a;
	int size;
	Node(int as, int s, ...) {
		size = s;
		a = new int(s);
	    va_list vl;
		va_start(vl,s);
		for(int i = 0; i<s; ++i) {
			a[i] = va_arg(vl,int);
		}
		va_end(vl);
	}
	void print() {
		for(int i = 0; i<size;++i) {
			cout << a[i] << endl;
		}
	}
};


int main()
{
	Node* arr = new Node(1,3,2,3,4);
	cout << arr->size <<endl;
	arr->print();
	return 0;
}
