package Java;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JOptionPane;

public class PlayButton extends JButton {

    private static final long serialVersionUID = 1L;
    


    public PlayButton(Finder window) {
        super("Lire");

        addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	String input = JOptionPane.showInputDialog(this, "Nom du média : ");
            	if (input != null) {
                    window.search(input);
            	}
            }
        });
    }
}
