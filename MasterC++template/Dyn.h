#pragma once

template <typename T>
class DynamicVector
{
private:
	T * elems;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 3);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	/*
	Overloading the subscript operator
	Input: pos - a valid position within the vector.
	Output: a reference to the element o position pos.
	*/
	T& operator[](int pos);

	// Adds an element to the current DynamicVector.
	void add(T e);
	void remove(const int pos);
	void update(const int pos, T e);

	T* getAllElems() const;

	int getSize() const;

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

/*
template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	T* aux;
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	aux = new T[this->capacity];

	delete[] this->elems;

	this->elems = aux;
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}
*/
template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename T>
void DynamicVector<T>::add(T e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <typename T>
void DynamicVector<T>::remove( const int pos)
{

	if (pos < 0 || pos >= this->size)
		return;

	for (int i = pos; i < this->size - 1; i++)
		this->elems[i] = this->elems[i + 1];

	this->size--;
}

template <typename T>
void DynamicVector<T>::update(const int pos, T e)
{	
	this->elems[pos] = e;	
}


template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= factor;

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

template <typename T>
T* DynamicVector<T>::getAllElems() const
{
	return this->elems;
}

