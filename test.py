from parser import Parser
from code_container import Code
from transform import *

# Prvo se ucita kod i prosledi parseru
c = Code('/home/ozzy/Desktop/VS_sinteza_merenje_predikcija/tmp kodovi/4.2.c')
p = Parser(c.getCode())

# Zatim se bira koji deo koda zelimo da promenimo
code = p.getForLoops()[0]
before_for = code[0]
for_loop = code[1]
after_for = code[2]

# Zatim se koristi funkcija za menjanje odabranog dela koda
while_loop = forToWhileTransform(for_loop)

# I na kraju se kod spaja sa originalnim kodom i snima u novi fajl
c.mergeCode(before_for, while_loop, after_for, 'f1')
c.saveCode('/home/ozzy/Desktop/', "while"+c.getFileName())
