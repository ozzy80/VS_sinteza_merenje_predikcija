def addRecursiveCall(code):
    bodyStart=code.find('{');
    newCode = code[:bodyStart+1]+ """int a[]={1,2,3,4,5};
    suma(a,0,5);""" + code[bodyStart+1:];
    return """int suma(int a[],int i,int length){
    if(i==length)
        return 0;
    else{
        return a[i]+suma(a,i+1,length);
    }
    return 0;
}"""+newCode.replace("function","f1");

def addNonRecursiveCall(code):
    bodyStart=code.find('{');
    newCode = code[:bodyStart+1]+ "helper();" + code[bodyStart+1:];
    return """void helper(){
    int a=1+2+3;
}"""+newCode.replace("function","f1");