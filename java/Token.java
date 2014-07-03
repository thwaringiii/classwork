package Lab1;

class Token {
//given operations   
public static final int SEMICOLON = 0; 
public static final int COMMA 	  = 1;
public static final int PERIOD    = 2;   
public static final int ADD_OP    = 3;   
public static final int SUB_OP    = 4;   
//implemented operations
public static final int MULT_OP   = 5;   
public static final int DIV_OP    = 6;   
public static final int ASSIGN_OP  = 7;   
public static final int LEFT_PAREN	= 8;   
public static final int RIGHT_PAREN	= 9;   
public static final int ID    		= 10;   
public static final int INT_LIT    = 11;
public static final int REAL_LIT	= 12;
  
private static String[] lexemes = {   
    ";", ",", ".", "+", "-", "*", "/", "=", "(", ")", "ID", "NUMBER", "REAL", 
    };   
  
public static String toString (int i) {   
    if (i < 0 || i > REAL_LIT)   
       return "";   
    else return lexemes[i];   
}
} 
