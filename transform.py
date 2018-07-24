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

def forToWhileTransform(code):
    pattern = re.compile(r'(\w+)\s+.*;\s*\n*\s*for(.*);(.*);(.*){')
    loop = ""
    for match in re.finditer(pattern, code):
        variable = match.group(1)
        init = match.group(2).strip()
        condition = match.group(3).strip()
        increment = match.group(4)[:-1].strip()
        statements = getStatementsInsideCurlyBraces(code)
        
        loop = variable + " " + init[1:] + ";\n"
        loop += "while(" + condition + ")"
        statements = addStatementInsideBlock(statements, "\n" + increment + ";\n", on_begin=False)

        return loop + statements