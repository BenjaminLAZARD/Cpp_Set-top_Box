import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Action;
import javax.swing.Icon;
import javax.swing.JMenuItem;


/**
 * @file
 * @author Benjamin
 * @brief Menu Item for the main window
 *
 */
public final class QuitMenuItem extends JMenuItem implements ActionListener {
	private final MainFrame mainframe;
	
	public QuitMenuItem(MainFrame mainframe) {
		super("Quit the set-top box") ;
		this.mainframe = mainframe;
		addActionListener(this) ;
		
	}

	@Override
	public void actionPerformed(ActionEvent arg0){
		mainframe.leave();

	}

}
