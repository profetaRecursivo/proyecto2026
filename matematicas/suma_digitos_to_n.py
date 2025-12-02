def suma(n):
    if n <= 9:
        return n * (n + 1) // 2
    s = str(n)
    d = len(s)
    p = 10 ** (d - 1)
    msd = n // p
    r = n % p
    S_p_1 = 45 * (d - 1) * (10 ** (d - 2))
    return msd * S_p_1 + (msd * (msd - 1) // 2) * p + msd * (r + 1) +suma(r)