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

void draw_bar_graph(int array[], int length, bar_graph bar[], int layer_id, int n){

    for (int i = 0; i < length; i++) {
        bar[i].x = WINDOW_X / length * i;
        bar[i].y = 0;
        bar[i].width = WINDOW_X / length;
        bar[i].height = WINDOW_Y / length * array[i];
    }

    HgLClear(layer_id);

//    HgWText(layer_id , 0, 0, "n = %d", n);

    HgWSetFillColor(layer_id, HG_BLACK);
    for (int i = 0; i < length; i++) {
        HgWBox(layer_id, bar[i].x, bar[i].y, bar[i].width, bar[i].height);
    }
    if (length < 500){
        HgSleep(0.1);
    }
}

void draw_bar_graph_for_Ста́линСорт(int array[], int length, int удалять_length, bar_graph_for_СталинСорт bar[], int layer_id, int is_После_чистки){

    if (is_После_чистки){
        for (int i = 0; i < удалять_length; i++) {
            bar[i].x = WINDOW_X / length * i;
            bar[i].y = 0;
            bar[i].width = WINDOW_X / length;
            bar[i].height = WINDOW_Y / length * array[i];
        }
    } else {
        for (int i = 0; i < length; i++) {
            bar[i].x = WINDOW_X / length * i;
            bar[i].y = 0;
            bar[i].width = WINDOW_X / length;
            bar[i].height = WINDOW_Y / length * array[i];
        }
    }

    HgLClear(layer_id);

    HgWSetFillColor(layer_id, HG_WHITE);
    for (int i = 0; i < length; i++) {
        if (bar[i].is_удалять == TRUE){
            HgWSetFillColor(layer_id, HG_RED);
        } else {
            HgWSetFillColor(layer_id, HG_WHITE);
        }
        HgWBoxFill(layer_id, bar[i].x, bar[i].y, bar[i].width, bar[i].height, 1);
    }
    if (length < 500){
        HgSleep(0.1);
    }
}


void merge(int array[], int length, int left, int mid, int right, bar_graph bar[], doubleLayer *layers, int *n){
    (*n)++;
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) // 配列L[0..n1]とR[0..n2]を作成
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2){ // 配列LとRをマージ
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

    while (i < n1){ // Lに残っている要素をコピー
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){ // Rに残っている要素をコピー
        array[k] = R[j];
        j++;
        k++;
    }

    int layer_id = HgLSwitch(layers);
    draw_bar_graph(array, length, bar, layer_id, *n); // 棒グラフを描画
}

void mergeSortHelper(int array[], int length,int left, int right, bar_graph bar[], doubleLayer *layers, int *n){
    (*n)++;
    if (left < right){ // 配列の要素が2つ以上ある場合
        int mid = left + (right - left) / 2; // 配列を分割するためのインデックスを計算

        mergeSortHelper(array, length,left, mid, bar, layers, n); // 左側をマージソート
        mergeSortHelper(array, length,mid + 1, right, bar, layers, n); // 右側をマージソート

        merge(array, length,left, mid, right, bar, layers, n); // 左右をマージ
    }

}