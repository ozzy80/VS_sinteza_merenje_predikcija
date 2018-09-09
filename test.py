from code_parser import Parser
from code_container import Code
from loop_transform import *
from relationallogical_transform import *
from arithmetic_transform import *
from branch_transform import *
from addfunction_transform import *

#1) -------------------------------------
#addRecursiveFunction
c = Code('./tmp kodovi/1.1.c')
p = Parser(c.getCode())
code = p.getFunctionBlockWithType("function")[0]
before_op = code[0]
op = code[1]
after_op = code[2]
newOp = addRecursiveCall(op)
c.mergeFunctionCode(before_op, newOp, after_op, op)
c.saveCode('./tmp kodovi/', "addRecursive"+c.getFileName())

#addNonRecursiveFunction
c = Code('./tmp kodovi/1.1.c')
p = Parser(c.getCode())
code = p.getFunctionBlockWithType("function")[0]
before_op = code[0]
op = code[1]
after_op = code[2]
newOp = addNonRecursiveCall(op)
c.mergeFunctionCode(before_op, newOp, after_op, op)
c.saveCode('./tmp kodovi/', "addNonRecursive"+c.getFileName())

#3) -----------------------------------------------
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
c = Code('./tmp kodovi/3.20.c')
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
c = Code('./tmp kodovi/3.20.c')
p = Parser(c.getCode())
code = p.getGotoBlocks()[0]
before_goto = code[0]
goto_loop = code[1]
after_goto = code[2]
while_loop = gotoToWhileTransform(goto_loop)
c.mergeCode(before_goto, while_loop, after_goto, 'f1')
c.saveCode('./tmp kodovi/', "while"+c.getFileName())
#razdvajanje jedne petlje na dve i njihovo mesanje pola sa while pola sa for
c = Code('./tmp kodovi/3.2.1.c')
p = Parser(c.getCode())
code = p.getWhileLoops()[0]
before_while = code[0]
while_loop = code[1]
after_while = code[2]
merge_loop = splitAndCombineWhileForLoopTransform(while_loop)
c.mergeCode(before_while, merge_loop, after_while, 'f1')
c.saveCode('./tmp kodovi/', "merge"+c.getFileName())
#4) -----------------------------------------------
# Menjanje mnozenja sa sabiranjem
c = Code('./tmp kodovi/2.1.1.c')
p = Parser(c.getCode())
code = p.getOneLineStatements()[0]
before_statement = code[0]
statement = code[1]
after_statement = code[2]
new_statement = multiplyToSumTransform(statement)
c.mergeCode(before_statement, new_statement, after_statement, 'f2')
c.saveCode('./tmp kodovi/', "sum"+c.getFileName())
# Menjanje deljenje sa sabiranjem
c = Code('./tmp kodovi/2.1.2.c')
p = Parser(c.getCode())
code = p.getOneLineStatements()[0]
before_statement = code[0]
statement = code[1]
after_statement = code[2]
new_statement = devideToSumTransform(statement)
c.mergeCode(before_statement, new_statement, after_statement, 'f2')
c.saveCode('./tmp kodovi/', "devide"+c.getFileName())
# Automatksa provera kljucnih reci koje se nalaze u kodu

#5) -------------------------------------
#lessToGreaterEqual a<b    ->    !(a>=b)
c = Code('./tmp kodovi/5.1.c')
p = Parser(c.getCode())
code = p.getLessOperators()[0]
before_op = code[0]
op = code[1]
after_op = code[2]
newOp = lesserToGreaterEqTransform(op)
c.mergeCode(before_op, newOp, after_op, 'f')
c.saveCode('./tmp kodovi/', "lesserToGreaterEqTransform"+c.getFileName())

#greaterToLesserEqTransform 
c = Code('./tmp kodovi/5.2.c')
p = Parser(c.getCode())
code = p.getGreaterOperators()[0]
before_op = code[0]
op = code[1]
after_op = code[2]
newOp = greaterToLesserEqTransform(op)
c.mergeCode(before_op, newOp, after_op, 'f')
c.saveCode('./tmp kodovi/', "greaterToLesserEqTransform"+c.getFileName())

#lesserEqToGreaterTransform 
c = Code('./tmp kodovi/5.3.c')
p = Parser(c.getCode())
code = p.getLessEqOperators()[0]
before_op = code[0]
op = code[1]
after_op = code[2]
newOp = lesserEqToGreaterTransform(op)
c.mergeCode(before_op, newOp, after_op, 'f')
c.saveCode('./tmp kodovi/', "lesserEqToGreaterTransform"+c.getFileName())

#greaterEqToLesserTransform 
c = Code('./tmp kodovi/5.4.c')
p = Parser(c.getCode())
code = p.getGreaterEqOperators()[0]
before_op = code[0]
op = code[1]
after_op = code[2]
newOp = greaterEqToLesserTransform(op)
c.mergeCode(before_op, newOp, after_op, 'f')
c.saveCode('./tmp kodovi/', "greaterEqToLesserTransform"+c.getFileName())

#eqToNeqTransform 
c = Code('./tmp kodovi/5.5.c')
p = Parser(c.getCode())
code = p.getEqOperators()[0]
before_op = code[0]
op = code[1]
after_op = code[2]
newOp = eqToNeqTransform(op)
c.mergeCode(before_op, newOp, after_op, 'f')
c.saveCode('./tmp kodovi/', "eqToNeqTransform"+c.getFileName())

#neqToEqTransform 
c = Code('./tmp kodovi/5.6.c')
p = Parser(c.getCode())
code = p.getNeqOperators()[0]
before_op = code[0]
op = code[1]
after_op = code[2]
newOp = neqToEqTransform(op)
c.mergeCode(before_op, newOp, after_op, 'f')
c.saveCode('./tmp kodovi/', "neqToEqTransform"+c.getFileName())

#orToAndTransform 
c = Code('./tmp kodovi/5.7.c')
p = Parser(c.getCode())
code = p.getOrOperators()[0]
before_op = code[0]
op = code[1]
after_op = code[2]
newOp = orToAndTransform(op)
c.mergeCode(before_op, newOp, after_op, 'f')
c.saveCode('./tmp kodovi/', "orToAndTransform"+c.getFileName())

#andToOrTransform 
c = Code('./tmp kodovi/5.8.c')
p = Parser(c.getCode())
code = p.getAndOperators()[0]
before_op = code[0]
op = code[1]
after_op = code[2]
newOp = andToOrTransform(op)
c.mergeCode(before_op, newOp, after_op, 'f')
c.saveCode('./tmp kodovi/', "andToOrTransform"+c.getFileName())

#6) -----------------------------------------------
# Inkrementiranje 
c = Code('./tmp kodovi/6.3.c')
p = Parser(c.getCode())
code = p.getIncrementOperators()[0]
before_increment = code[0]
increment = code[1]
after_increment = code[2]
increment_1 = incrementTransform(increment, mode=1)
increment_2 = incrementTransform(increment, mode=0)
c.mergeCode(before_increment, increment_1, after_increment, 'f1')
c.mergeCode(before_increment, increment_2, after_increment, 'f2')
c.saveCode('./tmp kodovi/', "increment1"+c.getFileName())
# Dekrementiranje
c = Code('./tmp kodovi/6.2.c')
p = Parser(c.getCode())
code = p.getDecrementOperators()[0]
before_decrement = code[0]
decrement = code[1]
after_decrement = code[2]
decrement_1 = decrementTransform(increment, mode=1)
decrement_2 = decrementTransform(increment, mode=0)
c.mergeCode(before_decrement, decrement_1, after_decrement, 'f1')
c.mergeCode(before_decrement, decrement_2, after_decrement, 'f2')
c.saveCode('./tmp kodovi/', "decrement1"+c.getFileName())
#7) -----------------------------------------------
# If else
c = Code('./tmp kodovi/7.1.c')
p = Parser(c.getCode())
before_conditional, conditional, after_conditional = p.getIfElse()[0]
transformed_conditional = ifToTernaryTransform(conditional)
c.mergeCode(before_conditional, transformed_conditional, after_conditional, 'f1')
c.saveCode('./tmp kodovi/', "ternary"+c.getFileName())
# Ternary
c = Code('./tmp kodovi/7.3.c')
p = Parser(c.getCode())
before_ternary, ternary, after_ternary = p.getTernaryConditionStatements()[0]
transformed_ternary = ternaryToIfTransform(ternary)
c.mergeCode(before_ternary, transformed_ternary, after_ternary, 'f1')
c.saveCode('./tmp kodovi/', "if"+c.getFileName())
# If else if
c = Code('./tmp kodovi/7.5.c')
p = Parser(c.getCode())
before_conditional, conditional, after_conditional = p.getIfBlocks()[0]
transformed_conditional = ifElseIfToSwitchTransform(conditional)
c.mergeCode(before_conditional, transformed_conditional, after_conditional, 'f1')
c.saveCode('./tmp kodovi/', "switch"+c.getFileName())
# Switch
c = Code('./tmp kodovi/7.7.c')
p = Parser(c.getCode())
before_switch, switch, after_switch = p.getSwitchBlocks()[0]
transformed_switch = switchToIfElseIfTransform(switch)
c.mergeCode(before_switch, transformed_switch, after_switch, 'f1')
c.saveCode('./tmp kodovi/', "if"+c.getFileName())
#8) -----------------------------------------------
# Continue Break 
c = Code('./tmp kodovi/8.1.c')
p = Parser(c.getCode())
before_loop, loop, after_loop = p.getWhileLoops()[0]
transformed_loop = breakContinueToGotoTransform(loop)
c.mergeCode(before_loop, transformed_loop, after_loop, 'f1')
c.saveCode('./tmp kodovi/', "goto"+c.getFileName())


print(p.getKeywordsList())
