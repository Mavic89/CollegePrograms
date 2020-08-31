import javax.swing.JOptionPane;

public class Student extends Person {
	String fieldofStudy;
	String gpa;
	
	@Override
	public void setData() {
		super.setData();
		fieldofStudy = JOptionPane.showInputDialog("Field of Study");
		gpa = JOptionPane.showInputDialog("GPA");
		
	}
	@Override
	public void displayData() {
		super.displayData();
		System.out.println("Major:"+fieldofStudy+"\nGPA:"+gpa);
	}
}
