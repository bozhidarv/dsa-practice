#include <cstddef>

class SortSolutions {
public:
  void mergeSort(int *arr, size_t arrSize) {
    int *buffArr = new int[arrSize];
    ms(arr, arrSize, buffArr, arrSize);
  }

private:
  void ms(int *arr, size_t arrSize, int *buffArr, size_t bSize) {
    if (arrSize <= 1) {
      return;
    }

    ms(arr, arrSize / 2, buffArr, bSize);
    ms(arr + (arrSize / 2), arrSize - (arrSize / 2), buffArr, bSize);

    merge(arr, arrSize / 2, arr + (arrSize / 2), arrSize - (arrSize / 2),
          buffArr, arr, arrSize);
  }

  void merge(int *left, size_t lSize, int *right, size_t rSize, int *buffArr,
             int *arr, size_t arrSize) {

    size_t lCursor = 0, rCursor = 0, bCursor = 0;

    while ((lCursor < lSize) && (rCursor < rSize)) {
      if (left[lCursor] < right[rCursor])
        buffArr[bCursor++] = left[lCursor++];
      else
        buffArr[bCursor++] = right[rCursor++];
    }

    while (lCursor < lSize) {
      buffArr[bCursor++] = left[lCursor++];
    }

    while (rCursor < rSize) {
      buffArr[bCursor++] = right[rCursor++];
    }

    for (size_t i = 0; i < arrSize; i++) {
      arr[i] = buffArr[i];
    }
  }
};
