#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>

namespace ariel {

    class MagicalContainer {
    private:
        std::vector<int> elements;

    public:
        void addElement(int element);
        void removeElement(int element);
        int size() const;
        const std::vector<int>& getElements() const;
        int contains(int number) const;

        class AscendingIterator {
        private:
            std::vector<int>::const_iterator currentIterator;
            std::vector<int>::const_iterator endIterator;

        public:
            AscendingIterator(const MagicalContainer& container);
            AscendingIterator();
            AscendingIterator(const AscendingIterator& other);
            ~AscendingIterator() = default;
            AscendingIterator& operator++();
            int operator*() const;
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            AscendingIterator begin() const;
            AscendingIterator end() const;
        };

        class SideCrossIterator {
        private:
            std::vector<int>::const_iterator currentIterator;
            std::vector<int>::const_iterator endIterator;

        public:
            SideCrossIterator(const MagicalContainer& container);
            SideCrossIterator();
            SideCrossIterator(const SideCrossIterator& other);
            ~SideCrossIterator() = default;
            SideCrossIterator& operator++();
            int operator*() const;
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            SideCrossIterator begin() const;
            SideCrossIterator end() const;
        };

        class PrimeIterator {
        private:
            std::vector<int>::const_iterator currentIterator;
            std::vector<int>::const_iterator endIterator;

        public:
            PrimeIterator(const MagicalContainer& container);
            PrimeIterator();
            PrimeIterator(const PrimeIterator& other);
            ~PrimeIterator() = default;
            PrimeIterator& operator++();
            int operator*() const;
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            PrimeIterator begin() const;
            PrimeIterator end() const;

        private:
            static bool isPrime(int num);
        };

    };
}

#endif // MAGICALCONTAINER_HPP
