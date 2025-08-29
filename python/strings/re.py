import re
#split
texto = "uno,dos;tres|cuatro"
partes = re.split("[,;|]", texto)
print(partes)   # ['uno', 'dos', 'tres', 'cuatro']
#----------------------------------------------
texto = "Mi número es 123-456-789"
# Reemplazar todos los dígitos por 'X'
nuevo = re.sub(r"\d", "X", texto)
print(nuevo)#no  es modificacion inplace
