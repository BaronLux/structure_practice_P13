#include <iostream>

using namespace std;

void main() {
    setlocale(0, "");
    const int arr_size = 4;
    int arr[arr_size][arr_size];
    int choise;
    cout << "1 - input array\t2 - random init" << endl;
    cin >> choise;
    switch (choise)
    {
        case 1:
        {
            for (int i = 0; i < arr_size; i++) {
                for (int j = 0; j < arr_size; j++) {
                    cout << "input a[" << i << "][" << j << "] ";
                    cin >> arr[i][j];
                }
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < arr_size; i++) {
                for (int j = 0; j < arr_size; j++) {
                    arr[i][j] = rand() % 10;
                }
            }
            break;
        }
    }

    for (int i = 0; i < arr_size; i++)
    {
        for (int j = 0; j < arr_size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int n = 7;
    bool* is_visited = new bool[n];
    memset(is_visited, false, sizeof(bool) * n);
    is_visited[0] = true;
    for (int l = 0; l < n - 1; l++)
    {
        int min_x = -1, min_y = -1;
        for (int i = 0; i < n; i++)
        {
            if (is_visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!is_visited[j] &&
                        arr[i][j] > 0 &&
                        (min_y == -1 || arr[i][j] < arr[min_y][min_x]))
                    {
                        min_y = i, min_x = j;
                    }
                }
            }
        }
        is_visited[min_x] = true;
        cout << min_y << "->" << min_x << endl;
    }
}