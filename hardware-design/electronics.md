
Tα ηλεκτρονικά κυκλώματα βρίσκονται πίσω από τον  **πίνακα ελέγχου θερμοκρασίας** (control panel) του πυρηνικού αντιδραστήρα

![πίνακας ελέγχου  θερμοκρασίας πυρηνικού αντιδραστήρα](/assets/images/control-panel-c.jpg)

πίσω από το κουτί...

![πίνακας ελέγχου  θερμοκρασίας πυρηνικού αντιδραστήρα](/assets/images/in.jpg)


Συνδέουμε το arduino ως εξής:
> - **1.**	**Pin 5V** στο arduino με pin στο **bus ανόδου (+)** στο breadboard με **κόκκινο καλώδιο**

> - **2.**	**GRD pin** στο arduino με pin στο **bus της καθόδου (-)**  στο breadboard  **με μαύρο καλώδιο**

> - **3.**	Tα digital pins (0,1,2,3,4,5,6,7,8,9,10,11,12,13) μπορούν να διακρίνουν 2 καταστάσεις HIGH (υπάρχει δυναμικό) και LOW (μηδέν δυναμικό). Μπορούν να  συμπεριφέρονται σαν **INPUTS** (δηλ. διαβάζουν δυναμικό   ή **OUTPUTS** (δηλ. δίνουν δυναμικό π.χ. συνδέουμε LEDs). 

> - **4.**	Συνδέουμε τo ένα **LED** ως εξής: 
κάθοδος (κοντό πόδι)  στο κάθοδος bus(-)  μέσω αντίστασης R= 220 Ω, 
άνοδος (μακρύ πόδι) στο digital pin 2

> - **5.**	Oμοίως συνδέουμε άλλα 2 LEDs στα digital pins  3 και 4

> - **6.**	Συνδέουμε έναν **ανιχνευτή θερμοκρασίας** ως εξής:

   a.το αριστερό άκρο του ανιχνευτή θερμότητας στο **κάθοδος bus (-)** με μαύρο καλώδιο
 
   b.δεξί άκρο του ανιχνευτή θερμότητας στο **άνοδος bus (+)** με κόκκινο καλώδιο
 
   c.το μεσαίο άκρο στο αναλογικό Α0 pin του Arduino γιατί μετράει ένα αναλογικό μέγεθος όπως είναι η Θερμοκρασία
 
 
 
 > - **7.**	 Συνδέουμε έναν **αντάπτορα** για να συνδέσουμε **ηχεία** ως εξής: το ένα άκρο  στο **κάθοδος bus (-)**  μέσω του μαύρου καλωδίου το άλλο άκρο στο **pin 8** για να παραγει ήχο το arduino μέσω της συνάρτησης tone.
 
![πίνακας ελέγχου  αντιδραστήρα](/assets/images/electronics.png)

Συνδέουμε και τα **2 servo motors** που θα στρέψουν τους σωλήνες με νερό πάνω στον πυρηνικό αντιδραστήρα
Για κάθε servo motor συνδέουμε:
> - 1.	Το κόκκινο καλώδιο  στο pin 5V στο arduino   ή  στο bus ανόδου (+) στο breadboard 
> - 2.	Το πιο σκούρο καλώδιο στο GRD  pin στο arduino ή στο bus της καθόδου (-)  στο breadboard  
> - 3.	To ανοιχτόχρωμο καλώδιο στα digital pins 12 και 13 αντιστοίχως για τα 2 servo motors

