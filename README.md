ΕΠΑΛ ΚΙΣΑΜΟΥ-ΓΕΛ ΚΙΣΑΜΟΥ

ΑΥΤΟ ΤΟ BRANCH είναι μια εναλλακτική προσέγγιση του master branch και χρησιμοποιεί ως πρόγραμμα .ino το Dual_Axis_Tracker_V2nektariosfinalgelunoplus6050plus2b.ino (τα άλλα .ino τα κρατάω εδώ για αρχειακούς λόγους).

Η κατασκευή γίνεται όπως περιγράφεται στο https://openedtech.ellak.gr/robotics2020/solar-tracker-epal-kisamou/
απλά τα stl αρχεία είναι λίγο διαφορετικά για να "μπαίνουν" τα απλά servo και όχι τα analogfeedback που έχουμε στο master branch.
Η ανίχνευση των γωνιών του ήλιου γίνεται με δύο τρόπους α) απο το απλό σερβο -για την γωνία azimuth- και για την γωνία altitude από το mpu6050 και β)για την γωνία azimuth και για την γωνία altitude από το mpu9250 -κολλημένο στο πάνελ- με έξτρα MCU για την σύνδεσή του αλλά με τον πρόσθετο πλεονέκτημα ότι δεν χρειάζεται προσανατολισμό βορά νότου η συσκευή μας.

Πιθανά υλικά :

1.arduino uno (https://grobotronics.com/funduino-uno-rev3-arduino-uno-compatible.html =11,9 euro) και mega
2.   4 ldr  (https://grobotronics.com/photo-resistor-ldr-5mm.html)=4*0,20=€ 0,80 
3.  2 servo (link:  https://grobotronics.com/servo-micro-2.2kg.cm-plastic-gears-waveshare-sg90.html =3,60 euro)
4.wires  (https://grobotronics.com/jumper-wires-15cm-female-to-male-pack-of-10.html ΚΑΙ https://grobotronics.com/jumper-wires-15cm-male-to-male-pack-of-10.html)=2*€1.80=€ 3,30
5..breadboard (link: https://grobotronics.com/breadboard-400-tie-point-white-half-size.html ) =€3.20

6.Bluetooth Module for Arduino - HC05 (https://grobotronics.com/bluetooth-module-for-arduino-hc05.html) =€6.80

7. αντιστάσεις 1kohm (https://grobotronics.com/carbon-1-4w-5-1kohm.html) = €0,04
8.αισθητήρας κλίσης -https://grobotronics.com/gy-521-mpu6050-3-axis-gyroscope-and-accelerometer-imu.html =4,9 ευρώ
9.Πλαστικά γρανάζια απο 3D εκτυπωτή του εκφέ χανίων-δωρεάν χορήγηση
10.solar panel https://grobotronics.com/solar-panel-3.5w-165x135mm.html =12,9 euro
ΕΝΔΕΙΚΤΙΚΟ  ΣΥΝΟΛΟ: 57 ευρώ

Ψάχνοντας έναν εναλλακτικό τρόπο μέτρησης των γωνιών συνδέσαμε-κολλήσαμε κάτω από το πάνελ έναν αισθητήρα mpu9050 sparfun και το συνδέσαμε με ένα διπλανό arduino -https://www.hellasdigital.gr/electronics/components/boards/sparkfun-imu-breakout-mpu-9250-sen-13762/ =€14,95 - όπου το εκπληκτικό είναι αφού προσαρμόσαμε την βιβλιοθήκη (περιγράφεται στο master2 ) που βρήκαμε στο τόπο(συντεταγμένες) εγκαθίδρυσης της κατασκευής μας με ένα καλιμπράρισμα (το 8 που κάνουμε και στο κινητό μας ) βρίσκει με την αυτόματα τις κλίσεις σε σχέση με τον πραγματικό βορά . Δηλαδή και λάθος να τοποθετήσουμε την συσκευή μας - κανονικά  πρέπει να χει προσανατολισμό βορά νότου όπως περιγράφω στις οδηγίες χρήσης master branch- βρίσκει τις σωστές γωνίες που σχηματίζει ο Ήλιος.

ΒΙΒΛΙΟΓΡΑΦΙΚΕΣ ΑΝΑΦΟΡΕΣ
1) https://en.wikipedia.org/wiki/Sun_path
2)https://en.wikipedia.org/wiki/Position_of_the_Sun
3)https://www.youtube.com/watch?v=lJVEubm9Ja8


Ο ΔΕΥΤΕΡΟΣ ΑΙΣΘΗΤΗΡΑΣ ΣΥΝΔΕΜΕΝΟΣ ΣΤΟ MEGA ΧΡΗΣΙΜΟΠΟΙΕΙ ΤΗΝ ΒΙΒΛΙΟΘΗΚΗ:
I2C device class (I2Cdev) demonstration Arduino sketch for MPU9250 class using DMP (MotionApps v2.0)
// 6/21/2012 by Jeff Rowberg <jeff@rowberg.net>
// Updates should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib



