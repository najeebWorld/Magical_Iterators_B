#include "MagicalContainer.hpp"
#include <algorithm>
#include <stdexcept>

namespace ariel {

    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element) {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it);
        } else {
            throw std::runtime_error("Element not found");
        }
    }

    int MagicalContainer::size() const {
        return elements.size();
    }

    const std::vector<int>& MagicalContainer::getElements() const {
        return elements;
    }

    int MagicalContainer::contains(int number) const {
        auto it = std::find(elements.begin(), elements.end(), number);
        return (it != elements.end()) ? 1 : 0;
    }

    // AscendingIterator

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
        : currentIterator(container.elements.begin()), endIterator(container.elements.end()) {
    }

    MagicalContainer::AscendingIterator::AscendingIterator()
        : currentIterator(), endIterator() {
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
        : currentIterator(other.currentIterator), endIterator(other.endIterator) {
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        ++currentIterator;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return *currentIterator;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return currentIterator == other.currentIterator;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return currentIterator != other.currentIterator;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return currentIterator < other.currentIterator;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return currentIterator > other.currentIterator;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        AscendingIterator it;
        it.currentIterator = currentIterator;
        it.endIterator = endIterator;
        return it;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        AscendingIterator it;
        it.currentIterator = endIterator;
        it.endIterator = endIterator;
        return it;
    }

    // SideCrossIterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
        : currentIterator(container.elements.begin()), endIterator(container.elements.end()) {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator()
        : currentIterator(), endIterator() {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
        : currentIterator(other.currentIterator), endIterator(other.endIterator) {
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        ++currentIterator;
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return *currentIterator;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return currentIterator == other.currentIterator;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return currentIterator != other.currentIterator;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return currentIterator < other.currentIterator;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return currentIterator > other.currentIterator;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
        SideCrossIterator it;
        it.currentIterator = currentIterator;
        it.endIterator = endIterator;
        return it;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        SideCrossIterator it;
        it.currentIterator = endIterator;
        it.endIterator = endIterator;
        return it;
    }

    // PrimeIterator

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
        : currentIterator(container.elements.begin()), endIterator(container.elements.end()) {
    }

    MagicalContainer::PrimeIterator::PrimeIterator()
        : currentIterator(), endIterator() {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
        : currentIterator(other.currentIterator), endIterator(other.endIterator) {
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        ++currentIterator;
        while (currentIterator != endIterator && !isPrime(*currentIterator)) {
            ++currentIterator;
        }
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return *currentIterator;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return currentIterator == other.currentIterator;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return currentIterator != other.currentIterator;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return currentIterator < other.currentIterator;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return currentIterator > other.currentIterator;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        PrimeIterator it;
        it.currentIterator = currentIterator;
        it.endIterator = endIterator;
        if (currentIterator != endIterator && !isPrime(*currentIterator)) {
            ++it;
        }
        return it;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
        PrimeIterator it;
        it.currentIterator = endIterator;
        it.endIterator = endIterator;
        return it;
    }

    bool MagicalContainer::PrimeIterator::isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

} // namespace ariel
