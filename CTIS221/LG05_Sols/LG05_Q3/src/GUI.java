import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.ImageIcon;
import javax.swing.JCheckBox;
import javax.swing.JRadioButton;
import javax.swing.ButtonGroup;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextArea;
import javax.swing.JButton;

public class GUI extends JFrame {

	double COST_VIP = 500.0;
	
	private JPanel contentPane;
	private final ButtonGroup buttonGroup = new ButtonGroup();
	private JTextField textField;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI frame = new GUI();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	ImageIcon image1;
	JLabel label;

	/**
	 * Create the frame.
	 */
	public GUI() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 684, 434);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(10, 11, 648, 373);
		contentPane.add(panel);
		panel.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Member Name Surname:");
		lblNewLabel.setBounds(28, 24, 122, 14);
		panel.add(lblNewLabel);
		
		JLabel lblGym = new JLabel("Gym");
		lblGym.setBounds(28, 52, 34, 14);
		panel.add(lblGym);
		
		JComboBox comboBox = new JComboBox();

		comboBox.setModel(new DefaultComboBoxModel(new String[] {"gymFit", "macFit", "sportsInternational"}));
		comboBox.setBounds(74, 49, 164, 22);
		panel.add(comboBox);
		
		JLabel lblNewLabel_1 = new JLabel("VIP Cost: " + COST_VIP + "TL");
		lblNewLabel_1.setBounds(248, 52, 115, 14);
		panel.add(lblNewLabel_1);
		
		JCheckBox chckbxNewCheckBox = new JCheckBox("VIP");
		chckbxNewCheckBox.setBounds(369, 48, 56, 23);
		panel.add(chckbxNewCheckBox);
		
		comboBox.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {				
		        var selectedGym = comboBox.getSelectedItem();
		        
				double old = COST_VIP;
				switch (selectedGym.toString()) {
				case "gymFit": {
					COST_VIP = 500;
					break;
				}
				case "macFit": {
					COST_VIP = 850;
					break;
				}
				case "sportsInternational": {
					COST_VIP = 1000;
				}
				}

				String newText = lblNewLabel_1.getText().replace(String.valueOf(old), String.valueOf(COST_VIP));
				lblNewLabel_1.setText(newText);
				
		        panel.remove(label);
		        
		        image1 = new ImageIcon("C:\\Users\\22303222\\eclipse-workspace\\LG05_Q3\\src\\assets\\" + selectedGym + ".png");
		        label = new JLabel(image1);
		        label.setBounds(448, 82, 151, 75);
		        
		        panel.add(label);
		        
		        panel.revalidate();
		        panel.repaint();
			}
		});
		
		JRadioButton rdbtnNewRadioButton = new JRadioButton("Student");
		rdbtnNewRadioButton.setActionCommand("Student");
		buttonGroup.add(rdbtnNewRadioButton);
		rdbtnNewRadioButton.setBounds(145, 114, 93, 23);
		panel.add(rdbtnNewRadioButton);
		
		JRadioButton rdbtnNewRadioButton_1 = new JRadioButton("Academic");
		rdbtnNewRadioButton_1.setActionCommand("Academic");
		buttonGroup.add(rdbtnNewRadioButton_1);
		rdbtnNewRadioButton_1.setBounds(43, 114, 93, 23);
		panel.add(rdbtnNewRadioButton_1);
		
		JRadioButton rdbtnOther = new JRadioButton("Other");
		rdbtnOther.setActionCommand("Other");
		buttonGroup.add(rdbtnOther);
		rdbtnOther.setBounds(256, 114, 93, 23);
		panel.add(rdbtnOther);
		
		textField = new JTextField();
		textField.setBounds(160, 21, 205, 20);
		panel.add(textField);
		textField.setColumns(10);
		
		image1 = new ImageIcon("C:\\Users\\22303222\\eclipse-workspace\\LG05_Q3\\src\\assets\\gymFit.png");
		label = new JLabel(image1);
		label.setBounds(448, 82, 151, 75);
		panel.add(label);
		
		JTextArea textArea = new JTextArea();
		textArea.setBounds(43, 209, 569, 153);
		panel.add(textArea);
		
		JButton btnNewButton = new JButton("Calculate");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				double calculation = 0;
				if (chckbxNewCheckBox.isSelected()) {
					calculation += COST_VIP;
				}
				
				var membType = buttonGroup.getSelection().getActionCommand();
				
				switch (comboBox.getSelectedItem().toString()){
				case "gymFit": {
					calculation += 52000;
					if (membType.equalsIgnoreCase("Academic")) {
						calculation -= calculation * 20 / 100;
					} else if (membType.equalsIgnoreCase("Student")) {
						calculation -= calculation * 10 / 100;
					} else {
						calculation -= calculation * 5 / 100;
					}
					break;
				}
				case "macFit": {
					calculation += 65000;
					if (membType.equalsIgnoreCase("Academic")) {
						calculation -= calculation * 6 / 100;
					} else if (membType.equalsIgnoreCase("Student")) {
						calculation -= calculation * 3.5 / 100;
					}
					break;
				}
				case "sportsInternational": {
					calculation += 75000;
					if (membType.equalsIgnoreCase("Academic")) {
						calculation -= calculation * 58 / 100;
					} else if (membType.equalsIgnoreCase("Student")) {
						calculation -= calculation * 38 / 100;
					} else {
						calculation -= calculation * 3 / 100;
					}
				}
				}
				
				String output = "Member name: " + textField.getText() + "\n";
				output += "VIP: " + chckbxNewCheckBox.isEnabled() + "\n";
				output += "Fee: " + calculation + "TL"; 
				textArea.setText(output);
			}
		});
		btnNewButton.setBounds(141, 159, 112, 23);
		panel.add(btnNewButton);
	}
}
