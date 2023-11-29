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
    if (length < 500){
        HgSleep(0.1);
    }
}

void merge(int array[], int length, int left, int mid, int right, bar_graph bar[], doubleLayer *layers){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }
        else{
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        array[k] = R[j];
        j++;
        k++;
    }

    int layer_id = HgLSwitch(layers);
    draw_bar_graph(array, length, bar, layer_id); // 棒グラフを描画
}

void mergeSortHelper(int array[], int length,int left, int right, bar_graph bar[], doubleLayer *layers){
    if (left < right){
        int mid = left + (right - left) / 2;

        mergeSortHelper(array, length,left, mid, bar, layers);
        mergeSortHelper(array, length,mid + 1, right, bar, layers);

        merge(array, length,left, mid, right, bar, layers);
    }

}
