#include "MagicalContainer.hpp"
using namespace ariel;
using namespace std;

// Default constructor for MagicalContainer
MagicalContainer::MagicalContainer()
{
}

// Adds an element to the container while maintaining sorted order.
void MagicalContainer::addElement(int element)
{
    // Find the position where the element should be inserted to maintain sorted order
    auto it = lower_bound(numberList.begin(), numberList.end(), element);
    
    // Insert the element at the calculated position
    numberList.insert(it, element);

    // Clear the prime indices
    primeIndices.clear();
    
    // Rebuild the primeIndices vector
    for (size_t i = 0; i < numberList.size(); ++i)
    {
        // If the number at the current index is prime, add it to primeIndices
        if (isPrime(numberList[i]))
        {
            primeIndices.push_back(&numberList[i]);
        }
    }
}

// Removes an element from the container, if it exists.
void MagicalContainer::removeElement(int element)
{
    // Find the position of the element in the container
    auto flag = lower_bound(numberList.begin(), numberList.end(), element);
    
    // If the element is found, erase it
    if (flag != numberList.end() && *flag == element)
    {
        numberList.erase(flag);
    }
    else
    {
        // Throw an exception if the element does not exist in the container
        throw std::runtime_error("The element could not be located within the magicContainer.");
    }

    // Clear the primeIndices
    primeIndices.clear();
    
    // Rebuild the primeIndices vector after erasing an element
    for (size_t i = 0; i < numberList.size(); ++i)
    {
        if (isPrime(numberList[i]))
        {
            primeIndices.push_back(&numberList[i]);
        }
    }
}

// Returns the size of the container
size_t MagicalContainer::size() const
{
    return numberList.size();
}

// Returns the element at the given index
int MagicalContainer::operator[](size_t index) const
{
    // If the index is out of range, throw an exception
    if (index >= numberList.size())
    {
        throw std::out_of_range("The index exceeds the valid bounds.");
    }
    return numberList[index];
}

// Returns all the elements of the container in a vector
vector<int> MagicalContainer::getElements() const
{
    return numberList;
}

// Checks if a number is prime
bool MagicalContainer::isPrime(int num) const
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

//*****AscendingIterator*****

// AscendingIterator constructor
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &magicContainer)
    : magicContainer(magicContainer), currentPosition(0)
{
}

// AscendingIterator copy constructor
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
    : magicContainer(other.magicContainer), currentPosition(other.currentPosition)
{
}

// AscendingIterator destructor
MagicalContainer::AscendingIterator::~AscendingIterator()
{
}

// Assignment operator overload for AscendingIterator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    // If the iterators point to different containers, throw an exception
    if (&magicContainer != &other.magicContainer)
    {
        throw std::runtime_error("The iterators are referencing distinct magicContainers.");
    }
    // If the iterators are not the same, copy the position of the other iterator
    if (this != &other)
    {
        this->currentPosition = other.currentPosition;
    }
    // Return this iterator
    return *this;
}

// Equality operator overload for AscendingIterator
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    // Iterators are equal if they have the same position and point to the same container
    return (currentPosition == other.currentPosition) && (&magicContainer == &other.magicContainer);
}

// Greater than operator overload for AscendingIterator
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    // If either iterator is beyond the end of the container, return false
    if (currentPosition >= magicContainer.size() || other.currentPosition >= magicContainer.size())
    {
        return false;
    }
    // Otherwise, check if this iterator's position is greater than the other iterator's position
    return currentPosition > other.currentPosition;
}

// Less than operator overload for AscendingIterator
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    // If either iterator is beyond the end of the container, return false
    if (currentPosition >= magicContainer.size() || other.currentPosition >= magicContainer.size())
    {
        return false;
    }
    // Otherwise, check if this iterator's position is less than the other iterator's position
    return currentPosition < other.currentPosition;
}

// Inequality operator overload for AscendingIterator
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    // Iterators are not equal if their positions are different
    return currentPosition != other.currentPosition;
}

// Dereference operator overload for AscendingIterator
int MagicalContainer::AscendingIterator::operator*() const
{
    // If the iterator is beyond the end of the container, throw an exception
    if (currentPosition >= magicContainer.size())
    {
        throw std::out_of_range("The index exceeds the valid bounds.");
    }
    // Return the value at the current position of the iterator
    return magicContainer[currentPosition];
}

// Pre-increment operator overload for AscendingIterator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    // If the iterator is beyond the end of the container, throw an exception
    if (currentPosition >= magicContainer.size())
    {
        throw std::runtime_error("The iterator has advanced past the endpoint.");
    }
    // Increment the position of the iterator
    currentPosition++;
    // Return this iterator
    return *this;
}

// Returns an iterator pointing to the first element of the container
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    AscendingIterator iter(magicContainer);
    iter.currentPosition = 0;
    return iter;
}

// Returns an iterator pointing one past the last element of the container
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator iter(magicContainer);
    iter.currentPosition = magicContainer.size();
    return iter;
}

//*****PrimeIterator*****

// Constructor for PrimeIterator that starts at the beginning of the given MagicalContainer
MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &magicContainer)
    : magicContainer(magicContainer), currentPosition(0)
{
    // Initializes the iterator with a specific MagicalContainer instance
}

// Copy constructor for PrimeIterator that clones from another iterator
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
    : magicContainer(other.magicContainer), currentPosition(other.currentPosition)
{
    // Initializes the iterator as a clone of another iterator
}

// Destructor for PrimeIterator
MagicalContainer::PrimeIterator::~PrimeIterator() 
{
    // No cleanup required here
}

// Assignment operator for PrimeIterator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (&magicContainer != &other.magicContainer)
    {
        throw std::runtime_error("The iterators are referencing distinct magicContainers.");
    }
    if (this != &other)
    {
        this->currentPosition = other.currentPosition; // Assign current position from other
    }
    return *this; // Return this instance
}

// Equality operator for PrimeIterator
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    // Two iterators are equal if they point to the same container and have the same position
    return (currentPosition == other.currentPosition) && (&magicContainer == &other.magicContainer);
}

// Inequality operator for PrimeIterator
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    // Inverse of the equality operation
    return !(*this == other);
}

// Greater than operator for PrimeIterator
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    // An iterator is greater if its current position is greater
    return currentPosition > other.currentPosition;
}

// Less than operator for PrimeIterator
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    // An iterator is lesser if its current position is lesser
    return currentPosition < other.currentPosition;
}

// Dereference operator for PrimeIterator
int MagicalContainer::PrimeIterator::operator*() const
{
    // If the current position is out of range, throw an exception
    if (currentPosition >= magicContainer.primeIndices.size())
    {
        throw std::out_of_range("The index exceeds the valid bounds.");
    }
    // Return the value pointed by the iterator
    return *magicContainer.primeIndices[currentPosition];
}

// Pre-increment operator for PrimeIterator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    // If the current position is beyond the end, throw an exception
    if (currentPosition >= magicContainer.primeIndices.size())
    {
        throw std::runtime_error("The iterator has advanced past the endpoint.");
    }
    // Increase the current position
    currentPosition++;
    // Return this instance
    return *this;
}

// Begin function for PrimeIterator that returns a new iterator at the start
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    PrimeIterator iter(magicContainer);
    iter.currentPosition = 0; // Assuming that currentPosition 0 always points to the first element.
    return iter;
}

// End function for PrimeIterator that returns a new iterator past the last valid element
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    PrimeIterator iter(magicContainer);
    iter.currentPosition = magicContainer.primeIndices.size(); // One past the last element.
    return iter;
}

//******SideCrossIterator*******

// Destructor for SideCrossIterator. It doesn't need to do anything special.
MagicalContainer::SideCrossIterator::~SideCrossIterator()
{
}

// Constructor for SideCrossIterator, initializing it with a specific position.
// This constructor will allow you to start iterating from any position in the MagicalContainer.
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& MagicalContainer, size_t pos)
    : magicContainer(MagicalContainer), currentPosition(pos)
{
}

// Default constructor for SideCrossIterator, initializing it with the start of the MagicalContainer.
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& MagicalContainer)
    : magicContainer(MagicalContainer), currentPosition(0)
{
}

// Overloading of operator* to get the value at the current position.
// It alternates between beginning and end, satisfying the O(1) condition.
int MagicalContainer::SideCrossIterator::operator*() const
{
    size_t index = (currentPosition % 2 == 0) ? (currentPosition / 2) : (magicContainer.size() - 1 - ((currentPosition - 1) / 2));
    return magicContainer[index];
}


// Overloading of operator= for assignment between iterators. 
// It throws an error if the iterators point to different containers.
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
{
    if (&magicContainer != &other.magicContainer)
    {
        throw std::runtime_error("Attempting to equate distinct magicContainers.");
    }
    if (this != &other)
    {
        currentPosition = other.currentPosition;
    }
    return *this;
}
    
// Overloading of operator!= to compare two iterators. Returns true if they are different.
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
{
    return !(*this == other);
}

// Overloading of operator== to compare two iterators. Returns true if they are equal.
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
{
    return &magicContainer == &other.magicContainer && currentPosition == other.currentPosition;
}

// Overloading of operator> to compare two iterators. Returns true if this iterator is greater.
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
{
    return currentPosition > other.currentPosition;
}

// Overloading of operator++ to increment the iterator's position. Throws an exception if the end is reached.
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
    if (*this == end() || currentPosition >= magicContainer.size())
    {
        throw runtime_error("Exceeding permissible limit!");
    }
    currentPosition++;
    return *this;
}

// Overloading of operator< to compare two iterators. Returns true if this iterator is lesser.
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
{
    return currentPosition < other.currentPosition;
}

// Function to get an iterator pointing to the beginning of the MagicalContainer.
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return SideCrossIterator(magicContainer, 0);
}

// Function to get an iterator pointing to the end of the MagicalContainer.
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    return SideCrossIterator(magicContainer, magicContainer.size());
}
