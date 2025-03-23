import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Subtraction extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	private JTextField textField_1;


	public Subtraction(Calculator calc) {
		setTitle("Subtraction");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 587, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		textField = new JTextField();
		textField.setColumns(10);
		textField.setBounds(10, 106, 136, 20);
		contentPane.add(textField);
		
		JLabel lblNewLabel = new JLabel("-");
		lblNewLabel.setFont(new Font("Tahoma", Font.BOLD, 24));
		lblNewLabel.setBounds(156, 96, 20, 29);
		contentPane.add(lblNewLabel);
		
		textField_1 = new JTextField();
		textField_1.setColumns(10);
		textField_1.setBounds(186, 106, 136, 20);
		contentPane.add(textField_1);
		
		JButton btnNewButton = new JButton("=");
		btnNewButton.setBounds(342, 105, 41, 23);
		contentPane.add(btnNewButton);
		
		JLabel result = new JLabel("");
		result.setBounds(406, 109, 46, 14);
		contentPane.add(result);
		
		JButton btnNewButton_1 = new JButton("<-");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
				calc.setVisible(true);
			}
		});
		btnNewButton_1.setBounds(489, 105, 45, 23);
		contentPane.add(btnNewButton_1);
		
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				result.setText(String.valueOf(Integer.parseInt(textField.getText()) - Integer.parseInt(textField_1.getText())));
			}
		});
	}

}
