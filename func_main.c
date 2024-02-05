//
// Created by 中川諒 on 2023/11/13.
//

#include "main.h"

int GenerateAndShuffleArray(int array[], int length);
int IsNotSorted(int array[], int length);
void draw_bar_graph(int array[], int length, bar_graph bar[], int layer_id, int n);
void draw_bar_graph_for_Ста́линСорт(int array[], int length, int удалять_length, bar_graph bar[], int layer_id, int is_После_чистки);

void mergeSortHelper(int array[], int length, int left, int right, bar_graph bar[], doubleLayer *layers, int *n);


int select_algorithm(void){
    int algorithm;
    printf("見たいソートアルゴリズムを選んでください(0以上4以下)\n\n");
    printf("0: バブルソート\n");
    printf("1: 選択ソート\n");
    printf("2: 挿入ソート\n");
//    printf("3: クイックソート\n");
    printf("3: マージソート\n");
//    printf("5: ヒープソート\n");
    printf("4: ボゴソート\n");
    printf("5: Ста́линСорт\n\n");

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

int sort_length_for_СталинСорт(void){
    int length;
    printf("Определить длину массива, который нужно отсортировать\n\n");
    printf(">>> ");
    scanf("%d", &length);
    return length;
}

void bubbleSort(int length){
    int array[length];
    int n = 0;

    GenerateAndShuffleArray(array, length);
    bar_graph bar[length];

    HgOpen(WINDOW_X, WINDOW_Y);

    int layer_id;
    doubleLayer layers;
    layers = HgWAddDoubleLayer(0);

    while (IsNotSorted(array, length)){ // ソートが終わるまで繰り返す
        n++;
        for (int i = 0; i < length - 1; i++) {
            if (array[i] > array[i + 1]) {
                // array[i] と array[i + 1] を交換
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        layer_id = HgLSwitch(&layers);
        draw_bar_graph(array, length, bar, layer_id, n); // 棒グラフを描画
    }
    layer_id = HgLSwitch(&layers);
    draw_bar_graph(array, length, bar,layer_id, n+1); //最後のレイヤーを表示
}

void selectionSort(int length){
    int array[length];
    bar_graph bar[length];

    GenerateAndShuffleArray(array, length);

    HgOpen(WINDOW_X, WINDOW_Y);

    int layer_id, i;
    doubleLayer layers;
    layers = HgWAddDoubleLayer(0);

    for (i = 0; i < length - 1; i++) {// 配列の最後の要素まで繰り返す
        // 配列の最小値を探す
        int min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        // array[i] と array[min_index] を交換
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;

        layer_id = HgLSwitch(&layers);
        draw_bar_graph(array, length, bar, layer_id, i+1); // 棒グラフを描画
    }
    layer_id = HgLSwitch(&layers);
    draw_bar_graph(array, length, bar, layer_id, i); //最後のレイヤーを表示
}

void insertionSort(int length){
    int array[length];
    bar_graph bar[length];

    GenerateAndShuffleArray(array, length);

    HgOpen(WINDOW_X, WINDOW_Y);

    int layer_id, i;
    doubleLayer layers;
    layers = HgWAddDoubleLayer(0);

    for (i = 1; i < length; i++) { // 配列の最後の要素まで繰り返す
        int key = array[i]; // 挿入する値
        int j = i - 1;

        // array[j] を右に移動
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key; // 挿入する値を挿入

        layer_id = HgLSwitch(&layers);
        draw_bar_graph(array, length, bar, layer_id, i-1); // 棒グラフを描画
    }
    layer_id = HgLSwitch(&layers);
    draw_bar_graph(array, length, bar, layer_id, i); //最後のレイヤーを表示
}

void quickSort(int length, int pivot){

}

void mergeSort(int length) {
    int array[length];
    bar_graph bar[length];

    GenerateAndShuffleArray(array, length);

    HgOpen(WINDOW_X, WINDOW_Y);

    int layer_id;
    doubleLayer layers;
    layers = HgWAddDoubleLayer(0);
    int n = 0;
    mergeSortHelper(array, length, 0, length - 1, bar, &layers, &n); // マージソートを実行

    layer_id = HgLSwitch(&layers);
    draw_bar_graph(array, length, bar, layer_id, n+1); //最後のレイヤーを表示

}

void heapSort(int length){

}

void bogoSort(int length){
    int array[length];
    bar_graph bar[length];

    GenerateAndShuffleArray(array, length);

    HgOpen(WINDOW_X, WINDOW_Y);

    int layer_id;
    int n = 0;

    doubleLayer layers;
    layers = HgWAddDoubleLayer(0);

    while (IsNotSorted(array, length)){
        n++;
        for (int i = length - 1; i > 0; --i) {
        // 0からiまでのランダムな位置を選ぶ
        int j = rand() % (i + 1);

        // array[i] と array[j] を交換
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

        layer_id = HgLSwitch(&layers);
        draw_bar_graph(array, length, bar, layer_id, n); // 棒グラフを描画
    }
    layer_id = HgLSwitch(&layers);
    draw_bar_graph(array, length, bar, layer_id, n+1); //最後のレイヤーを表示
}

void Ста́линСорт(int length){
    int array[length];
    int удалять_array[length]; //粛清後の配列
    int удалять_length = -1; //粛清後の配列の長さ
    bar_graph_for_СталинСорт bar_for_СталинСорт[length];

    for (int i = 0; i < length; i++) {
        bar_for_СталинСорт[i].is_удалять = FALSE;
    }

    GenerateAndShuffleArray(array, length);

    HgOpen(WINDOW_X, WINDOW_Y);

    int layer_id;
    int n = 0;

    doubleLayer layers;
    layers = HgWAddDoubleLayer(0);

    int tmp = array[0] - 1;
    for (int i = 0; i < length; i++) {
        if (tmp <= array[i]) {
            удалять_array[++удалять_length] = array[i];
            tmp = array[i];
            bar_for_СталинСорт[i].is_удалять = FALSE;
        } else {
            bar_for_СталинСорт[i].is_удалять = TRUE;
        }

        layer_id = HgLSwitch(&layers);
        draw_bar_graph_for_Ста́линСорт(array, length, удалять_length, bar_for_СталинСорт, layer_id, FALSE); // 棒グラフを描画
    }
    layer_id = HgLSwitch(&layers);
    draw_bar_graph_for_Ста́линСорт(удалять_array, length, удалять_length, bar_for_СталинСорт, layer_id, TRUE); //最後のレイヤーを表示

}
