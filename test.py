from parser import Parser
from code_container import Code
from transform import *

#4) -----------------------------------------------
# For - While
# Prvo se ucita kod i prosledi parseru
c = Code('./tmp kodovi/4.2.c')
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
c.saveCode('./tmp kodovi/', "while"+c.getFileName())



# While - For 
c = Code('./tmp kodovi/3.2.1.c')
p = Parser(c.getCode())
 
code = p.getWhileLoops()[0]
before_while = code[0]
while_loop = code[1]
after_while = code[2]
 
for_loop = whileToForTransform(while_loop)

c.mergeCode(before_while, for_loop, after_while, 'f1')
c.saveCode('./tmp kodovi/', "for"+c.getFileName())



# For - Goto 
c = Code('./tmp kodovi/4.2.c')
p = Parser(c.getCode())

code = p.getForLoops()[0]
before_for = code[0]
for_loop = code[1]
after_for = code[2]

goto_loop = forToGotoTransform(for_loop, "LOOP")

c.mergeCode(before_for, goto_loop, after_for, 'f1')
c.saveCode('./tmp kodovi/', "goto"+c.getFileName())



# Goto - For 
c = Code('./tmp kodovi/3.4.c')
p = Parser(c.getCode())

code = p.getGotoBlocks()[0]
before_goto = code[0]
goto_loop = code[1]
after_goto = code[2]

for_loop = gotoToForTransform(goto_loop)

c.mergeCode(before_goto, for_loop, after_goto, 'f1')
c.saveCode('./tmp kodovi/', "for"+c.getFileName())



# While - Goto 
c = Code('./tmp kodovi/3.2.1.c')
p = Parser(c.getCode())

code = p.getWhileLoops()[0]
before_while = code[0]
while_loop = code[1]
after_while = code[2]

goto_loop = whileToGotoTransform(while_loop, "LOOP")

c.mergeCode(before_while, goto_loop, after_while, 'f1')
c.saveCode('./tmp kodovi/', "goto"+c.getFileName())



# Goto - While
c = Code('./tmp kodovi/3.4.c')
p = Parser(c.getCode())

code = p.getGotoBlocks()[0]
before_goto = code[0]
goto_loop = code[1]
after_goto = code[2]

while_loop = gotoToWhileTransform(goto_loop)

c.mergeCode(before_goto, while_loop, after_goto, 'f1')
c.saveCode('./tmp kodovi/', "while"+c.getFileName())