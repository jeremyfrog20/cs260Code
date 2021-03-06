//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//Declare functions from Sorts we will test
void insertionSort(int arr[], int arrSize);
void selectionSort(int arr[], int arrSize);

#include <algorithm>

using namespace std;

TEST_CASE( "Sort/Insertion" ) {
    int list[] = {12, 9, 16, 2, 1, 16, 18, 7};
    int size = 8;

    //Copy to compare against
    int list_key[8];
    std::copy(list, list + size, list_key);
    std::sort(list_key, list_key + size);

    insertionSort(list, size);

    bool isSorted = std::is_sorted(list, list + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(list, list + size, list_key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}

TEST_CASE( "Sort/Section" ) {
    int list[] = {12, 9, 16, 2, 1, 16, 18, 7};
    int size = 8;

    //Copy to compare against
    int list_key[8];
    std::copy(list, list + size, list_key);
    std::sort(list_key, list_key + size);

    selectionSort(list, size);

    bool isSorted = std::is_sorted(list, list + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(list, list + size, list_key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}
