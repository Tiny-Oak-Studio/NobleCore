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
        explicit List(Address::AddressType startCapacity = InitialArraySize);

        /// @brief Deletes the underlying array when destroyed
        ~List();

        /// @brief Adds an element to the array
        void Add(T element);

        /// @brief Appends the elements from the given list to this list
        void Add(const List& list);

        /// @brief Removes the most recently added element
        T Pop();

        /// @brief Get a copy of an indexed element of the array
        T operator[](Address::AddressType index) const;

        /// @brief Access an indexed element of the array
        T& operator[](Address::AddressType index);

        /// @brief Returns the capacity of the array
        Address::AddressType Capacity() const;

        /// @brief Returns the number of elements in the array
        Address::AddressType Count() const;

        /// @brief Get a pointer to the underlying array
        T* GetArray();

        /// @brief Get a const pointer to the underlying array
        const T* GetArray() const;
    protected:
        /// @brief The number of elements initially allocated to the array
        static constexpr Address::AddressType InitialArraySize = 2;

        /// @brief The factor to grow the array by when a reallocation occurs
        static constexpr Address::AddressType GrowthFactor = 2;

        /// @brief The underlying array
        T* array = nullptr;

        /// @brief The current capacity of the array.
        Address::AddressType capacity = 0;

        /// @brief Number of elements currently in the array.
        Address::AddressType count = 0;
    };

    template<typename T>
    List<T>::List(const Address::AddressType startCapacity)
    {
        array = new T[startCapacity];
        capacity = startCapacity;
    }

    template<typename T>
    List<T>::~List()
    {
        delete [] array;
    }

    template<typename T>
    void List<T>::Add(T element)
    {
        if (count >= capacity)
        {
            const Address::AddressType newCapacity = capacity * GrowthFactor;
            T* tempArray = new T[newCapacity];
            memcpy(tempArray, array, count * sizeof(T));
            delete [] array;
            array = tempArray;
            capacity = newCapacity;
        }
        array[count++] = element;
    }

    template<typename T>
    void List<T>::Add(const List& list)
    {
        for (Address::AddressType i = 0; i < list.count; ++i)
        {
            Add(list[i]);
        }
    }

    template<typename T>
    T List<T>::Pop()
    {
        return array[--count];
    }

    template<typename T>
    T List<T>::operator[](Address::AddressType index) const
    {
        return array[index];
    }

    template<typename T>
    T& List<T>::operator[](Address::AddressType index)
    {
        return array[index];
    }

    template<typename T>
    Address::AddressType List<T>::Capacity() const
    {
        return capacity;
    }

    template<typename T>
    Address::AddressType List<T>::Count() const
    {
        return count;
    }

    template<typename T>
    T* List<T>::GetArray()
    {
        return array;
    }

    template<typename T>
    const T* List<T>::GetArray() const
    {
        return array;
    }

} // Noble::Core

#endif //LIST_H
