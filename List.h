#ifndef NOBLE_CORE_LIST_H_INCLUDED
#define NOBLE_CORE_LIST_H_INCLUDED

#include <string.h> //Use old headers for Arduino compatibility

#include "Address.h"

namespace Noble::Core
{
    /// @brief Generic dynamic array implementation
    template <typename T>
    class List
    {
    public:
        /// @brief Allocates the underlying array
        explicit List();

        /// @brief Deletes the underlying array when destroyed
        ~List();

        /// @brief Adds an element to the array
        void Add(T element);

        /// @brief Appends the elements from the given list to this list
        void Add(const List& list);

        /// @brief Resize the underlying array to specified size
        void Resize(Address::Single size);

        /// @brief Removes the most recently added element
        T Pop();

        /// @brief Get a const ref of an indexed element of the array
        const T& operator[](Address::Single index) const;

        /// @brief Get a ref to an indexed element of the array
        T& operator[](Address::Single index);

        /// @brief Get a const ref of an element offset from back
        const T& Peek(Address::Single offset) const;

        /// @brief Get ref of an element offset from back
        T& Peek(Address::Single offset);

        /// @brief Returns the capacity of the array
        Address::Single Capacity() const;

        /// @brief Returns the number of elements in the array
        Address::Single Count() const;

        /// @brief Get a pointer to the underlying array
        T* GetArray();

        /// @brief Get a const pointer to the underlying array
        const T* GetArray() const;
    protected:
        /// @brief The number of elements initially allocated to the array
        static constexpr Address::Single InitialArraySize = 2;

        /// @brief The factor to grow the array by when a reallocation occurs
        static constexpr Address::Single GrowthFactor = 2;

        /// @brief The underlying array
        T* array = nullptr;

        /// @brief The current capacity of the array.
        Address::Single capacity = 0;

        /// @brief Number of elements currently in the array.
        Address::Single count = 0;
    };

    template <typename T>
    List<T>::List()
    {
        array = new T[InitialArraySize];
        capacity = InitialArraySize;
    }

    template <typename T>
    List<T>::~List()
    {
        delete [] array;
    }

    template <typename T>
    void List<T>::Add(T element)
    {
        if (count >= capacity)
        {
            const Address::Single newCapacity = capacity * GrowthFactor;
            T* tempArray = new T[newCapacity];
            memcpy(tempArray, array, count * sizeof(T));
            delete [] array;
            array = tempArray;
            capacity = newCapacity;
        }
        array[count++] = element;
    }

    template <typename T>
    void List<T>::Add(const List& list)
    {
        for (Address::Single i = 0; i < list.count; ++i)
        {
            this->Add(list[i]);
        }
    }

    template <typename T>
    void List<T>::Resize(const Address::Single size)
    {
        delete [] array;
        array = new T[size];
        capacity = size;
        count = size;
        memset(array, 0, count * sizeof(T)); //Zero-write the empty elements
    }

    template <typename T>
    T List<T>::Pop()
    {
        return array[--count];
    }

    template <typename T>
    const T& List<T>::operator[](Address::Single index) const
    {
        return array[index];
    }

    template <typename T>
    T& List<T>::operator[](Address::Single index)
    {
        return array[index];
    }

    template <typename T>
    const T &List<T>::Peek(const Address::Single offset) const
    {
        return array[count - offset - 1];
    }

    template <typename T>
    T& List<T>::Peek(const Address::Single offset)
    {
        return array[count - offset - 1];
    }

    template <typename T>
    Address::Single List<T>::Capacity() const
    {
        return capacity;
    }

    template <typename T>
    Address::Single List<T>::Count() const
    {
        return count;
    }

    template <typename T>
    T* List<T>::GetArray()
    {
        return array;
    }

    template <typename T>
    const T* List<T>::GetArray() const
    {
        return array;
    }
} // Noble::Core

#endif //LIST_H
