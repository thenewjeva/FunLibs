#include <fstream>
#include <string>
#include <iostream>


// using std::ifstream;
// using std::ofstream;
// using std::string;
// using std::getline;
// using std::cout;
// using std::cin;
// using std::endl;
using namespace std;

int main()
{
	string the_story;
	string word_type;
	string response;
	string outfile = "output.txt";
	string usrNum;
	string puzzle;

	while(1){
		cout << "Welcome to FunLibs!" << endl << "Choose puzzle (#1-6)" << endl;
		cin >> usrNum;
		ifstream in("test.txt");

		getline(in, puzzle, ']');

		while (usrNum != puzzle)
		{
			in.ignore (200, '\n');
			getline(in, puzzle, ']');
		}

		getline(in, the_story, '(');
		string word;

		while(!in.eof())
		{
			getline(in, word_type, ')');
			if(word_type == "end")
				break;
			cout << "Type a " << word_type << endl;
			cin >> word;
			the_story.append(word);
			string appended;
			getline(in, appended, '(');
			the_story.append(appended);
		}

		cout << the_story << endl;
		
		while(1){
			cout << "Would you like to save this puzzle? (y/n)" << endl;
			
			cin >> response;
			
			if(response == "yes" || response == "y"){
				cout << "Please name the output file ending with .txt (default is output.txt)" << endl;
				cin >> response;
				if(response != "" && response.substr(response.size() - 4) == ".txt"){
					outfile = response;
				}
				else if(response != "" && response.substr(response.size() - 4) != ".txt"){
					cout << "File name does not end with .txt" << endl;
					continue;
				}
				
				ofstream out(outfile.c_str());
				
				out << the_story << endl;
				
				out.close();
				break;
				
			}
			else if(response == "no" || response == "n"){
				break;
			}
			else{
				cout << "Response not understood please try again" << endl;
			}
		}
		
		while(1){
			cout << "Would you like to do another puzzle? (y/n)" << endl;
			
			cin >> response;
			
			if(response == "yes" || response == "y"){
				break;
			}
			else if(response == "no" || response == "n"){
				return 0;
			}
			else{
				cout << "Response not understood please try again" << endl;
			}
		}
	}
	return 0;
}
