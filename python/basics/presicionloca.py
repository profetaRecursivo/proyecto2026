from decimal import Decimal, getcontext

getcontext().prec = 50  # precisión global
x = Decimal("1") / Decimal("7")
print(x)  # imprime con 50 cifras de precisión
print(float(x))