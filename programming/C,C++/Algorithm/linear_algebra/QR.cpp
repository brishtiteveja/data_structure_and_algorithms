#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct vector<double> v;

typedef struct vector<v> mat;

typedef struct QR_struct {
    mat Q;
    mat R;
} QR;


void printVec(v x)
{
    for(int i=0; i<x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;

    return;
}
    
void printMat(mat A, int m, int n) 
{
    for (int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << A[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;

    return;
}

double abs(v x, int n)
{
    double s = 0;
    for(int i=0; i<n; i++)
    {
        s += x[i] * x[i];
    }

    s = sqrt(s);

    return s;
}

v getUnitVec(v x, int n)
{
    v r;
   
    double a = abs(x, n);

    for(int i=0; i<n; i++)
    {
        double r_i = x[i] / a;
        r.push_back(r_i);
    }

    return r;
}

double dot(v x1, v x2, int n)
{
    double s = 0;
    for(int i=0; i<n; i++) 
    {
        s += x1[i] * x2[i];
    }

    return s;
}

v matmult(mat A, v x, int m, int n)
{
    v r;

    for(int i=0; i<m; i++) 
    {
        double s = 0;
        for(int j=0; j<n; j++) 
        {
            s += A[i][j] * x[j];
        }
        r.push_back(s);
    }

    return r;
}

v vecscale(v x1, double sf, int n) 
{
    v r;
    for(int i=0; i<n; i++)
    {
        double s = x1[i] * sf;
        r.push_back(s);
    }

    return r;
}

v vecadd(v x1, v x2, int n) 
{
    v r;
    for(int i=0; i<n; i++)
    {
        double s = x1[i] + x2[i];
        r.push_back(s);
    }

    return r;
}

v vecsub(v x1, v x2, int n) 
{
    v r;
    for(int i=0; i<n; i++)
    {
        double s = x1[i] - x2[i];
        r.push_back(s);
    }

    return r;
}

mat transpose(mat A, int m, int n)
{
    mat A_T(m, v(n));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            A_T[j][i] = A[i][j];
        }
    }

    return A_T;
}

mat gram_schmidt(mat A, int m, int n)
{
    mat Q;
    
    for(int j=0; j<n; j++)
    {
        v a;
        for (int i=0; i<m; i++)
        {
            a.push_back(A[i][j]);
        }

        v u(a);
        for(int k=0; k<j; k++)
        {
            v a_k;
            for (int i=0; i<m; i++)
            {
                a_k.push_back(A[i][j]);
            }
            v u_k = a_k; 

            v e_k = getUnitVec(u_k, n);
            double dp = dot(a_k, e_k, n);
            v p = vecscale(e_k,dp, n);
            u = vecsub(u, p, n); 
        }

        Q.push_back(u);
    }

    return Q;

}

QR getQR(mat A, int m, int n)
{
    QR qr;

    mat Q;
    mat R;
    
    for(int j=0; j<n; j++)
    {
        v a;
        for (int i=0; i<m; i++)
        {
            a.push_back(A[i][j]);
        }

        v u(a); // column for Q mat

        v r(m); // column for R mat
        for(int k=0; k<j; k++)
        {
            v a_k;
            for (int i=0; i<m; i++)
            {
                a_k.push_back(A[i][j]);
            }
            v u_k = a_k; 

            v e_k = getUnitVec(u_k, n);
            double dp = dot(a_k, e_k, n);

            // column of R
            r.push_back(dp);
            for(int l=k+1; l<m; l++)
                r.push_back(0);

            v p = vecscale(e_k,dp, n);
            u = vecsub(u, p, n); 
        }
        R.push_back(r);

        Q.push_back(u);
    }

    qr.Q = Q;
    printMat(R, m, n);
    qr.R = transpose(R, m, n);

    return qr;
}

int main()
{

    cout << "Give a vector x." << endl;
    cout << "Size of the vector (n=?)" << endl;
    int n;
    cin >> n;

    // create the vector x
    v x(n);

    cout << "Give the values for each of the n components of the vector x." << endl;
    for(int i=0; i<n; i++)
    {
        cin >> x[i]; 
    }
    cout << endl;

    // printVec(x);

    cout << "Give the matrix A." << endl;
    cout << "Row and Column size of the matrix (m, n)" << endl;
    int m, n2;
    cin >> m >> n2;
    cout << endl;

    // Create the matrix A 
    mat A;

    cout << "Give the values for each of m*n components of the matrix A." << endl;
    for (int i=0; i<n2; i++)
    {
        v r(n2);

        cout << "Row " << i << ": " ;
        for(int j=0; j<n2; j++)
        {
            cin >> r[j]; 
        }
        A.push_back(r);
    }
    //printMat(A, m, n2); 

    //cout << dot(x, x, n);

    v y = matmult(A, x, m, n);
    //printVec(y);
    //check abs of vec
    //cout << abs(y, n) << endl;
    //
    //check unitvec
    //v yhat = getUnitVec(y, n); 
    //
    //printVec(yhat);

    // check matrix transpose
    //mat A_T = transpose(A, m, n);
    //printMat(A_T, m, n);
    //
    QR qr = getQR(A, m, n);
    printMat(qr.Q, m, n);
    cout << endl;
    printMat(qr.R, m, n);
    cout << endl;

    return 0;
}

