package Java;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JButton;
import javax.swing.JToolBar;

public class FinderToolBar extends JToolBar {

    private static final long serialVersionUID = 1L;

    public FinderToolBar(Finder window) {
        Action addAction = new AbstractAction("Ajouter une ligne") {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void actionPerformed(ActionEvent e) {
                (window.getTextArea()).append("Nouvelle ligne\n");
            }
        };

        JButton addButton = new JButton(addAction);
        add(addButton);
    }
}
