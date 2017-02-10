/**
 * @file
 * This class is a windows playing the role of the Client in the C++ set-top box/remote communication scheme of the project.
 */

import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;

public class MainFrame extends JFrame{

	public static void main(String[] args){ MainFrame frame = new MainFrame();}
	
	private static final long serialVersionUID = 1L;
	private final JButton button1 = new JButton("Yes");
	private final JButton button2 = new JButton("No");
	private final JButton button3 = new JButton("Stop app");
	private final JTextArea textArea = new JTextArea();
	
	public MainFrame(){
		super();
		//set default parameters of the window
		this.setTitle("BandMaster");
		this.setLocationRelativeTo(null);
		this.setResizable(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//stop program when window is closed
		this.pack();//auto-resize
		
		//Create the layout of the page.
		JPanel MainPanel = new JPanel();
		MainPanel.setLayout(new BoxLayout(MainPanel, BoxLayout.PAGE_AXIS));
		
		//One layout for the buttons
		JPanel ButtonPanel = new JPanel();
		ButtonPanel.add(button1);
		ButtonPanel.add(button2);
		ButtonPanel.add(textArea);
		textArea.setSize(900, 100);
		textArea.setLineWrap(true);
		textArea.setText("Welcome to Benjamin LAZARD's fantastic GUI");
		//textArea.setFont(Font.truc);
		
		//Another one for the text area
		//JPanel P1 = new JPanel();
		//P1.setLayout(new BoxLayout(P1, BoxLayout.PAGE_AXIS));
		//P1.add(textArea);
		JScrollPane pane = new JScrollPane(textArea);
		pane.setSize(textArea.getSize());
		
		//Assembly
		MainPanel.add(ButtonPanel, BorderLayout.CENTER);
		MainPanel.add(pane, BorderLayout.SOUTH);
		this.setContentPane(MainPanel);
		this.setVisible(true);
		
		/**
		 * set Listeners (anonymous embedded class)
		 */
		button1.addMouseListener(new MouseListener() {
			@Override
			public void mouseReleased(MouseEvent arg0){}
			@Override
			public void mousePressed(MouseEvent arg0){}
			@Override
			public void mouseExited(MouseEvent arg0){}
			@Override
			public void mouseEntered(MouseEvent arg0){}
			
			@Override
			public void mouseClicked(MouseEvent arg0){
				textArea.append("\n" + button1.getText());
			}
		});
		button2.addMouseListener(new MouseListener() {
			@Override
			public void mouseReleased(MouseEvent arg0){}
			@Override
			public void mousePressed(MouseEvent arg0){}
			@Override
			public void mouseExited(MouseEvent arg0){}
			@Override
			public void mouseEntered(MouseEvent arg0){}
			
			@Override
			public void mouseClicked(MouseEvent arg0){
				textArea.append( "\n" + button2.getText());
			}
		});
		button3.addMouseListener(new MouseListener() {
			@Override
			public void mouseReleased(MouseEvent arg0){}
			@Override
			public void mousePressed(MouseEvent arg0){}
			@Override
			public void mouseExited(MouseEvent arg0){}
			@Override
			public void mouseEntered(MouseEvent arg0){}
			
			@Override
			public void mouseClicked(MouseEvent arg0){
				System.exit(1);
			}
		});
		
		this.setSize(900, 500);
	}
	

}
