import hashlib
import string

res ='C6 3A E6 DD 4F C9 F9 DD A6 69 70 E8 27 D1 3F 7C 73 FE 84 1C'
res = res.replace(' ','')
res = res.lower()


alphabet = list(string.ascii_lowercase + string.ascii_uppercase)

for a in alphabet: 
    sha1 = hashlib.sha1(a.encode()).hexdigest()
    if sha1 == res:
        print("The result is: " + a)
        break

