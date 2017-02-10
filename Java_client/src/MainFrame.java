/**
 * @file
 * This class is a windows playing the role of the Client in the C++ set-top box/remote communication scheme of the project.
 */

import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.event.*;

public class MainFrame extends JFrame{

	public static void main(String[] args){ new MainFrame();}
	
	private static final long serialVersionUID = 1L;
	private final JTextArea textArea = new JTextArea();
	private JTextField queryField = new JTextField(50);
	private Remote remote = null;
	
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
		MainPanel.add(pane, BorderLayout.CENTER);
		this.setContentPane(MainPanel);
		this.setVisible(true);
		
		
		//create menu
		JMenuBar bar = new JMenuBar();
		JMenu menu = new JMenu("Menu"); JToolBar toolBar = new JToolBar("toolbar");
		menu.add(new QuitMenuItem(this));
		
		//create actions with same functions than above
		My_Action action1 = new My_Action("Search (by medium/album name)", My_Action.SEARCH);
		menu.add(action1); toolBar.add(action1);
		My_Action action2 = new My_Action("Play a medium", My_Action.PLAY);
		menu.add(action2); toolBar.add(action2);
		My_Action action3 = new My_Action("Re-Connect", My_Action.CONNECT);
		menu.add(action3); toolBar.add(action3);
		
		//Add a TextField
		JLabel queryLabel = new JLabel("Please enter the name of a medium, then select an option from the toolbar");
		ButtonPanel.add(queryLabel);
		ButtonPanel.add(queryField);
		
		//add Menu
		bar.add(menu);  bar.add(toolBar);
		setJMenuBar(bar);
		
		this.setSize(900, 500);
		
		//create the client
		this.tryToConnect();
	}
	
	public final void leave(){
		System.exit(1);
	}
	
	public final void tryToConnect(){
		try {
	      remote = new Remote(Remote.DEFAULT_HOST, Remote.DEFAULT_PORT);
	      System.out.println("Remote connected to set-top box at "+Remote.DEFAULT_HOST+":"+Remote.DEFAULT_PORT );
	      textArea.append("\n"  + "Remote connected to set-top box at "+Remote.DEFAULT_HOST+":"+Remote.DEFAULT_PORT );
	    }
	    catch (Exception e1) {
	      System.err.println("Remote couldn't connect to "+Remote.DEFAULT_HOST+":"+Remote.DEFAULT_PORT);
	      textArea.append("\n"  + "Remote couldn't connect to "+Remote.DEFAULT_HOST+":"+Remote.DEFAULT_PORT);
	    }
	}
	
	/**
	 * 
	 * @author Benjamin
	 * @brief an action that behaves differently depending on its initialization
	 * 
	 * The asset of this technique is clarity for the the code above
	 */
	class My_Action extends AbstractAction{
		private static final long serialVersionUID = 1L;
		private static final String SEARCH = "SEARCH$";
		private static final String PLAY = "PLAY$";
		private static final String CONNECT = "CONNECT";
		private String action = "";
		
		private String title = "";
		
		public My_Action(String title, String action) {
			super(title);//does not seem to work well
			this.action = action;
			this.title = title;
		}

		@Override
		public void actionPerformed(ActionEvent e){
			String query_name;
			switch (action) {
				case SEARCH:
					query_name = queryField.getText();
					if (query_name == "" || query_name == null || remote == null) {
						textArea.append("\n"  + "Please enter a name in the field above and make sure you are connected, prior to any query");
					}
					else {
						String response = remote.query(SEARCH + query_name);
						textArea.append("\n"  + response);
					}
					break;
					
					
				case PLAY:
					query_name = queryField.getText();
					if (query_name == "" || query_name == null || remote == null) {
						textArea.append("\n"  + "Please enter a name in the field above and make sure you are connected, prior to any query");
					}
					else {
						String response = remote.query(PLAY + query_name);
						textArea.append("\n"  + response);
					}
					break;
					
					
				case CONNECT:
					if (remote == null) {tryToConnect();}
					else {textArea.append("\n"  + "You are already connected");}					
					break;
				default:
					break;
			}	
		}
		
		public String getTitle(){return title;}
		public String getAction(){return action;}
	}

}
