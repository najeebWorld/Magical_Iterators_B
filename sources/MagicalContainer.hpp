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
        vector<int> numberList;
        vector<int*> primeIndices;

    public:
        MagicalContainer();
        void addElement(int number);
        void removeElement(int number);
        size_t size() const;
        int operator[](size_t index) const;
        vector<int> getElements() const;
        bool isPrime(int num) const;

        class AscendingIterator
        {
        private:
            const MagicalContainer &magicContainer;
            size_t currentPosition;

        public:
            AscendingIterator(const MagicalContainer &magicContainer);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);

            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            
            int operator*() const;
            AscendingIterator &operator++();

            AscendingIterator begin();
            AscendingIterator end();
        };

        class PrimeIterator
        {
        private:
            const MagicalContainer &magicContainer;
            size_t currentPosition;

        public:
            PrimeIterator(const MagicalContainer &magicContainer);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);

            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;

            int operator*() const;
            PrimeIterator &operator++();

            PrimeIterator begin();
            PrimeIterator end();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &magicContainer;
            size_t currentPosition;

        public:
            ~SideCrossIterator();
            SideCrossIterator(MagicalContainer &magicContainer, size_t pos);
            SideCrossIterator(MagicalContainer &);

            SideCrossIterator &operator=(const SideCrossIterator &other);

            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            SideCrossIterator &operator++();
            int operator*() const;

            SideCrossIterator begin();
            SideCrossIterator end();
        };
    };
}

#endif // MAGICALCONTAINER_HPP
