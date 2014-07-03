%
% queries.pl
% CSE305
% Assignment 8 Question 2
% Thomas Waring III



% Calls to course

course(cse115, 'Intro to CSE I').
course(cse116, 'Intro to CSE II').
course(cse191, 'Discrete Structures').
course(cse241, 'Digital Systems').
course(cse250, 'Data Structures').
course(cse305, 'Programming Languages').
course(cse321, 'Real-time and Embedded Systems').
course(cse331, 'Algorithms I').
course(cse341, 'Computer Organization').
course(cse396, 'Automata Theory').
course(cse379, 'Microprocessors I').
course(cse380, 'Microprocessors II').
course(cse411, 'Computer Systems Administration').
course(cse421, 'Operating Systems').
course(cse431, 'Algorithms II').
course(cse441, 'Software Engineering').
course(cse422, 'OS Internals').
course(cse435, 'Information Retrieval').
course(cse443, 'Language Processors').
course(cse452, 'VLSI Testing').
course(cse453, 'Hardware-Software Integration').
course(cse455, 'Pattern Recognition').
course(cse462, 'Databases').
course(cse463, 'Knowledge Representation').
course(cse467, 'Computational Linguistics').
course(cse474, 'Machine Learning').
course(cse484, 'Philopsohy of Computer Science').
course(cse486, 'Distributed Systems').
course(cse487, 'Data Intensive Computing').
course(cse489, 'Networking Concepts').
course(cse490, 'Computer Architecture').
course(cse493, 'VLSI Electronics').


% NO PREREQS (A)

no_prereqs(List):- setof(X, prereqs(X,[]), List).


% POST REQS (B)

post_reqs(Class,List):- setof(X, gocheck(Class, X), List).
gocheck(Class,List):- prereqs(List,Reqs), member(Class,Reqs).


% TERMINAL (C)
terminal(List):- setof(X, find_reqs(X), List).
find_reqs(List):- prereqs(List,_), \+ dig(List).
dig(X):- prereqs(_, Reqs), member(X, Reqs),!.


% ALL PREREQS (D)

all_prereqs(Class, List):- setof(X, check(Class, X), List).
prereq(Class, List):- prereqs(Class, Reqs), member(List, Reqs).
check(Class, List):- prereq(Class, List).
check(Class, List):- prereq(Class, X), check(X, List).

% Calls to prereqs

prereqs(cse101, []).
prereqs(cse115, []).
prereqs(cse116, [cse115]).
prereqs(cse191, [cse115]).
prereqs(cse241, [cse116,cse191]).
prereqs(cse250, [cse116,cse191]).
prereqs(cse305, [cse250]).
prereqs(cse321, [cse341]).
prereqs(cse331, [cse250,mth142]).
prereqs(cse341, [cse241]).
prereqs(cse379, [cse241]).
prereqs(cse380, [cse241]).
prereqs(cse396, [cse250]).
prereqs(cse411, [cse241]).
prereqs(cse421, [cse305]).
prereqs(cse422, [cse421]).
prereqs(cse431, [cse331]).
prereqs(cse435, [cse250,mth309]).
prereqs(cse442, [cse305]).
prereqs(cse443, [cse305]).
prereqs(cse452, [cse493]).
prereqs(cse453, [cse442,cse380]).
prereqs(cse455, [mth309,cse250]).
prereqs(cse462, [cse305]).
prereqs(cse463, [cse305]).
prereqs(cse467, [cse305]).
prereqs(cse474, [mth309,cse250]).
prereqs(cse484, []).
prereqs(cse486, [cse305]).
prereqs(cse487, [cse305]).
prereqs(cse489, [cse250,cse341,mth411]).
prereqs(cse490, [cse341]).
prereqs(cse493, [cse341,ee310]).