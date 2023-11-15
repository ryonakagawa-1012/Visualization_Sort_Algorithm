//
// Created by 中川諒 on 2023/11/15.
//

#include <stdlib.h>
#include <time.h>

void GenerateAndShuffleArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        array[i] = i+1;
    }
    srand((unsigned int)time(NULL)); // 乱数のシードを設定

    for (int i = length - 1; i > 0; --i) {
        // 0からiまでのランダムな位置を選ぶ
        int j = rand() % (i + 1);

        // array[i] と array[j] を交換
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
