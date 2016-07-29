#include <iostream>
#include <vector>
#include <algorithm>

auto  operator << (std::ostream & output, const std::vector<ssize_t> & array) -> std::ostream &
{
    std::ostream_iterator<ssize_t> output_iterator = { output, " " };
    std::copy(array.cbegin(), array.cend(), output_iterator);
    
    return output;
}


auto partition(std::vector<ssize_t> & array, size_t begin, size_t end)
{
    auto last_elemeny_index = end - 1;
    auto last_element = array[ last_elemeny_index ];
    
    size_t middle = begin;
    for ( size_t index = begin; index < last_elemeny_index; ++index ) {
        if ( array[ index ] < last_element ) {
            std::swap(array[ middle++ ], array[ index ]);
        }
    }

    std::swap(array[ last_elemeny_index ], array[ middle ] );
    
    return middle;
}

auto quicksort(std::vector<ssize_t> & array, size_t begin, size_t end) -> void
{
    if ( begin < end && begin != end - 1 ) {
        auto middle = partition(array, begin, end);
        quicksort(array, begin, middle);
        quicksort(array, middle + 1, end);
    }
}

auto quicksort(std::vector<ssize_t> & array)
{
    quicksort(array, 0, array.size());
}

int main(int argc, const char * argv[]) {
    
    std::vector<ssize_t> array = {2, 8, 7, 1, 3, 5, 6, 4};
    
    std::cout << array << std::endl;
    
    quicksort(array);
    
    std::cout << array << std::endl;
    
    
    return 0;
}
