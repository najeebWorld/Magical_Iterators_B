#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <stdexcept>
#include <vector>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> numberList;// The container for storing numbers
        vector<int*> primeIndices;// Pointers to prime numbers within numberList

    public:
        MagicalContainer();
        
        // Adds an element to the container while maintaining sorted order.
        void addElement(int number);

        // Removes an element from the container.
        void removeElement(int number);

        // Returns the size of the container.
        size_t size() const;

        // Accesses the element at the given index in the container.
        int operator[](size_t index) const;

        // Returns a vector containing all the elements in the container.
        vector<int> getElements() const;

        // Checks if a number is prime.
        bool isPrime(int num) const;

        class AscendingIterator
        {
        private:
            const MagicalContainer &magicContainer;// Reference to the MagicalContainer being iterated
            size_t currentPosition;// Current position in the iteration

        public:
            AscendingIterator(const MagicalContainer &magicContainer);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);

            // Comparison operators for iterators
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;

            // Dereference operator for accessing the element
            int operator*() const;

            // Increment operator for advancing the iterator
            AscendingIterator &operator++();

            // Returns an iterator pointing to the beginning of the container
            AscendingIterator begin();

            // Returns an iterator pointing to the end of the container
            AscendingIterator end();
        };

        class PrimeIterator
        {
        private:
            const MagicalContainer &magicContainer;// Reference to the MagicalContainer being iterated
            size_t currentPosition;// Current position in the iteration

        public:
            PrimeIterator(const MagicalContainer &magicContainer);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);

            // Comparison operators for iterators
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;

            // Dereference operator for accessing the element
            int operator*() const;

            // Increment operator for advancing the iterator
            PrimeIterator &operator++();

            // Returns an iterator pointing to the beginning of the container
            PrimeIterator begin();

            // Returns an iterator pointing to the end of the container
            PrimeIterator end();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &magicContainer;// Reference to the MagicalContainer being iterated
            size_t currentPosition;// Current position in the iteration

        public:
            ~SideCrossIterator();

            // Constructor with a specified starting position
            SideCrossIterator(MagicalContainer &magicContainer, size_t pos);

            // Constructor without a specified starting position
            SideCrossIterator(MagicalContainer &magicContainer);

            SideCrossIterator &operator=(const SideCrossIterator &other);

            // Comparison operators for iterators
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;

            // Increment operator for advancing the iterator
            SideCrossIterator &operator++();

            // Dereference operator for accessing the element
            int operator*() const;

            // Returns an iterator pointing to the beginning of the container
            SideCrossIterator begin();

            // Returns an iterator pointing to the end of the container
            SideCrossIterator end();
        };
    };
}

#endif // MAGICALCONTAINER_HPP
