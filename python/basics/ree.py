import re
#caracteres que necesitan un \
# . ^ $ * + ? { } [ ] \ | ( )
a = input()
b = re.sub(r'[\[\]abc123]', '?', a)
print(b)