package Lab1;

//simple testing file

public class Test {   
  
public static void main(String args[]) throws ErrorHandling {   
    System.out.println("Enter an arithmetic expression and end with semi-colon!\n"); 
    Lexer.lex();
    Expr e = new Expr();
    try{
    	e.expr();
    } catch(ErrorHandling h){
    	System.out.println("Type Mismatch: " + h.errorHandle());
    }
} 
} 
