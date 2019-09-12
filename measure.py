import os
import time
import csv
import subprocess
import string

from code_parser import Parser

csv_filds = ["for loop", "while loop", "goto loop", "multiplication operator", 'divide operator', 'less operator', 'lessEq operator',
        'greater operator', 'greaterEq operator', 'eq operator', 'neq operator', 'and operator', 'or operator', 'decrement operator',
        'increment operator', 'if statement', '? statement', 'switch statement', 'continue statement', 'break statement', 'recursion block', 'garbage block']

def createCsv(csv_file_directory):
    with open(csv_file_directory, 'w') as csvfile:
        filds = ['func-1 ' + s for s in csv_filds] + ['func-2 ' + s for s in csv_filds]
        fieldnames = ["file name"] + filds + ["--depth", "--unwind", "--partial-loops", '--no-unwinding-assertions', "execution time", "cbmc time", "successful verification"]
        
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()

def writeInCsv(csv_file_directory, file_name, keywords_list_f1, keywords_list_f2, execution_time, cbmc_time, successful_verification, 
               depth=0, unwind=0, partial_loops=0, no_unwind=0):
    result = []
    result.append(file_name)
    with open(csv_file_directory, 'a') as csvfile:
        for name in csv_filds:
            if name in keywords_list_f1: 
                result.append(1)
            else:
                result.append(0)
        for name in csv_filds:
            if name in keywords_list_f2: 
                result.append(1)
            else:
                result.append(0)
        
        result.append(depth)
        result.append(unwind)
        result.append(partial_loops)
        result.append(no_unwind)
        result.append(execution_time)
        result.append(cbmc_time)
        result.append(successful_verification)

        writer=csv.writer(csvfile)
        writer.writerow(result)

def getContainedKeywords(code):
    keywords = set()

    if 'for' in code:
        keywords.add('for loop')
    if 'while' in code:
        keywords.add('while loop')
    if 'goto' in code:
        keywords.add('goto loop')
    if '*' in code and '*=' not in code:
        keywords.add('multiplication operator')
    if '/' in code and '/=' not in code:
        keywords.add('divide operator')
    if '<' in code and '<=' not in code:
        keywords.add('less operator')
    if '<=' in code:
        keywords.add('lessEq operator')
    if '>' in code and '>=' not in code:
        keywords.add('greater operator')
    if '>=' in code:
        keywords.add('greaterEq operator')
    if '==' in code:
        keywords.add('eq operator')
    if '!=' in code:
        keywords.add('neq operator')
    if '&&' in code:
        keywords.add('and operator')
    if '||' in code:
        keywords.add('or operator')
    if code.find('--') != -1:
        keywords.add('decrement operator')
    if code.find('++') != -1:
        keywords.add('increment operator')
    if 'if' in code:
        keywords.add('if statement')
    if '?' in code:
        keywords.add('? statement')
    if 'switch' in code:
        keywords.add('switch statement')
    if 'continue' in code:
        keywords.add('continue statement')
    if 'break' in code:
        keywords.add('break statement')

    return keywords

def createParser(filename):
    with open(filename) as f:
        code = f.read()
    p = Parser(code)
    return p

def getCbmcOutputAndExecutionTime(args):
    start_time = time.clock()
    cbmc_command = "timeout 10 "+" ".join(args)
    output = subprocess.check_output(cbmc_command, stderr=subprocess.DEVNULL,shell=True) 
    execution_time = time.clock() - start_time

    if len(str(output).split('Runtime decision procedure: ')) > 1:
        cbmc_time = str(output).split('Runtime decision procedure: ')[1]
        cbmc_time = cbmc_time.split('s\\n')[0]
    else:
        cbmc_time = None

    if 'VERIFICATION SUCCESSFUL' in str(output):
        print('Uspesno verifikovan')
    else:
        raise ValueError('GRESKA: Funkcije nisu ekvivalentne')

    return (output, execution_time, cbmc_time)