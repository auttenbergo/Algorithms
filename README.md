# Regex To NFA Algorithm

This branch has two codes, one for converting regex to nfa, second for simulating the nfa.

1) Converting regex to nfa:

Input: 
	regex
Output: 
	Number of states, Number of recepient states, Number of transitions
	Indexes of recepient states
	For each state, printing on the independent line following these schema:
		Number of transitions, Pairs where first one is the symbol and the second one is state index to wich it connects

2) Simulatins the nfa:

Input:
	Word to simulate
	NFA according to the previous task
Output:
	Printing side by side:
		Y(yes) if after reading one symbol NFA was in at least one recepient state
		N(no)  if after reading one symbol NFA was not in any recepient state


/---------------------------------/
I had this tasks as homework in university(Free University). Tests are provided by my lecturer, Nikoloz Tsimakuridze
	