# Algorithm_Learning

<!-- TOC -->

- [Algorithm_Learning](#algorithm_learning)
  - [01. Array](#01-array)
    - [118_PascalTrangle](#118_pascaltrangle)

<!-- /TOC -->



## 01. Array

### 118_PascalTrangle

- 构建一个可以放置10个 `int` 的链表
  - 完成内存分配
  - 按有小到大排序插入新的数据
  - 查询链表内容
  - 删除链表内容

- 题目

  ```
  Input: 5
  Output:
  [
       [1],
      [1,1],
     [1,2,1],
    [1,3,3,1],
   [1,4,6,4,1]
  ]
  ```

- 我的思考

  ```c
  #include <stdio.h>
  #include <stdlib.h>
  
  
  
  int main( ) {
  
      int num;
  
      int *arrayLast, *arrayCurrent;  // 数组指针
      arrayLast = (int*)malloc( num*sizeof(int) );
      arrayCurrent = (int*)malloc( num*sizeof(int) );
      arrayLast[0] = 1;
      arrayLast[1] = 1;
      
      printf( "Enter a value :");
      scanf("%d", &num);
      printf( "\nYou entered: %d\n", num);
  
      
      int i, j;
      for ( i = 0; i < num; i++)
      {
          //printf("%d:", i);
          for ( j = 0; j <= num - i; j++)  // for output format
              printf(" ");
          if ( i == 0 )
              printf("[1]\n");
          else if ( i == 1)
              printf("[1,1]\n");
          else
          {
              printf("[");
              arrayCurrent[0] = 1;
              printf("%d", arrayCurrent[0]);
              for ( j = 1; j <= i; j++)
              {
                  //printf("%d,", j);
                  arrayCurrent[j] = arrayLast[j-1] + arrayLast[j];
                  printf(",%d", arrayCurrent[j]);
              }
              printf("]\n");
              for (j = 0; j < num; j++)
              {
                  printf("%d,", arrayCurrent[j]);
                  arrayLast[j] = arrayCurrent[j];
              }
          }
      }
      free(arrayLast);
      free(arrayCurrent);
      return 0;
  }
  ```

- 最快速程序

  ```c++
  class Solution {
  public:
      vector<vector<int>> generate(int numRows) {
          int n = numRows;
          if(n<1) return {};
          vector<vector<int>> ans(n);
          ans[0].push_back(1);
          for(int i = 2; i <= n; ++i){
              ans[i-1].resize(i, 1);
              vector<int>& v0 = ans[i-2]; // vector 的直接复制
              vector<int>& v = ans[i-1];
              int i0 = 1; 
              int j0 = i-2;
              while(i0<=j0){
                  v[i0] = v[j0] = v0[i0-1]+v0[i0]; // 两边向中间运算
                  ++i0;
                  --j0;
              }
          }
          return ans;
      }
  };
  ```

- 算法问题

  - 思路1 - 依据上一行内容叠加

    - 需要两个空间，记录上一个，存储下一个。

    - 或补充一个0的思路

      ```
      1 0 
      1 1 0
      1 2 1 0
      1 3 3 1 0
      ```

  - 思路2 - 多项式系数问题

    $$
    \begin{array}{c}  (x+y)^0 = 1\\  (x+y)^1 = x + y\\  (x+y)^2 = x^2 + 2xy + y^2\\  (x+y)^3 = x^3 + 3x^2 y + 3xy^2 + y^3\\  (x+y)^4 = x^4 + 4x^3 y + 6x^2 y^2 + 4x y^3 + y^4\\  \end{array}
    $$

    以第6行为例

    - 目标值：1，6，15，20，15，6，1
    - 计算方法 
    $$
    \begin{array}{rcl}  1\times\frac{6}{1}&=&6 \\ 6 \times \frac{5}{2} &=& 15 \\15 \times \frac{4}{3} &=& 20\\  20 \times \frac{3}{4} &=& 15\\  15 \times \frac{2}{5} &=& 6\\  6 \times \frac{1}{6} &=& 1\\  \end{array}
    $$

- 输出格式问题

  - 空格次数为递减数列：5-4-3-2-1
