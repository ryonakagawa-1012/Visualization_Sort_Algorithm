//
// Created by 中川諒 on 2023/11/15.
//

#include "main.h"

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

int IsNotSorted(int array[], int length){
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i+1]) {
            return 1;
        }
    }
    return 0;
}

void draw_bar_graph(int array[], int length, bar_graph bar[], int layer_id){

    for (int i = 0; i < length; i++) {
        bar[i].x = WINDOW_X / length * i;
        bar[i].y = 0;
        bar[i].width = WINDOW_X / length;
        bar[i].height = WINDOW_Y / length * array[i];
    }

    HgLClear(layer_id);
    HgWSetFillColor(layer_id, HG_BLACK);
    for (int i = 0; i < length; i++) {
        HgWBox(layer_id, bar[i].x, bar[i].y, bar[i].width, bar[i].height);
    }
    HgSleep(0.1);
}