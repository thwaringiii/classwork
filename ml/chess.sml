(*
 CSE305 - CHESS.SML
 Assignment 7, Question 1
 Name: Thomas Waring III
*)


datatype piece = king | queen of int | bishop of int 
| knight of int | rook of int | pawn of int;

fun value(king) = 100
    | value(queen(x)) = x*50
    | value(bishop(x)) = x*25
    | value(knight(x)) = x*15
    | value(rook(x)) = x*25
    | value(pawn(x)) = x*3; 

fun strength([]) = 0
    | strength(x::t) = strength(t) + value(x);

(*
  Value of a should be 215
*)

val a = strength([pawn(5), queen(1), rook(2), king]);
