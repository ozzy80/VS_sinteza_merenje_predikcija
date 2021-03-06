from loop_transform import formForLoop, formWhileLoop

def incrementTransform(code, mode):
    code = code[:-2]
    if mode == 0:
        code = code + "+= 1;\n"
    elif mode == 1:
        code = code + " = " + code + " + 1;\n"
    else:
        increment = code.split(' ')[-1]
        code = code + " = " + increment + "+ 1"

    return code

def decrementTransform(code, mode):
    code = code[:-2]
    if mode == 0:
        code = code + "-= 1;\n"
    elif mode == 1:
        code = code + " = " + code + " - 1;\n"
    else:
        increment = code.split(' ')[-1]
        code = code + " = " + increment + " - 1"

    return code

def multiplyToSumTransform(code):
    variable = "\n int i_i = 0;\n"
    increment = "i_i++" 

    code_split = code.split('*')

    result = code_split[0].split('=')[0]
    first_sum_variable = code_split[0].split('=')[1]
    second_sum_variable = code_split[1][:-1]
    condition = "i_i < " +  second_sum_variable

    statements = "{\n"
    statements += result + " += " + first_sum_variable + ";\n"
    
    return formForLoop(variable, condition, increment, statements)

def devideToSumTransform(code):
    code_split = code.split('/')

    result = code_split[0].split('=')[0]
    first_variable = code_split[0].split('=')[1]
    second_variable = code_split[1][:-1]
    condition = first_variable + " - " +  second_variable + " > 0"

    statements = "{\n"
    statements += result.strip() + "++;\n"
    statements += first_variable + " = " + first_variable + " - " +  second_variable + ";\n}\n"
    return formWhileLoop("", condition, "", statements)

def bitLeftToForTransform(code):
    variable = "\n int i_i = 0;\n"
    increment = "i_i++" 

    code_split = code.split('<<')

    result = code_split[0].split('=')[0]
    first_bitleft_variable = code_split[0].split('=')[1]    
    second_bitleft_variable = code_split[1][:-1]
    condition = "i_i < " +  second_bitleft_variable

    statements = "{\n"
    statements += result + " *= 2\n"
    
    return result+"="+first_bitleft_variable+";\n"+ formForLoop(variable, condition, increment, statements)