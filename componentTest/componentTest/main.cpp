//component class example
//composite class example
//justin caddaye
// sept 2017


#include <iostream>
#include <vector>
using namespace std;

char mystring;

// 2. Create an "interface" (lowest common denominator)
class Component
{
public:
	virtual void traverse() = 0;
};

class Leaf : public Component
{
	// 1. Scalar class   3. "is a" relationship
	int value;
public:
	Leaf(int val)
	{
		value = val;
	}
	void traverse()
	{
		cout << value << ' ';
	}
};


class Composite : public Component
{
	// 1. Vector class   3. "is a" relationship
	vector < Component * > children; // 4. "container" coupled to the interface
public:
	// 4. "container" class coupled to the interface
	void add(Component *ele)
	{
		children.push_back(ele);
	}
	void traverse()
	{
		for (unsigned i = 0; i < children.size(); i++)
			// 5. Use polymorphism to delegate to children
			children[i]->traverse();
	}
};

int main()
{
	Composite containers[4];

	for (unsigned i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			containers[i].add(new Leaf(i * 3 + j));

	for (unsigned i = 1; i < 4; i++)
		containers[0].add(&(containers[i]));

	for (unsigned i = 0; i < 4; i++)
	{
		containers[i].traverse();
		cout << endl;
	}

	cin >> mystring;
}