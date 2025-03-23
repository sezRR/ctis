import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Calculator extends JFrame {

	private JPanel contentPane;
	private Summation summation = new Summation(this);
	private Subtraction subtraction = new Subtraction(this);

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Calculator frame = new Calculator();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Calculator() {
		setTitle("Calculator");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lbl_selectOperation = new JLabel("Select Operation:");
		lbl_selectOperation.setBounds(162, 65, 96, 14);
		contentPane.add(lbl_selectOperation);
		
		JButton btnSummation = new JButton("+");
		btnSummation.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				summation.setVisible(true);
				setVisible(false);
			}
		});
		btnSummation.setBounds(61, 125, 89, 23);
		contentPane.add(btnSummation);
		
		JButton btnSubtraction = new JButton("-");
		btnSubtraction.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				subtraction.setVisible(true);
				setVisible(false);
			}
		});
		btnSubtraction.setBounds(247, 125, 89, 23);
		contentPane.add(btnSubtraction);
	}
}
