#include"MyArray.h"
#include<iostream>
using namespace std;

int main() {
	MyArray<int> arr;
	arr.setCapacity(5, 7);
	cout << "\nSize: " << arr.getSize();
	cout << "\nCapacity: " << arr.getCapacity() << endl;

	arr.add(1);
	arr.add(1);
	arr.add(1);
	arr.add(1);
	arr.add(1);
	arr.insertAt(2, 2);
	arr.insertAt(2, 2);
	arr.insertAt(2, 2);
	arr.insertAt(2, 2);
	arr.insertAt(2, 2);
	arr.insertAt(2, 2);
	arr.insertAt(2, 2);
	arr.insertAt(2, 2);

	cout << "Elements: ";
	for (int i = 0; i < arr.getSize(); ++i) {
		cout << arr[i] << " ";
	}
	cout << "\nSize: " << arr.getSize();
	cout << "\nCapacity: " << arr.getCapacity();

	MyArray<int>arr2;
	arr2 = arr;
	for (int i = 0; i < arr2.getSize(); ++i) {
		cout << arr2[i] << " ";
	}

	MyArray<int>arr3;
	cout << "\n\n";
	arr3.append(arr2);
	arr3.append(arr);
	for (int i = 0; i < arr3.getSize(); ++i) {
		cout << arr3[i] << " ";
	}
	cout << arr3.getSize();

}