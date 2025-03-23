import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class StringFrame extends JFrame {

	private JPanel contentPane;
	private JTextField textField_firstString;
	private JTextField textField_secondString;
	private JTextField textField_beginIndex;
	private JTextField textField_endIndex;
	private JLabel lbl_newStringResult;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					StringFrame frame = new StringFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	private void clean(JTextArea output, JLabel lbl_newStringResult) {
		textField_firstString.setText("");
		textField_secondString.setText("");
		lbl_newStringResult.setText("");
		output.setText("");
	}
	
	private void concat(JLabel lbl_newStringResult, JTextArea output) {
		String concatenated = textField_firstString.getText().concat(" " + textField_secondString.getText());
		lbl_newStringResult.setText(concatenated);
		output.setText("New String -> " + lbl_newStringResult.getText());
		textField_firstString.setText("");
		textField_secondString.setText("");
	}
	
	private void length(JTextArea output) {
		output.setText("Length of the New String -> " + lbl_newStringResult.getText().length());
	}
	

	private void replace(JTextArea output) {
		String toReplace = textField_firstString.getText();
		String replaceWith = textField_secondString.getText();
		String result = lbl_newStringResult.getText().replace(toReplace, replaceWith);
		lbl_newStringResult.setText(result);
		
		output.setText("Replaced!\n"
				+ "New String -> " + lbl_newStringResult.getText());
	}
	
	private void substring(JTextArea output) {
		int startIndex = Integer.parseInt(textField_beginIndex.getText());
		int endIndex = Integer.parseInt(textField_endIndex.getText());
		output.setText("Characters between the range -> " + lbl_newStringResult.getText().substring(startIndex, endIndex));
	}
	
	private void toUpperCase(JTextArea output) {
		output.setText("Converted to Upper Case letters!\n" +
				"New String is -> " + lbl_newStringResult.getText().toUpperCase());
	}
	
	private void toLowerCase(JTextArea output) {
		output.setText("Converted to Lower Case letters!\n" +
				"New String is -> " + lbl_newStringResult.getText().toLowerCase());
	}
	
	private void trim(JTextArea output) {
		output.setText("Trimmed!\n" +
					"First String -> " + lbl_newStringResult.getText().trim());
	}
	
	/**
	 * Create the frame.
	 */
	public StringFrame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 671, 402);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lbl_SecondString = new JLabel("Second String:");
		lbl_SecondString.setBounds(76, 82, 82, 14);
		contentPane.add(lbl_SecondString);
		
		JLabel lbl_FirstString_1 = new JLabel("First String: ");
		lbl_FirstString_1.setBounds(76, 60, 82, 14);
		contentPane.add(lbl_FirstString_1);
		
		textField_firstString = new JTextField();
		textField_firstString.setBounds(212, 57, 165, 20);
		contentPane.add(textField_firstString);
		textField_firstString.setColumns(10);
		
		textField_secondString = new JTextField();
		textField_secondString.setColumns(10);
		textField_secondString.setBounds(212, 90, 165, 20);
		contentPane.add(textField_secondString);
		
		JButton btnConcatenate = new JButton("Concatenate");

		btnConcatenate.setBounds(152, 151, 106, 23);
		contentPane.add(btnConcatenate);
		
		JButton btnFindLength = new JButton("Find Length");
		btnFindLength.setBounds(268, 151, 89, 23);
		contentPane.add(btnFindLength);
		
		JButton btnReplace = new JButton("Replace");
		btnReplace.setBounds(401, 151, 89, 23);
		contentPane.add(btnReplace);
		
		JButton btnReplaceWord = new JButton("Replace Word");
		btnReplaceWord.setBounds(525, 151, 99, 23);
		contentPane.add(btnReplaceWord);
		
		JButton btnSubstring = new JButton("Substring");
		btnSubstring.setBounds(152, 204, 89, 23);
		contentPane.add(btnSubstring);
		
		JButton btnUpperCase = new JButton("Upper Case");
		btnUpperCase.setBounds(268, 204, 89, 23);
		contentPane.add(btnUpperCase);
		
		JButton btnLowerCase = new JButton("Lower Case");
		btnLowerCase.setBounds(401, 204, 89, 23);
		contentPane.add(btnLowerCase);
		
		JButton btnTrim = new JButton("Trim");
		btnTrim.setBounds(525, 204, 89, 23);
		contentPane.add(btnTrim);
		
		JLabel lbl_beginIndex = new JLabel("Begin Index:");
		lbl_beginIndex.setBounds(10, 204, 82, 14);
		contentPane.add(lbl_beginIndex);
		
		JLabel lbl_endIndex = new JLabel("End Index:");
		lbl_endIndex.setBounds(10, 236, 82, 14);
		contentPane.add(lbl_endIndex);
		
		textField_beginIndex = new JTextField();
		textField_beginIndex.setText("0");
		textField_beginIndex.setBounds(81, 205, 43, 20);
		contentPane.add(textField_beginIndex);
		textField_beginIndex.setColumns(10);
		
		textField_endIndex = new JTextField();
		textField_endIndex.setText("0");
		textField_endIndex.setColumns(10);
		textField_endIndex.setBounds(76, 233, 43, 20);
		contentPane.add(textField_endIndex);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(20, 264, 605, 88);
		contentPane.add(scrollPane);
		
		JTextArea output = new JTextArea();
		scrollPane.setViewportView(output);
		
		JLabel lbl_newString = new JLabel("New String:");
		lbl_newString.setBounds(76, 126, 82, 14);
		contentPane.add(lbl_newString);
		
		lbl_newStringResult = new JLabel("");
		lbl_newStringResult.setBounds(212, 126, 390, 14);
		contentPane.add(lbl_newStringResult);
		
		JButton btnClean = new JButton("Clean");
		btnClean.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				clean(output, lbl_newStringResult);
			}
		});
		btnClean.setBounds(46, 151, 89, 23);
		contentPane.add(btnClean);
		
		btnConcatenate.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				concat(lbl_newStringResult, output);
			}
		});
		
		btnFindLength.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				length(output);
			}
		});
		
		btnReplace.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				replace(output);
			}
		});
		
		btnReplaceWord.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				replace(output);
			}
		});
		
		btnSubstring.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				substring(output);
			}
		});
		
		btnUpperCase.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				toUpperCase(output);
			}
		});
		
		btnLowerCase.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				toLowerCase(output);
			}
		});
		
		btnTrim.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				trim(output);
			}
		});
	}
}
