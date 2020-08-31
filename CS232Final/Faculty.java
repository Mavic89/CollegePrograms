import javax.swing.JOptionPane;

public class Faculty extends CollegeEmployee {
	boolean tenured;
	
	@Override
	public void setData() {
		super.setData();
		int istenured = JOptionPane.showConfirmDialog(null, "Is this employee tenured?");
		//if user entered yes(0), tenured is set to true, if no(1) tenured is set to false
		if(istenured == 0) {
			tenured = true;
		}
		else if(istenured == 1) {
			tenured = false;
		}
	}
	@Override
	public void displayData() {
		super.displayData();
		//checks if tenured is true or false to determine which option to display
		if(tenured == true) {
			System.out.println("Employee is tenured");
		}
		else if (tenured == false) {
			System.out.println("Employee is not tenured");
		}
	}
	
	
}
