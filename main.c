#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Dimension of input square matrix
#define N 7

// Function to get cofactor of mat[p][q] in temp[][]. n is
// current dimension of mat[][]
void getCofactor(int mat[N][N], int temp[N][N], int p,
                 int q, int n)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
float determinantOfMatrix(int mat[N][N], int n)
{
    float D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
        return (float) mat[0][0];

    int temp[N][N]; // To store cofactors

    int sign = 1; // To store sign multiplier

    // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f]
             * determinantOfMatrix(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}


// Driver program to test above functions
int main()
{
    int n=0, sw=0, counter=0, num = 0;
    printf("Enter number of alignments:");
    //readInt
    scanf("%d", &n);
    printf("N = %d\n", n);

    int mat[7][7] = { { 3, -2, 4},
                      { 3, 4, -2},
                      { 2, -1, -1}};
    int tmp[7][7];
    int B[7];
    float result[7];
//
    while(counter < n)
    {
//        //readSwitch
//        printf("Select switch and press enter");
//        scanf("%d", &sw);
//        for(int i=0; i<n; i++)
//        {
//            //readInt
//            scanf("%d", &mat[sw][i]);
//            printf("A[%d][%d]: %d\n", sw, i ,mat[sw][i]);
//        }
//        //readInt
//CHANGE SW
        scanf("%d", &B[counter]);
        printf("B[%d]: %d\n", sw, B[counter]);
        counter++;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("A[%d][%d]: %d ", i, j ,mat[i][j]);
        printf("B[%d]: %d\n", i, B[i]);
    }

    printf("Solving...\n");

    float det_matrix = determinantOfMatrix(mat, n);
    // Function call
    printf("Determinant of the matrix is : %7.3lf\n", det_matrix);

    for (int k=0; k < n; k++) {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++) {
                if (i == num) {
                    tmp[i][j] = B[i];
                    num++;
                    printf("A[%d][%d]: %d ", i, j ,tmp[i][j]);
                } else{
                    tmp[i][j] = mat[i][j];
                    printf("A[%d][%d]: %d ", i, j ,tmp[i][j]);
                }
            }
        }
        float det_tmp = determinantOfMatrix(tmp, n);
        result[k] = det_tmp/det_matrix;
        printf("RESULT[%d] : %7.3lf\n", k,result[k]);
    }

    return 0;
}


