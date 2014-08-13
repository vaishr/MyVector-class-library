#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class myvector
{

private:
  int _size;
  T *vec;
  int capac;// capacity
  int index;

public:

  myvector(int capacity)
  {
    vec = new T [capacity];
    _size = 0;
    capac = capacity;
  }

  myvector(myvector const &v)// parameter vector of same type as a const ref, copy contents to vec
  {
    _size = v._size;
    capac = v.capac;
    vec = new T [v.capac];
    for (int i = 0; i <= v._size; i++)
      vec[i]= v.vec[i];
  }

  myvector(T *arr, int length)// parameter array of same type, and length- copy into vector
  {
    vec= new T [10];
    capac= 10;
    _size= length;
    for (int i = 0; i < length; i++)
      vec[i] = arr[i];
  }

  ~myvector()
  {
    delete [] vec;
  }

  int size() const
  {
    return _size;
  }

  int capacity() const
  {
    return capac;
  }

  bool empty() const
  {
    return (_size==0);
  }

  void resize (int size)
  {
    if (size < 0) {
      cerr << "Size has to be a non-negative integer." << endl;
    }
    if (size > capac)
      {
	reserve(2*size);
      }

    _size = size;
  }

  void reserve(int cap)
  {
    if (cap <= _size)
      cerr << "Error, capacity should be greater than size";

    if (cap > _size)
      {
	capac= cap;
	T *newbuffer = new T [cap];
	for (int i=0; i < _size; i++)
	  newbuffer[i]= vec[i];
	delete [] vec;
	vec = newbuffer;
      }
  }

  T pop_back()
  {
    return vec[--_size];
  }

  void push_back(T const &element)
  {
    // If it doesn't fit, reserve more space
    if (capac <= _size)
      {
	reserve(2*capac);
      }
    // Add the element
    vec[_size] = element;
    _size++;			
  }

  T & operator[] (int index)
  {
    return vec[index];
  }
	
  myvector &  operator= (const myvector& rhs)
  {
    _size = rhs._size;
    capac = rhs.capac;
    vec = new T [rhs.capac];
    for (int i = 0; i <= rhs._size; i++)
      vec[i]= rhs.vec[i];
    return *this;
  }

  void assign(int index, T const &d)
  {
    if (index < 0) {
      cerr << "Index has to be a non-negative integer." << endl;
    }

    if (index >= capac)
      {
	reserve(index*2);
	_size= index +1;
      }

    if (index < capac && index > _size)
      _size= index+1;

    vec[index] = d;
  }

  void insert(int index, T const &d)
  {
    // If it doesn't fit, reserve more space
    if (index >= _size)
      {
	cerr << "Index has to be less than size." << endl;
	return;
      }
    // Push elements over
    for (int i=_size-1; i>=index; i--)
      {
	vec[i+1]= vec[i];
      }
    vec[index] = d;
    _size++;
  }


  T at(int index)
  {
    assert( index >= 0 && index < size);

    return vec[index];
  }

  void erase(int index)
  {
    if (!(index >=0 && index < _size))
      {
	cerr << "Index number is invalid" << endl;
      }
		
    else
      {
	for (int i=index; i<(_size-1); i++)
	  vec[i]=vec[i+1];

	_size--;
      }
  }

  void erase(int i1, int i2) 
  {
    if ( (i1 < 0) || (i2 < 0) || (i1 >= _size) || (i2 >= _size) ) 
	{
      cerr << "Index number is invalid" << endl;
    }

    if (i2 < i1)
	{
		int c = i2;
		i2 = i1;
		i1 = c;
	}

	int range = (i2 - i1);

    for (int i = i2; i < _size; i++) {
      vec[i - range] = vec[i+1];
    }
    _size -= range + 1;
  }


  void clear()
  {
    _size = 0;
  }

  void print() {
    std::cout << std::endl;
    std::cout << "size: " << _size << std::endl;
    std::cout << "capacity: " << capac << std::endl;
    std::cout << "[";

    for (int i = 0; i < _size; i++) {
      std::cout << vec[i];
      if (i < _size - 1) 
	{
	  std::cout << ", ";
	}
    }
    std::cout << "]" << std::endl;

  }
};
