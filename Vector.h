// Vector.h
//---------------------------------------------------------------------------------

#ifndef VECTOR_H
#define VECTOR_H

//---------------------------------------------------------------------------------

    /**
     * @class Vector
     * @brief  Has all the required methods for using the vector
     *
     * @author Ryan Draper
     * @version 01
     * @date 20/04/2020 Ryan Draper, Started
     *
     * @version 02
     * @date 21/04/2020 Ryan Draper, Added size function and constructor for setting size and initialising values.
     *
     *
     * @version 03
     * @date 26/04/2020 Ryan Draper, Added initialised function.
     *
     * @version 04
     * @date 27/4/2020 Ryan Draper, Added overloaded assignment operator with vector parameter.
     */

template<class T>
class Vector
{
public:
        /**
        * @brief  Default constructor
        *
        * This constructor creates a new arr of size 5.
        */
    Vector();

        /**
        * @brief  Constructor
        *
        * This constructor creates a new arr the size of the parameter.
        *
        * @param  An integer which indicates the size of arr.
        */
    Vector(int s);

        /**
        * @brief  Constructor
        *
        * This constructor creates a new arr the size of the parameter with all elements set to the second parameter.
        *
        * @param  An integer which indicates the size of arr.
        * @param  A parameter of type T which all elements will be set to.
        */
    Vector(int s, T i);

        /**
        * @brief  Destructor
        *
        * This destructor is for freeing arr.
        */
    ~Vector();

        /**
        * @brief  Copy constructor
        *
        * This constructor is used for creating a new arr as a copy of the parameter.
        *
        * @param  The reference to the vector type to be copied.
        */
    Vector(const Vector& vec);

        /**
        * @brief  Assignment operator
        *
        * @param  A vector of any type to set arr.
        */
    const Vector<T> & operator=(const Vector<T>& vec);

        /**
        * @brief  Assignment operator
        *
        * @param  An element of any type to be added to arr.
        */
    Vector& operator=(const T & i);

        /**
        * @brief  Overloaded operator
        *
        * This overloaded operator is for returning the value in arr at the paramater position.
        *
        * @param  An integer which indicates which position of arr to return the value of.
        */
    const T& operator[](int i) const;


        /**
        * @brief  return size of arr function
        *
        * This function is for returning the size of arr.
        *
        *@return int
        */
    int size();

        /**
        * @brief  return number of initialised elements.
        *
        * This function is for returning the number of initialised elements.
        *
        *@return int
        */
    int initialised() const;

private:
        /// The size of arr.
    int vecSize = 0;

        /// The number of elements in arr.
    int numInitialisedElem = 0;

        /// an array of type T
    T* arr;

        /**
        * @brief  Used for resizing arr.
        *
        * @return void
        */
    void allocate();
};

//---------------------------------------------------------------------------------
    /**
     *default constructor.
     *creates a vector of size 5.
     */
template<class T>
Vector<T>::Vector()
{
    vecSize = 5;
    numInitialisedElem = 0;
    arr = new T[vecSize];
}

//---------------------------------------------------------------------------------
    /**
     *Constructor
     *creates a vector of size s
     */
template<class T>
Vector<T>::Vector(int s)
{
    vecSize = s;
    numInitialisedElem = 0;
    arr = new T[vecSize];
}

//---------------------------------------------------------------------------------
    /**
     *Constructor
     *creates a vector of size s with all elements set to i
     */
template<class T>
Vector<T>::Vector(int s, T i)
{
    vecSize = s;
    numInitialisedElem = 0;
    arr = new T[vecSize];
    for(int j=0; j<s; j++){
        arr[j] = i;
        numInitialisedElem++;
    }
}

//---------------------------------------------------------------------------------
    /**
     *deconstructor.
     *deletes the vector
     */
template<class T>
Vector<T>::~Vector()
{
    delete[] arr;
    arr = nullptr;
}

//---------------------------------------------------------------------------------
    /**
     *copy constructor.
     *Creates a new vector with size and number of
     *elements initialised as the vector it is
     *being copied from.
     *Then copies each element to the new vector.
     */
template<class T>
Vector<T>::Vector(const Vector& vec)
{
    vecSize = vec.vecSize;
    numInitialisedElem = vec.numInitialisedElem;
    arr = new T[vecSize];

    for(int i=0; i<vec.numInitialisedElem; i++)
    {
        arr[i] = vec.arr[i];
    }
}

//---------------------------------------------------------------------------------
    /**
     *Assignment operator.
     *Sets the vector
     *to the vector passed in.
     */
template<class T>
const Vector<T> & Vector<T>::operator=(const Vector<T>& vec)
{
    if(this != &vec)
    {
        delete [] arr;
        vecSize = vec.vecSize;
        numInitialisedElem = vec.numInitialisedElem;

        arr = new T[vecSize];

        for(int i=0; i<numInitialisedElem; i++)
        {
            arr[i] = vec.arr[i];
        }
    }
    return *this;
}

//---------------------------------------------------------------------------------
    /**
     *Assignment operator.
     *Sets the next available memory location
     *of the vector to the object passed in.
     *If there is not enough space in the vector,
     *the allocate() function is called to resize
     *the vector.
     */
template<class T>
Vector<T>& Vector<T>::operator=(const T & i)
{
    if(numInitialisedElem+1 > vecSize)
    {
        allocate();
    }
    arr[numInitialisedElem] = i;
    numInitialisedElem++;
    return *this;
}

//---------------------------------------------------------------------------------
    /**
     *Overloaded operator []
     *returns the vector at position i,
     *passed in as a parameter.
     */
template<class T>
const T& Vector<T>::operator[](int i) const
{
    return arr[i];
}

//---------------------------------------------------------------------------------
    /**
     *This is a function used for adding elements to the vector.
     *If the vector only has one free space of memory, a temporary
     *vector is created of double the size, the old vector is copied
     *to the temporary vector. The original vector is deleted and
     *then recreated by copying the temporary vector into it.
     */
template<class T>
void Vector<T>::allocate()
{
    vecSize = vecSize*2;
    T* tempVec = new T[vecSize];

    for(int i=0; i<numInitialisedElem; i++)
    {
        tempVec[i] = arr[i];
    }

    delete[] arr;
    arr = tempVec;
}

//---------------------------------------------------------------------------------
    /**
     *size function
     *returns the size of the vector
     *returns an int
     */
template<class T>
int Vector<T>::size()
{
    return vecSize;
}

//---------------------------------------------------------------------------------
    /**
     *initialised function
     *returns the number of initialised elements
     *returns an int
     */
template<class T>
int Vector<T>::initialised() const
{
    return numInitialisedElem;
}

//---------------------------------------------------------------------------------
#endif // VECTOR_H
