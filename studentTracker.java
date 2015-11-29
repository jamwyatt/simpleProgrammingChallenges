//
//  studentTracker.java
//  studentTracker
//
//  Created by James Wyatt on 3/27/08.
//

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.text.*;
import java.io.*;
import java.util.*;
import javax.print.*;
import javax.print.attribute.*;
import javax.print.attribute.standard.*;

public class studentTracker extends JFrame {

	private Font font = new Font("serif", Font.ITALIC+Font.BOLD, 36);
	final String rootPath = "/Users/jamwyatt/students/";
	final String EmptyListEntry = "Add Student";
	final String prefix = "student_";
	final String suffix = ".txt";

	// Selection list of students
	JComboBox students = new JComboBox();

	// Editor Window
	JEditorPane textEntry = new JEditorPane();

	// Action Buttons
	JButton viewButton = new JButton("View");
	JButton printButton = new JButton("Print");
	JButton newStudentButton = new JButton("New Student");
	JButton commitButton = new JButton("Commit");
	JButton clearButton = new JButton("Clear");

	// Outter most container
	Container myContainer;

	private void printStudent(String name) {

		File studentFile = new File(rootPath, prefix + students.getSelectedItem().toString() + suffix);
		PrintService defaultPrinter = PrintServiceLookup.lookupDefaultPrintService();

		DocFlavor flavor = DocFlavor.INPUT_STREAM.AUTOSENSE;
		DocAttributeSet das = new HashDocAttributeSet();
		PrintRequestAttributeSet attributes = new HashPrintRequestAttributeSet();
		attributes.add(MediaSizeName.ISO_A4);
		attributes.add(new Copies(1));

		DocPrintJob pj = defaultPrinter.createPrintJob();

		try {
			FileInputStream fis = new FileInputStream(studentFile);
			Doc doc = new SimpleDoc(fis,flavor,das);
			pj.print(doc, attributes);
			fis.close();
		} catch(FileNotFoundException fnfe) {
			JOptionPane.showMessageDialog(myContainer,"Student File: '" + name + "' " + fnfe);
			}
		  catch(PrintException pe) {
			JOptionPane.showMessageDialog(myContainer,"Print Exception:" + pe);
			}
		  catch(IOException ioe) {
			JOptionPane.showMessageDialog(myContainer,"IO Exception:" + ioe);
			}
		}

	private void writeEntry() {
		File studentDir = new File(rootPath);
		studentDir.mkdirs();		// always remakr the directory
		File studentFile = new File(rootPath, prefix + students.getSelectedItem().toString() + suffix);
		try {
			if(!studentFile.exists())
				studentFile.createNewFile();
			FileWriter fw = new FileWriter(studentFile,true);	// always open for append!!!!!!!
			fw.write("\n" + new Date().toString() + "\n\n" + textEntry.getText() +
				"\n--------------------------------------------------------------------------------\n");
			fw.close();
		} catch(IOException ioe) {
			System.out.println("IO Failure writing entry: " + ioe);
			System.exit(-1);
			}
		}
	
	private void clearForm() {
		textEntry.setText("");
		upDateStudentList(students);	// reset the pull down
		}

	private void createNewStudent(String name) {
		File studentDir = new File(rootPath);
		studentDir.mkdirs();		// always remakr the directory
		File studentFile = new File(rootPath,prefix + name + suffix);
		try {
			if(!studentFile.exists())
				studentFile.createNewFile();
			else
				JOptionPane.showMessageDialog(myContainer,"Student '" + name + "' already exists");
		} catch(IOException ioe) {
			System.out.println("IO Failure creating student: " + ioe);
			System.exit(-1);
			}
		upDateStudentList(students);	// Completely update the list again, no matter what
		}

	private void upDateStudentList(JComboBox friends) {
		friends.removeAllItems();		// Always start with a clear list
		File studentDir = new File(rootPath);
		if(studentDir.exists()) {
			String [] files = studentDir.list();
			for(int x=0;x<files.length;x++) {
				if(files[x].matches("^" + prefix + ".+\\" + suffix + "$"))
					friends.addItem(files[x].substring(8,files[x].length()-4)); // Just use the name of the student in the list
				}
			Arrays.sort(files);	// pretty
			}
		else {
			friends.addItem(EmptyListEntry);
			}
		students.setSelectedIndex(0);		// always set to the first element
		}


	public studentTracker() {
		
		setTitle("Student Tracker 1.0");


		myContainer = this.getContentPane();

		// Top Continer 
		myContainer.setLayout(new BorderLayout());

		// Top Row container ... this is added to the layout of the main content
		Container northContent = new Container();
		northContent.setLayout(new GridLayout(1,3));

		northContent.add(students);		// Student Pull Down
		northContent.add(viewButton);		// view the selected student's file
		// northContent.add(printButton);		// print the selected student button
		northContent.add(newStudentButton);	// New Student editor pane
		myContainer.add(northContent, BorderLayout.NORTH);

		// Setup the text entry pane
		textEntry.setContentType("text/plain");
		textEntry.setEditable(true);
		textEntry.setPreferredSize(new Dimension(500,700));
		JScrollPane scrollable = new JScrollPane(textEntry);
		scrollable.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		scrollable.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		myContainer.add(scrollable, BorderLayout.CENTER);

		// Bottom Row container ... this is added to the layout of the main content
		Container southContent = new Container();
		southContent.setLayout(new GridLayout(1,2));

		southContent.add(commitButton);		// Commit entry to file ... needs to trigger pop-up
		southContent.add(clearButton);		// Reset form ... abort editting ... pop-up confirm
		myContainer.add(southContent, BorderLayout.SOUTH);

		pack();

		// Build List of students
		upDateStudentList(students);


		// Set actions for GUI artifacts

		// Commit button ... commit on popup "ok", then clear ... ignore on others
		commitButton.addActionListener(new ActionListener() { public void actionPerformed(ActionEvent ae) {
			if(EmptyListEntry.equals(students.getSelectedItem())) {
				// Nothing to do ... but warn about adding first ...
				JOptionPane.showMessageDialog(myContainer,"Add a student first");
				}
			else {
				int result = JOptionPane.showConfirmDialog(myContainer,
						"Write Entry for '" + students.getSelectedItem() + "'?",
						"Commit Entry",
						JOptionPane.YES_NO_CANCEL_OPTION);
				if(result == JOptionPane.YES_OPTION) {
					writeEntry();
					clearForm();
					}
				}
			}
		});


		// Verify intent and clear form
		clearButton.addActionListener(new ActionListener() { public void actionPerformed(ActionEvent ae) {
			int result = JOptionPane.showConfirmDialog(myContainer,
						"Clear Form?",
						"Clear",
						JOptionPane.YES_NO_CANCEL_OPTION);
			if(result == JOptionPane.YES_OPTION)
				clearForm();
			}
		});


		// Query for new student name and create student
		newStudentButton.addActionListener(new ActionListener() { public void actionPerformed(ActionEvent ae) {
			String newStudentName = "";
			newStudentName = JOptionPane.showInputDialog(myContainer,"New Student Name");
			if((newStudentName instanceof String) && !newStudentName.equals("") && (newStudentName.charAt(0) != ' ')) 
				createNewStudent(newStudentName);	// myContainer is the top-level container for any warnings
			else
				JOptionPane.showMessageDialog(myContainer,"Name can not begin with a space");
			}
		});


		// Print a student's file
		printButton.addActionListener(new ActionListener() { public void actionPerformed(ActionEvent ae) {
			printStudent(students.getSelectedItem().toString());
			}
		});


		setVisible(true);
	}

	public void paint(Graphics g) {
		super.paint(g);
		g.setColor(Color.blue);
		g.setFont (font);
	}
	
	
	 public static void main(String args[]) {
		new studentTracker();
	 }

}
