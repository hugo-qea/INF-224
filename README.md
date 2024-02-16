# **Travaux Pratiques - INF224 - Hugo Queniat**

### **Étape 4**
Une méthode qui est déclarée au niveau de la classe de base et qui ne peut pas avoir d'implémentation à ce niveau est dite méthode abstraite. Il est nécessaire de l'implémenter en utilisant dans le fichier header `const = 0`

La classe étant devenue abstraite, il n'est plus possible d'en instancier des éléments.

### **Étape 5**
- La propriété de l'orienté objet qui permet ça ets le polymorphisme qui permet de considérer un objet comme une instance de la classe dont il a été déclaré mais aussi de toute classe dont il hérite.
- En C++, il est nécessaire de déclarer les méthodes de la classe de base comme virtuelles afin que le polymorphisme puisse fonctionner.
- Le type des éléments du tableau doit être des pointeurs vers des objets de la classe de base. Le polymorphisme le nécessite car si le tableau contient des objets, alors il ne saurait pas quelle méthode utiliser. C'est différent de Java où la méthode utilisée est déterminée à l'éxécution en fonction de l'objet réel et pas du type du pointeur.

### **Étape 7**
- Il est nécessaire de modifier la classe `Film` afin que le destructeur de la classe détruise le tableau des chapitres.
- ??

### **Étape 8**
- ??

## **Java**

### **Étape 1**
- Lorsque je retaille la fenêtre les boutons disparaissent ou apparaissent, leur taille ne s'adapte pas à la nouvelle taille de la fenêtre. Le texte ne s'adapte pas non plus et au bout d'un moment on ne peut plus voir les nouvelles lignes.



