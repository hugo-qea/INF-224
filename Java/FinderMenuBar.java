package Java;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

public class FinderMenuBar extends JMenuBar {

    private static final long serialVersionUID = 1L;

    public FinderMenuBar(Finder window) {
        JMenu menu = new JMenu("Menu");

        Action addAction = new AbstractAction("Ajouter une ligne") {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			public void actionPerformed(ActionEvent e) {
            (window.getTextArea()).append("Nouvelle ligne \n");
            }
        };
        JMenuItem menuItem = new JMenuItem(addAction);
        menu.add(menuItem);

        add(menu);
    }
}
