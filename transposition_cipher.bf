+
[ repeat until input=32
	>++++++++[->++++<]>[-<+>]< 32
	<[->>+<<]>
	[->-<]> if input != 32
	[
        [-<<+>>]<
		++++++++[->++++<]>[-<<-->>]<< sub 64 to make letters in range 1 to 26
		>+>[-] exit
	]<[,>]<
	else exit
]<[<]>[-]>[>]

+++++[->++++<]>++++++ for i=1 to 26 do
[
	>[-]<[->>+<<] move counter to end 
	, read alphabet offset
	>>- then go to counter and subtract counter by 1
]
<< << << << << << << << << <<
<< << << << << << << << << <<
<< << << << << << <

<
[ while message is not empty
	[<]>[[>]>>+<<[<]<[<]>-] move cell
	>[>]>>- sub 1
	[[->>+<<]+>>-]<.< find a cell with offset
	we're adding 1 to empty to make moving to message easier
	[-<<]< coming back
]
