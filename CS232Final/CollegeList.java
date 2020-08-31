import java.util.Scanner;

public class CollegeList {
	
	public static void main(String args[]) {
		//2d array for storing person objects
		Person[][] people = new Person[3][7];
		String userInput;
		//scanner object
		Scanner inputScanner = new Scanner(System.in);
		int numF = 0;
		int numC = 0;
		int numS = 0;
		boolean enterFData=false;
		boolean enterCData=false;
		boolean enterSData=false;
		boolean running = true;
			//while loop to continuously checks if running is equal to true, if it is set to false by the user entering 'Q' then it breaks the loop
			while(running == true) {
				System.out.println("Please enter F for faculty, C for College Employee, S for student, or Q to quit:");
				userInput = inputScanner.nextLine();
				//checks user input
				if(userInput.toLowerCase().equals("f")){
					//verifies that the number of faculty entered is not more than 3
					if(!(numF >= 3)) {
						//creates faculty object in array people(people is person object array, faculty inherits from person)
						people[1][numF] = new Faculty();
						//runs setData method from faculty object
						people[1][numF].setData();
						//increments one to numF, which is to represent number of faculty entered
						numF++;
						enterFData=true;
					}
					else {
						System.out.println("You've entered the maximum amount of Faculty");
					}
				
				}
				else if(userInput.toLowerCase().equals("c")) {
					if(!(numC >=4)) {
						people[0][numC]= new CollegeEmployee();
						people[0][numC].setData();
						numC++;
						enterCData=true;
					}
					else {
						System.out.println("You've entered the maximum amount of Employees");
					}
				}
				else if(userInput.toLowerCase().equals("s")) {
					if(!(numS >= 7)) {
						people[2][numS]= new Student();
						people[2][numS].setData();
						numS++;
						enterSData=true;
					}
					else {
						System.out.println("You've entered the maximum amount of Students");
					}
				}
				else if(userInput.toLowerCase().equals("q")) {
					System.out.println("Goodbye!");
					running=false;
				}
		}
			
			
			//checks if data was entered, if so, it enumerates through the objects in the correct array in people array and runs the displaydata method for each object
			System.out.println("\nFaculty"+"\n***************************");
			if(enterFData==true) {
				for(int i = 0; i < numF;i++) {
					people[1][i].displayData();
				}
			}
			else {
				System.out.println("No faculty entered");
			}
			
			
			System.out.println("\nEmployees"+"\n***************************");
			
			if(enterCData==true) {
				for(int i = 0; i < numC;i++) {
					people[0][i].displayData();
				}
			}
			else {
				System.out.println("No faculty entered");
			}
			
			
			System.out.println("\nStudents"+"\n***************************");
			
			if(enterSData==true) {
				for(int i = 0; i < numS;i++) {
					people[2][i].displayData();
				}
			}
			else {
				System.out.println("No faculty entered");
			}
	}
	
}
