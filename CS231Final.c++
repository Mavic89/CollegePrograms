
#include<iostream>
#include<iomanip>
#include<vector> 
#include<fstream>
#include<string>
#include <ctime>

/*

Course Simulation Program
By:Jacob Shumate
Note:Sometimes when running this code through an ide, if you terminate the program by clicking X before the program finishes, you will have to kill the process with task manager or wait a few minutes to be able to run the program again.
This is due to the "Press c to continue" aspect of the program

Note:Security key is '12345'
*/

using namespace std;

string stuNumber;
string stuLastName;
string stuFirstName;
string stuMajor;
int numCourse;
vector<string> courseArray;
vector<int> courseHoursArray;
vector<string> fileInputArray;
string courseEntry;
int hoursEntry;
string fileName;
int hoursSum;
void inputInfo();

void finalScreen(){
	cout << string(100, '_') << endl;
	cout << string(100, ' ') << endl;
	cout << setw(65) << "Jacksonville State University" << endl;
    cout << setw(60) << "Fall Semester 2019" << endl;
    cout << setw(58) << "Class Schedule" << endl;
	cout << string(100, ' ') << endl;
	time_t now = time(0);
   	char* dt = ctime(&now);
	cout<< "Date:";
	cout << dt;
	cout << "Advisor:Dr Robert A Elliot Sr PhD" << endl;
	cout << "SSN:11111   ";
	cout << "Name:";
	cout << stuFirstName;
	cout << " ";
	cout << stuLastName;
	cout << "         Major:";
	cout << stuMajor << endl;
	for(int j = 0; j < courseArray.size();j++){	
		cout << courseArray[j];
		cout << "   ";
	}
	for(int k = 0; k < courseHoursArray.size();k++){
		hoursSum+=courseHoursArray[k];

	}
	cout << "" << endl;
	cout << setw(45) << "Total Hours:";
	cout << hoursSum << endl;
	cout << string(100, '_') << endl;
	cout << string(100, '_') << endl;
	ofstream outputFile;
  	outputFile.open ("StudentSchedule.txt");
  	outputFile << stuNumber << endl << stuFirstName << endl << stuLastName << endl;
	for(int h =0; h < courseArray.size(); h++){
		outputFile << courseArray[h] << endl;

	}
  	outputFile.close();
	cout << "A text file containing your schedule named 'StudentSchedule.txt has been created in the same directory" << endl;
	inputInfo();
	
}


void inputCourses(int x){
	switch(x){
		case 1:
		{
			for(int i =0;i < 1;i++){
				cout << "Section, Course Number:" << endl;
    			cin.ignore();
				getline(cin, courseEntry);
				cout << "Course Hours:" << endl;
				cin >> hoursEntry;
				courseArray.push_back(courseEntry);
				courseHoursArray.push_back(hoursEntry);
			}
		}
		break;
		case 2:
		{
			for(int i =0;i < 2;i++){
				cout << "Section, Course Number:" << endl;
    			cin.ignore();
				getline(cin, courseEntry);
				cout << "Course Hours:" << endl;
				cin >> hoursEntry;
				courseArray.push_back(courseEntry);
				courseHoursArray.push_back(hoursEntry);
			}
		}
		break;
		case 3:
		{
			for(int i =0;i < 3;i++){
				cout << "Section, Course Number:" << endl;
    			cin.ignore();
				getline(cin, courseEntry);
				cout << "Course Hours:" << endl;
				cin >> hoursEntry;
				courseArray.push_back(courseEntry);
				courseHoursArray.push_back(hoursEntry);
			}
		}
		break;
		case 4:
		{
			for(int i =0;i < 4;i++){
				cout << "Section, Course Number:" << endl;
    			cin.ignore();
				getline(cin, courseEntry);
				cout << "Course Hours:" << endl;
				cin >> hoursEntry;
				courseArray.push_back(courseEntry);
				courseHoursArray.push_back(hoursEntry);
			}
		}
		break;
		case 5:
		{
			for(int i =0;i < 5;i++){
				cout << "Section, Course Number:" << endl;
    			cin.ignore();
				getline(cin, courseEntry);
				cout << "Course Hours:" << endl;
				cin >> hoursEntry;
				courseArray.push_back(courseEntry);
				courseHoursArray.push_back(hoursEntry);
			}
		}
		break;
		case 6:
		{
			for(int i =0;i < 6;i++){
				cout << "Section, Course Number:" << endl;
    			cin.ignore();
				getline(cin, courseEntry);
				cout << "Course Hours:" << endl;
				cin >> hoursEntry;
				courseArray.push_back(courseEntry);
				courseHoursArray.push_back(hoursEntry);
			}
		}
		break;
	}
	finalScreen();
	

	
}


void inputInfo(){
    cout << string(30,'-');
    cout << "COURSE ENROLLMENT SIMULATION";
    cout << string(30,'-') << endl;
    cout << string(60,' ') << endl;
    cout << setw(63) << "Please enter a valid directory with a text file containing the following information in the exact order:(student number, last name, first name, major)" << endl;
	cout << "Note:Input needs to be on separate lines" << endl;
	cout << ">>"; 
	cin >> fileName;
	string str;
	ifstream file;
	file.open(fileName.c_str());
	while (getline(file, str))
	{
	if(str.size() > 0)
		fileInputArray.push_back(str);
	}
	file.close();
	try{

		stuNumber = fileInputArray[0];
		stuLastName =fileInputArray[1];
		stuFirstName = fileInputArray[2];
		stuMajor = fileInputArray[3];
	}
	catch(int xyz){
		cout << "An error occurred. Please make sure your input file is formatted properly and that the inputs are each on separate lines.";
	}
	cout << "\nPlease enter the number of courses you will be taking this semester(Maximum of 6):";
	cin >> numCourse;
	inputCourses(numCourse);
}

void initialize(){
    string contChar;
    cout << string(100, '_') << endl;
    cout << string(100, ' ') << endl;
    cout << setw(65) << "Jacksonville State University" << endl;
    cout << setw(60) << "Fall Semester 2019" << endl;
    cout << setw(54) << "CS230" << endl;
    cout << setw(58) << "Jacob Shumate" << endl;
    cout << string(100, '_') << endl;
    cout << string(100, ' ') << endl;
    cout << setw(65) << "COURSE ENROLLMENT SIMULATION" << endl;
    cout << string(100, ' ') << endl;
    cout << string(100, '_') << endl;
    cout << string(100, '_') << endl;
    do 
    {
        cout << '\n' << "Enter 'c' to continue:";
        cin >> contChar;
        
    }  while (contChar != "c" && contChar != "C");
    inputInfo();
    
    

}

int authenticate(){
    int securityKey;
    cout << "Enter security key: ";
    cin >> securityKey;
    if (cin.fail() == false && securityKey == 12345){
        initialize();
    }
    else{
		if(cin.fail() == true){
			cout << "Please enter a valid number:" << endl;
			return 0;
		}
		else{
        	cout << "Access Denied " << endl; 
        	return 0;
		}
    }
    
}

int main(){
    authenticate();
    
}

