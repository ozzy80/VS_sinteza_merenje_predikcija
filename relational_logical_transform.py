def lesserToGreaterEqTransform(code):
    opPosition = code.find('<')
    leftSide= code[:opPosition]
    rightSide = code[opPosition+1:]
    return "!("+leftSide+">="+rightSide+")"


def greaterToLesserEqTransform(code):
    opPosition = code.find('>')
    leftSide= code[:opPosition]
    rightSide = code[opPosition+1:]
    return "!("+leftSide+"<="+rightSide+")"

def lesserEqToGreaterTransform(code):
    opPosition = code.find('<=')
    leftSide= code[:opPosition]
    rightSide = code[opPosition+2:]
    return "!("+leftSide+">"+rightSide+")"

def greaterEqToLesserTransform(code):
    opPosition = code.find('>=')
    leftSide= code[:opPosition]
    rightSide = code[opPosition+2:]
    return "!("+leftSide+"<"+rightSide+")"

def eqToNeqTransform(code):
    opPosition = code.find('==')
    leftSide= code[:opPosition]
    rightSide = code[opPosition+2:]
    return "!("+leftSide+"!="+rightSide+")"

def neqToEqTransform(code):
    opPosition = code.find('!=')
    leftSide= code[:opPosition]
    rightSide = code[opPosition+2:]
    return "!("+leftSide+"=="+rightSide+")"

def orToAndTransform(code):
    opPosition = code.find('||')
    leftSide= code[:opPosition]
    rightSide = code[opPosition+2:]
    return "!(!("+leftSide+")&&!("+rightSide+"))"

def andToOrTransform(code):
    opPosition = code.find('&&')
    leftSide= code[:opPosition]
    rightSide = code[opPosition+2:]
    return "!(!("+leftSide+")||!("+rightSide+"))"

