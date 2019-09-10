import sys
import os
from code_parser import Parser
from code_container import Code
from loop_transform import *
from relational_logical_transform import *
from arithmetic_transform import *
from branch_transform import *
from add_function_transform import *
from global_data import *


iteration_count=1 
code_directory_path = './test code/'
new_code_save_path = './function_equivalent_code/'
directory = os.fsencode(code_directory_path)

for iter in range(iteration_count):
    clearPrevious=False
    if iter>0:
        code_directory_path=new_code_save_path
        directory= os.fsencode(code_directory_path)
        clearPrevious=True

    for file in os.listdir(directory):
        filename = code_directory_path + os.fsdecode(file)
        print("--------")
        print(filename)
        if filename.find('uncrustify')>=0:
            continue
        c = Code(filename)  
        p = Parser(c.getCode())
        prefix = 0

        cleanCode=None
        try:
            if clearPrevious:
                before_fun, fun, after_fun = p.getFunctionBlockWithType("function")[0]
                cleanCode=before_fun+after_fun
                cleanCode=cleanCode.replace('f1','function',1)

            if cleanCode!=None:
                c.setCode(cleanCode)
                p = Parser(c.getCode())
        except:
            f = open("errors.txt", "a")
            f.write(filename+"  Creating equivalent function failed at:"+keyword+"\n")
            f.close()
        
        for keyword in p.getKeywordsList():
            try:
                print(keyword)
                if cleanCode==None:
                    c = Code(filename)
                else:
                    c.setCode(cleanCode)
                p = Parser(c.getCode())

                if keyword == CodeKeyword.FOR_WHILE_LOOP.value:
                    before, statement, after = p.getForLoops()[0]
                    res = forToWhileTransform(statement)
                elif keyword == CodeKeyword.FOR_GOTO_LOOP.value:
                    before, statement, after = p.getForLoops()[0]
                    res = forToGotoTransform(statement, 'LOOP')
                elif keyword == CodeKeyword.WHILE_FOR_LOOP.value:
                    before, loop, after = p.getWhileLoops()[0]
                    res = whileToForTransform(loop)
                elif keyword == CodeKeyword.WHILE_GOTO_LOOP.value:
                    before, loop, after = p.getWhileLoops()[0]
                    res = whileToGotoTransform(loop, 'LOOP')
                elif keyword == CodeKeyword.GOTO_FOR_LOOP.value:
                    before, block, after = p.getGotoBlocks()[0]
                    res = gotoToForTransform(block)
                elif keyword == CodeKeyword.GOTO_WHILE_LOOP.value:
                    before, block, after = p.getGotoBlocks()[0]
                    res = gotoToWhileTransform(block)
                elif keyword == CodeKeyword.MULTIPLICATION_OPERATOR.value:
                    before, statement, after = p.getOneLineStatements()[0]
                    res = multiplyToSumTransform(statement)
                elif keyword == CodeKeyword.BITLEFT_OPERATOR.value:
                    before, statement, after = p.getOneLineStatements()[0]
                    res = bitLeftToForTransform(statement)
                elif keyword == CodeKeyword.DIVIDE_OPERATOR.value:
                    before, statement, after = p.getOneLineStatements()[0]
                    res = devideToSumTransform(statement)
                elif keyword == CodeKeyword.LESS_OPERATOR.value:
                    before, statement, after = p.getLessOperators()[0]
                    res = lesserToGreaterEqTransform(statement)
                elif keyword == CodeKeyword.LESS_EQ_OPERATOR.value:
                    before, statement, after = p.getLessEqOperators()[0]
                    res = lesserEqToGreaterTransform(statement)
                elif keyword == CodeKeyword.GREATHER_OPERATOR.value:
                    before, statement, after = p.getGreaterOperators()[0]
                    res = greaterToLesserEqTransform(statement)
                elif keyword == CodeKeyword.GREATHER_EQ_OPERATOR.value:
                    before, statement, after = p.getGreaterEqOperators()[0]
                    res = greaterEqToLesserTransform(statement)
                elif keyword == CodeKeyword.EQUAL_OPERATOR.value:
                    before, statement, after = p.getEqOperators()[0]
                    res = eqToNeqTransform(statement)
                elif keyword == CodeKeyword.NOT_EQUAL_OPERATOR.value:
                    before, statement, after = p.getNeqOperators()[0]
                    res = neqToEqTransform(statement)
                elif keyword == CodeKeyword.AND_OPERATOR.value:
                    before, statement, after = p.getAndOperators()[0]
                    res = andToOrTransform(statement)
                elif keyword == CodeKeyword.OR_OPERATOR.value:
                    before, statement, after = p.getOrOperators()[0]
                    res = orToAndTransform(statement)
                elif keyword == CodeKeyword.DECREMENT_OPERATOR.value:
                    before, statement, after = p.getDecrementOperators()[0]
                    res = decrementTransform(statement, 1)
                elif keyword == CodeKeyword.INCREMENT_OPERATOR.value:
                    before, statement, after = p.getIncrementOperators()[0]
                    res = incrementTransform(statement, 1)
                elif keyword == CodeKeyword.IF_STATEMENT.value:
                    before, statement, after = p.getIfBlocks()[0]
                    res = ifElseIfToSwitchTransform(statement)
                    if not res:
                        continue
                elif keyword == CodeKeyword.TERNAR_STATEMENT.value:
                    before, statement, after = p.getTernaryConditionStatements()[0]
                    res = ternaryToIfTransform(statement)
                elif keyword == CodeKeyword.SWITCH_STATEMENT.value:
                    before, block, after = p.getSwitchBlocks()[0]
                    res = switchToIfElseIfTransform(block)
                elif keyword == CodeKeyword.SIMPLE_IF_STATEMENT.value:
                    before, statement, after = p.getIfElse()[0]
                    res = ifToTernaryTransform(statement)
                elif keyword == CodeKeyword.CONT_BREAK_FOR_STATEMENT.value:
                    before, statement, after = p.getForLoops()[0]
                    res = breakContinueToGotoTransform(statement)
                elif keyword == CodeKeyword.CONT_BREAK_WHILE_STATEMENT.value:
                    before, statement, after = p.getWhileLoops()[0]
                    res = breakContinueToGotoTransform(statement)
                elif keyword == CodeKeyword.DECREMENT_LOOP_OPERATOR.value:
                    before, statement, after = p.getDecrementOperators()[0]
                    res = decrementTransform(statement, 2)
                elif keyword == CodeKeyword.INCREMENT_LOOP_OPERATOR.value:
                    before, statement, after = p.getIncrementOperators()[0]
                    res = incrementTransform(statement, 2)

                c.mergeCode(before, res, after, 'f1')
                c.saveCode(new_code_save_path, str(prefix) + '_' + c.getFileName())
                prefix += 1
            except:
                f = open("errors.txt", "a")
                f.write(filename+"  Creating equivalent function failed at:"+keyword+"\n")
                f.close()
            

        try:
            c = Code(filename)  
            p = Parser(c.getCode())

            if cleanCode!=None:
                c.setCode(cleanCode)
                p = Parser(c.getCode())
            before_fun, fun, after_fun = p.getFunctionBlockWithType("function")[0]
            newOp = addRecursiveCall(fun)
            c.mergeFunctionCode(before_fun, newOp, after_fun, fun)
            c.saveCode(new_code_save_path, str(prefix) + '_' + c.getFileName())

            c = Code(filename)  
            p = Parser(c.getCode())
            if cleanCode!=None:
                c.setCode(cleanCode)
                p = Parser(c.getCode())
            before_fun, fun, after_fun = p.getFunctionBlockWithType("function")[0]
            newOp = addNonRecursiveCall(fun)
            c.mergeFunctionCode(before_fun, newOp, after_fun, fun)
            c.saveCode(new_code_save_path, str(prefix+1) + '_' + c.getFileName())
        except:
                f = open("errors.txt", "a")
                f.write(filename+"  Creating equivalent function failed at second part (adding recursion, or non recursion)\n")
                f.close()



print("Done")