#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> dist;
long double k, m, t, c, n;

void swap(int &a, int &b) // used to swap two value on their reference
{
    int temp = a;
    a = b;
    b = temp;
}

void Print_distences() //  prints the given distance matrix
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
    cout << endl
         << endl;
}

double GoodNess(vector<int> state) // takes an state and find its goodness
{
    double Similarity = 0, Distance = 0;
    //cout << "Similarity" << endl;
    for (int i = 0; i < n; i += k)
    {
        for (int j = i; j < i + k; j++) // 1 2 3  ,  8 5 6  ||  i = 3 state[i] = 4  || mx = i+k = 3+3 =6
        {
            int mx = i + k;
            for (int jj = j + 1; jj < mx; jj++)
            {
                Similarity += (1 - dist[state[j] - 1][state[jj] - 1]);
                //cout << state[j] << " " << state[jj] << endl;
            }
        }
    }
    //cout << endl<< "Distance" << endl;
    for (int i = 0; i < n; i++)
    {
        int nxt = i - i % (int(k));
        for (int j = 1; nxt + j * k * t < n; j++)
        {
            int s = j * k * t + nxt;
            for (int jj = s; jj < s + k; jj++)
            {
                Distance += dist[state[i] - 1][state[jj] - 1];
                //cout << state[i] << " " << state[jj] << endl;
            }
        }
    }

    long double Goog = Similarity + c * Distance;

    return Goog;
}

void represent_output(vector<int> state) // takes an state and prits it in out put formate
{
    int i = 0;

    if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << state[i] << " ";
            if (i % (int)k == (int)(k - 1))
                cout << endl;
        }
    }
    else
    {
        for (int o = 0; o < n; o += t * k)
        {
            for (int i = o; i < o + k; i++)
            {
                cout << state[i] << " ";
            }
            for (int j = 1; j < t; j++)
            {
                cout << "| ";
                for (int i = o + j * k; i < o + (j + 1) * k; i++)
                {
                    cout << state[i] << " ";
                }
            }
            cout << endl;
        }
    }
    return;
}
bool same_market(int i, int j, long double k)
// chacks if two indexces correspond to same market
{
    return (i - i % (int)k) == (j - j % (int)k);
}

void AI_solver(vector<int> state, long double cur_Good, long double &max_Good, vector<int> &MG_state)
{
    while (1)
    {
        max_Good = max(max_Good, cur_Good); //  max = x , cur =  x+1

        if (max_Good == cur_Good)
        {
            MG_state = state;
        }

        long double best_child_good = 0;
        vector<int> best_child_state(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (same_market(i, j, k))
                    continue;

                vector<int> child_state = state;

                swap(child_state[i], child_state[j]);

                long double child_Good = GoodNess(child_state);

                if (child_Good > cur_Good)
                {
                    if (best_child_good < child_Good)
                    {
                        best_child_good = child_Good;
                        best_child_state = child_state;
                    }
                }
            }
        }
        if (best_child_good > 0)
        {
            state = best_child_state;
            cur_Good = best_child_good;
        }
        else
            break;
    }
}

int main() //  main instructions
{
    cin >> k;
    cin >> m;
    cin >> t;
    cin >> c;
    n = k * m * t;

    dist = vector<vector<double>>(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    vector<int> state(n), MG_state(n);
    for (int i = 0; i < n; i++)
        state[i] = i + 1;

    long double max_Good;

    max_Good = GoodNess(state);

    AI_solver(state, max_Good, max_Good, MG_state);

    represent_output(MG_state);

    return 0;
}
