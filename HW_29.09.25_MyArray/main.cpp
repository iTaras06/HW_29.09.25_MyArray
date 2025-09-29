#include "MyArray.h"
#include <iostream>
using namespace std;

int main()
{
	int arr1[] = { 5, 4, 3, 2, 1 };
	MyArray obj1(arr1, 5);
	cout << "Array 1: ";
	obj1.Print();
	int arr2[] = { 1, 2, 3 };
	MyArray obj2(arr2, 3);
	cout << "Array 2: ";
	obj2.Print();

	MyArray obj3 = obj1 + obj2;
	cout << "Array 3 (Array 1 + Array 2): ";
	for (int i = 0; i < obj3.GetSize(); i++)
	{
		cout << obj3[i] << " ";
	}
	cout << endl;

	MyArray obj4 = obj1 - obj2;
	cout << "Array 4 (Array 1 - Array 2): ";
	for (int i = 0; i < obj4.GetSize(); i++)
	{
		cout << obj4[i] << " ";
	}
	cout << endl;

	MyArray obj5 = obj1;
	cout << "Array 5 (Copy of Array 1): ";
	for (int i = 0; i < obj5.GetSize(); i++)
	{
		cout << obj5[i] << " ";
	}
	cout << endl;

	cout << "Adding 0 to the end of the array: ";
	++obj5;
	for (int i = 0; i < obj5.GetSize(); i++)
	{
		cout << obj5[i] << " ";
	}
	cout << endl;

	cout << "Removing one element from the end of array: ";
	--obj5;
	for (int i = 0; i < obj5.GetSize(); i++)
	{
		cout << obj5[i] << " ";
	}
	cout << endl;
	return 0;
}