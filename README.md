# semaforo-oop-arduino
prototipo di una classe con la possibilita di creare dei semafori come oggetti in arduino
per creare un oggetto si specifica in questo ordine: numerodel pin rosso, di quello giallo e di quello verde, oltre a la fase iniziale
le fasi vanno da 1 a 4 e rappresentano: 1->verde; 2->giallo; 3->rosso; 4->rosso
sono diponibili funzioni per:
spegnere il semaforo con spegni().
accendere il singolo colore con rosso(), giallo(), verde().
rFase() per riportare l'avanzamento di stato al valore specificato nella creazione dell'oggetto.
avanza() per far avanzare il valore della fase.
accendi() per applicare il cambio di fase nella realtà.
