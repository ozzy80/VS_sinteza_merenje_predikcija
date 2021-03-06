import re
from global_data import *

class Parser:
    def __init__(self, code):
        self.code = code

    def curlyBracesPairing(self, start_position):
        counter = 0
        end_position = start_position
        for character in self.code[start_position:]:
            end_position += 1
            if character == '{':
                counter += 1
            elif character == '}':
                counter -= 1
                if counter == 0:
                    return end_position + 1
        return -1

    def getIfBlocks(self):
        start_position = 0
        end_position = 0
        pattern = re.compile(r'[^else][\s+]if.*{')

        code_array = []
        for match in re.finditer(pattern, self.code):
            start_position = match.span()[0]
            end_position = self.curlyBracesPairing(match.span()[1]-1)
            end_position = self.lastPositionOfElseStatements(end_position)
            end_position = self.lastPositionOfElseStatements(end_position, False)

            code_before_if = self.code[:start_position]
            if_statement_code = self.code[start_position:end_position]
            code_after_if = self.code[end_position:]
            code_array.append([code_before_if, if_statement_code, code_after_if])

        return code_array

    def getElseStatements(self, start_position, search_else_if):
        end_position = start_position
        for character in self.code[start_position:]:
            end_position += 1
            if character != ' ' and character != '\n':
                if character != 'e':
                    return start_position
                elif search_else_if and self.code[end_position-1:].find('else if') != 1:
                    break
                elif not search_else_if and self.code[end_position-1:].find('else') != 1:
                    break
  
        return self.curlyBracesPairing(end_position)

    def lastPositionOfElseStatements(self, end_position, search_else_if=True):
        while True:
            new_end_position = self.getElseStatements(end_position, search_else_if)
            if new_end_position == end_position:
                return end_position
            end_position = new_end_position

    def getIfElse(self):
        pattern = re.compile(r'[{};]\s*if\s+[^{]*;\s+else\s+[^{]*;')
        split_code = self.splitCodeUsingRegex(pattern, left_padding = 1, do_braces_pairing=False) 
        return split_code
    
    def splitCodeUsingRegex(self, pattern, left_padding = 0, do_braces_pairing=True):
        start_position = 0
        end_position = 0
        code_array = []
        for match in re.finditer(pattern, self.code):
            start_position = match.span()[0] + left_padding
            if do_braces_pairing:
                end_position = self.curlyBracesPairing(start_position)
            else:
                end_position = match.span()[1]

            code_before_stm = self.code[:start_position]
            stm_code = self.code[start_position:end_position]
            code_after_stm = self.code[end_position:]
            code_array.append([code_before_stm, stm_code, code_after_stm])

        return code_array

    def getTernaryConditionStatements(self):
        pattern = re.compile(r';[\n*\s*]+.+\?.*;')
        split_code = self.splitCodeUsingRegex(pattern, left_padding=1, do_braces_pairing=False)
        return split_code

    def getOneLineStatements(self):
        pattern = re.compile(r';\n*.+[*|\+|/|\-|<<]+.*;')
        split_code = self.splitCodeUsingRegex(pattern, left_padding=1, do_braces_pairing=False)
        return split_code

    def getFunctionBlock(self, function_name):
        pattern = re.compile(function_name)
        split_code = self.splitCodeUsingRegex(pattern)
        return split_code

    def getFunctionBlockWithType(self, function_name):
        pattern = re.compile(r'((double)|(float)|(int)|(short)|(long)|(void)|(char))\s+'+function_name)
        split_code = self.splitCodeUsingRegex(pattern)
        return split_code

    def getAllFunctionName(self):
        pattern = re.compile(r'[double|float|int|short|long|void|char]\s+([\w|\d]+)(.*){')
        names = []
        for match in re.finditer(pattern, self.code):
            function_name = match.group(1).strip()
            names.append(function_name)

        return names

    def getForLoops(self):
        pattern = re.compile(r'\n*.+;\s*for(.*){')
        split_code = self.splitCodeUsingRegex(pattern, left_padding=1)
        return split_code

    def getWhileLoops(self):
        pattern = re.compile(r'\n*.+;\s*while(.*){')
        split_code = self.splitCodeUsingRegex(pattern, left_padding=1)
        return split_code

    def getDoWhileLoops(self):
        start_position = 0
        end_position = 0
        pattern = re.compile(r'\n*.+;\s*do{')

        code_array = []
        for match in re.finditer(pattern, self.code):
            start_position = match.span()[0] + 1
            end_position = self.curlyBracesPairing(start_position)

            new_end_position = end_position
            for character in self.code[new_end_position:]:
                end_position += 1
                if character == ';':
                    break

            code_before_do = self.code[:start_position]
            do_statement_code = self.code[start_position:end_position]
            code_after_do = self.code[end_position:]
            code_array.append([code_before_do, do_statement_code, code_after_do])

        return code_array

    def getGotoBlocks(self):
        start_position = 0
        end_position = 0
        pattern = re.compile(r'goto (.*);\s*}\s*\n*.*:')

        code_array = []
        for match in re.finditer(pattern, self.code):
            end_position = match.span()[1]
            label = match.group(1)
            pattern_label = re.compile('\n*.+;\s*' + label)
            for match in re.finditer(pattern_label, self.code):
                start_position = match.span()[0]

                code_before_go = self.code[:start_position]
                go_statement_code = self.code[start_position:end_position]
                code_after_go = self.code[end_position:]

                code_array.append([code_before_go, go_statement_code, code_after_go])

        return code_array

    def getDecrementOperators(self):
        pattern = re.compile(r'\s?.*\-\-')
        split_code = self.splitCodeUsingRegex(pattern, do_braces_pairing=False)
        return split_code

    def getIncrementOperators(self):
        pattern = re.compile(r'\s?.*\+\+')
        split_code = self.splitCodeUsingRegex(pattern, do_braces_pairing=False)
        return split_code

    def getLessOperators(self):
        pattern = re.compile(r'(?<=[(])\s*(\w+(\w|\d)*)\s*<(?!=)\s*(\w+(\w|\d)*)')
        split_code = self.splitCodeUsingRegex(pattern, do_braces_pairing=False)
        return split_code

    def getLessEqOperators(self):
        pattern = re.compile(r'(?<=[(])\s*(\w+(\w|\d)*)\s*<=\s*(\w+(\w|\d)*)')
        split_code = self.splitCodeUsingRegex(pattern, do_braces_pairing=False)
        return split_code

    def getGreaterOperators(self):
        pattern = re.compile(r'(?<=[(])\s*(\w+(\w|\d)*)\s*>(?!=)\s*(\w+(\w|\d)*)')
        split_code = self.splitCodeUsingRegex(pattern, do_braces_pairing=False)
        return split_code

    def getGreaterEqOperators(self):
        pattern = re.compile(r'(?<=[(])\s*(\w+(\w|\d)*)\s*>=\s*(\w+(\w|\d)*)')
        split_code = self.splitCodeUsingRegex(pattern, do_braces_pairing=False)
        return split_code
        
    def getEqOperators(self):
        pattern = re.compile(r'(?<=[(])\s*(\w+(\w|\d)*)\s*==\s*(\w+(\w|\d)*)')
        split_code = self.splitCodeUsingRegex(pattern, do_braces_pairing=False)
        return split_code

    def getNeqOperators(self):
        pattern = re.compile(r'(?<=[(])\s*(\w+(\w|\d)*)\s*!=\s*(\w+(\w|\d)*)')
        split_code = self.splitCodeUsingRegex(pattern, do_braces_pairing=False)
        return split_code

    def getAndOperators(self):
        pattern = re.compile(r'(?<=[(])\s*(\w+(\w|\d)*)\s*&&\s*(\w+(\w|\d)*)')
        split_code = self.splitCodeUsingRegex(pattern, do_braces_pairing=False)
        return split_code

    def getOrOperators(self):
        pattern = re.compile(r'(?<=[(])\s*(\w+(\w|\d)*)\s*\|\|\s*(\w+(\w|\d)*)')
        split_code = self.splitCodeUsingRegex(pattern, do_braces_pairing=False)
        return split_code

    def getSwitchBlocks(self):
        pattern = re.compile(r'switch(.*){')
        split_code = self.splitCodeUsingRegex(pattern)
        return split_code

    def setCode(self, code):
        self.code = code

    def getCode(self):
        return self.code

    def getKeywordsList(self):
        keywords = set()

        # Petlje i izrazi u petljama: for, while, goto, break, continue, dekrementiranje i inkrementiranje
        if self.getForLoops():
            if self.code.find('continue') == -1:
                keywords.add(CodeKeyword.FOR_WHILE_LOOP.value)
            elif self.code.find('break') != -1 or self.code.find('continue') != -1:
                keywords.add(CodeKeyword.CONT_BREAK_FOR_STATEMENT.value)
            else:
                keywords.add(CodeKeyword.FOR_GOTO_LOOP.value)
            if self.getDecrementOperators():
                keywords.add(CodeKeyword.DECREMENT_LOOP_OPERATOR.value)
            if self.getIncrementOperators():
                keywords.add(CodeKeyword.INCREMENT_LOOP_OPERATOR.value)

        if self.getWhileLoops():
            if self.code.find('continue') == -1:
                keywords.add(CodeKeyword.WHILE_FOR_LOOP.value)
            elif self.code.find('break') != -1 or self.code.find('continue') != -1:
                keywords.add(CodeKeyword.CONT_BREAK_WHILE_STATEMENT.value)
            else:
                keywords.add(CodeKeyword.WHILE_GOTO_LOOP.value)
            if self.getDecrementOperators():
                keywords.add(CodeKeyword.DECREMENT_LOOP_OPERATOR.value)
            if self.getIncrementOperators():
                keywords.add(CodeKeyword.INCREMENT_LOOP_OPERATOR.value)

        if self.getGotoBlocks():
            keywords.add(CodeKeyword.GOTO_FOR_LOOP.value)
            keywords.add(CodeKeyword.GOTO_WHILE_LOOP.value)

        # Operacije: *, /
        code = self.getOneLineStatements()
        pointerExists = False
        if code:
            pointerCheck=re.search("(int|unsigned|long|short|char)\s+\*",code[0][1])
            if pointerCheck!=None:
                pointerExists=True
        if code and code[0][1].find('*') != -1 and code[0][1].find('*=') == -1 and (not pointerExists):
            keywords.add(CodeKeyword.MULTIPLICATION_OPERATOR.value)
        if code and code[0][1].find('/') != -1 and code[0][1].find('/=') == -1:
            keywords.add(CodeKeyword.DIVIDE_OPERATOR.value)
        if code and code[0][1].find('<<') != -1:
            keywords.add(CodeKeyword.BITLEFT_OPERATOR.value)

        # Relacioni i logicki operatori: <, <=, >, >=, ==, !=, &&, ||, !
        if self.getLessOperators():
            keywords.add(CodeKeyword.LESS_OPERATOR.value)
        if self.getLessEqOperators():
            keywords.add(CodeKeyword.LESS_EQ_OPERATOR.value)
        if self.getGreaterOperators():
            keywords.add(CodeKeyword.GREATHER_OPERATOR.value)
        if self.getGreaterEqOperators():
            keywords.add(CodeKeyword.GREATHER_EQ_OPERATOR.value)
        if self.getEqOperators():
            keywords.add(CodeKeyword.EQUAL_OPERATOR.value)
        if self.getNeqOperators():
            keywords.add(CodeKeyword.NOT_EQUAL_OPERATOR.value)
        if self.getAndOperators():
            keywords.add(CodeKeyword.AND_OPERATOR.value)
        if self.getOrOperators():
            keywords.add(CodeKeyword.OR_OPERATOR.value)

        # Inkrementiranje i dekrementiranje
        if self.getDecrementOperators() and not 'decrement-loop operator' in keywords:
            keywords.add(CodeKeyword.DECREMENT_OPERATOR.value)
        if self.getIncrementOperators() and not 'increment-loop operator' in keywords:
            keywords.add(CodeKeyword.INCREMENT_OPERATOR.value)

        # Uslovna nareba: if, ?, if-else_if-else, switch
        if self.getIfBlocks():
            keywords.add(CodeKeyword.IF_STATEMENT.value)
        if self.getTernaryConditionStatements():
            keywords.add(CodeKeyword.TERNAR_STATEMENT.value)
        if self.getSwitchBlocks():
            keywords.add(CodeKeyword.SWITCH_STATEMENT.value)
        if self.getIfElse():
            keywords.add(CodeKeyword.SIMPLE_IF_STATEMENT.value)

        return keywords
