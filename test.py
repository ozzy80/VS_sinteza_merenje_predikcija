import os
from code_parser import Parser
from code_container import Code
from loop_transform import *
from relationallogical_transform import *
from arithmetic_transform import *
from branch_transform import *
from addfunction_transform import *


directory_path = './tmp kodovi/'
directory = os.fsencode(directory_path)

for file in os.listdir(directory):
    filename = directory_path + os.fsdecode(file)
    print("--------")
    print(filename)
    c = Code(filename)  
    p = Parser(c.getCode())
    prefix = 0
    for keyword in p.getKeywordsList():
        print(keyword)
        c = Code(filename)  
        p = Parser(c.getCode())
        if   keyword == 'multiple functions':
            continue
        elif keyword == 'for-while loop':
            before, statement, after = p.getForLoops()[0]
            res = forToWhileTransform(statement)
        elif keyword == 'for-goto loop':
            before, statement, after = p.getForLoops()[0]
            res = forToGotoTransform(statement, 'LOOP')
        elif keyword == 'while-for loop':
            before, loop, after = p.getWhileLoops()[0]
            res = whileToForTransform(loop)
        elif keyword == 'while-goto loop':
            before, loop, after = p.getWhileLoops()[0]
            res = whileToGotoTransform(loop, 'LOOP')
        elif keyword == 'goto-for loop':
            before, block, after = p.getGotoBlocks()[0]
            res = gotoToForTransform(block)
        elif keyword == 'goto-while loop':
            before, block, after = p.getGotoBlocks()[0]
            res = gotoToWhileTransform(block)
        elif keyword == 'multiplication operator':
            before, statement, after = p.getOneLineStatements()[0]
            res = multiplyToSumTransform(statement)
        elif keyword == 'divide operator':
            before, statement, after = p.getOneLineStatements()[0]
            res = devideToSumTransform(statement)
        elif keyword == 'less operator':
            before, statement, after = p.getLessOperators()[0]
            res = lesserToGreaterEqTransform(statement)
        elif keyword == 'lessEq operator':
            before, statement, after = p.getLessEqOperators()[0]
            res = lesserEqToGreaterTransform(statement)
        elif keyword == 'greater operator':
            before, statement, after = p.getGreaterOperators()[0]
            res = greaterToLesserEqTransform(statement)
        elif keyword == 'greaterEq operator':
            before, statement, after = p.getGreaterEqOperators()[0]
            res = greaterEqToLesserTransform(statement)
        elif keyword == 'eq operator':
            before, statement, after = p.getEqOperators()[0]
            res = eqToNeqTransform(statement)
        elif keyword == 'neq operator':
            before, statement, after = p.getNeqOperators()[0]
            res = neqToEqTransform(statement)
        elif keyword == 'and operator':
            before, statement, after = p.getAndOperators()[0]
            res = andToOrTransform(statement)
        elif keyword == 'or operator':
            before, statement, after = p.getOrOperators()[0]
            res = orToAndTransform(statement)
        elif keyword == 'decrement operator':
            before, statement, after = p.getDecrementOperators()[0]
            res = decrementTransform(statement, 1)
        elif keyword == 'increment operator':
            before, statement, after = p.getIncrementOperators()[0]
            res = incrementTransform(statement, 1)
        elif keyword == 'if statement':
            before, statement, after = p.getIfBlocks()[0]
            res = ifElseIfToSwitchTransform(statement)
            if not res:
               continue
        elif keyword == '? statement':
            before, statement, after = p.getTernaryConditionStatements()[0]
            res = ternaryToIfTransform(statement)
        elif keyword == 'switch statement':
            before, block, after = p.getSwitchBlocks()[0]
            res = switchToIfElseIfTransform(block)
        elif keyword == 'simple if else statement':
            before, statement, after = p.getIfElse()[0]
            res = ifToTernaryTransform(statement)
        elif keyword == 'continue-break for statement':
            before, statement, after = p.getForLoops()[0]
            res = breakContinueToGotoTransform(statement)
        elif keyword == 'continue-break while statement':
            before, statement, after = p.getWhileLoops()[0]
            res = breakContinueToGotoTransform(statement)

        c.mergeCode(before, res, after, 'f1')
        c.saveCode('./transformed/', str(prefix) + 'new' + c.getFileName())
        prefix += 1

    c = Code(filename)  
    p = Parser(c.getCode())
    before_fun, fun, after_fun = p.getFunctionBlockWithType("function")[0]
    newOp = addRecursiveCall(fun)
    c.mergeFunctionCode(before_fun, newOp, after_fun, fun)
    c.saveCode('./transformed/', str(prefix) + 'new' + c.getFileName())

    c = Code(filename)  
    p = Parser(c.getCode())
    before_fun, fun, after_fun = p.getFunctionBlockWithType("function")[0]
    newOp = addNonRecursiveCall(fun)
    c.mergeFunctionCode(before_fun, newOp, after_fun, fun)
    c.saveCode('./transformed/', str(prefix) + 'new' + c.getFileName())

print("Done")