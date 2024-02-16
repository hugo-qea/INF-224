package Java;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;

public class QuitButton extends JButton {

    private static final long serialVersionUID = 1L;

    public QuitButton() {
        super("Quitter");

        addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
    }
}
