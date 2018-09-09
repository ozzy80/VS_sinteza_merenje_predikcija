import re

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
        pattern = re.compile(r';\n*.+[*|\+|/|\-]+.*;')
        split_code = self.splitCodeUsingRegex(pattern, left_padding=1, do_braces_pairing=False)
        return split_code

    def getFunctionBlock(self, function_name):
        pattern = re.compile(function_name)
        split_code = self.splitCodeUsingRegex(pattern)
        return split_code

    def getFunctionBlockWithType(self, function_name):
        pattern = re.compile(r'[double|float|int|short|long|void|char]\s+'+function_name)
        split_code = self.splitCodeUsingRegex(pattern ,left_padding=-2)
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
        # Izvlacenje dela koda u funkciju 
        keywords = set()

        # Umetanje metod na mesto gde se poziva
        if len(self.getAllFunctionName()) > 2:
            keywords.add('multiple functions')

        # Menjanje for-while, while-for, for-goto, goto-for, while-goto, goto-while
        if self.getForLoops():
            keywords.add('for-while loop')
            keywords.add('for-goto loop')
            if self.code.find('break') != -1 or self.code.find('continue') != -1:
                keywords.add('continue-break for statement')
        if self.getWhileLoops():
            keywords.add('while-for loop')
            keywords.add('while-goto loop')
            if self.code.find('break') != -1 or self.code.find('continue') != -1:
                keywords.add('continue-break while statement')
        if self.getGotoBlocks():
            keywords.add('goto-for loop')
            keywords.add('goto-while loop')

        # Menjanje * ili / sa sabiranjem u petlji
        code = self.getOneLineStatements()
        if code and code[0][1].find('*') != -1:
            keywords.add('multiplication operator')
        if code and code[0][1].find('/') != -1:
            keywords.add('divide operator')

        # Relacioni i logicki operatori: <, <=, >, >=, ==, !=, &&, ||, ! kad god ima neka petlja sa uslovima
        if self.getLessOperators():
            keywords.add('less operator')
        if self.getLessEqOperators():
            keywords.add('lessEq operator')
        if self.getGreaterOperators():
            keywords.add('greater operator')
        if self.getGreaterEqOperators():
            keywords.add('greaterEq operator')
        if self.getEqOperators():
            keywords.add('eq operator')
        if self.getNeqOperators():
            keywords.add('neq operator')
        if self.getAndOperators():
            keywords.add('and operator')
        if self.getOrOperators():
            keywords.add('or operator')

        # Inkrementiranje i dekrementiranje
        if self.getDecrementOperators():
            keywords.add('decrement operator')
        if self.getIncrementOperators():
            keywords.add('increment operator')

        # Uslovna nareba: if, ?, if-else_if-else, switch
        if self.getIfBlocks():
            keywords.add('if statement')
        if self.getTernaryConditionStatements():
            keywords.add('? statement')
        if self.getSwitchBlocks():
            keywords.add('switch statement')
        if self.getIfElse():
            keywords.add('simple if else statement')

        # Kontrola toka: Break, continue
        
        
        return keywords
