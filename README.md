# Regex To NFA Algorithm

This branch has two codes, one for converting Regex to NFA second for simulating the NFA.

1) Converting Regex to NFA:

Input:\n
	Regex
Output:\n
	Number of states, Number of recepient states, Number of transitions\n
	Indexes of recepient states\n
	For each state, printing on the independent line following these schema:\n
		Number of transitions, Pairs where first one is the symbol and the second one is state index to wich it connects\n

2) Simulating The NFA:

Input:\n
	Word to simulate\n
	NFA according to the previous task\n
Output:
	Printing side by side:
		Y(yes) if after reading one symbol NFA was in at least one recepient state
		N(no)  if after reading one symbol NFA was not in any recepient state


/---------------------------------/\n
I had this tasks as homework in university(Free University). Tests are provided by my lecturer, Nikoloz Tsimakuridze
	