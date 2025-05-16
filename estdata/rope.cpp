/*
Operación               Complejidad        Descripción
---------------------------------------------------------------
insert(pos, s)          O(log n)           Inserta una subsecuencia en la posición `pos`
erase(pos, len)         O(log n)           Elimina un fragmento de longitud `len` desde `pos`
replace(pos, len, s)    O(log n)           Reemplaza un fragmento por otra subsecuencia
substr(pos, len)        O(log n + len)     Extrae una subsecuencia (subrope) desde `pos`
operator[]              O(log n)           Accede al i-ésimo elemento
+= / append             O(log n)           Concatena eficientemente al final
report(start, end)      O(log n + len)     Similar a substr, útil para debugging o extracción
*/
#include <ext/rope>
using namespace __gnu_cxx;