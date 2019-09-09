import re
import ntpath
from code_parser import Parser
import subprocess


class Code:
    def __init__(self, file_location):
        self.file_name = ntpath.basename(file_location)
        self.code = ""
        with open(file_location) as f:
             self.code = f.read()

    def setCode(self,code_body):
        self.code=code_body

    def getCode(self):
        return self.code

    def mergeCode(self, first_part_modified, second_part_modified, third_part_modified, new_function_name):
        position_before_difference = len(first_part_modified)
        merge_function_name = re.findall(r"(\w+\d*\w+\s+\w+\d*\w+)\s*\(.*\)\s*{", self.code[:position_before_difference])
        merge_function_name = merge_function_name[-1]

        p1 = Parser(self.code)
        p2 = Parser(first_part_modified + second_part_modified + third_part_modified)
        main_code = p1.getFunctionBlock("int\s+main\(")
        modified_code =  p2.getFunctionBlock(merge_function_name)

        function_name = merge_function_name.split(' ')[-1]
        modified_code[0][1] = modified_code[0][1].replace(function_name, new_function_name)

        self.code = main_code[0][0] + modified_code[0][1] + "\n" + main_code[0][1] + "\n" + main_code[0][2]

    def mergeFunctionCode(self, first_part_modified, second_part_modified, third_part_modified, old_function):
        self.code = first_part_modified + second_part_modified + "\n" + old_function + "\n" + third_part_modified

    def saveCode(self, file_location, file_name):
        with open(file_location + file_name, "w") as f:
            f.write(self.code)
        subprocess.call('.\\uncrustify\\uncrustify.exe -c .\\uncrustify\\cfg\\linux.cfg --no-backup -f '+file_location + file_name+' -o '+file_location + file_name)
        

    def getFileName(self):
        return self.file_name
