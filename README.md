ΕΠΑΛ ΚΙΣΑΜΟΥ-ΓΕΛ ΚΙΣΑΜΟΥ

ΛΙΓΑ ΛΟΓΙΑ ΓΙΑ ΤΗΝ ΠΕΡΙΠΕΤΕΙΑ ΤΗΣ ΚΑΤΑΣΚΕΥΗΣ ΜΑΣ
Η αναζήτηση άρχισε με σκοπό τη κατασκευή ενός solar tracker όπως του συναδέλφου https://www.thingiverse.com/thing:53321
ή https://www.instructables.com/id/Arduino-Solar-Tracker/ .
ΟΜΩΣ όλες αυτές οι κατασκευές είναι για εσωτερικό χώρο και για λόγους επίδειξης και όχι για ένα πραγματικό solar tracker.
Και εδώ μπήκαμε στην μεγάλη περιπέτεια κατασκευής ενός πραγματικού solar tracker και ως φυσική συνέπεια (ο καθηγητής μας είναι φυσικός και του αρέσει η αστροφυσική) και solar path finder- επιστημονικό εργαλείο εύρεσης των γωνίων που διαγράφει ο ΗΛΙΟΣ στην περιοχή μας.
ΚΑΙ ΑΝΑΣΧΕΔΙΑΣΑΜΕ ΤΑ ΠΑΝΤΑ ΕΞ ΑΡΧΗΣ!!!


Η ηλιακή ενέργεια αποτελεί ανανεώσιμη πηγή ενέργειας με πρόσφορη μέθοδο χρησιμοποίησή της τα φωτοβολταϊκά πάνελ. Όμως ο ήλιος αποδίδει τα μέγιστα μόνο όταν «πέφτει» κάθετα στο πάνελ, έτσι ψάχνουμε τρόπο να ακολουθεί το πάνελ τις ακτίνες του ήλιου. Ένας τρόπος παρακολούθησης του είναι με φωτοευαίσθητες αντιστάσεις οι οποίες παρακολουθούνται από τον μικροελεγκτή arduino και με servo ο μικροελεγκτής προσαρμόζει το πάνελ ώστε οι ακτίνες να πέφτουν κάθετα.

Υλικά (τελικός απολογισμός) :

1.arduino uno (https://grobotronics.com/funduino-uno-rev3-arduino-uno-compatible.html) = € 11.90 
2.   4 ldr (https://grobotronics.com/photo-resistor-ldr-5mm.html)=4*0,20=€ 0,80
3.  2 servo (link:  https://grobotronics.com/servo-small-5kg.cm-metal-gears-with-analog-feedback-feetech-fs9225m.html
https://grobotronics.com/analog-feedback-micro-servo-plastic-gear.html
 )=€9.90+€12.20=€21,10
4.wires (https://grobotronics.com/jumper-wires-15cm-female-to-male-pack-of-10.html ΚΑΙ https://grobotronics.com/jumper-wires-15cm-male-to-male-pack-of-10.html)=2*€1.80=€ 3,30
5..breadboard (link: https://grobotronics.com/breadboard-400-tie-point-white-half-size.html ) =€3.20
6.Bluetooth Module for Arduino - HC05 (https://grobotronics.com/bluetooth-module-for-arduino-hc05.html) =€6.80
6.Πλαστικά γρανάζια απο 3D εκτυπωτή του εκφέ χανίων (ΤΑ STL ΑΡΧΕΙΑ ΠΕΡΙΛΑΜΒΑΝΟΝΤΑΙ ΩΣ ST1,ST2,..)
ΕΝΔΕΙΚΤΙΚΟ ΣΥΝΟΛΟ=€43,90
ΣΕ ΕΞΩΤΕΡΙΚΟ ΧΩΡΟ ΠΟΥ ΤΟ ΔΟΚΙΜΑΣΑΜΕ ΔΙΑΠΙΣΤΩΣΑΜΕ ΟΤΙ ΘΑ ΧΡΕΙΑΣΤΕΙ ΚΑΙ ΕΝΑ ΓΥΑΛΙΝΟ ΣΚΕΠΑΣΜΑ
 

ΠΕΡΙΓΡΑΦΗ ΠΡΟΒΛΗΜΑΤΟΣ
Η εποχή μας απαιτεί μεγάλα ενεργειακά αποθέματα , έτσι ένα αποδοτικό φωτοβολταικό πάνελ που ακολουθεί τον ήλιο μας δείχνει τον δρόμο στους κατασκευαστές φωτοβ.συστημάτων.Πόσο μάλλον όταν το πρότζεκτ μας καταγράφει τις γωνίες που δημιουργεί ο ήλιος στο στερέωμα στο καστέλι κισάμου και έτσι δείχνει ανα ημέρα και ώρα την κατάλληλη γωνία που πρέπει να έχει το φ. πάνελ για μέγιστη απόδοση.

Το μοίρασμα της γνώσης προτεραιότητα μας!
Μια επιστημονική εργασία αυτού του είδους εκπαιδεύει τους μελλοντικούς μας επιστήμονες στο διαθεματικό πλαίσιο STEM-ΘΕΤΙΚΕΣ ΕΠΙΣΤΗΜΕΣ-ΡΟΜΠΟΤΙΚΗ.
ΑΚΟΛΟΥΘΩΝΤΑΣ ΤΟ ΜΟΝΟΠΑΤΙ ΤΟΥ ΗΛΙΟΥ
Σε συνέχεια της προηγούμενης απάντησης η ιδέα μας είναι να κατασκευάσουμε ένα ηλιακό ανιχνευτή της πορείας του ήλιου που θα προσαρμόζει το φωτοβολταικό πάνελ μας κάθετα στις ακτίνες του ήλιου για να έχει την μέγιστη απόδοση και ταυτόχρονα θα καταγράφει τις γωνίες αυτές.Θα χρησιμοποιήσουμε 4 ldr φωτοαντιστάσεις-οι αισθητήρες φωτός που ανάλογα με το φως που λαμβάνουν θα δίνουν εντολή να στραφεί το πάνελ μας στη σωστή θέση- 2 σερβομηχανισμούς για να εκτελούν τις παραπάνω εντολές και θα αποτελούν συνάμα αισθητήρες κλίσης για την καταγραφή αυτών των γωνιών. Φυσικά και arduino που είναι ο εγκέφαλος της κατασκευής μας.
3D εκτυπωμένα εξαρτήματα θα δώσουν σταθερότητα και αποδοτικότητα στην κατασκευή μας.
Η ομάδα μας αποτελείται απο 3 μαθητές του ΓΕΛ Κισάμου β λυκείου με θαυμαστή όρεξη για μάθηση.
ΑΘΗΝΑ ΑΘΟΥΣΑΚΗ
ΣΤΕΛΛΑ ΑΜΠΟΥΧΑΝΗ
ΣΠΥΡΟΣ ΕΙΡΗΝΑΚΗΣ
Τα κορίτσια είναι οι προγραμματίστριες του arduino και ο Σπύρος το πρακτικό μυαλό.
(Βέβαια οι απαιτήσεις του έργου ήταν να αναμιχθούν όλοι σε όλα τα στάδια της κατασκευής)
Ο Σπύρος βοήθησε και στο 3D σχεδιασμό εξαρτημάτων.
ΒΙΒΛΙΟΓΡΑΦΙΚΕΣ ΑΝΑΦΟΡΕΣ
1) https://en.wikipedia.org/wiki/Sun_path
2)https://en.wikipedia.org/wiki/Position_of_the_Sun
3)https://www.youtube.com/watch?v=lJVEubm9Ja8
4)https://www.instructables.com/id/Arduino-Solar-Tracker/

LINK ΠΟΥ ΒΟΗΘΗΣΕ ΣΤΗΝ ΒΑΘΜΟΝΟΜΗΣΗ-CALIBRATION SERVO : https://dronebotworkshop.com/analog-feedback-servo-motor/

ΓΙΑ ΤΟΝ ΔΙΑΓΩΝΙΣΜΟ ΤΗΣ ΕΛΛΑΚ ΠΑΡΑΠΕΜΠΩ ΣΤΟ GITHUB ΤΗΣ ΜΑΘΗΤΡΙΑΣ ΑΘΗΝΑΣ ΑΘΑΝΑΚΗ: https://github.com/Ampirath/Solar-Tracker
VIDEO LINK:  https://www.youtube.com/watch?v=TfUpVVRkGPY
ΜΑΘΗΤΕΣ : ΑΘΗΝΑ ΑΘΑΝΑΣΑΚΗ,ΣΤΕΛΛΑ ΑΜΠΟΥΧΑΝΗ ΚΑΙ ΣΠΥΡΟΣ ΕΙΡΗΝΑΚΗΣ-ΓΕΛ ΚΙΣΑΜΟΥ,ΕΠΑΛ ΚΙΣΑΜΟΥ


