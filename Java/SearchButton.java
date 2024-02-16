package Java;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JOptionPane;

public class SearchButton extends JButton {

    private static final long serialVersionUID = 1L;


    public SearchButton(Finder window) {
        super("Rechercher");

        addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	String input = JOptionPane.showInputDialog(this, "Nom du média/groupe : ");
            	if (input != null) {
                    window.search(input);
            	}


            }
        });
    }
}
