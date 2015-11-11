#include <iostream>

using namespace std;
class A
{
protected:
	int dat;
public:
	A(){dat = 1;}
	void getType(){cout << "A" << endl;}
	virtual int fuck(){ cout << dat <<endl;}
};
class B1
	: public A
{
private:

public:
	B1(){dat = 2;}
	void getType(){cout << "b1" << endl;}
	int fuck(){cout << dat <<endl;}

};

class B2
	: public A
{
private:

public:
	B2(){dat = 3;}
	void getType(){cout << "b2" << endl;}
	int fuck(){cout << dat <<endl;}

};

class C1
	: public B1
{
private:

public:
	C1(){dat = 4;}
	void getType(){cout << "c3" << endl;}
	int fuck(){cout << dat <<endl;}

};

class C2
	: public B1
{
private:

public:
	
	C2(){dat = 5;}
	void getType(){cout << "c2" << endl;}
	int fuck(){cout << dat <<endl;}

};

class C3
	: public B2
{
private:

public:
	C3(){dat = 6;}
	void getType(){cout << "c3" << endl;}
	int fuck(){cout << dat <<endl;}

};

class C4
	: public B2
{
private:
	
public:	
	C4(){dat = 7;}
	void getType(){cout << "c4" << endl;}
	int fuck(){cout << dat <<endl;}


};


int main()
{
	C1* c;
	A* a = c;
	a->fuck();
	return 0;
}
