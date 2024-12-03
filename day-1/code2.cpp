#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void bsorter(int arr[], int size)
  {

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int finder1(int arr1[], int arr2[], int size)
{
  int sum = 0;
  for (int i =0; i<size; i++)
  {
    int diff = arr1[i]-arr2[i];
    diff = abs(diff);
    sum = sum + diff;

  }
  cout << sum<<endl;
  return sum;

}

void similarity(int arr1[], int arr2[], int size)
{
    int score = 0;
    int count = 0;
    int mains = 0;
  for (int i =0; i<size; i++){
    count = 0;
  for (int j =0; j<size; j++)
  {if (arr1[i] == arr2[j])
  {
    count = count+1;
   
  }
  
score = arr1[i] * count;
  }
  
  mains= mains + score;
}

cout << mains<<endl;;
}

int main()
{

    ifstream file("input.txt");
    vector<vector<int>> columns; 
    string line;

    if (file.is_open())
    {
        while (getline(file, line)) 
        {
            stringstream ss(line);
            int num;
            int col_index = 0;

            while (ss >> num) 
            {
                if (columns.size() <= col_index)
                {
                    columns.push_back({});
                }
                columns[col_index].push_back(num); 
                col_index++;
            }
        }
        file.close();
    }
    else
    {
        cerr << "Unable to open file!" << endl;
        return 1;
    }
    
    int size1 = columns[0].size();
    int size2 = columns[1].size();

    int arr1[size1];
    int arr2[size2];

    for (int i = 0; i < size1; i++) arr1[i] = columns[0][i];
    for (int i = 0; i < size2; i++) arr2[i] = columns[1][i];

    int bigger1 = (sizeof(arr1)/sizeof(arr1[0]));
    bsorter(arr1, bigger1);
    int bigger2 = (sizeof(arr2)/sizeof(arr2[0]));
    bsorter(arr2, bigger2);

    finder1(arr1, arr2, bigger1);
    similarity( arr1, arr2, bigger1);



}