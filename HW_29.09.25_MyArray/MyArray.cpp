#include "MyArray.h"
#include <iostream>
using namespace std;
MyArray::MyArray()
{
	arr = nullptr;
	size = 0;
}	
MyArray::MyArray(int* a, int s) 
{
	size = s;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = a[i];
	}
}
MyArray::~MyArray()
{
	delete[] arr;
}
MyArray::MyArray(const MyArray& obj)
{
	size = obj.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
}
MyArray::MyArray(MyArray&& obj)
{
	arr = obj.arr;
	obj.arr = nullptr;
	size = obj.size;
	obj.size = 0;
}	
MyArray MyArray::operator+(MyArray& obj)
{
	MyArray temp;	
	temp.size = size + obj.size;	
	temp.arr = new int[temp.size];
	for (int i = 0; i < size; i++)
	{
		temp.arr[i] = arr[i];
	}
	for (int i = 0; i < obj.size; i++)
	{
		temp.arr[i + size] = obj.arr[i];
	}
	return temp;

}
MyArray MyArray::operator-(MyArray& obj)
{
	MyArray temp;
	temp.size = size;
	temp.arr = new int[temp.size];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		bool found = false;
		for (int j = 0; j < obj.size; j++)
		{
			if (arr[i] == obj.arr[j])
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			temp.arr[k] = arr[i];
			k++;
		}
	}
	temp.size = k;
	return temp;
}
MyArray& MyArray::operator=(const MyArray& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	if (arr != nullptr)
	{
		delete[] arr;
	}
	size = obj.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}

MyArray& MyArray::operator++()
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = 0;
	size++;
	delete[] arr;
	arr = temp;
	return *this;
}
MyArray& MyArray::operator--()
{
	if (size == 0)
	{
		return *this;
	}
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	size--;
	delete[] arr;
	arr = temp;
	return *this;
}
int MyArray::GetSize()
{
	return size;
}
int& MyArray::operator[](int index)
{
	if (index >= 0 && index < size)
	{
		
		return arr[index];
	}
	throw exception("index error");
}

void MyArray::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
