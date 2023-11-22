//
// Created by 中川諒 on 2023/11/13.
//

#include "main.h"

int GenerateAndShuffleArray(int array[], int length);
int IsNotSorted(int array[], int length);
void draw_bar_graph(int array[], int length, bar_graph bar[], int layer_id);


int select_algorithm(void){
    int algorithm;
    printf("見たいソートアルゴリズムを選んでください\n\n");
    printf("0: バブルソート\n");
    printf("1: 選択ソート\n");
    printf("2: 挿入ソート\n");
    printf("3: クイックソート\n");
    printf("4: マージソート\n");
    printf("5: ヒープソート\n");
    printf("6: ボゴソート\n\n");

    printf(">>> ");
    scanf("%d", &algorithm);
    return algorithm;
}

int sort_length(void){
    int length;
    printf("ソートする配列の長さを決めてください\n\n");
    printf(">>> ");
    scanf("%d", &length);
    return length;
}

void bubbleSort(int length){
    int array[length];

    GenerateAndShuffleArray(array, length);
    bar_graph bar[length];

    HgOpen(WINDOW_X, WINDOW_Y);

    int layer_id;
    doubleLayer layers;
    layers = HgWAddDoubleLayer(0);

    while (IsNotSorted(array, length)){
        for (int i = 0; i < length - 1; i++) {
            if (array[i] > array[i + 1]) {
                // array[i] と array[i + 1] を交換
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        layer_id = HgLSwitch(&layers);
        draw_bar_graph(array, length, bar, layer_id); // 棒グラフを描画
    }
    layer_id = HgLSwitch(&layers);
    draw_bar_graph(array, length, bar,layer_id); //最後のレイヤーを表示
}

void selectionSort(int length){

}

void insertionSort(int length){

}

void quickSort(int length){

}

void mergeSort(int length){

}

void heapSort(int length){

}

void bogoSort(int length){

}
