#include <iostream>

using namespace std;

template <typename T>
class _vector {
private:
	int _capacity = 0;
	int _size = 0;
	T* arr;

public:
	_vector(int size = 1) : _capacity(size), _size(0), arr(new T[size]) {}

	~_vector() {
		delete[] arr;
	}

	int size() {
		return _size;
	}

	void clear() {
		_capacity = 8;
		_size = 0;

		delete[] arr;

		arr = new T[_capacity];
	}

	void resize(int size) {
		_capacity = size;
		T* temp = new T[size];

		for (int i = 0; i < _size; i++)
			temp[i] = arr[i];
		delete[] arr;

		arr = temp;
	}

	void push_back(T val) {
		if (_size == _capacity)
			resize(_capacity * 2);

		arr[_size++] = val;
	}

	void pop_back() {
		if (_size == 0)
			return;
		arr[_size--] = 0;
	}

	T* begin() {
		return &arr[0];
	}

	T* end() {
		return &arr[0] + _size;
	}

	T operator[](int idx) {
		return arr[idx];
	}

};

int main() {
	_vector <int > v;

	for (int i = 0; i < 5; i++)
		v.push_back(i);

	for (int i = 0; i < 5; i++)
		cout << v[i] << " ";
	cout << "\n";

	return 0;
}