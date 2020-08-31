import javax.swing.JOptionPane;

//inherits from person
public class CollegeEmployee extends Person {
	String ssn;
	String salary;
	String deptName;
	//overrides setData method in person
	@Override
	public void setData() {
		//runs setdata method from superclass person
		super.setData();
		ssn = JOptionPane.showInputDialog("Social Security Number");
		salary = JOptionPane.showInputDialog("Salary");
		deptName = JOptionPane.showInputDialog("Department Name");
	}
	//overrides super class' method, runs super class method and then continues to display information relative to college employees
	@Override
	public void displayData() {
		super.displayData();
		System.out.println("Social Security Number:"+ssn+"\nSalary:"+salary+"\nDepartment:"+deptName);
		
	}
}
