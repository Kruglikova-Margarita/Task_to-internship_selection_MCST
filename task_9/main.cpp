#include <iostream>
#include <vector>
#include "FindSeqWithMaxSum/findSeqWithMaxSum.hpp"
#include "ArrayFunctions/arrayFunctions.hpp"

using namespace std;

int main() {
    vector<int> array = inputArray();
    cout << "Inputed array: ";
    printArray(array);

    vector<int> sub_seq = findSeqWithMaxSum(array);

    cout << "\nThe continuous sequence of numbers with a maximum sum: ";
    printArray(sub_seq);
    cout << "Sum of elements of this sequence is " << sumElements(sub_seq) << "\n";

    return 0;
}