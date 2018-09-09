from parser import Parser
from code_container import Code
from loop_transform import *
#from arithmetic_transform import *
#
##3) -----------------------------------------------
## For - While
## Prvo se ucita kod i prosledi parseru
#c = Code('./tmp kodovi/4.2.c')
#p = Parser(c.getCode())
#
## Zatim se bira koji deo koda zelimo da promenimo
#code = p.getForLoops()[0]
#before_for = code[0]
#for_loop = code[1]
#after_for = code[2]
#
## Zatim se koristi funkcija za menjanje odabranog dela koda
#while_loop = forToWhileTransform(for_loop)
#
## I na kraju se kod spaja sa originalnim kodom i snima u novi fajl
#c.mergeCode(before_for, while_loop, after_for, 'f1')
#c.saveCode('./tmp kodovi/', "while"+c.getFileName())
#
#
#
## While - For 
#c = Code('./tmp kodovi/3.2.1.c')
#p = Parser(c.getCode())
# 
#code = p.getWhileLoops()[0]
#before_while = code[0]
#while_loop = code[1]
#after_while = code[2]
# 
#for_loop = whileToForTransform(while_loop)
#
#c.mergeCode(before_while, for_loop, after_while, 'f1')
#c.saveCode('./tmp kodovi/', "for"+c.getFileName())
#
#
#
#


## For - Goto 
#c = Code('./tmp kodovi/4.2.c')
#p = Parser(c.getCode())
#
#code = p.getForLoops()[0]
#before_for = code[0]
#for_loop = code[1]
#after_for = code[2]
#
#goto_loop = forToGotoTransform(for_loop, "LOOP")
#
#c.mergeCode(before_for, goto_loop, after_for, 'f1')
#c.saveCode('./tmp kodovi/', "goto"+c.getFileName())
#
#
#
## Goto - For 
#c = Code('./tmp kodovi/3.4.c')
#p = Parser(c.getCode())
#
#code = p.getGotoBlocks()[0]
#before_goto = code[0]
#goto_loop = code[1]
#after_goto = code[2]
#
#for_loop = gotoToForTransform(goto_loop)
#
#c.mergeCode(before_goto, for_loop, after_goto, 'f1')
#c.saveCode('./tmp kodovi/', "for"+c.getFileName())
#
#
#
## While - Goto 
#c = Code('./tmp kodovi/3.2.1.c')
#p = Parser(c.getCode())
#
#code = p.getWhileLoops()[0]
#before_while = code[0]
#while_loop = code[1]
#after_while = code[2]
#
#goto_loop = whileToGotoTransform(while_loop, "LOOP")
#
#c.mergeCode(before_while, goto_loop, after_while, 'f1')
#c.saveCode('./tmp kodovi/', "goto"+c.getFileName())
#
#
#
## Goto - While
#c = Code('./tmp kodovi/3.4.c')
#p = Parser(c.getCode())
#
#code = p.getGotoBlocks()[0]
#before_goto = code[0]
#goto_loop = code[1]
#after_goto = code[2]
#
#while_loop = gotoToWhileTransform(goto_loop)
#
#c.mergeCode(before_goto, while_loop, after_goto, 'f1')
#c.saveCode('./tmp kodovi/', "while"+c.getFileName())
#
#
#
##razdvajanje jedne petlje na dve i njihovo mesanje pola sa while pola sa for
#c = Code('./tmp kodovi/3.2.1.c')
#p = Parser(c.getCode())
#
#code = p.getWhileLoops()[0]
#before_while = code[0]
#while_loop = code[1]
#after_while = code[2]
#
#merge_loop = splitAndCombineWhileForLoopTransform(while_loop)
#
#c.mergeCode(before_while, merge_loop, after_while, 'f1')
#c.saveCode('./tmp kodovi/', "merge"+c.getFileName())
#
#
#
##6) -----------------------------------------------
## Inkrementiranje 
#c = Code('./tmp kodovi/5.2.c')
#p = Parser(c.getCode())
#
#code = p.getIncrementOperators()[0]
#before_increment = code[0]
#increment = code[1]
#after_increment = code[2]
#
#increment_1 = incrementTransform(increment, mode=1)
#increment_2 = incrementTransform(increment, mode=0)
#
#c.mergeCode(before_increment, increment_1, after_increment, 'f1')
#c.mergeCode(before_increment, increment_2, after_increment, 'f2')
#c.saveCode('./tmp kodovi/', "increment1"+c.getFileName())
#
#
## Dekrementiranje
#c = Code('./tmp kodovi/5.2.c')
#p = Parser(c.getCode())
#
#code = p.getDecrementOperators()[0]
#before_decrement = code[0]
#decrement = code[1]
#after_decrement = code[2]
#
#decrement_1 = decrementTransform(increment, mode=1)
#decrement_2 = decrementTransform(increment, mode=0)
#
#c.mergeCode(before_decrement, decrement_1, after_decrement, 'f1')
#c.mergeCode(before_decrement, decrement_2, after_decrement, 'f2')
#c.saveCode('./tmp kodovi/', "decrement1"+c.getFileName())
#
#
##4) -----------------------------------------------
## Menjanje mnozenja sa sabiranjem
#c = Code('./tmp kodovi/2.1.1.c')
#p = Parser(c.getCode())
#
#code = p.getOneLineStatements()[0]
#before_statement = code[0]
#statement = code[1]
#after_statement = code[2]
#
#new_statement = multiplyToSumTransform(statement)
#
#c.mergeCode(before_statement, new_statement, after_statement, 'f2')
#c.saveCode('./tmp kodovi/', "sum"+c.getFileName())
#
#
## Menjanje deljenje sa sabiranjem
#c = Code('./tmp kodovi/2.1.2.c')
#p = Parser(c.getCode())
#
#code = p.getOneLineStatements()[0]
#before_statement = code[0]
#statement = code[1]
#after_statement = code[2]
#
#new_statement = devideToSumTransform(statement)
#
#c.mergeCode(before_statement, new_statement, after_statement, 'f2')
#c.saveCode('./tmp kodovi/', "devide"+c.getFileName())
#
#
#
#
#
#
## Automatksa provera kljucnih reci koje se nalaze u kodu
#print(p.getKeywordsList())
#