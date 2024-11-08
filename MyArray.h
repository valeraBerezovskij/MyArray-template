#pragma once

template<class T>
class MyArray
{
public:
	MyArray();
	MyArray(size_t size);
	~MyArray();

	size_t getSize()       { return size; }
	size_t getCapacity()   { return capacity; }
	T& getAt(size_t index) { return data[index]; }
	void setAt(T value, size_t index) { data[index] = value; }
	bool isEmpty()         { return size == 0; }
	T* getData() { return data; }
	size_t getUpperBound() { return capacity - 1; }
	/*
	!
		Функция setSize(которая указана в условие) не имеет смысла, так как в функции add(),
		где мы добавляем новый элемент в массив, у нас size вырастает на значение grow,
		в следствие чего, в контейнер добавляется новый элемент и `grow - 1` количество нулей
		или же мусора (-235246472).
		Если же мы добавляем такую переменную как capacity которая отвечает за `размер массива + grow`
		(то есть выделеную, но не инициализированую память), то ситуация становится яснее:
		size увеличивается с каждым новым элементом, а capacity с каждым новым элементом который достигает 
		предела выделенной памяти. Но функция setSize всё еще смысла не имеет, так как сам `size`
		мы там не меняем, а меняем capacity. В следствие всего этого я поменял название функции setSize на setCapacity,
		и так же добавил такую переменную.
	!
	*/
	void setCapacity(size_t capacity, size_t grow = 1);
	void add(T value);
	void removeAt(size_t index);
	void freeExtra() { capacity = size; }
	void insertAt(size_t index, T value);
	void append(const MyArray& other);
	void removeAll();

	T& operator[](int index) { return data[index]; }
	MyArray<T>& operator=(const MyArray& other);
private:
	T* data;
	size_t size;
	size_t capacity;
	size_t grow;
};

#include"MyArray_impl.h"
