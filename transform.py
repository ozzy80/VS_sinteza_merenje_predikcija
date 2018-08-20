import re

def getStatementsInsideCurlyBraces(code):
    start_position = 0
    for character in code:
        start_position += 1
        if character == '{':
            break

    tmp_position = start_position + 1
    end_position = start_position + 1
    for character in code[start_position:]:
        tmp_position += 1
        if character == '}':
            end_position = tmp_position
    
    return code[start_position-1:end_position]

def addStatementInsideBlock(code, statement, on_begin=False):
    current_position = 0

    if on_begin:
        for character in code:
            current_position += 1
            if character == '{':
                code = code[:current_position] + statement + code[current_position:]
                return code
    else:
        tmp_current_position = 0
        for character in code:
            tmp_current_position += 1
            if character == '}':
                current_position = tmp_current_position - 1
    
    code = code[:current_position] + statement + code[current_position:]
    return code   

def getForData(code):
    pattern = re.compile(r'(\w+)\s+.*;\s*\n*\s*for(.*);(.*);(.*){')
    for match in re.finditer(pattern, code):
        variable = match.group(1)
        init = match.group(2).strip()
        condition = match.group(3).strip()
        increment = match.group(4)[:-1].strip()
        statements = getStatementsInsideCurlyBraces(code)
        
        return (variable + " " + init[1:] + ";\n", condition, increment, statements)

def getWhileData(code):
    pattern = re.compile(r'(\w+\s+.*;)\s*\n*\s*while(.*){')
    for match in re.finditer(pattern, code):
        variable = match.group(1)
        condition = match.group(2)
        statements = getStatementsInsideCurlyBraces(code)
        increment = statements.split(';')[-2]
        statements = statements.split(';')[:-2]
        statements = ";".join(statements)
        return (variable, condition, increment, statements + ";\n}\n")

def getGotoData(code):
    pattern = re.compile(r'(.*);\s*\n*\s*if(.*){')
    for match in re.finditer(pattern, code):
        increment = match.group(1).strip()
        condition = match.group(2).strip()
        variable = code.split(';')[0].strip() + ";"
        statements = ";".join(code.split(';')[2:-2]) + ";"
        statements = statements.split('}')[1]

        return (variable, condition, increment, statements)

def devideCondition(condition, number_of_part):
    pattern = re.compile(r'(.*)([<|<=|>|>=])(.*)')
    for match in re.finditer(pattern, condition):
        first_part = match.group(1).strip()
        operator = match.group(2).strip()
        second_part = match.group(3).strip()
        if operator.find('<') != -1:
            return first_part + operator + second_part[:-1] + "/" +  str(number_of_part) + ")"
        else:
            return first_part +  "/" +  str(number_of_part) + operator + second_part   

def formWhileLoop(variable, condition, increment, statements):
    loop = variable
    loop += "while(" + condition + ")"
    statements = addStatementInsideBlock(statements, "\n" + increment + ";\n", on_begin=False)

    return loop + statements

def formForLoop(variable, condition, increment, statements):
    loop = variable + "\n"
    loop += "for(;" + condition + "; " + increment + " )\n"
    statements += "; \n}\n"

    return loop + statements

def formGotoLoop(variable, condition, increment, statements, gotoLabelName):
    loop = variable + "\n"
    loop += gotoLabelName + ":\n"
    loop += "if(!(" + condition + ")){\n"
    loop += "   goto " + gotoLabelName + "END;\n}\n"
    statements += gotoLabelName + "END:\n"
    loop_condition = "if(" + condition + "){\n"
    loop_condition += "   goto " + gotoLabelName + ";\n}\n"

    statements = addStatementInsideBlock(statements, "\n" + increment + ";\n", on_begin=False)
    statements = addStatementInsideBlock(statements, "\n" + loop_condition + ";\n", on_begin=False)

    return loop + statements
 
def forToWhileTransform(code):
    variable, condition, increment, statements = getForData(code)  
    return formWhileLoop(variable, condition, increment, statements)    

def whileToForTransform(code):
    variable, condition, increment, statements = getWhileData(code)
    statements = statements[:-2]
    print(statements)
    return formForLoop(variable, condition, increment, statements)

def forToGotoTransform(code, gotoLabelName):
    variable, condition, increment, statements = getForData(code)
    return formGotoLoop(variable, condition, increment, statements, gotoLabelName)    
      
def gotoToForTransform(code):
    variable, condition, increment, statements = getGotoData(code)
    statements = "{" + statements
    return formForLoop(variable, condition, "", statements)

def whileToGotoTransform(code, gotoLabelName):
    variable, condition, increment, statements = getWhileData(code)
    return formGotoLoop(variable, condition, increment, statements, gotoLabelName)    

def gotoToWhileTransform(code):
    variable, condition, increment, statements = getGotoData(code)
    statements = "{" + statements + "}" 
    return formWhileLoop(variable, condition, "", statements)

def splitAndCombineWhileForLoopTransform(code):
    variable, condition, increment, statements = getWhileData(code)
    condition_1 = devideCondition(condition, 2)

    first_loop = formForLoop(variable, condition_1, increment, statements[:-4])
    second_loop = formWhileLoop("", condition, increment, statements)
    return first_loop + "\n" + second_loop