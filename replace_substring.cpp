//Write a program that can replace a part of the string with another substring.
/*
1). A function that will get the substring to be replaced.
2). A function that will get the position of the substring if exists.
3). A function that will replace the substring with the required string.
*/

#include<iostream>
#include<vector>
#include<string>

std::vector<int> position(std::string input_string, std::string substring){
	std::vector<int> container(3);
	
	//start will hold the starting index of the substring.
	//Pointer will point to the character of the substring till where the match has occurred.
	int start = 0, pointer = 0;
	
	//Loop through the input string and search for a match. time complexity O(n).
	int i = 0;
	for(i=0; i<=(input_string.size() - substring.size()) or pointer != 0; i++){
		std::cout<<input_string[i]<<" "<<substring[pointer]<<std::endl;
		if(input_string[i] == substring[pointer]) pointer += 1;
		else pointer = 0;
		std::cout<<"pointer = "<<pointer<<std::endl;
		//If the substring is matched or found the come out of the loop.
		if(pointer == substring.size()) break;
	}
	
	//If the string is matched.
	if(pointer == substring.size()){
		container[0] = 1;
		container[1] = i - substring.size() + 1;
		container[2] = i;
	}
	//If the string is not matched or ther is no string in the input string.
	else container[0] = container[1] = container[2] = 0;
	
	return container;
}

std::string replace(std::string input_string, int start, int end, std::string replace_string){
	std::string output_string = "";
	std::cout<<start<<" "<<end;
	
	//Loops to add the first required part of the input string and the string to be replaced with and the last required part of the input string.
	for(int i=0; i<start; i++){
		output_string += input_string[i];
		std::cout<<output_string<<" "<<input_string<<std::endl;
	}
	output_string += replace_string;
	for(int i=end+1; i<input_string.size(); i++) output_string += input_string[i];
	
	return output_string;
}

int main(){
	//Input string.
	std::string input_string;
	std::cin>>input_string;
	
	//Substring to be replaced;
	std::string substring;
	std::cin>>substring;
	
	//Enter the string to be replaced by.
	std::string replace_string;
	std::cin>>replace_string;
	
	//container will contain the flag, start index, and end index of the substring.
	//flag = 0 if the string does not exist and 1 if it exists.
	std::vector<int> container = position(input_string, substring);
	
	//If the string exists then call the replace function else print a message and end the program.
	if(container[0]){
		std::string output_string = replace(input_string, container[1], container[2], replace_string);
		
		//Print the final string after the replacement.
		std::cout<<"The string after the replacement is "<<output_string;
	}
	else std::cout<<"The substring "<<substring<<" does not exist in the input string.";
	
	return 0;
}

/*
Input string: roshannayak.
Substring to be replaced: hannay.
String to be replaced with: winsye.
Output string: roswinsyeak.
*/
