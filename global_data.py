from enum import Enum

class CodeKeyword(Enum):
    FOR_WHILE_LOOP = 'for-while loop'
    FOR_GOTO_LOOP = 'for-goto loop'
    WHILE_FOR_LOOP = 'while-for loop'
    WHILE_GOTO_LOOP = 'while-goto loop'
    GOTO_FOR_LOOP = 'goto-for loop'
    GOTO_WHILE_LOOP = 'goto-while loop'
    MULTIPLICATION_OPERATOR ='multiplication operator'
    BITLEFT_OPERATOR = 'bitleft operator'
    DIVIDE_OPERATOR = 'divide operator'
    LESS_OPERATOR = 'less operator'
    LESS_EQ_OPERATOR = 'lessEq operator'
    GREATHER_OPERATOR = 'greater operator'
    GREATHER_EQ_OPERATOR = 'greaterEq operator'
    EQUAL_OPERATOR = 'eq operator'
    NOT_EQUAL_OPERATOR = 'neq operator'
    AND_OPERATOR = 'and operator'
    OR_OPERATOR = 'or operator'
    DECREMENT_OPERATOR = 'decrement operator'
    INCREMENT_OPERATOR = 'increment operator'
    IF_STATEMENT = 'if statement'
    TERNAR_STATEMENT = '? statement'
    SWITCH_STATEMENT = 'switch statement'
    SIMPLE_IF_STATEMENT = 'simple if else statement'
    CONT_BREAK_FOR_STATEMENT = 'continue-break for statement'
    CONT_BREAK_WHILE_STATEMENT = 'continue-break while statement'
    DECREMENT_LOOP_OPERATOR = 'decrement-loop operator'
    INCREMENT_LOOP_OPERATOR = 'increment-loop operator'