import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JMenuItem;


/**
 * @file
 * @author Benjamin
 * @brief Menu Item for the main window
 *
 */
public final class QuitMenuItem extends JMenuItem implements ActionListener {
	private static final long serialVersionUID = 1L;
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
