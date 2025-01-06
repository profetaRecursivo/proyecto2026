const int N  = 9999700;
vector<int> spf(N + 1);
vector<int> prim;
void sieve()
{
    for (int i = 2; i <= N; ++i)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            prim.push_back(i);
        }
        for (int j = 0; i * prim[j] <= N; ++j)
        {
            spf[i * prim[j]] = prim[j];
            if (prim[j] == spf[i])
            {
                break;
            }
        }
    }
}