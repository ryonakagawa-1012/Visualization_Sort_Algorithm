# Visualization_Sort_Algorithm
様々なソートアルゴリズムをHandy Graphicを用いて可視化する

## 実装したソートアルゴリズム
- バブルソート
- 選択ソート
- 挿入ソート
- マージソート
- ボゴソート
- スターリンソート（2024/2/5追加）

## 実行方法
1. Visualization_Sort_Algorithm内に移動した後、コンソール上で以下のコマンドを実行
    ```
    hgcc main.c func_main.c func_sub.c && ./a.out
    ```
2. 画面上にソートアルゴリズムの選択肢が表示されるので、数字を入力
3. ソートする長さを入力

## 実行例(バブルソート、長さ100)

https://github.com/ryonakagawa-1012/Visualization_Sort_Algorithm/assets/132760282/a240f054-3338-4fab-8deb-5388c9e375f8

## 今後実装したいこと（やる気があれば）
 - クイックソート、ヒープソート
 - 比較回数を表示（[この動画](https://youtu.be/kPRA0W1kECg?si=QX30_fNQGmWx0lwI)の左上の方にあるようなもの）
 - 複数のソートアルゴリズムを複数ウィンドウで同時実行
