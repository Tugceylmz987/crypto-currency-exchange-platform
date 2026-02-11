tokeniseCSV

string csvLine='thing,thing2,thing3'## the string we are processing

string vector token ## stores tokens

char seperator= ',' ## the character that separates the tokens (chose char not string cause we want only one character)

int start, end ## use to delineate the position of the tokens ( controller variables here)

start= csvLine.find_first_not_of(seperator)

## do-while loop , do while loop runs at least once cause first "do2 this 
# end =5 and start=0
# start 6 and end 12
do 
   
	end= next 'seperator' after start
	if start== csvLine.length or start ==end ## nothing more to find
		break
	if end>=0 ## we found the seperator 
		token =cvsLine.substr(start, end-start) ## start, substring length
	else 
		token =cvsLine.substr(start, csvLine.length-start) ## end is invalid

	tokens.push_back(token) ## save the token 
	start =end+1 ## move past this token

while (end > 0) ## continue loop contion 

