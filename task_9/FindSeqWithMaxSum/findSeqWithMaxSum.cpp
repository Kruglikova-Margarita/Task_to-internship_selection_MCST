#include <iostream>
#include <vector>
#include "../ArrayFunctions/arrayFunctions.hpp"

using namespace std;

vector<int> findSeqWithMaxSum(vector<int> array) {
    int size = array.size();
    int sub_seq_start_index = 0;
    int sub_seq_sum = 0;
    int sub_seq_len = 0;
    int current_sum = 0;
    int current_size = 0;
    int i;

    for(i = 0; i < size; i++) {
        current_sum = array[i];
        current_size = 0;

        while((i + current_size + 1 < size) && (array[i + current_size + 1] > array[i + current_size])) {
            current_sum += array[i + current_size + 1];
            current_size++;
        }

        current_size++;

        if ((current_sum > sub_seq_sum) || ((current_sum == sub_seq_sum) && (current_size > sub_seq_len))) {
            sub_seq_start_index = i;
            sub_seq_sum = current_sum;
            sub_seq_len = current_size;
        }
    }

    vector<int> sub_sequence = getSubSequence(array, sub_seq_start_index, sub_seq_start_index + sub_seq_len - 1);

    return sub_sequence;
}