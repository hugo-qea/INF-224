package Java;

import javax.swing.*;
import java.awt.*;
import java.io.IOException;
import java.net.UnknownHostException;


public class Finder extends JFrame {

    private static final long serialVersionUID = 1L;

    private JTextArea textArea;
    private SearchButton searchButton;
    private PlayButton playButton;
    private QuitButton quitButton;
	private Client client;

    public Finder() {
        super("Finder");

        // Créer un client pour communiquer avec le serveur
		try {
			client = new Client(Client.DEFAULT_HOST, Client.DEFAULT_PORT);
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

        // Créer une barre de menuq
        JMenuBar menuBar = new FinderMenuBar(this);

        // Ajouter la barre de menus à la fenêtre
        setJMenuBar(menuBar);

        // Créer une barre d'outils
        JToolBar toolBar = new FinderToolBar(this);

        // Ajouter la barre d'outils à la fenêtre
        add(toolBar, BorderLayout.NORTH);

        // Créer une zone de texte multi-lignes
        textArea = new JTextArea(10, 20);

        // Ajouter la zone de texte à un JScrollPane pour permettre le scrolling
        JScrollPane scrollPane = new JScrollPane(textArea);

        // Ajouter le JScrollPane à la fenêtre
        add(scrollPane, BorderLayout.CENTER);

        // Créer un conteneur pour les boutons
        JPanel buttonPanel = new JPanel();

        // Ajouter les boutons au conteneur
        searchButton = new SearchButton(this);
        buttonPanel.add(searchButton);

        playButton = new PlayButton(this);
        buttonPanel.add(playButton);

        quitButton = new QuitButton();
        buttonPanel.add(quitButton);

        // Ajouter le conteneur à la fenêtre
        add(buttonPanel, BorderLayout.SOUTH);

        // Configurer la fermeture de l'application lorsque la fenêtre est fermée
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Calculer la disposition spatiale des composants graphiques
        pack();

        // Faire apparaître l'interface
        setVisible(true);

        System.setProperty("apple.laf.useScreenMenuBar", "true");
		
    }

    public void search(String name) {
        // Envoi de la commande "search nom_du_fichier" au serveur
        String request = "search " + name;
        String response = client.send(request);

        // Affichage de la réponse sur l'interface graphique
        textArea.setText(response);
    }

    public void play(String name) {
        // Envoi de la commande "play nom_du_fichier" au serveur
        client.send("play " + name);
    }

	public JTextArea getTextArea() {
		// TODO Auto-generated method stub
		return textArea;
	}
}
