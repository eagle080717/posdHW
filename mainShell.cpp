#include <iostream>
#include <string>
#include "parser.h"
#include "scanner.h"
using namespace std;

int main(int argc, char **argv)
{
	//Parser p;
	string input, output = "";
	int i, flag = 0;
	while(1){
		flag = 0;	
		input.clear();
		cout << "?- ";
		while(!flag){
			i = 0;
			getline(cin, input);

			if(input.back() == ';'){
				output += input;
				cout << "|  ";
			}
			if(input == "halt."){
				flag = 2;
				break;			
			}
			if(input.back() == '.' || input.find("=") != string::npos){
				try {
					output += input;
					Scanner scanner(output); 
					Parser p(scanner);
				    p.buildExpression();
				    string result = p.express();
				    cout << result << endl;
				} catch (std::string &msg) {
				    cout << msg << endl;
				}
				flag = 1;
			}
			if(!flag)
				cout << "?- ";
		}
		if(flag == 2)
			break;
	}
}