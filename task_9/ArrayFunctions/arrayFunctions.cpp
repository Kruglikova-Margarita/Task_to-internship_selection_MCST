#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> getSubSequence(vector<int> sequence, int start_index, int end_index) {
    vector<int> subSequence;

    for (int i = start_index; i <= end_index; i++) {
        subSequence.push_back(sequence[i]);
    }

    return subSequence;
}



int sumElements(vector<int> array) {
    int size = array.size();
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum;
}



void printArray(vector<int> array) {
    int size = array.size();

    cout << "[";

    for (int i = 0; i < size - 1; i++) {
        cout << array[i] << ", ";
    }

    cout << array[size - 1] << "]\n";
}



int inputInt() {
    int num;

    while(!(cin >> num)) {
        cout << "Error: the value must be an integer. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return num;
}



int inputNatural() {
    int num = -1;

    while(!(cin >> num) || (num <= 0)) {
        cout << "Error: the value must be an integer and more than zero. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return num;
}



vector<int> inputArray() {
    int size;
    vector<int> array;
    int element;

    cout << "Input the size of the array: ";
    size = inputNatural();

    for (int i = 0; i < size; i++) {
        cout << "array[" << i << "] = ";
        element = inputInt();
        array.push_back(element);
    }

    return array;
}