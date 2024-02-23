#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void swap(vector<vector<int>> &matrix, int i1, int j1, int i2, int j2)
    {
        int temp = matrix[i1][j1];
        matrix[i1][j1] = matrix[i2][j2];
        matrix[i2][j2] = temp;
    }
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size() / 2; i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                swap(matrix, i, j, matrix.size() - 1 - i, j);
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                swap(matrix, i, j, j, i);
            }
        }
    }
};
int **createMatrix(int n)
{
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * n);
    }
    return (matrix);
}
int **copyMatrix(int **arr, int n)
{
    int **matrix = createMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = arr[i][j];
        }
    }
    return (matrix);
}
void printMatrix(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void initMatrix(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
}
void destroyMatrix(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);
}
void rotate_2d_matrix(int **matrix, int size)
{
    int **copy = copyMatrix(matrix, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = copy[size - 1 - j][i];
        }
    }
    // cout << (&matrix) << " " << (&copy)<< endl;
    destroyMatrix(copy, size);
}
void swap(int **matrix, int i1, int j1, int i2, int j2)
{
    cout << "swapping indexes " << i1 << " " << j1 << " with indexes " << i2 << " " << j2 << endl;
    int temp = matrix[i1][j1];
    matrix[i1][j1] = matrix[i2][j2];
    matrix[i2][j2] = temp;
}
void rotate_2d_matrix_in_place(int **matrix, int size)
{
    // reversing the matrix
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            swap(matrix, i, j, size - 1 - i, j);
        }
    }
    // transposing the matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i <= j)
            {
                swap(matrix, i, j, j, i);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int **matrix = createMatrix(n);
    initMatrix(matrix, n);
    cout << "\n**********************************************************************************************************************\n"
         << endl;
    printMatrix(matrix, n);
    cout << "\n**********************************************************************************************************************\n"
         << endl;
    rotate_2d_matrix_in_place(matrix, n);
    cout
        << "\n**********************************************************************************************************************\n"
        << endl;
    printMatrix(matrix, n);
    cout << "\n**********************************************************************************************************************\n"
         << endl;
    destroyMatrix(matrix, n);
    return (0);
}
