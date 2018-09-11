import subprocess

from measure import *

csv_file_directory = './result/function_time.csv'
createCsv(csv_file_directory)

def execution_cbmc(filename, unwind=-1, depth=-1, no_unwinding=False, partial_loops=False):
    if unwind != -1 and no_unwinding:
        args = ['cbmc', filename, '--unwind', str(unwind), '--no-unwinding-assertions']
    elif depth != -1 and no_unwinding:
        args = ['cbmc', filename, '--depth', str(depth), '--no-unwinding-assertions']
    elif unwind != -1 and partial_loops:
        args = ['cbmc', filename, '--unwind', str(unwind), '--partial-loops']
    elif depth != -1 and partial_loops:
        args = ['cbmc', filename, '--depth', str(depth), '--partial-loops']
    elif unwind != -1:
        args = ['cbmc', filename, '--unwind', str(unwind)]
    elif depth != -1:
        args = ['cbmc', filename, '--depth', str(depth)]
    else:
        args = ['cbmc', filename]

    try:
        execution_time = None
        cbmc_time = None
        output, execution_time, cbmc_time = getCbmcOutputAndExecutionTime(args)
        success = True
    except ValueError as error:
        print('Nije pronadjena ekvivalencija')
        success = False
    except subprocess.TimeoutExpired as error:
        print('Nije pronadjena ekvivalencija')
        execution_time = 60.0
        success = False
    except subprocess.CalledProcessError as error:
        print('Nije pronadjena ekvivalencija')
        success = False
    except Exception as error:
        print('ERROR: ' + repr(error))
    finally:
        return (execution_time, cbmc_time, success)

code_directory_path = './function_equivalent_code/'
for file in os.listdir(code_directory_path):
    filename = code_directory_path + os.fsdecode(file)
    print("--------")
    print(filename)

    p = createParser(filename)
    fun1 = p.getFunctionBlock("function")[0][1]
    fun2 = p.getFunctionBlock("f1")[0][1]
    keywordsContainedFunc1 = getContainedKeywords(fun1)
    keywordsContainedFunc2 = getContainedKeywords(fun2)
    
    if 'helper' in p.getAllFunctionName():
        keywordsContainedFunc2.add('garbage block')
    elif 'suma' in p.getAllFunctionName():
        keywordsContainedFunc2.add('recursion block')

    execution_time, cbmc_time, success = execution_cbmc(filename)
    writeInCsv(csv_file_directory, filename, keywordsContainedFunc1, keywordsContainedFunc2, execution_time, cbmc_time, success)
    if 'loop' or 'recursion block' in keywordsContainedFunc2:
        for i in [1, 2, 4, 8, 16]:
            execution_time, cbmc_time, success = execution_cbmc(filename, unwind=i, no_unwinding=True)
            writeInCsv(csv_file_directory, filename, keywordsContainedFunc1, keywordsContainedFunc2, execution_time, cbmc_time, success, unwind=1, no_unwind=1)
            execution_time, cbmc_time, success = execution_cbmc(filename, depth=i, no_unwinding=True)
            writeInCsv(csv_file_directory, filename, keywordsContainedFunc1, keywordsContainedFunc2, execution_time, cbmc_time, success, depth=1, no_unwind=1)
            execution_time, cbmc_time, success = execution_cbmc(filename, unwind=i, partial_loops=True)
            writeInCsv(csv_file_directory, filename, keywordsContainedFunc1, keywordsContainedFunc2, execution_time, cbmc_time, success, unwind=1, partial_loops=1)
            execution_time, cbmc_time, success = execution_cbmc(filename, depth=i, partial_loops=True)
            writeInCsv(csv_file_directory, filename, keywordsContainedFunc1, keywordsContainedFunc2, execution_time, cbmc_time, success, depth=1, partial_loops=1)
            execution_time, cbmc_time, success = execution_cbmc(filename, unwind=i)
            writeInCsv(csv_file_directory, filename, keywordsContainedFunc1, keywordsContainedFunc2, execution_time, cbmc_time, success, unwind=1)
            execution_time, cbmc_time, success = execution_cbmc(filename, depth=i)
            writeInCsv(csv_file_directory, filename, keywordsContainedFunc1, keywordsContainedFunc2, execution_time, cbmc_time, success, depth=1)

        
