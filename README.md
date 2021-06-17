# Regex To NFA Algorithm

This branch has two codes, one for converting Regex to NFA second for simulating the NFA.<br/>

1) Converting Regex to NFA:<br/>

Input:<br/>
	Regex<br/>
Output:<br/>
	Number of states, Number of recepient states, Number of transitions<br/>
	Indexes of recepient states<br/>
	For each state, printing on the independent line following these schema:<br/>
		Number of transitions, Pairs where first one is the symbol and the second one is state index to wich it connects<br/>

2) Simulating The NFA:<br/>

Input:<br/>
	Word to simulate<br/>
	NFA according to the previous task<br/>
Output:<br/>
	Printing side by side:<br/>
		Y(yes) if after reading one symbol NFA was in at least one recepient state<br/>
		N(no)  if after reading one symbol NFA was not in any recepient state<br/>


/---------------------------------/<br/>
I had this tasks as homework in university(Free University). Tests are provided by my lecturer, Nikoloz Tsimakuridze
	