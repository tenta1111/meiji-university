# 訂正

訂正しました。
以前は与えられたデータを１０進数に直した後−５〜５[V]の範囲に収める処理をしていませんでした。

今回訂正した

```cpp
fprintf(ofp, "%f\n", (float)bin2dec(data[i])*5.0/0x0fff);
```

の0x0fffは２進数に直すと１が１２個並んだものになります。つまり１２ビットのデータを0x0fffで割り５をかけることで値域に収めるようにしました。
ウェブのテキストをよく読むとこの処理が必要なことに気づき訂正にいたりました。
- - -
2017年７月８日