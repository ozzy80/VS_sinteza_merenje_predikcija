import re
from transform import getStatementsInsideCurlyBraces
from transform import addStatementInsideBlock

def getIfElseData(code):
    pattern = re.compile(r'([{};]\s*)if\((.*)\)(.*);else(.*);')
    for match in re.finditer(pattern, code):
        variable = match.group(1)
        condition = match.group(2).strip()
        consequent = match.group(3).strip()
        alternative = match.group(4).strip()
        
        return (variable, condition, consequent, alternative)

def getTernaryData(code):
    pattern = re.compile(r'([{};]\s*)(.*)\?(.*):(.*);')
    for match in re.finditer(pattern, code):
        variable = match.group(1)
        condition = match.group(2).strip()
        consequent = match.group(3).strip()
        alternative = match.group(4).strip()

        return (variable, condition, consequent, alternative)

def getIfElseIfData(code):
    pattern = re.compile(r'([{};]\s*)if\((\w+)\s*==(.+)\)(.*);else if\(\w+==(.+)\)(.*);else (.*);')
    for match in re.finditer(pattern, code):
        variable = match.group(1)
        condition_variable = match.group(2).strip()
        condition_value1 = match.group(3).strip()
        consequent1 = match.group(4).strip()
        condition_value2 = match.group(5).strip()
        consequent2 = match.group(6).strip()
        alternative = match.group(7).strip()

        return (variable, condition_variable, condition_value1, consequent1, condition_value2, consequent2, alternative)

def getSwitchData(code):
    pattern = re.compile(r'([{};]\s*)switch\((\w+)\)')
    match = pattern.search(code)
    variable = match.group(1)
    control = match.group(2).strip()
    cases = []
    statements = [] 
    pattern = re.compile(r'case ([0-9]+):(.*);\s*break;')
    for match in re.finditer(pattern, code):
        cases.append(match.group(1))
        statements.append(match.group(2).strip())
    pattern = re.compile(r'default:(.*);')
    match = pattern.search(code)
    
    return (variable, control, cases, statements)

        

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
    statement += alternative if alternative else ""
    return statement + ";" 

def formSwitch (variable, control, cases, statements, default):
    switchCode = variable + "\nswitch(" + control + "){\n" 
    casesCode = ""
    for case, statement in zip(cases, statements):
       casesCode += "case " + case + ": " + statement + "; " + "break;\n"
    defaultCode = "default: " + default	+ ";\n" if default else ""
    return switch +  casesCode + defaultCode + "}\n" 


def ifToTernaryTransform(code):
    variable, condition, consequent, alternative = getIfElseData(code)
    return formTernary(variable, condition, consequent, alternative)

def ternaryToIfTransform(code):
    variable, condition, consequent, alternative = getTernaryData(code)
    return formIfElse(variable, condition, consequent, alternative)
