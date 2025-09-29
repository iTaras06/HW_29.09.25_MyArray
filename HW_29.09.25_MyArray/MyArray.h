#pragma once
class MyArray
{
	int* arr;
	int size;
public:
	MyArray();
	MyArray(int* a, int s);
	~MyArray();
	MyArray(const MyArray& obj);
	MyArray(MyArray&& obj);
	MyArray operator+(MyArray& obj);
	MyArray operator-(MyArray& obj);
	MyArray& operator=(const MyArray& obj);
	MyArray& operator++();
	MyArray& operator--();
	int& operator[](int index);

	int GetSize();
	void Print();
};