#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

template<typename T>
void Print2DVector(std::vector<std::vector<T>> const& aVec)
{
   int row_size = aVec.size();
   int col_size = aVec[0].size();

   for (int row_loop = 0; row_loop < row_size; row_loop++)
   {
	  col_size = aVec[row_loop].size();
      for (int col_loop = 0; col_loop < col_size; col_loop++)
      {
         // let's display the filled 2D vector
         std::cout << aVec[row_loop][col_loop] << ' ';
      }
      std::cout << '\n';
   }
}


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > temp;
		if(numRows == 0)
			return temp;
		vector<int> row;
		row.push_back(1);
		temp.push_back(row);

		if(numRows == 1)
			return temp;

		row.push_back(1);
		temp.push_back(row);

		if(numRows == 2)
			return temp;

		for(int j = 3;j <= numRows;j++){
			vector<int> row;
			row.push_back(1);
			for(int i = 1;i < j-1;i++){
				row.push_back(temp[j-2][i-1] + temp[j-2][i]);
			}
			row.push_back(1);
			temp.push_back(row);
		}
		return temp;
    }
};



int main( ) {

	Solution s;

	vector<vector<int> > res = s.generate(5);

    int num;

    //printf( "Enter a value :");
	//scanf("%d", &num);
	//printf( "\nYou entered: %d\n", num);
	Print2DVector(res);


    return 0;
}
