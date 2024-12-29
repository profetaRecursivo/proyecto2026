unsigned int fgcd(unsigned int u, unsigned int v) {
  int shift, uz, vz;
  if (u == 0) return v;
  if (v == 0) return u;
  uz = __builtin_ctzll(u);
  vz = __builtin_ctzll(v);
  shift = uz > vz ? vz : uz;
  u >>= uz;
  do {
   v >>= vz;
   int diff = v;
   diff -= u;
   vz = __builtin_ctzll(diff);
   if (diff == 0) break;
   if (v < u) u = v;
   v = abs(diff);
  } while (1);
  return u << shift;
}