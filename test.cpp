#include <iostream>

using namespace std;

class Test
{
private:
	int *p;
     int A = 10;
public:
	Test(int tmp)
	{
		this->p = new int(tmp);
		cout << "Test(int tmp)" << endl;
	}

    void funfun(){
        A = 20;
    }
    void fun() const{
        // funfun();
    }

	~Test()
	{
		if (p != NULL)
		{
			delete p;
		}
		cout << "~Test()" << endl;
	}
};

int main()
{
	// Test ex1(10);	
    // ex1.fun();
    auto p = nullptr;
	// Test ex2 = ex1; 
	return 0;
}
