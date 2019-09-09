import re
from transform import getStatementsInsideCurlyBraces
from transform import addStatementInsideBlock

def getIfElseData(code):
    pattern = re.compile(r'([{};]?\s*)if\s*(.*)[\n]*(.*);\s*else\s*(.*);(\n(.*);)*')
    for match in re.finditer(pattern, code):
        variable = match.group(1)
        condition = match.group(2).strip()
        consequent = match.group(3).strip()
        alternative = match.group(4).strip()
        if match.group(5):
            restPart = match.group(5).strip()
        else:
            restPart = ""
        return (variable, condition, consequent, alternative, restPart)

def getTernaryData(code):
    pattern = re.compile(r'([{};]?\s*)(.*)\?(.*):(.*);')
    for match in re.finditer(pattern, code):
        variable = match.group(1)
        condition = match.group(2).strip()
        consequent = match.group(3).strip()
        alternative = match.group(4).strip()

        return (variable, condition, consequent, alternative)

def getIfElseIfData(code):
    pattern = re.compile(r'([{};]?\s*)' \
                         r'if \((\w+) == (.+)\){\n' \
                         r'\s*(.*);\n\s*}\n' \
                         r'\s*else if \(\w+\s*==\s*(.+)\s*\)\s*{\n' \
                         r'\s*(.*);\n\s*}\n' \
                         r'\s*else{\n\s*(.*);\s*\n\s*}'
                        )
    for match in re.finditer(pattern, code):
        variable = match.group(1)
        condition_variable = match.group(2).strip()
        condition_value1 = match.group(3).strip()
        consequent1 = match.group(4).strip()
        condition_value2 = match.group(5).strip()
        consequent2 = match.group(6).strip()
        alternative = match.group(7).strip()
        return (variable, condition_variable, condition_value1, consequent1, condition_value2, consequent2, alternative)
    return None

def getSwitchData(code):
    pattern = re.compile(r'switch\((\w+)\)')
    match = pattern.search(code)
    control = match.group(1).strip()
    cases = []
    statements = [] 
    pattern = re.compile(r'case ([0-9]+):(.*);\s*break;')
    for match in re.finditer(pattern, code):
        cases.append(match.group(1))
        statements.append(match.group(2).strip())
    pattern = re.compile(r'default:(.*);')
    match = pattern.search(code)
    if match:
        default = match.group(1)
    else:
        default = None
    
    return (control, cases, statements, default)

        

def formIfElse(variable, condition, consequent, alternative):
    return variable + "\nif (" + condition + ")\n   " + consequent + ";\nelse\n   " \
            + alternative + ";" 

def formTernary(variable, condition, consequent, alternative):
    return variable + "\n(" + condition + ") ? (" + consequent + ") : (" \
            + alternative + ");" 

def formIfElseIf(variable, conditions, consequents, alternative):
    statement = ""
    for condition, consequent in zip(conditions, consequents):
       statement += "if(" + condition + "){\n   " + consequent + ";\n}\nelse "
    statement += "{\n   " + alternative + ";\n}\n" if alternative else ""
    return statement + ";" 

def formSwitch (variable, control, cases, statements, default):
    switchCode = variable + "\nswitch(" + control + "){\n" 
    casesCode = ""
    for case, statement in zip(cases, statements):
       casesCode += "case " + case + ": " + statement + "; " + "break;\n"
    defaultCode = "default: " + default	+ ";\n" if default else ""
    return switchCode +  casesCode + defaultCode + "}\n" 


def ifToTernaryTransform(code):
    variable, condition, consequent, alternative, restPart = getIfElseData(code)
    return formTernary(variable, condition, consequent, alternative) + restPart

def ternaryToIfTransform(code):
    variable, condition, consequent, alternative = getTernaryData(code)
    return formIfElse(variable, condition, consequent, alternative)

def ifElseIfToSwitchTransform(code):
    res = getIfElseIfData(code)
    if not res:
        return None
    else:
        variable, condition_variable, condition_value1, consequent1, condition_value2, consequent2, alternative = getIfElseIfData(code)
        return formSwitch(variable, condition_variable, [condition_value1, condition_value2], [consequent1, consequent2], alternative)
    
def switchToIfElseIfTransform(code):
    control, cases, statements, default = getSwitchData(code)
    conditions = []
    for case in cases:
        conditions.append(control + " == " + case)
    return formIfElseIf("", conditions, statements, default)

def breakContinueToGotoTransform(code):
    code = re.sub("continue", "goto LOOP", code)
    code = re.sub("break", "goto LOOPEND", code)
    beforeSemicolon, afterSemicolon = code.split(';', 1)
    return beforeSemicolon + ";\n" + "LOOP:\n" + afterSemicolon + "LOOPEND:\n"
