class semaforo
{
private:
    short const pinRosso, pinGiallo, pinVerde, valoreReset; // contenitori dei pin e del valore di reset
    short int fase;                                         // 1->verde; 2->giallo; 3->rosso; 4->rosso;
public:
    void avanza()
    { // fa avanzare lo stato del semaforo
        fase++;
        if (fase > 4)
        {
            fase = 1;
        }
    }
    void rFase()
    { // funzione che fa ripartire dalla fase iniziale
        fase = valoreReset;
    }
    void rosso()
    {
        digitalWrite(pinRosso, HIGH);
        digitalWrite(pinVerde, LOW);
        digitalWrite(pinGiallo, LOW);
    }
    void verde()
    {
        digitalWrite(pinRosso, LOW);
        digitalWrite(pinVerde, HIGH);
        digitalWrite(pinGiallo, LOW);
    }
    void giallo()
    {
        digitalWrite(pinRosso, LOW);
        digitalWrite(pinVerde, LOW);
        digitalWrite(pinGiallo, HIGH);
    }
    void spegni()
    {
        digitalWrite(pinRosso, LOW);
        digitalWrite(pinVerde, LOW);
        digitalWrite(pinGiallo, LOW);
    }
    void accendi()
    { // accende il led corrispondente alla fase
        spegni();
        switch (fase)
        {
        case 1:
            verde();
            break;

        case 2:
            giallo();
            break;

        case 3:
        case 4:
            rosso();
            break;
        }
    }
    semaforo(int const r, int const g, int const v, int const res) : pinRosso(r), pinGiallo(g), pinVerde(v), valoreReset(res)
    { // constructor che chiede pin, fase di inizio e fa operazioni di routine
        pinMode(r, OUTPUT);
        pinMode(g, OUTPUT);
        pinMode(v, OUTPUT);
        rFase();
    }
};

#define puls 3
volatile bool interr = 0; // necessario per utilizzare l'interrupt

semaforo s1(0, 1, 2, 1);
semaforo s2(4, 5, 6, 3);

void setup()
{
    pinMode(puls, INPUT);
    attachInterrupt(digitalPinToInterrupt(puls), reset, RISING); // interrupt di reset
    lampeggia();
}
void loop()
{
    s1.accendi();
    s2.accendi();
    delay(5000);
    s1.avanza();
    s2.avanza();
    s1.accendi();
    s2.accendi();
    delay(3000);
    s1.avanza();
    s2.avanza();
    if (interr == 1)
    {
        lampeggia();
    }
}

void lampeggia()
{
    for (int i = 0; i < 5; i++)
    {
        s1.giallo();
        s2.giallo();
        delay(500);
        s1.spegni();
        s2.spegni();
        delay(500);
    }
    interr = 0;
    s1.rFase();
    s2.rFase();
}

void reset() 
{
    interr = 1;
}