//
// Created by 中川諒 on 2023/11/15.
//

#include "main.h"

typedef struct {
    double x; // 棒グラフの左下隅のx座標
    double y; // 棒グラフの左下隅のy座標
    double width; // 棒グラフの幅
    double height;  // 棒グラフの高さ
} bar_graph;

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

void draw_bar_graph(int array[], int length){
    bar_graph bar[length];

    for (int i = 0; i < length; i++) {
        bar[i].x = WINDOW_X / length * i;
        bar[i].y = 0;
        bar[i].width = WINDOW_X / length;
        bar[i].height = WINDOW_Y / length * array[i];
    }

    HgClear();
    HgSetColor(HG_BLACK);
    HgSetFillColor(HG_BLACK);
    for (int i = 0; i < length; i++) {
        HgBox(bar[i].x, bar[i].y, bar[i].width, bar[i].height);
    }
    HgSleep(0.1);
}