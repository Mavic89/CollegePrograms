import javax.swing.JOptionPane;

public class Person {
	//person variable
	String firstName;
	String lastName;
	String streetAddress;
	String zipcode;
	String phoneNumber;
	//Sets information for person object using input dialog box
	public void setData() {
		firstName = JOptionPane.showInputDialog("First Name");
		lastName = JOptionPane.showInputDialog("Last Name");
		streetAddress = JOptionPane.showInputDialog("Street Address");
		zipcode = JOptionPane.showInputDialog("Zip code");
		phoneNumber=JOptionPane.showInputDialog("Phone Number");
		
	}
	//displays information relative to person object
	public void displayData() {
		System.out.println("\nName:"+firstName+lastName+"\nStreet Address:"+streetAddress+"\nZip code:"+zipcode+"\nPhone Number:"+phoneNumber);
	}
}
