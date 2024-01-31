import requests
s = 2425357
a = 'https://www.comap math.com/mcm/2024Certs/{}.pdf'.format(str(s))
b = requests.get(a).content

file = 'd:\\test.pdf'
open(file,'wb').write(b)