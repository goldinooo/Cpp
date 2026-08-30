#pragma once
// bnaya 

template<typename T>
Array<T>::Array() : data(NULL), _size(0) {}

template<typename T>
Array<T>::Array(ui n) : data(new T[n]), _size(n) {}

template<typename T>
Array<T>::Array(const Array& oth) : data(new T[oth._size]), _size(oth._size) 
{
    for(ui i = 0; i < _size; i++)
    {
        data[i] = oth.data[i];
    }
}

template<typename T>
Array<T>::~Array(){
	delete [] data;
}

//exception

template<typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
    return "the index is Out of bounds";
}

// operators

template <typename T>
T &Array<T>::operator[](ui i)
{
	if (i >= _size)
		throw OutOfBounds();
	return (data[i]);
}

template <typename T>
T const &Array<T>::operator[](ui i) const
{
	if (i >= _size)
		throw OutOfBounds();
	return (data[i]);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& oth)
{
	if (this != &oth)
	{
		delete [] data;
		_size = oth._size;
		data = new T[_size];
		for(ui i = 0; i < _size; i++)
		{
			data[i] = oth.data[i];
		}
	}
	return *this;
}

template <typename T>
ui Array<T>::size() const
{
	return (_size);
}